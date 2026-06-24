package parksys.services;

import parksys.entities.Veiculo;
import parksys.enums.TipoVeiculo;
import parksys.exceptions.PlacaInvalidaException;
import parksys.exceptions.VagaOcupadaException;


// EntradaRunnable simula o processamento da entrada de um veículo em uma thread separada. Cada cancela do estacionamento seria uma thread.

public class EntradaRunnable implements Runnable {

    private final String placa;
    private final TipoVeiculo tipo;
    private final String idVagaDesejada;
    private final GerenciadorEstacionamento gerenciador;

    public EntradaRunnable(String placa, TipoVeiculo tipo, String idVagaDesejada, GerenciadorEstacionamento gerenciador) {
        this.placa = placa;
        this.tipo = tipo;
        this.idVagaDesejada = idVagaDesejada;
        this.gerenciador = gerenciador;
    }

    @Override
    public void run() {
        try {

            // M02 — simula o tempo real de processamento: leitura da placa pela câmera, abertura da cancela, impressão do ticket, etc.
            Thread.sleep(200);

            Veiculo veiculo = new Veiculo(placa, tipo, "");
            gerenciador.registrarEntrada(veiculo, idVagaDesejada);

            System.out.println("[" + Thread.currentThread().getName()
                    + "] Entrada registrada: " + placa
                    + " → vaga " + idVagaDesejada);

        } catch (InterruptedException e) {

//          Nunca executar InterruptedException silenciosamente. Restaurar o status de interrupção permite que o chamador (join(), executor, etc.) saiba que esta thread foi interrompida.

            Thread.currentThread().interrupt();
            System.err.println("[" + Thread.currentThread().getName()
                    + "] Processamento interrompido para placa " + placa);

        } catch (VagaOcupadaException e) {
            System.err.println("[" + Thread.currentThread().getName()
                    + "] Vaga indisponível: " + e.getMessage());

        } catch (PlacaInvalidaException e) {
            System.err.println("[" + Thread.currentThread().getName()
                    + "] Placa inválida: " + e.getMessage());
        }
    }
}