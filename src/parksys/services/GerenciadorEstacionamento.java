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

    // =========================================================
    // P01 — Singleton
    // =========================================================
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

    // =========================================================
    // C01 — HashMap<String, Vaga>
    // Acesso O(1) por ID de vaga (ex: "A01", "B07").
    // =========================================================
    private HashMap<String, Vaga> vagas = new HashMap<>();

}
