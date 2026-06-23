package parksys.ui;

import parksys.entities.Mensalista;
import parksys.services.GerenciadorEstacionamento;

import javax.swing.*;
import java.awt.*;

public class TelaCadastroMensalista extends JDialog {

    private JTextField txtNome;
    private JTextField txtCpf;
    private JTextField txtTelefone;
    private JTextField txtVaga;
    private JTextField txtMensalidade;
    private JButton btnSalvar;

    public TelaCadastroMensalista(JFrame parent) {
        super(parent, "Cadastrar Mensalista", true);
        setSize(350, 320);
        setLayout(new GridLayout(6, 1, 10, 10)); // 6 linhas para caber tudo
        setLocationRelativeTo(parent);

        // Componentes do Nome
        JPanel painelNome = new JPanel(new FlowLayout(FlowLayout.LEFT));
        painelNome.add(new JLabel("Nome:"));
        txtNome = new JTextField(20);
        painelNome.add(txtNome);
        add(painelNome);

        // Componentes do CPF
        JPanel painelCpf = new JPanel(new FlowLayout(FlowLayout.LEFT));
        painelCpf.add(new JLabel("CPF:"));
        txtCpf = new JTextField(15);
        painelCpf.add(txtCpf);
        add(painelCpf);

        // Componentes do Telefone
        JPanel painelTelefone = new JPanel(new FlowLayout(FlowLayout.LEFT));
        painelTelefone.add(new JLabel("Telefone:"));
        txtTelefone = new JTextField(15);
        painelTelefone.add(txtTelefone);
        add(painelTelefone);

        // Componentes da Vaga
        JPanel painelVaga = new JPanel(new FlowLayout(FlowLayout.LEFT));
        painelVaga.add(new JLabel("Vaga Reservada (Ex: A01):"));
        txtVaga = new JTextField(5);
        painelVaga.add(txtVaga);
        add(painelVaga);

        // Componentes da Mensalidade
        JPanel painelMensalidade = new JPanel(new FlowLayout(FlowLayout.LEFT));
        painelMensalidade.add(new JLabel("Valor Mensalidade (R$):"));
        txtMensalidade = new JTextField(8);
        painelMensalidade.add(txtMensalidade);
        add(painelMensalidade);


        JPanel painelBotao = new JPanel(new FlowLayout(FlowLayout.CENTER));
        btnSalvar = new JButton("Salvar Cadastro");
        painelBotao.add(btnSalvar);
        add(painelBotao);

        btnSalvar.addActionListener(e -> cadastrarMensalista());
    }

    private void cadastrarMensalista() {
        String nome = txtNome.getText().trim();
        String cpf = txtCpf.getText().trim();
        String telefone = txtTelefone.getText().trim();
        String vaga = txtVaga.getText().trim().toUpperCase();
        String mensalidadeTexto = txtMensalidade.getText().trim().replace(",", ".");

        if (nome.isEmpty() || cpf.isEmpty() || telefone.isEmpty() || vaga.isEmpty() || mensalidadeTexto.isEmpty()) {
            JOptionPane.showMessageDialog(this, "Por favor, preencha todos os campos.", "Aviso", JOptionPane.WARNING_MESSAGE);
            return;
        }

        try {
            double mensalidade = Double.parseDouble(mensalidadeTexto);


            Mensalista mensalista = new Mensalista(nome, cpf, telefone, vaga, mensalidade);

            // Requisito C03: Cadastra o mensalista na LinkedList do Gerenciador
            GerenciadorEstacionamento.getInstance().cadastrarMensalista(mensalista);

            JOptionPane.showMessageDialog(this, "Mensalista cadastrado com sucesso!\nVencimento: " + mensalista.getDataVencimento(), "Sucesso", JOptionPane.INFORMATION_MESSAGE);
            dispose();

        } catch (NumberFormatException ex) {
            JOptionPane.showMessageDialog(this, "Por favor, digite um valor numérico válido para a mensalidade.", "Erro de Formato", JOptionPane.ERROR_MESSAGE);
        } catch (Exception ex) {
            JOptionPane.showMessageDialog(this, "Erro ao cadastrar: " + ex.getMessage(), "Erro", JOptionPane.ERROR_MESSAGE);
        }
    }
}