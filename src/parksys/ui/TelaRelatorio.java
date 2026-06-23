package parksys.ui;

import parksys.entities.Registro;
import parksys.enums.StatusVaga;
import parksys.services.GerenciadorEstacionamento;

import javax.swing.*;
import java.awt.*;
import java.util.List;
import java.util.Map;

public class TelaRelatorio extends JDialog {

    private JTextArea txtRelatorio;
    private JButton btnFechar;

    public TelaRelatorio(JFrame parent) {
        super(parent, "Relatório do Sistema (C06)", true);
        setSize(450, 400);
        setLayout(new BorderLayout(10, 10));
        setLocationRelativeTo(parent);

        // Área de texto onde o relatório será impresso
        txtRelatorio = new JTextArea();
        txtRelatorio.setEditable(false);
        txtRelatorio.setFont(new Font("Monospaced", Font.PLAIN, 14));

        JScrollPane scroll = new JScrollPane(txtRelatorio);
        scroll.setBorder(BorderFactory.createTitledBorder("Dados do Estacionamento"));
        add(scroll, BorderLayout.CENTER);

        // Botão para fechar
        JPanel painelBotao = new JPanel();
        btnFechar = new JButton("Fechar Relatório");
        btnFechar.addActionListener(e -> dispose());
        painelBotao.add(btnFechar);
        add(painelBotao, BorderLayout.SOUTH);

        gerarRelatorio();
    }

    private void gerarRelatorio() {
        GerenciadorEstacionamento ger = GerenciadorEstacionamento.getInstance();
        StringBuilder sb = new StringBuilder();

        sb.append("========================================\n");
        sb.append("          RELATÓRIO DO PARKSYS          \n");
        sb.append("========================================\n\n");

        // C06 - Total de vagas iterando com entrySet
        Map<StatusVaga, Long> vagasPorStatus = ger.contarVagasPorStatus();
        sb.append("--- STATUS DAS VAGAS ---\n");
        sb.append("Livres:     ").append(vagasPorStatus.get(StatusVaga.LIVRE)).append("\n");
        sb.append("Ocupadas:   ").append(vagasPorStatus.get(StatusVaga.OCUPADA)).append("\n");
        sb.append("Reservadas: ").append(vagasPorStatus.get(StatusVaga.RESERVADA)).append("\n\n");

        // C06 - Receita Total
        double receita = ger.calcularReceitaTotal();
        sb.append("--- RECEITA TOTAL DO SISTEMA ---\n");
        sb.append(String.format("R$ %.2f\n\n", receita));

        // C05 e C06 - Listagem de Registros ordenados por receita
        sb.append("--- REGISTROS ORDENADOS POR VALOR ---\n");
        List<Registro> registros = ger.getRegistrosOrdenadosPorReceita();

        if (registros.isEmpty()) {
            sb.append("Nenhum registro de veículo encontrado.\n");
        } else {
            for (Registro r : registros) {
                String placa = r.getVeiculo().getPlaca();
                String vagas = r.getIdsVagas().toString();
                double valor = r.getValorPago();

                sb.append(String.format("Placa: %s | Vagas: %s | Valor Pago: R$ %.2f\n", placa, vagas, valor));
            }
        }

        txtRelatorio.setText(sb.toString());
        txtRelatorio.setCaretPosition(0);
    }
}