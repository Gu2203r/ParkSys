package parksys.ui;

import parksys.observer.PainelMonitor;
import parksys.services.GerenciadorEstacionamento;

import javax.swing.*;
import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class TelaInicial extends JFrame {

    private PainelMonitor painelMonitor;
    private JButton btnEntrada;
    private JButton btnSaida;
    private JButton btnMensalista;
    private JButton btnRelatorio;

    public TelaInicial() {
        setTitle("ParkSys - Sistema de Gestão de Estacionamento");
        setSize(380, 250);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setLayout(new BorderLayout());

        painelMonitor = new PainelMonitor();

        // Requisito P06: Registrar o PainelMonitor como observador ao iniciar
        GerenciadorEstacionamento.getInstance().addObserver(painelMonitor);

        JPanel painelBotoes = new JPanel(new GridLayout(4, 1, 5, 5));
        painelBotoes.setBorder(BorderFactory.createEmptyBorder(15, 35, 15, 35));

        btnEntrada = new JButton("Registrar Entrada");
        btnSaida = new JButton("Registrar Saída");
        btnMensalista = new JButton("Cadastrar Mensalista");
        btnRelatorio = new JButton("Exibir Relatório");

        painelBotoes.add(btnEntrada);
        painelBotoes.add(btnSaida);
        painelBotoes.add(btnMensalista);
        painelBotoes.add(btnRelatorio);

        add(painelBotoes, BorderLayout.WEST);

        btnEntrada.addActionListener(e -> {
            new TelaRegistroEntrada(TelaInicial.this).setVisible(true);
        });

        btnSaida.addActionListener(e -> {
            new TelaSaida(TelaInicial.this).setVisible(true);
        });

        add(new JLabel("Painel do Sistema de Estacionamento", SwingConstants.CENTER), BorderLayout.CENTER);

        // Requisito P06: Ao fechar a aplicação, remover o observador antes de encerrar
        addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                GerenciadorEstacionamento.getInstance().removeObserver(painelMonitor);
            }
        });
    }
}