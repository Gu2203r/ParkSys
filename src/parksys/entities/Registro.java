package parksys.entities;

import parksys.enums.TipoVeiculo;
import java.io.Serializable;
import java.time.LocalDateTime;
import java.time.Duration;
import java.util.ArrayList;
import java.util.List;
import java.util.UUID;

public class Registro implements Serializable, Comparable<Registro> {

    private static final long serialVersionUID = 1L;

    private String id;
    private Veiculo veiculo;
    private List<String> idsVagas;
    private LocalDateTime dataEntrada;
    private LocalDateTime dataSaida;
    private double valorPago;

    private transient String threadOrigem;

    // --- Construtor (chamado na entrada do veículo) ---

    public Registro(Veiculo veiculo, List<String> idsVagas, LocalDateTime dataEntrada) {
        this.id = UUID.randomUUID().toString();
        this.veiculo = veiculo;
        this.idsVagas = new ArrayList<>(idsVagas);
        this.dataEntrada = dataEntrada;
        this.dataSaida = null;
        this.valorPago = 0.0;
    }

    // --- Operações ---

    public void registrarSaida(LocalDateTime dataSaida, double valorPago) {
        this.dataSaida = dataSaida;
        this.valorPago = valorPago;
    }

    public boolean isAtivo() {
        return dataSaida == null;
    }

    public double getDuracaoHoras() {
        LocalDateTime fim = (dataSaida != null) ? dataSaida : LocalDateTime.now();
        long minutos = Duration.between(dataEntrada, fim).toMinutes();
        double horas = minutos / 60.0;
        return Math.max(horas, 1.0);
    }

    @Override
    public int compareTo(Registro outro) {
        return this.dataEntrada.compareTo(outro.dataEntrada);
    }

    // --- Getters ---

    public String getId() { return id; }
    public Veiculo getVeiculo() { return veiculo; }
    public List<String> getIdsVagas() { return idsVagas; }
    public LocalDateTime getDataEntrada() { return dataEntrada; }
    public LocalDateTime getDataSaida() { return dataSaida; }
    public double getValorPago() { return valorPago; }
    public String getThreadOrigem() { return threadOrigem; }
    public void setThreadOrigem(String threadOrigem) { this.threadOrigem = threadOrigem; }

    @Override
    public String toString() {
        String saida = (dataSaida != null) ? dataSaida.toString() : "em aberto";
        return "[" + veiculo.getPlaca() + " | entrada: " + dataEntrada
                + " | saída: " + saida + " | R$ " + String.format("%.2f", valorPago) + "]";
    }
}