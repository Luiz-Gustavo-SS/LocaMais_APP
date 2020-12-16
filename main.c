#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include "LocaMais_B.h"

int main()
{
    system("CLS");
    setlocale(LC_ALL,"portuguese");
    int op;
    FILE *CLIENTE, *FUNCIONARIO, *SETCODIGO_F, *SETCODIGO_C, *arquivoLocacao, *SETCODIGOS_L, *ARQUIVO_VEICULO, *CODIGO_V;
    if (( ARQUIVO_VEICULO=fopen("ARQUIVO_VEICULO.dat","r+b"))==NULL)
    {
        printf("Arquivo ainda não existente. Criando ARQUIVO_VEICULO.dat\n");
        if ((ARQUIVO_VEICULO=fopen("ARQUIVO_VEICULO.dat","w+b"))==NULL)
        {
            printf("erro na criação do arquivo:");
            exit(1);
        }
        system("pause");
        system("cls");
    }
    if (( CODIGO_V=fopen("CODIGO_V.dat","r+b"))==NULL)
    {
        printf("Arquivo ainda não existente. Criando CODIGO_V.dat\n");
        if ((CODIGO_V=fopen("CODIGO_V.dat","w+b"))==NULL)
        {
            printf("erro na criação do arquivo:");
            exit(1);
        }
        system("pause");
        system("cls");
    }
    if((arquivoLocacao=fopen("arquivoLocacao.dat","r+b"))==NULL)
    {
        printf("Arquivo ainda não existente. Criando arquivoLocacao.dat\n");
        if((arquivoLocacao=fopen("arquivoLocacao.dat","w+b"))==NULL)
        {
            printf("Erro na criação do arquivo.\n");
            exit(1);
        }
        system("pause");
        system("cls");
    }
    if((SETCODIGOS_L=fopen("SETCODIGOS_L.dat","r+b"))==NULL)
    {
        printf("Arquivo de codigo ainda não existente SETCODIGOS_L.dat\n");
        if((SETCODIGOS_L=fopen("SETCODIGOS_L.dat","w+b"))==NULL)
        {
            printf("Erro na criação do arquivo.\n");
            exit(1);
        }
        system("pause");
        system("cls");
    }
    if ((CLIENTE= fopen("Clientes.dat", "r+b"))==NULL)
    {
        printf("Arquivo não existia ... criando arquivo Clientes.dat\n");
        if((CLIENTE = fopen("Clientes.dat", "w+b"))==NULL)
        {
            printf("Erro na criação do arquivo Clientes.dat\n");
            exit(1);
        }
        system("pause");
        system("cls");
    }
    if ((FUNCIONARIO= fopen("FUNCIONARIO.dat", "r+b"))==NULL)
    {
        printf("Arquivo não existia ... criando arquivo FUNCIONARIO.dat\n");
        if((CLIENTE = fopen("FUNCIONARIO.dat", "w+b"))==NULL)
        {
            printf("Erro na criação do arquivo FUNCIONARIO.dat\n");
            exit(1);
        }
        system("pause");
        system("cls");
    }
    if ((SETCODIGO_C= fopen("SETCODIGO_C.dat", "r+b"))==NULL)
    {
        printf("Arquivo não existia ... criando arquivo SETCODIGO_C.dat\n");
        if((SETCODIGO_C = fopen("SETCODIGO_C.dat", "w+b"))==NULL)
        {
            printf("Erro na criação do arquivo SETCODIGO_C.dat\n");
            exit(1);
        }
        system("pause");
        system("cls");
    }
    if ((SETCODIGO_F= fopen("SETCODIGO_F.dat", "r+b"))==NULL)
    {
        printf("Arquivo não existia ... criando arquivo SETCODIGO_F.dat\n");
        if((SETCODIGO_F = fopen("SETCODIGO_F.dat", "w+b"))==NULL)
        {
            printf("Erro na criação do arquivo SETCODIGO_F.dat\n");
            exit(1);
        }
        system("pause");
        system("cls");
    }
    do
    {
        printf ("====================================\n");
        printf ("| a -    Adcionar Cliente          |\n");
        printf ("| b -    Imprimir Cliente          |\n");
        printf ("| c -    Adcionar Funcionario      |\n");
        printf ("| d -    Imprimir Funcionario      |\n");
        printf ("| e -    Pesquisar pessoa          |\n");
        printf ("| f -    Gerar Código de Locação   |\n");
        printf ("| g -    Listar locações           |\n");
        printf ("| h -    Dar Baixa em Locação      |\n");
        printf ("| i -    Adcionar Carro            |\n");
        printf ("| j -    Imprimir Carro            |\n");
        printf ("| k -    Lista de Fidelidade       |\n");
        printf ("====================================");
        printf ("\n|      DIGITE x  PARA SAIR         |\n");
        printf ("====================================\n");
        op=getch();
        switch (op)
        {
        case 'a':
            adcionar_cliente(CLIENTE,SETCODIGO_C);
            break;
        case 'b':
            listar_cliente(CLIENTE);
            break;
        case 'c':
            adcionar_funcionario(FUNCIONARIO,SETCODIGO_F);
            break;
        case 'd':
            listar_funcionarios(FUNCIONARIO);
            break;
        case 'e':
            pesquisa(FUNCIONARIO,CLIENTE);
            break;
        case 'f':
            gerandoLocacao(arquivoLocacao, SETCODIGOS_L, CLIENTE);
            break;
        case 'g':
            listarLocacao(arquivoLocacao);
            break;
        case 'h':
            baixarLocacao(arquivoLocacao,SETCODIGOS_L,CLIENTE);
            break;
        case 'i':
            incluirDadosVeiculo(ARQUIVO_VEICULO,CODIGO_V);
            break;
        case 'j':
            listar_carro(ARQUIVO_VEICULO);
            break;
        case 'k':
            pontosFidelidade(CLIENTE);
        }
    }
    while(op!='x');
    fclose(CLIENTE);
    fclose(FUNCIONARIO);
    fclose(SETCODIGO_C);
    fclose(SETCODIGO_F);
    fclose(arquivoLocacao);
    fclose(SETCODIGOS_L);
    fclose(ARQUIVO_VEICULO);
    fclose(CODIGO_V);
    system("CLS");
    printf("Até a proxima\n");
    return 0;
}
//FIM INT MAIN
