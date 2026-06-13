package parksys.services;

import parksys.enums.StatusVaga;
import java.util.Map;


public class MonitorRunnable implements Runnable {

    private final GerenciadorEstacionamento gerenciador;

    public MonitorRunnable(GerenciadorEstacionamento gerenciador) {
        this.gerenciador = gerenciador;
    }

    @Override
    public void run() {
        while (!Thread.currentThread().isInterrupted()) {
            try {
                Map<StatusVaga, Long> contagem = gerenciador.contarVagasPorStatus();

                System.out.printf("[Monitor] Livres: %d | Ocupadas: %d | Reservadas: %d%n", contagem.getOrDefault(StatusVaga.LIVRE, 0L), contagem.getOrDefault(StatusVaga.OCUPADA, 0L), contagem.getOrDefault(StatusVaga.RESERVADA, 0L));

                Thread.sleep(1000);

            } catch (InterruptedException e) {
                // Restaura o status e encerra o loop limpo
                Thread.currentThread().interrupt();
                System.out.println("[Monitor] Encerrado.");
            }
        }
    }
}