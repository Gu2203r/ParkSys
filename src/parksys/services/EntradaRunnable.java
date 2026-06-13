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
        
    }
}