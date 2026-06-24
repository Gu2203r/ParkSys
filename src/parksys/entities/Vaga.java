package parksys.entities;

import parksys.enums.StatusVaga;
import parksys.enums.TipoVeiculo;
import java.io.Serializable;

public class Vaga implements Serializable {

    private static final long serialVersionUID = 1L;

    private String id;
    private StatusVaga status;
    private String placaVeiculoAtual;
    private TipoVeiculo tipoVeiculoAtual;

    public Vaga(String id) {
        this.id = id;
        this.status = StatusVaga.LIVRE;
        this.placaVeiculoAtual = null;
        this.tipoVeiculoAtual = null;
    }

    // --- Mudanças de estado ---

    public void ocupar(String placa, TipoVeiculo tipo) {
        this.status = StatusVaga.OCUPADA;
        this.placaVeiculoAtual = placa;
        this.tipoVeiculoAtual = tipo;
    }

    public void liberar() {
        this.status = StatusVaga.LIVRE;
        this.placaVeiculoAtual = null;
        this.tipoVeiculoAtual = null;
    }

    public void reservar() {
        this.status = StatusVaga.RESERVADA;
    }

    // --- Consulta ---

    public boolean isDisponivel() {
        return status.isDisponivel(); // delega para o Enum — nunca compare status diretamente
    }

    // --- Getters ---

    public String getId() { return id; }
    public StatusVaga getStatus() { return status; }
    public String getPlacaVeiculoAtual() { return placaVeiculoAtual; }
    public TipoVeiculo getTipoVeiculoAtual() { return tipoVeiculoAtual; }

    @Override
    public String toString() {
        String veiculo = (placaVeiculoAtual != null)
                ? placaVeiculoAtual + " | " + tipoVeiculoAtual.getNomeLegivel()
                : "-";
        return "[" + id + " | " + status.getDescricao() + " | " + veiculo + "]";
    }
}