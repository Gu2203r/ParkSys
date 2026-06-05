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

    public static synchronized GerenciadorEstacionamento getInstance() {
        if (instancia == null) {
            instancia = new GerenciadorEstacionamento();
        }
        return instancia;
    }

    private HashMap<String, Vaga> vagas = new HashMap<>();

    private ArrayList<Registro> registros = new ArrayList<>();

    private LinkedList<Mensalista> mensalistas = new LinkedList<>();

}
