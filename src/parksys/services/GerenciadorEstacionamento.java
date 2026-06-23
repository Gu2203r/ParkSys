package parksys.services;

import parksys.entities.Mensalista;
import parksys.entities.Registro;
import parksys.entities.Vaga;
import parksys.entities.Veiculo;
import parksys.enums.StatusVaga;
import parksys.enums.TipoVeiculo;
import parksys.exceptions.VagaOcupadaException;
import parksys.exceptions.VeiculoNaoEncontradoException;
import parksys.observer.EstacionamentoObserver;

import java.time.LocalDateTime;
import java.time.temporal.ChronoUnit;
import java.util.*;

public class GerenciadorEstacionamento {

    private static GerenciadorEstacionamento instancia;

    private GerenciadorEstacionamento() {
        inicializarVagas();
    }


    // P01: Implementacao do padrao Singleton com construtor private e getInstance()
    public static synchronized GerenciadorEstacionamento getInstance() {
        if (instancia == null) {
            instancia = new GerenciadorEstacionamento();
        }
        return instancia;
    }

    private HashMap<String, Vaga> vagas = new HashMap<>();

    private ArrayList<Registro> registros = new ArrayList<>();

    private LinkedList<Mensalista> mensalistas = new LinkedList<>();

    private List<EstacionamentoObserver> observadores = new ArrayList<>();

    private void inicializarVagas() {
        for (int i = 1; i <= 15; i++) {
            String numero = String.format("%02d", i);
            vagas.put("A" + numero, new Vaga("A" + numero));
            vagas.put("B" + numero, new Vaga("B" + numero));
        }
    }

    public synchronized void registrarEntrada(Veiculo veiculo, String idVagaInicial)
            throws VagaOcupadaException {

        // T03 — número de vagas vem do Enum, sem valor fixo no código
        int vagasNecessarias = veiculo.getTipo().getVagasOcupadas();

        List<String> idsSelecionados = encontrarVagasConsecutivas(idVagaInicial, vagasNecessarias);

        // Verifica se todas as vagas consecutivas estão livres
        for (String id : idsSelecionados) {
            Vaga v = vagas.get(id);
            if (v == null || !v.isDisponivel()) {
                throw new VagaOcupadaException("Vaga " + id + " não está disponível.");
            }
        }

        // Ocupa todas as vagas consecutivas necessárias
        for (String id : idsSelecionados) {
            vagas.get(id).ocupar(veiculo.getPlaca(), veiculo.getTipo());
            notificarObservadores(id, StatusVaga.OCUPADA);
        }

        // C02 — adiciona registro no ArrayList
        Registro registro = new Registro(veiculo, idsSelecionados, LocalDateTime.now());
        // M04 — grava o nome da thread que processou a entrada (campo transient)
        registro.setThreadOrigem(Thread.currentThread().getName());
        registros.add(registro);
    }

    private List<String> encontrarVagasConsecutivas(String idInicial, int quantidade) {
        List<String> ids = new ArrayList<>();

        if (quantidade == 1) {
            ids.add(idInicial);
            return ids;
        }

        char fileira = idInicial.charAt(0);
        int numero = Integer.parseInt(idInicial.substring(1));

        for (int i = 0; i < quantidade; i++) {
            String id = fileira + String.format("%02d", numero + i);
            ids.add(id);
        }
        return ids;
    }

    public synchronized double registrarSaida(String placa)
            throws VeiculoNaoEncontradoException {

        Registro registroAberto = null;
        for (Registro r : registros) {
            if (r.getVeiculo().getPlaca().equals(placa) && r.getDataSaida() == null) {
                registroAberto = r;
                break;
            }
        }

        if (registroAberto == null) {
            throw new VeiculoNaoEncontradoException("Veículo com placa " + placa + " não encontrado.");
        }

        LocalDateTime saida = LocalDateTime.now();
        registroAberto.setDataSaida(saida);

        // T03 — tarifa calculada via TipoVeiculo.getTarifaHora(), sem valor fixo
        long minutos = ChronoUnit.MINUTES.between(registroAberto.getDataEntrada(), saida);
        double horas = Math.max(minutos / 60.0, 1.0); // mínimo 1 hora
        double tarifa = registroAberto.getVeiculo().getTipo().getTarifaHora() * horas;
        registroAberto.setValorCobrado(tarifa);

        // Libera as vagas ocupadas
        for (String id : registroAberto.getIdsVagas()) {
            Vaga v = vagas.get(id);
            if (v != null) {
                v.liberar();
                notificarObservadores(id, StatusVaga.LIVRE);
            }
        }

        return tarifa;
    }

