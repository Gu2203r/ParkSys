package parksys.main;

import parksys.entities.Registro;
import parksys.enums.TipoVeiculo;
import parksys.services.*;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;

public class Principal {

    private static final String ARQUIVO_DADOS = "parksys.ser";

    public static void main(String[] args) throws InterruptedException {

        GerenciadorEstacionamento gerenciador = GerenciadorEstacionamento.getInstance();

        // desserializa automaticamente ao iniciar
        DadosParkSys dados = GerenciadorArquivo.desserializar(ARQUIVO_DADOS);

        System.out.println("\n--- threadOrigem após desserialização ---");
        for (Registro r : gerenciador.getRegistros()) {
            System.out.println("  " + r.getVeiculo().getPlaca()
                    + " → threadOrigem: " + r.getThreadOrigem()); // sempre null aqui
        }
        System.out.println("-----------------------------------------\n");

        if (!dados.getVagas().isEmpty()) {
            gerenciador.setVagas(new HashMap<>(dados.getVagas()));
        }
        gerenciador.setRegistros(new ArrayList<>(dados.getRegistros()));
        gerenciador.setMensalistas(new LinkedList<>(dados.getMensalistas()));

        // setDaemon(true) deve ser chamado antes de start(), caso contrário lança IllegalThreadStateException
        Thread monitor = new Thread(new MonitorRunnable(gerenciador), "Monitor");
        monitor.setDaemon(true);
        monitor.start();

        // mínimo de 4 threads, cada uma com nome "Entrada-X"
        Thread t1 = new Thread(new EntradaRunnable("ABC1234", TipoVeiculo.CARRO,    "A01", gerenciador), "Entrada-1");
        Thread t2 = new Thread(new EntradaRunnable("DEF5678", TipoVeiculo.MOTO,     "A03", gerenciador), "Entrada-2");
        Thread t3 = new Thread(new EntradaRunnable("GHI9J12", TipoVeiculo.SUV,      "B01", gerenciador), "Entrada-3");
        Thread t4 = new Thread(new EntradaRunnable("JKL3456", TipoVeiculo.CAMINHAO, "B05", gerenciador), "Entrada-4");

        t1.start();
        t2.start();
        t3.start();
        t4.start();

        // join() bloqueia a thread main até cada thread terminar. Sem join(), o relatório final seria exibido antes das entradas serem processadas — race condition clássica.

        t1.join();
        t2.join();
        t3.join();
        t4.join();

        // Encerra o monitor após todas as entradas concluírem
        monitor.interrupt();

        // Aguarda o monitor encerrar de forma limpa antes do relatório
        monitor.join();

        // Relatório final no console (M05)
        System.out.println("\n========== RELATÓRIO FINAL ==========");
        System.out.printf("Receita total: R$ %.2f%n",
                gerenciador.calcularReceitaTotal());
        System.out.println("Registros (ordem cronológica):");
        for (Registro r : gerenciador.getRegistrosOrdenados()) {
            System.out.println("  " + r);
        }


        // serializa automaticamente ao encerrar
        GerenciadorArquivo.serializar(gerenciador.getVagas(), gerenciador.getRegistros(), gerenciador.getMensalistas(), ARQUIVO_DADOS);

        GerenciadorArquivo.exportarRelatorioTxt(gerenciador.getRegistros(), gerenciador.getVagas(), "relatorio.txt");

        System.out.println("=====================================");
    }
}