package parksys.services;

import parksys.entities.Mensalista;
import parksys.entities.Registro;
import parksys.entities.Vaga;
import parksys.enums.StatusVaga;

import java.io.*;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.*;

public class GerenciadorArquivo {

    private static final DateTimeFormatter FORMATTER = DateTimeFormatter.ofPattern("dd/MM/yyyy HH:mm:ss");

    // serializa os objetos pelo ObjectOutputStream
    public static void serializar(Map<String, Vaga> vagas, List<Registro> registros, List<Mensalista> mensalistas, String path) {

        ObjectOutputStream oos = null;
        boolean sucesso = false;

        // Serializa o arquivo para .ser
        try {
            DadosParkSys dadosParkSys = new DadosParkSys(vagas, registros, mensalistas);

            FileOutputStream fos = new FileOutputStream(path);
            oos = new ObjectOutputStream(fos);

            oos.writeObject(dadosParkSys);
            sucesso = true;

        } catch (IOException e) {
            System.err.println("[Arquivo] Erro ao serializar: " + e.getMessage());
        } finally {

            if (oos != null) {
                try {
                    oos.close();
                } catch (IOException e) {
                    System.err.println("[Arquivo] Erro ao fechar stream: " + e.getMessage());
                }
            }
            System.out.println("[Arquivo] Serialização " + (sucesso ? "concluída → " + path : "falhou"));
        }
    }

    public static DadosParkSys desserializar(String path) {
        ObjectInputStream ois = null;
        boolean sucesso = false;

        try {
            FileInputStream fis = new FileInputStream(path);
            ois = new ObjectInputStream(fis);
            sucesso = true;
            return (DadosParkSys) ois.readObject();

        } catch (FileNotFoundException e) { // tratamento d FileNotFoundException
            System.out.println("[Arquivo] Nenhum dado salvo encontrado. Iniciando do zero.");
            return new DadosParkSys(new HashMap<>(), new ArrayList<>(), new LinkedList<>());

        } catch (IOException | ClassNotFoundException e) {
            System.err.println("[Arquivo] Erro ao desserializar: " + e.getMessage());
            return new DadosParkSys(new HashMap<>(), new ArrayList<>(), new LinkedList<>());

        } finally {
            if (ois != null) {
                try {
                    ois.close();
                } catch (IOException e) {
                    System.err.println("[Arquivo] Erro ao fechar stream: " + e.getMessage());
                }
            }
            System.out.println("[Arquivo] Desserialização " + (sucesso ? "concluída → " + path : "falhou"));
        }
    }

    // Exporta o relatorio para um txt usando o FileWriter
    public static void exportarRelatorioTxt(List<Registro> registros, Map<String, Vaga> vagas, String path) {

        BufferedWriter writer = null;
        boolean sucesso = false;

        try {
            FileWriter fw = new FileWriter(path);
            writer = new BufferedWriter(fw);

            // Cabeçalho
            escreverLinha(writer, "================================================");
            escreverLinha(writer, "          PARKSYS - RELATÓRIO GERAL             ");
            escreverLinha(writer, "================================================");
            escreverLinha(writer, "Gerado em: " + LocalDateTime.now().format(FORMATTER));
            escreverLinha(writer, "");

            // Status das vagas
            long livres    = contarStatus(vagas, StatusVaga.LIVRE);
            long ocupadas  = contarStatus(vagas, StatusVaga.OCUPADA);
            long reservadas = contarStatus(vagas, StatusVaga.RESERVADA);

            escreverLinha(writer, "--- VAGAS ---");
            escreverLinha(writer, "Livres: " + livres);
            escreverLinha(writer, "Ocupadas: " + ocupadas);
            escreverLinha(writer, "Reservadas: " + reservadas);
            escreverLinha(writer, "");

            // Financeiro
            double totalReceita = registros.stream()
                    .filter(r -> !r.isAtivo())
                    .mapToDouble(Registro::getValorPago)
                    .sum();

            escreverLinha(writer, "--- FINANCEIRO ---");
            escreverLinha(writer, String.format("Receita total: R$ %.2f", totalReceita));
            escreverLinha(writer, "");

            // Registros
            escreverLinha(writer, "--- REGISTROS ---");
            if (registros.isEmpty()) {
                escreverLinha(writer, "(nenhum registro no período)");
            } else {
                for (Registro r : registros) {
                    escreverLinha(writer, r.toString());
                }
            }
            sucesso = true;

        } catch (IOException e) {
            System.err.println("[Arquivo] Erro ao exportar relatório: " + e.getMessage());
        } finally {
            if (writer != null) {
                try { writer.close(); } catch (IOException e) {
                    System.err.println("[Arquivo] Erro ao fechar writer: " + e.getMessage());
                }
            }
            System.out.println("[Arquivo] Exportação para txt " + (sucesso ? "concluída → " + path : "falhou"));
        }
    }

    // usado para escrever no txt
    private static void escreverLinha(BufferedWriter writer, String texto) throws IOException {
        writer.write(texto);
        writer.newLine();
    }

    private static long contarStatus(Map<String, Vaga> vagas, StatusVaga status) {
        return vagas.values().stream()
                .filter(v -> v.getStatus() == status)
                .count();
    }
}
