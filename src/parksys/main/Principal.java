package parksys.main;

import parksys.entities.Registro;
import parksys.enums.TipoVeiculo;
import parksys.services.*;
import parksys.ui.TelaInicial;

import javax.swing.SwingUtilities;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;

public class Principal {

    private static final String ARQUIVO_DADOS = "parksys.ser";

    public static void main(String[] args) throws InterruptedException {

        GerenciadorEstacionamento gerenciador = GerenciadorEstacionamento.getInstance();

        DadosParkSys dados = GerenciadorArquivo.desserializar(ARQUIVO_DADOS);

        if (!dados.getVagas().isEmpty()) {
            gerenciador.setVagas(new HashMap<>(dados.getVagas()));
        }
        gerenciador.setRegistros(new ArrayList<>(dados.getRegistros()));
        gerenciador.setMensalistas(new LinkedList<>(dados.getMensalistas()));
        
        System.out.println("\n--- threadOrigem após desserialização ---");
        for (Registro r : gerenciador.getRegistros()) {
            System.out.println("  " + r.getVeiculo().getPlaca()
                    + " → threadOrigem: " + r.getThreadOrigem()); // sempre null aqui
        }
        System.out.println("-----------------------------------------\n");

        // M06 — daemon iniciado antes das threads de entrada
        Thread monitor = new Thread(new MonitorRunnable(gerenciador), "Monitor");
        monitor.setDaemon(true);
        monitor.start();

        // M05 — mínimo de 4 threads simulando entradas concorrentes
        Thread t1 = new Thread(new EntradaRunnable("ABC1234", TipoVeiculo.CARRO,    "A01", gerenciador), "Entrada-1");
        Thread t2 = new Thread(new EntradaRunnable("DEF5678", TipoVeiculo.MOTO,     "A03", gerenciador), "Entrada-2");
        Thread t3 = new Thread(new EntradaRunnable("GHI9J12", TipoVeiculo.SUV,      "B01", gerenciador), "Entrada-3");
        Thread t4 = new Thread(new EntradaRunnable("JKL3456", TipoVeiculo.CAMINHAO, "B05", gerenciador), "Entrada-4");

        t1.start();
        t2.start();
        t3.start();
        t4.start();

        // M05 — join() garante que o relatório só roda após todas as entradas
        t1.join();
        t2.join();
        t3.join();
        t4.join();

        monitor.interrupt();
        monitor.join();

        // Relatório da demonstração de threads no console
        System.out.println("\n========== RELATÓRIO DA DEMONSTRAÇÃO (THREADS) ==========");
        System.out.printf("Receita total: R$ %.2f%n", gerenciador.calcularReceitaTotal());
        System.out.println("Registros (ordem cronológica):");
        for (Registro r : gerenciador.getRegistrosOrdenados()) {
            System.out.println("  " + r);
        }
        System.out.println("===========================================================\n");

        // Persiste o estado gerado pela demonstração antes de abrir a UI
        GerenciadorArquivo.serializar(
                gerenciador.getVagas(),
                gerenciador.getRegistros(),
                gerenciador.getMensalistas(),
                ARQUIVO_DADOS);


        SwingUtilities.invokeLater(() -> new TelaInicial().setVisible(true));
    }
}