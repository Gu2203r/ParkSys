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

        // Serializa o arquivo para .ser
        try {
            DadosParkSys dadosParkSys = new DadosParkSys(vagas, registros, mensalistas);

            FileOutputStream fos = new FileOutputStream(path);
            oos = new ObjectOutputStream(fos);

            oos.writeObject(dadosParkSys);

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
        }
    }

    public static DadosParkSys desserializar(String path) {
        ObjectInputStream ois = null;
        try {
            FileInputStream fis = new FileInputStream(path);
            ois = new ObjectInputStream(fis);
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
        }
    }
}
