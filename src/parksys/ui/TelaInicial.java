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

        JPanel painelFundo = new JPanel(new BorderLayout()) {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                // O Java vai procurar uma imagem chamada "fundo.jpg" na pasta principal do seu projeto
                Image imagemFundo = new ImageIcon("Parking.jpg").getImage();
                g.drawImage(imagemFundo, 0, 0, getWidth(), getHeight(), this);
            }
        };

        setContentPane(painelFundo);

        painelMonitor = new PainelMonitor();

        // Requisito P06: Registrar o PainelMonitor como observador ao iniciar
        GerenciadorEstacionamento.getInstance().addObserver(painelMonitor);

        JPanel painelBotoes = new JPanel(new GridLayout(4, 1, 5, 5));
        painelBotoes.setBorder(BorderFactory.createEmptyBorder(15, 35, 15, 35));

        painelBotoes.setOpaque(false);

        btnEntrada = new JButton("Registrar Entrada");
        btnSaida = new JButton("Registrar Saída");
        btnMensalista = new JButton("Cadastrar Mensalista");
        btnRelatorio = new JButton("Exibir Relatório");

        painelBotoes.add(btnEntrada);
        painelBotoes.add(btnSaida);
        painelBotoes.add(btnMensalista);
        painelBotoes.add(btnRelatorio);

        painelFundo.add(painelBotoes, BorderLayout.WEST);

        Color corBotoes = new Color(90, 15, 20);
        Font fonteBotoes = new Font("Segoe UI", Font.BOLD, 14);

        btnEntrada.setBackground(corBotoes);
        btnEntrada.setForeground(Color.WHITE);
        btnEntrada.setFont(fonteBotoes);
        btnEntrada.setFocusPainted(false);

        btnSaida.setBackground(corBotoes);
        btnSaida.setForeground(Color.WHITE);
        btnSaida.setFont(fonteBotoes);
        btnSaida.setFocusPainted(false);

        btnMensalista.setBackground(corBotoes);
        btnMensalista.setForeground(Color.WHITE);
        btnMensalista.setFont(fonteBotoes);
        btnMensalista.setFocusPainted(false);

        btnRelatorio.setBackground(corBotoes);
        btnRelatorio.setForeground(Color.WHITE);
        btnRelatorio.setFont(fonteBotoes);
        btnRelatorio.setFocusPainted(false);
        // ========================================================

        btnEntrada.addActionListener(e -> {
            new TelaRegistroEntrada(TelaInicial.this).setVisible(true);
        });

        btnSaida.addActionListener(e -> {
            new TelaSaida(TelaInicial.this).setVisible(true);
        });

        btnMensalista.addActionListener(e -> {
            new TelaCadastroMensalista(TelaInicial.this).setVisible(true);
        });

        btnRelatorio.addActionListener(e -> {
            new TelaRelatorio(TelaInicial.this).setVisible(true);
        });

        JLabel tituloCentral = new JLabel("Painel do Sistema", SwingConstants.CENTER);
        tituloCentral.setForeground(Color.WHITE);
        painelFundo.add(tituloCentral, BorderLayout.CENTER);

        // Requisito P06: Ao fechar a aplicação, remover o observador antes de encerrar
        addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                GerenciadorEstacionamento.getInstance().removeObserver(painelMonitor);
            }
        });
    }
}