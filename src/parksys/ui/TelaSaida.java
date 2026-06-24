package parksys.ui;

import parksys.services.GerenciadorEstacionamento;

import javax.swing.*;
import java.awt.*;

public class TelaSaida extends JDialog{
    private JTextField txtPlaca;
    private JButton btnRegistrarSaida;

    public TelaSaida(JFrame parent) {
        super(parent, "Registrar Saída", true);
        setSize(380, 250);
        setLayout(new FlowLayout(FlowLayout.CENTER, 10, 20));
        setLocationRelativeTo(parent);

        add(new JLabel("Placa do Veículo:"));
        txtPlaca = new JTextField(15);
        add(txtPlaca);

        btnRegistrarSaida = new JButton("Registrar Saída");
        add(btnRegistrarSaida);

        btnRegistrarSaida.addActionListener(e -> registrarSaida());
    }

    private void registrarSaida() {
        String placa = txtPlaca.getText().trim().toUpperCase();

        if (placa.isEmpty()) {
            JOptionPane.showMessageDialog(this, "Informe a placa do veículo!", "Aviso", JOptionPane.WARNING_MESSAGE);
            return;
        }

        try {

            double valorPago = GerenciadorEstacionamento.getInstance().registrarSaida(placa);

            JOptionPane.showMessageDialog(this,
                    String.format("Saída registrada com sucesso!\nValor a pagar: R$ %.2f", valorPago),
                    "Sucesso",
                    JOptionPane.INFORMATION_MESSAGE);
            dispose();

        } catch (Exception ex) {
            JOptionPane.showMessageDialog(this, "Erro ao registrar saída: " + ex.getMessage(), "Erro", JOptionPane.ERROR_MESSAGE);
        }
    }
}
