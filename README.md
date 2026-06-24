

PARKSYS — SISTEMA DE GESTÃO DE ESTACIONAMENTO

Projeto acadêmico desenvolvido para a disciplina de Desenvolvimento Orientado a Objetos do curso de Tecnologia em Sistemas Para Internet — IFSP Câmpus Araraquara.

**DESCRIÇÃO**

O ParkSys é um sistema de gerenciamento de estacionamento que simula o controle de entrada e saída de veículos, gestão de vagas, cadastro de mensalistas e geração de relatórios financeiros. O sistema foi desenvolvido com foco na aplicação de conceitos fundamentais de POO, padrões de projeto, concorrência e persistência de dados.

**FUNCIONALIDADE**

•Registro de entrada e saída de veículos com cálculo automático de tarifa

•Suporte a múltiplos tipos de veículos (moto, carro, SUV e caminhão)

•Alocação de vagas consecutivas para veículos de maior porte

•Cadastro e gerenciamento de mensalistas com controle de vencimento

•Monitoramento em tempo real do status das vagas via thread dedicada

•Painel de notificações com padrão Observer

•Persistência de dados via serialização binária (.ser)

•Exportação de relatório financeiro em arquivo .txt

•Validação de placas nos formatos antigo (ABC-1234) e Mercosul (ABC1D23)

•Interface gráfica Swing (TelaInicial)

**ARQUITETURA E PADRÕES DE PROJETO**

Padrão Singleton

GerenciadorEstacionamento é instanciado uma única vez via getInstance() com construtor privado, garantindo ponto de acesso global e consistência dos dados em ambiente multithreaded.

Padrão Observer

A interface EstacionamentoObserver define o contrato de notificação. O GerenciadorEstacionamento mantém uma lista de observadores e notifica todos sempre que o status de uma vaga é alterado. O PainelMonitor implementa essa interface e atualiza seu mapa local de status em tempo real.

Arquitetura MVC

A UI (TelaInicial) não acessa as coleções internas diretamente — toda interação passa pelo GerenciadorEstacionamento, respeitando a separação de responsabilidades.

**CONCORRENCIA**

O sistema utiliza múltiplas threads para simular o funcionamento paralelo das cancelas de entrada:

•Threads de entrada (EntradaRunnable): cada cancela é representada por uma thread (Entrada-1 a Entrada-4). Simulam o processamento real de leitura de placa, abertura da cancela e impressão de ticket.

•Thread monitor (MonitorRunnable): thread daemon que imprime o status das vagas a cada segundo. Encerrada via interrupt() após o fim das entradas.

•Sincronização: os métodos críticos de GerenciadorEstacionamento (registrarEntrada, registrarSaida, cadastrarMensalista, etc.) são declarados como synchronized para evitar condições de corrida.

Join: a thread main aguarda todas as threads de entrada finalizarem antes de exibir o relatório final, evitando race conditions na leitura dos dados.

**ESTRUTURA DE PACOTES**

parksys/

├── entities/

│   ├── Veiculo.java          # Entidade veículo com validação de placa

│   ├── Vaga.java             # Entidade vaga com controle de estado

│   ├── Registro.java         # Registro de entrada/saída (implementa Comparable)

│   ├── Mensalista.java       # Mensalista com controle de vencimento mensal

│

├── enums/

│   ├── TipoVeiculo.java      # MOTO, CARRO, SUV, CAMINHAO (tarifa e vagas por tipo)

│   ├── StatusVaga.java       # LIVRE, OCUPADA, RESERVADA

│

├── exceptions/

│   ├── PlacaInvalidaException.java

│   ├── VagaOcupadaException.java

│   └── VeiculoNaoEncontradoException.java

│

├── observer/

│   ├── EstacionamentoObserver.java   # Interface Observer

│   └── PainelMonitor.java            # Implementação concreta do Observer

│

├── services/

│   ├── GerenciadorEstacionamento.java  # Singleton; lógica central do sistema

