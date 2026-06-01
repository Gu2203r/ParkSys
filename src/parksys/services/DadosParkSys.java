package parksys.services;

import parksys.entities.Mensalista;
import parksys.entities.Registro;
import parksys.entities.Vaga;
import java.io.Serializable;
import java.util.List;
import java.util.Map;

public class DadosParkSys implements Serializable {

    private static final long serialVersionUID = 1L;

    // Possui os três mapas/listas
    private final Map<String, Vaga> vagas;
    private final List<Registro> registros;
    private final List<Mensalista> mensalistas;

    public DadosParkSys(Map<String, Vaga> vagas, List<Registro> registros, List<Mensalista> mensalistas) {
        this.vagas = vagas;
        this.registros = registros;
        this.mensalistas = mensalistas;
    }

    public Map<String, Vaga> getVagas(){
        return vagas;
    }
    public List<Registro> getRegistros(){
        return registros;
    }
    public List<Mensalista> getMensalistas(){
        return mensalistas;
    }
}