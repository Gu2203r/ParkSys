package parksys.ui;

import parksys.observer.PainelMonitor;
import parksys.services.GerenciadorArquivo;
import parksys.services.GerenciadorEstacionamento;

import javax.swing.*;
import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class TelaInicial extends JFrame {

    private static final String ARQUIVO_DADOS = "parksys.ser";

    private PainelMonitor painelMonitor;
    private JButton btnEntrada, btnSaida, btnMensalista, btnRelatorio;

    public TelaInicial() {
        setTitle("ParkSys - Sistema de Gestão de Estacionamento");
        setSize(380, 250);
        setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE); // controlado manualmente no windowClosing
        setLocationRelativeTo(null);

        JPanel painelFundo = new JPanel(new BorderLayout()) {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                Image imagemFundo = new ImageIcon("estacionamento.jpg").getImage();
                g.drawImage(imagemFundo, 0, 0, getWidth(), getHeight(), this);
            }
        };
        setContentPane(painelFundo);

        // P06: Inicialização e Registro do Observador
        // Nota: a desserialização inicial já ocorreu em Principal.java —
        // o Gerenciador (Singleton) chega aqui com os dados já carregados.
        painelMonitor = new PainelMonitor();
        GerenciadorEstacionamento.getInstance().addObserver(painelMonitor);

        JPanel painelBotoes = new JPanel(new GridLayout(4, 1, 5, 5));
        painelBotoes.setBorder(BorderFactory.createEmptyBorder(15, 35, 15, 35));
        painelBotoes.setOpaque(false);

        btnEntrada = new JButton("Registrar Entrada");
        btnSaida = new JButton("Registrar Saída");
        btnMensalista = new JButton("Cadastrar Mensalista");
        btnRelatorio = new JButton("Exibir Relatório");

        estilizarBotao(btnEntrada);
        estilizarBotao(btnSaida);
        estilizarBotao(btnMensalista);
        estilizarBotao(btnRelatorio);

        painelBotoes.add(btnEntrada);
        painelBotoes.add(btnSaida);
        painelBotoes.add(btnMensalista);
        painelBotoes.add(btnRelatorio);

        painelFundo.add(painelBotoes, BorderLayout.WEST);

        btnEntrada.addActionListener(e -> new TelaRegistroEntrada(TelaInicial.this).setVisible(true));
        btnSaida.addActionListener(e -> new TelaSaida(TelaInicial.this).setVisible(true));
        btnMensalista.addActionListener(e -> new TelaCadastroMensalista(TelaInicial.this).setVisible(true));
        btnRelatorio.addActionListener(e -> new TelaRelatorio(TelaInicial.this).setVisible(true));

        addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                GerenciadorEstacionamento ger = GerenciadorEstacionamento.getInstance();

                // P06: Remove o observador antes de encerrar
                ger.removeObserver(painelMonitor);

                /*
                 * S06 — serializa automaticamente ao fechar a janela principal.
                 * Este é o ponto final de persistência: tudo que o usuário fez
                 * nas telas de entrada, saída, mensalista, etc. é salvo aqui.
                 */
                GerenciadorArquivo.serializar(
                        ger.getVagas(),
                        ger.getRegistros(),
                        ger.getMensalistas(),
                        ARQUIVO_DADOS);

                dispose();
                System.exit(0);
            }
        });
    }

    private void estilizarBotao(JButton btn) {

        btn.setPreferredSize(new Dimension(220, 30));

        btn.setContentAreaFilled(false);
        btn.setBorderPainted(false);
        btn.setOpaque(false);

        btn.setForeground(Color.WHITE);
        btn.setFont(new Font("Segoe UI", Font.BOLD, 14));
        btn.setFocusPainted(false);

        btn.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                btn.setForeground(new Color(200, 200, 200));
            }

            public void mouseExited(java.awt.event.MouseEvent evt) {
                btn.setForeground(Color.WHITE);
            }
        });

    }
}