package parksys.entities;

import java.io.Serializable;
import java.time.LocalDate;
import java.time.YearMonth;

public class Mensalista implements Serializable {

    private static final long serialVersionUID = 1L;

    private String nome;
    private String cpf;
    private String telefone;
    private String idVaga;       // ID da vaga reservada exclusivamente para este mensalista
    private LocalDate dataInicio;
    private LocalDate dataVencimento;
    private double mensalidade;

    // --- Construtor ---

    /*
     * Ao cadastrar, o vencimento é definido como o último dia do mês atual.
     * Usar YearMonth.atEndOfMonth() garante que fevereiro (28/29 dias),
     * meses de 30 e 31 dias sejam tratados corretamente sem nenhum cálculo manual.
     */
    public Mensalista(String nome, String cpf, String telefone,
                      String idVaga, double mensalidade) {
        this.nome = nome;
        this.cpf = cpf;
        this.telefone = telefone;
        this.idVaga = idVaga;
        this.mensalidade = mensalidade;
        this.dataInicio = LocalDate.now();
        this.dataVencimento = YearMonth.now().atEndOfMonth();
    }

    // --- Lógica de negócio ---

    /*
     * Verifica se a mensalidade está vigente no mês corrente.
     * Chamado pelo GerenciadorEstacionamento antes de permitir a entrada:
     * se retornar false, o acesso é negado mesmo que a vaga esteja RESERVADA.
     */
    public boolean isAtivoNoMes() {
        return !LocalDate.now().isAfter(dataVencimento);
    }

    /*
     * Renova por mais um mês a partir do vencimento atual.
     * Evita "pular" dias caso a renovação seja feita antes do vencimento.
     */
    public void renovar() {
        this.dataVencimento = YearMonth.from(dataVencimento)
                .plusMonths(1)
                .atEndOfMonth();
    }

    // --- Getters ---

    public String getNome()          { return nome; }
    public String getCpf()           { return cpf; }
    public String getTelefone()      { return telefone; }
    public String getIdVaga()        { return idVaga; }
    public LocalDate getDataInicio() { return dataInicio; }
    public LocalDate getDataVencimento() { return dataVencimento; }
    public double getMensalidade()   { return mensalidade; }

    @Override
    public String toString() {
        String status = isAtivoNoMes() ? "ATIVO" : "VENCIDO";
        return "[" + nome + " | CPF: " + cpf
                + " | Vaga: " + idVaga
                + " | Venc.: " + dataVencimento
                + " | " + status + "]";
    }
}