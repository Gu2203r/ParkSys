package parksys.observer;

import parksys.enums.StatusVaga;
import java.util.HashMap;
import java.util.Map;


public class PainelMonitor implements EstacionamentoObserver {

    // Mapa local: idVaga -> StatusVaga
    private final Map<String, StatusVaga> mapaStatus = new HashMap<>();


    // Chamado pelo GerenciadorEstacionamento via notificarObservadores() sempre que uma vaga muda de status (ocupar, liberar, reservar).

    @Override
    public void onVagaAlterada(String idVaga, StatusVaga novoStatus) {
        mapaStatus.put(idVaga, novoStatus);
        exibirAtualizacao(idVaga, novoStatus);
    }

    protected void exibirAtualizacao(String idVaga, StatusVaga novoStatus) {
        System.out.println("[PainelMonitor] Vaga " + idVaga
                + " → " + novoStatus.getDescricao());
    }

    // --- Consultas úteis para a UI ---

    public StatusVaga getStatus(String idVaga) {
        return mapaStatus.getOrDefault(idVaga, StatusVaga.LIVRE);
    }

    public long contarPorStatus(StatusVaga status) {
        return mapaStatus.values().stream()
                .filter(s -> s == status)
                .count();
    }

    public Map<String, StatusVaga> getMapaStatus() {
        return mapaStatus;
    }

    public void exibirResumo() {
        System.out.printf("[PainelMonitor] Livres: %d | Ocupadas: %d | Reservadas: %d%n", contarPorStatus(StatusVaga.LIVRE), contarPorStatus(StatusVaga.OCUPADA), contarPorStatus(StatusVaga.RESERVADA));
    }
}