    public synchronized void cadastrarMensalista(Mensalista mensalista) {
        // LinkedList.add() é O(1) — adiciona no fim da lista
        mensalistas.add(mensalista);

        // Reserva a vaga do mensalista
        Vaga v = vagas.get(mensalista.getIdVaga());
        if (v != null) {
            v.reservar();
            notificarObservadores(mensalista.getIdVaga(), StatusVaga.RESERVADA);
        }
    }

    public synchronized void removerMensalista(String cpf) {
        // LinkedList.remove() via iterator é eficiente para remoção durante iteração
        Iterator<Mensalista> it = mensalistas.iterator();
        while (it.hasNext()) {
            Mensalista m = it.next();
            if (m.getCpf().equals(cpf)) {
                // Libera a vaga reservada
                Vaga v = vagas.get(m.getIdVaga());
                if (v != null) {
                    v.liberar();
                    notificarObservadores(m.getIdVaga(), StatusVaga.LIVRE);
                }
                it.remove(); // O(1) para LinkedList
                break;
            }
        }
    }

    public TreeSet<Registro> getRegistrosOrdenados() {
        return new TreeSet<>(registros);
    }

    public List<Registro> getRegistrosOrdenadosPorReceita() {
        List<Registro> lista = new ArrayList<>(registros);
        // Comparator decrescente por valor cobrado
        lista.sort(Comparator.comparingDouble(Registro::getValorCobrado).reversed());
        return lista;
    }

    public Map<StatusVaga, Long> contarVagasPorStatus() {
        Map<StatusVaga, Long> contagem = new EnumMap<>(StatusVaga.class);
        for (StatusVaga s : StatusVaga.values()) {
            contagem.put(s, 0L);
        }
        // C06 — iteração via entrySet() do HashMap
        for (Map.Entry<String, Vaga> entry : vagas.entrySet()) {
            StatusVaga status = entry.getValue().getStatus();
            contagem.put(status, contagem.get(status) + 1);
        }
        return contagem;
    }

    public double calcularReceitaTotal() {
        double total = 0;
        for (Registro r : registros) {
            if (r.getDataSaida() != null) {
                total += r.getValorCobrado();
            }
        }
        return total;
    }

    public List<Registro> getRegistrosDoDia() {
        List<Registro> hoje = new ArrayList<>();
        LocalDateTime inicioDoDia = LocalDateTime.now().toLocalDate().atStartOfDay();
        for (Registro r : registros) {
            if (!r.getDataEntrada().isBefore(inicioDoDia)) {
                hoje.add(r);
            }
        }
        return hoje;
    }

    public synchronized HashMap<String, Vaga> getVagas() {
        return vagas;
    }

    public synchronized void setVagas(HashMap<String, Vaga> vagas) {
        this.vagas = vagas;
    }

    public synchronized ArrayList<Registro> getRegistros() {
        return registros;
    }

    public synchronized void setRegistros(ArrayList<Registro> registros) {
        this.registros = registros;
    }

    public synchronized LinkedList<Mensalista> getMensalistas() {
        return mensalistas;
    }

    public synchronized void setMensalistas(LinkedList<Mensalista> mensalistas) {
        this.mensalistas = mensalistas;
    }

    public synchronized Vaga getVaga(String id) {
        return vagas.get(id);
    }

    public synchronized boolean isVagaDisponivel(String id) {
        Vaga v = vagas.get(id);
        return v != null && v.isDisponivel();
    }

    public synchronized List<Vaga> getVagasLivres() {
        List<Vaga> livres = new ArrayList<>();
        for (Vaga v : vagas.values()) {
            if (v.getStatus() == StatusVaga.LIVRE) {
                livres.add(v);
            }
        }
        return livres;
    }


    public void addObserver(EstacionamentoObserver obs) {
        observadores.add(obs);
    }

    public void removeObserver(EstacionamentoObserver obs) {
        observadores.remove(obs);
    }

    private void notificarObservadores(String idVaga, StatusVaga novoStatus) {
        for (EstacionamentoObserver obs : observadores) {
            obs.onVagaAlterada(idVaga, novoStatus);
        }
    }

}