│   ├── GerenciadorArquivo.java         # Serialização, desserialização e export .txt

│   ├── DadosParkSys.java               # DTO para persistência

│   ├── EntradaRunnable.java            # Runnable para threads de entrada

│   └── MonitorRunnable.java            # Runnable para thread monitora

│

├── ui/

│   ├── TelaInicial.java              # Janela principal com menu de navegação

│   ├── TelaRegistroEntrada.java      # Formulário de entrada de veículo

│   ├── TelaSaida.java                # Formulário de saída e cobrança

│   ├── TelaCadastroMensalista.java   # Cadastro de mensalistas

│   └── TelaRelatorio.java            # Relatório financeiro e de vagas

│

└── main/

└── Principal.java        # Ponto de entrada da aplicação

Interface Gráfica (Swing)

A UI é construída com Java Swing e segue o padrão de janelas modais (JDialog) abertas a partir da janela principal (JFrame).

Tela                    Classe                      Descrição       

Tela Principal          TelaInicial              Menu central com fundo customizado e botões estilizados. Registra o PainelMonitor como observador ao abrir e o remove ao fechar.

Registrar Entrada       TelaRegistroEntrada      Formulário com campos de placa, tipo de veículo (JComboBox), proprietário e vaga inicial. Valida os campos antes de chamar o gerenciador.

Registrar Saída         TelaSaida                Busca o veículo pela placa, calcula o valor e exibe o total cobrado ao operador.

Cadastrar Mensalista    TelaCadastroMensalista   Formulário completo com nome, CPF, telefone, vaga reservada e valor da mensalidade. Exibe a data de vencimento após o cadastro.

Relatório               TelaRelatorio            Exibe em área de texto monospaced: status das vagas, receita total e registros ordenados por valor pago (decrescente).

A TelaInicial usa WindowAdapter para garantir que o PainelMonitor seja removido da lista de observadores quando a janela é fechada, evitando vazamento de referências.

Tabela de Tarifas

Tipo de Veículo     Tarifa/hora     Vagas ocupadas      

Motocicleta         R$ 5,00             1

Automóvel           R$ 10,00            1

Caminhonete         R$ 18,00            2

Caminhão            R$ 30,00            3

O tempo mínimo cobrado é de 1 hora. O cálculo é feito automaticamente na saída com base no tipo do veículo (TipoVeiculo.getTarifaHora()).

**PERSISTÊNCIA**

Os dados são persistidos automaticamente via serialização Java (ObjectOutputStream / ObjectInputStream) no arquivo parksys.ser. Ao iniciar, o sistema desserializa o estado anterior; ao encerrar, serializa o estado atual.

O campo threadOrigem de Registro é marcado como transient — não é serializado, pois representa contexto de execução e não dado de negócio.

Além disso, é gerado um relatório em texto simples (relatorio.txt) contendo o status das vagas, receita total e todos os registros do período.

**COLEÇÕES UTILIZADAS**

Coleção       Uso  

HashMap       Mapa de vagas por ID (vagas)

ArrayList     Lista de registros de entrada/saída (registros)

LinkedList    Fila de mensalistas — remoção eficiente O(1) via iterator

TreeSet       Registros ordenados cronologicamente (usa Comparable<Registro>)

EnumMap       Contagem de vagas por status (contarVagasPorStatus)

**COMO EXECUTAR**

Pré-requisitos: Java 11 ou superior.

bash

# Compilar

javac -d out -sourcepath src src/parksys/main/Principal.java

# Executar

java -cp out parksys.main.Principal

Ou importe o projeto em uma IDE (IntelliJ IDEA, Eclipse) e execute a classe Principal.

**AUTORES**

Desenvolvido por estudantes do curso Tecnologia em Sistemas Para Internet — IFSP Câmpus Araraquara.

•Laura Marinho Mendes

•Gustavo Siciliano Belinelli

•Julie Hervias Mendes Leal

Disciplina: Desenvolvimento Orientado a Objetos
