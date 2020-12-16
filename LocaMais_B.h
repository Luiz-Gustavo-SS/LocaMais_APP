#ifndef LOCAMAIS_B_H_INCLUDED
#define LOCAMAIS_B_H_INCLUDED
//INICIO STRUCT CODIGOL
struct veiculoStruct
{
    int codigo_do_veiculo,quantidade_de_ocupante,status;
    char descricao[100],modelo[100],cor[100],placa[100],disponibilidade[100];
    float valor_diario;
};
typedef struct veiculoStruct veiculo;
//INICIO STRUCT CODIGOL

//========================================

//INICIO STRUCT CODIGOL
struct codigoL
{
    int cod;
};
typedef struct codigoL codigo;
//FIM STRUCT CODIGOL

//========================================

//INICIO STRUCT CADASTRO LOCAÇÃO
struct cadastroLocacao
{
    char seguro, nomeCliente[50];
    int quantOcupantes, codigoLocacao, status, diarias;
    int diaRetirada, mesRetirada, anoRetirada;
    int diaDevolucao, mesDevolucao, anoDevolucao;
};
typedef struct cadastroLocacao cadLocacao;
//FIM STRUCT CADASTRO LOCAÇÃO

//========================================

//INICIO STRUCT CODIGO PESSOA
struct Codigo_pessoa
{
    int codigo_cliente;
    int codigo_funcionario;
    //int codigo_carro;
};
typedef struct Codigo_pessoa codigos;
//FIM STRUCT CODIGO PESSOA

//========================================

//INICIO STRUCT CLIENTES
struct Clientes
{
    int codigo;
        int fidelidade;
    char nome[50];
    char endereco[150];
    char telefone[50];
    int avaliacaoatendimento,avaliacaocarro,recomendado;
    char avaliacao_atendimento[140],avaliacao_carro[140],recomendar[140];
    int numero_de_locacoes;
};
typedef struct Clientes cliente;
//FIM STRUCT CLIENTES

//========================================

//INICIO STRUCT FUNCIONAIROS
struct Funcionarios
{
    int codigo;
    float salario;
    char nome[50];
    char cargo[50];
    char telefone[50];
};
typedef struct Funcionarios funcionario;
//FIM STRUCT FUNCIONAIROS

//========================================

//INICIO HEADERS

int main();

//========================================

//INICIO GERADOR DE CODIGOS

int gera_codigo_clientes (FILE *SETCODIGO_C);
int gera_codigo_funcionario (FILE *SETCODIGO_F);
int gerarCodigoLoc(FILE *SETCODIGOS_L);
int gerarCodigoLoc_veiculo(FILE *banco_codigo);
//FIM GERADOR DE CODIGOS

//========================================

//INICIO LOCALIZADOR DE DADOS

int localiza_dado_cliente(FILE *CLIENTE,int codigo);
int localiza_dados_funcionarios(FILE *FUNCIONARIO,int codigo);
int localizaLocacao(FILE *arquivoLocacao, int);
int localiza_modelo(FILE *banco_loca,char modelo[100]);

//FIM LOCALIZADOR DE DADOS

//========================================

//INICIO METODOS
void pontosFidelidade(FILE *CLIENTE);
void adcionar_cliente(FILE *Clientes,FILE *SETCODIGO_C);
void adcionar_funcionario(FILE *FUNCIONARIO,FILE *SETCODIGO_F);
void listar_cliente(FILE *CLIENTE);
void listar_funcionarios(FILE *FUNCIONARIO);
void gerandoLocacao(FILE *arquivoLocacao, FILE *SETCODIGOS_L,FILE *CLIENTE);
void listarLocacao(FILE *arquivoLocacao);
void baixarLocacao(FILE *arquivoLocacao,FILE *CLIENTE,FILE *SETCODIGO_C);
void incluirDadosVeiculo(FILE *banco_loca,FILE *banco_codigo);
void listar_carro(FILE *banco_loca);
void avaliar(FILE *CLIENTE,FILE *SETCODIGO_C);
//FIM METODOS

//========================================

//INCIO PESQUISA
int localiza_locacao(FILE *arquivoLocacao,char nome[50]);
int localiza_cliente(FILE *Clientes,char nome[50]);
int localiza_funcionario(FILE *FUNCIONARIO,char nome[50]);
void pesquisa(FILE *FUNCIONARIO,FILE *CLIENTE);
void pesquisar_cliente(FILE *CLIENTE);
void pesquisar_funcionario(FILE *FUNCIONARIO);
char *remove_espacos_clientes( char  *out,  char  *in );
char *remove_espacos_funcionario( char  *out,  char  *in );
char *remove_espacos_locacao( char  *out,  char  *in );
void pontosFidelidade(FILE *CLIENTE);

//FIM PESQUISA

//FIM HEADERS
//========================================
#endif // LOCAMAIS_B_H_INCLUDED
