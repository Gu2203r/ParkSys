package parksys.ui;

import parksys.entities.Veiculo;
import parksys.enums.TipoVeiculo;
import parksys.services.GerenciadorEstacionamento;

import javax.swing.*;
import java.awt.*;

public class TelaRegistroEntrada extends JDialog {

    private JTextField txtPlaca;
    private JComboBox<TipoVeiculo> cbTipoVeiculo;
    private JTextField txtProprietario;
    private JTextField txtVagaInicial;
    private JButton btnRegistrar;

    public TelaRegistroEntrada(JFrame parent) {
        super(parent, "Registrar Entrada", true);
        setSize(320, 290);
        setLayout(new GridLayout(6, 1, 10, 10));
        setLocationRelativeTo(parent);

        // Componentes da Placa
        JPanel painelPlaca = new JPanel(new FlowLayout(FlowLayout.LEFT));
        painelPlaca.add(new JLabel("Placa:"));
        txtPlaca = new JTextField(15);
        painelPlaca.add(txtPlaca);
        add(painelPlaca);

        // Componentes do Tipo de Veículo
        JPanel painelTipo = new JPanel(new FlowLayout(FlowLayout.LEFT));
        painelTipo.add(new JLabel("Tipo de Veículo:"));
        cbTipoVeiculo = new JComboBox<>(TipoVeiculo.values());
        painelTipo.add(cbTipoVeiculo);
        add(painelTipo);

        // Componentes do Proprietário
        JPanel painelProprietario = new JPanel(new FlowLayout(FlowLayout.LEFT));
        painelProprietario.add(new JLabel("Proprietário:"));
        txtProprietario = new JTextField(15);
        painelProprietario.add(txtProprietario);
        add(painelProprietario);

        // Componentes da Vaga Inicial
        JPanel painelVaga = new JPanel(new FlowLayout(FlowLayout.LEFT));
        painelVaga.add(new JLabel("Vaga Inicial:"));
        txtVagaInicial = new JTextField(10);
        painelVaga.add(txtVagaInicial);
        add(painelVaga);

        // Botão de registrar
        JPanel painelBotao = new JPanel(new FlowLayout(FlowLayout.CENTER));
        btnRegistrar = new JButton("Registrar Entrada");
        painelBotao.add(btnRegistrar);
        add(painelBotao);

        // Ação do botão
        btnRegistrar.addActionListener(e -> registrarEntrada());
    }

    private void registrarEntrada() {
        String placa = txtPlaca.getText().trim().toUpperCase();
        TipoVeiculo tipo = (TipoVeiculo) cbTipoVeiculo.getSelectedItem();
        String proprietario = txtProprietario.getText().trim();
        String vagaInicial = txtVagaInicial.getText().trim().toUpperCase(); // Pega a vaga digitada

        if (placa.isEmpty() || proprietario.isEmpty() || vagaInicial.isEmpty()) {
            JOptionPane.showMessageDialog(this, "Por favor, preencha todos os campos.", "Aviso", JOptionPane.WARNING_MESSAGE);
            return;
        }

        try {

            Veiculo veiculo = new Veiculo(placa, tipo, proprietario);


            GerenciadorEstacionamento.getInstance().registrarEntrada(veiculo, vagaInicial);

            JOptionPane.showMessageDialog(this, "Entrada do veículo " + placa + " registrada com sucesso na vaga " + vagaInicial + "!", "Sucesso", JOptionPane.INFORMATION_MESSAGE);
            dispose();

        } catch (Exception ex) {
            JOptionPane.showMessageDialog(this, "Erro ao registrar entrada: " + ex.getMessage(), "Erro", JOptionPane.ERROR_MESSAGE);
        }
    }
}