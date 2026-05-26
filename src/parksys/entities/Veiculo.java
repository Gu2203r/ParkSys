package parksys.entities;

import parksys.enums.TipoVeiculo;
import parksys.exceptions.PlacaInvalidaException;
import java.io.Serializable;

public class Veiculo implements Serializable {

    private static final long serialVersionUID = 1L;

    private String placa;
    private TipoVeiculo tipo;
    private String proprietario;

    public Veiculo(String placa, TipoVeiculo tipo, String proprietario)
            throws PlacaInvalidaException {
        validarPlaca(placa);
        this.placa = placa.toUpperCase().trim();
        this.tipo = tipo;
        this.proprietario = proprietario;
    }

    // --- Validação ---

    /*
     * Aceita dois formatos de placa brasileira:
     *   Padrão antigo:  ABC-1234  ou  ABC1234
     *   Padrão Mercosul: ABC1D23
     */
    private void validarPlaca(String placa) throws PlacaInvalidaException {
        if (placa == null || placa.isBlank()) {
            throw new PlacaInvalidaException("Placa não pode ser vazia.");
        }
        String normalizada = placa.toUpperCase().trim().replace("-", "");
        boolean antigoValido   = normalizada.matches("[A-Z]{3}[0-9]{4}");
        boolean mercosulValido = normalizada.matches("[A-Z]{3}[0-9][A-Z][0-9]{2}");
        if (!antigoValido && !mercosulValido) {
            throw new PlacaInvalidaException(
                    "Placa inválida: \"" + placa + "\". Use ABC1234 ou ABC1D23.");
        }
    }

    // --- Getters ---

    public String getPlaca() { return placa; }
    public TipoVeiculo getTipo() { return tipo; }
    public String getProprietario() { return proprietario; }

    @Override
    public String toString() {
        return "[" + placa + " | " + tipo.getNomeLegivel() + " | " + proprietario + "]";
    }
}