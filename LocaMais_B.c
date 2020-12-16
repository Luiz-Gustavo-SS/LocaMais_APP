#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include "LocaMais_B.h"

//CODIGOS SOBRE CLIENTES INICIO
int gera_codigo_clientes (FILE *SETCODIGO_C)
{
    codigos codigo;
    int c;
    fseek(SETCODIGO_C,0,SEEK_SET);
    fread(&codigo, sizeof(codigo),1, SETCODIGO_C);
    if(!feof(SETCODIGO_C))
    {
        codigo.codigo_cliente=codigo.codigo_cliente+1;
    }
    else
    {
        codigo.codigo_cliente=1;
        codigo.codigo_funcionario=1;
    }
    fseek(SETCODIGO_C,0,SEEK_SET);
    fwrite(&codigo, sizeof(codigo),1,SETCODIGO_C);
    fflush(SETCODIGO_C);
    c=codigo.codigo_cliente;
    return c;
}
int localiza_dado(FILE *CLIENTE,int codigo)
{
    cliente c;
    int posicao=-1,achou=0;
    fseek(CLIENTE,0,SEEK_SET);
    fread(&c, sizeof(c),1, CLIENTE);
    while (!feof(CLIENTE) && !achou)
    {
        posicao++;
        if (c.codigo==codigo)
        {
            achou=1;
        }
        fread(&c, sizeof(c),1, CLIENTE);
    }
    if (achou==1)
    {
        return posicao;
    }
    else
    {
        return -1;
    }
}
void adcionar_cliente(FILE *CLIENTE,FILE *SETCODIGO_C)
{
    cliente c;
    int posicao;
    c.codigo=gera_codigo_clientes(SETCODIGO_C);
    posicao=localiza_dado(CLIENTE,c.codigo);
    if (posicao==-1)
    {
        printf("Digite o nome do Cliente\n");
        fflush(stdin);
        gets(c.nome);
        printf("Digite o endereço\n");
        fflush(stdin);
        gets(c.endereco);
        printf("Digite o telefone\n");
        fflush(stdin);
        gets(c.telefone);
        fseek(CLIENTE,0,SEEK_END); // posicionado o arquivo no final
        fwrite(&c, sizeof(c),1,CLIENTE); //gravando os dados
        fflush(CLIENTE);
    }
    else
    {
        printf("Código já existe no arquivo. Inclusão não realizada!\n");
    }
    printf("\n_______________________________________\n");
    system("PAUSE");
    system("CLS");

}
void listar_cliente(FILE *CLIENTE)
{
    cliente c;
    fseek(CLIENTE,0,SEEK_SET);
    fread(&c, sizeof(c),1, CLIENTE);
    printf("Imprimindo clinetes\n");
    while (!feof(CLIENTE))
    {
        printf("\nNome:%s \n",c.nome);
        printf("Codigo:%d \n",c.codigo);
        printf("Telefone:%s \n",c.telefone);
        printf("Endereço:%s \n",c.endereco);
        printf("Pontos de Fidelidade:%d\n",c.fidelidade);
        printf("Numero de locações:%d\n",c.numero_de_locacoes);
        printf("Avaliações atendimento 0 a 5:%d\n",c.avaliacaoatendimento);
        printf("Avaliações atendimento breve texto:%s\n",c.avaliacao_atendimento);
        printf("Avaliações veiculo:%d\n",c.avaliacaocarro);
        printf("Avaliações veiculo:%s\n",c.avaliacao_carro);
        printf("Avaliações recomendação:%d\n",c.recomendado);
        printf("Avaliações recomendação:%s\n",c.recomendar);
        fread(&c, sizeof(c),1, CLIENTE);
    }
    printf("\n_______________________________________\n");
    system("PAUSE");
    system("CLS");

}
//CODIGOS SOBRE CLIENTES FIM

//======================================================================//
//CODIGOS SOBRE FUNCIONARIOS INCIO
int gera_codigo_funcionario (FILE *SETCODIGO_F)
{
    codigos codigs;
    int f;
    fseek(SETCODIGO_F,0,SEEK_SET);
    fread(&codigs, sizeof(codigs),1, SETCODIGO_F);
    if(!feof(SETCODIGO_F))
    {
        codigs.codigo_funcionario=codigs.codigo_funcionario+1;
    }
    else
    {
        codigs.codigo_cliente=1;
        codigs.codigo_funcionario=1;
    }
    fseek(SETCODIGO_F,0,SEEK_SET);
    fwrite(&codigs, sizeof(codigs),1,SETCODIGO_F);
    fflush(SETCODIGO_F);
    f=codigs.codigo_funcionario;
    return f;
}
int localiza_dados_funcionarios(FILE *FUNCIONARIO,int codigo)
{
    funcionario f;
    int posicao=-1,achou=0;
    fseek(FUNCIONARIO,0,SEEK_SET);
    fread(&f, sizeof(f),1, FUNCIONARIO);
    while (!feof(FUNCIONARIO) && !achou)
    {
        posicao++;
        if (f.codigo==codigo)
        {
            achou=1;
        }
        fread(&f, sizeof(f),1, FUNCIONARIO);
    }
    if (achou==1)
    {
        return posicao;
    }
    else
    {
        return -1;
    }
}
void adcionar_funcionario(FILE *FUNCIONARIO,FILE *SETCODIGO_F)
{
    funcionario f;
    int posicao;
    f.codigo=gera_codigo_funcionario(SETCODIGO_F);
    posicao=localiza_dados_funcionarios(FUNCIONARIO,f.codigo);
    if (posicao==(-1))
    {
        printf("Digite o nome do funcionario\n");
        fflush(stdin);
        gets(f.nome);
        printf("Digite o cargo\n");
        fflush(stdin);
        gets(f.cargo);
        printf("Digite o telefone\n");
        fflush(stdin);
        gets(f.telefone);
        printf("Digite o salario\n");
        scanf("%f",&f.salario);
        fseek(FUNCIONARIO,0,SEEK_END);
        fwrite(&f, sizeof(f),1,FUNCIONARIO);
        fflush(FUNCIONARIO);
    }
    else
    {
        printf("Código já existe no arquivo. Inclusão não realizada!\n");
    }
    printf("\n_______________________________________\n");
    system("PAUSE");
    system("CLS");

}
void listar_funcionarios(FILE *FUNCIONARIO)
{
    funcionario f;
    fseek(FUNCIONARIO,0,SEEK_SET);
    fread(&f, sizeof(f),1, FUNCIONARIO);
    printf("Imprimindo Funcionrios\n\n");
    while (!feof(FUNCIONARIO))
    {
        printf("\nNome:%s \n",f.nome);
        printf("Codigo:%d \n",f.codigo);
        printf("Telefone:%s \n",f.telefone);
        printf("Cargo:%s \n",f.cargo);
        printf("Salario:%.2f\n",f.salario);
        fread(&f, sizeof(f),1,FUNCIONARIO);
    }
    printf("\n_______________________________________\n");
    system("PAUSE");
    system("CLS");
}
//CODIGOS SOBRE FUNCIONARIOS FIM

//======================================================================//

void pesquisa(FILE *FUNCIONARIO,FILE *CLIENTE)
{
    system("CLS");
    int op;
    printf ("=================================\n");
    printf ("| 01 -    Pesquisar Cliente      |\n");
    printf ("| 02 -    Pesquisar Funcionario  |\n");
    printf ("| 03 -    Voltar                 |\n");
    printf ("=================================\n");
    op=getch();
    switch (op)
    {
    case '1':
        pesquisar_cliente(CLIENTE);
        break;
    case '2':
        pesquisar_funcionario(FUNCIONARIO);
        break;
    case '3':
        break;
    }
    system("CLS");
}

//CODIGO PESQUISA CLIENTE INICIO
void pesquisar_cliente(FILE *CLIENTE)
{
    char nome[50];
    int i;
    printf("Digite o nome a pesquisar...\n");
    gets(nome);
    fflush(stdin);
    i=localiza_cliente(CLIENTE,nome);
    if (i!=-1)
    {
        printf("Nome pesquisado com sucesso\n");
    }
    else
    {
        printf("Nome não encontrado!\n");
    }
    printf("\n_______________________________________\n");
    system("PAUSE");
    system("CLS");
}
int localiza_cliente(FILE *CLIENTE,char nome[50])
{
    cliente c;
    char aux[50],aux2[50];
    fseek(CLIENTE,0,SEEK_SET);
    fread(&c, sizeof(c),1, CLIENTE);
    int posicao=-1,achou=0;
    while (!feof(CLIENTE) && !achou)
    {
        posicao++;
        remove_espacos_clientes(aux,nome);
        remove_espacos_clientes(aux2,c.nome);
        if (strcasecmp(aux,aux2)==0)
        {
            printf("\nNome:%s \n",c.nome);
            printf("Codigo:%d \n",c.codigo);
            printf("Telefone:%s \n",c.telefone);
            printf("Endereço:%s \n",c.endereco);
            achou=1;
        }
        fread(&c, sizeof(c),1, CLIENTE);
    }
    if (achou)
    {
        return posicao;
    }
    else
    {
        return -1;
    }
}
int localiza_locacao(FILE *arquivoLocacao,char nome[50])
{
    cadLocacao cl;
    char aux[50],aux2[50];
    fseek(arquivoLocacao,0,SEEK_SET);
    fread(&cl, sizeof(cl),1, arquivoLocacao);
    while (!feof(arquivoLocacao))
    {
        remove_espacos_locacao(aux,nome);
        remove_espacos_locacao(aux2,cl.nomeCliente);
        if (strcasecmp(aux,aux2)==0)
        {
            printf("Nome do cliente:%s\n",cl.nomeCliente);
            printf("Seguro: %c\n",cl.seguro);
            printf("Diárias: %d\n",cl.diarias);
            printf("Data retirada: %d/%d/%d \n",cl.diaRetirada,cl.mesRetirada,cl.anoRetirada);
            printf("Data devolução: %d/%d/%d \n",cl.diaDevolucao,cl.mesDevolucao,cl.anoDevolucao);
            printf("Número de Ocupantes: %d\n",cl.quantOcupantes);
        }
        fread(&cl, sizeof(cl),1, arquivoLocacao);
        fseek(arquivoLocacao,0,SEEK_SET);
    }
    return 0;
}

char *remove_espacos_clientes( char  *out,  char  *in )
{
    char  *p = in;
    int i = 0;
    while( *p )
    {
        if( !isspace(*p) )
            out[i++] = *p;
        p++;
    }
    out[i] = 0;
    return out;
}

char *remove_espacos_locacao( char  *out,  char  *in )
{
    char  *p = in;
    int i = 0;
    while( *p )
    {
        if( !isspace(*p) )
            out[i++] = *p;
        p++;
    }
    out[i] = 0;
    return out;
}


//CODIGO PESQUISA CLIENTE FIM

//CODIGO PESQUISA FUNCIONARIO INICIO
void pesquisar_funcionario(FILE *FUNCIONARIO)
{
    char nome[50];
    int i;
    printf("Digite o nome a pesquisar...\n");
    gets(nome);
    fflush(stdin);
    i=localiza_funcionario(FUNCIONARIO,nome);
    if (i!=-1)
    {
        printf("Nome pesquisado com sucesso\n");
    }
    else
    {
        printf("Nome não encontrado!\n");
    }
    printf("\n_______________________________________\n");
    system("PAUSE");
    system("CLS");
}
int localiza_funcionario(FILE *FUNCIONARIO,char nome[50])
{
    funcionario f;
    char aux[50],aux2[50];
    fseek(FUNCIONARIO,0,SEEK_SET);
    fread(&f, sizeof(f),1,FUNCIONARIO);
    int posicao=-1,achou=0;
    while (!feof(FUNCIONARIO) && !achou)
    {
        posicao++;
        remove_espacos_funcionario(aux,nome);
        remove_espacos_funcionario(aux2,f.nome);
        if (strcasecmp(aux,aux2)==0)
        {
            printf("\nNome:%s \n",f.nome);
            printf("Codigo:%d \n",f.codigo);
            printf("Telefone:%s \n",f.telefone);
            printf("Cargo:%s \n",f.cargo);
            printf("Salario:%.2f\n",f.salario);
            achou=1;
        }
        fread(&f, sizeof(f),1,FUNCIONARIO);
    }
    if (achou)
    {
        return posicao;
    }
    else
    {
        return -1;
    }
}
char *remove_espacos_funcionario( char  *out,  char  *in )
{
    char  *p = in;
    int i = 0;
    while( *p )
    {
        if( !isspace(*p) )
            out[i++] = *p;
        p++;
    }
    out[i] = 0;
    return out;
}
//CODIGO PESQUISA FUNCIONARIO FI

//Início - Função de Locação

void gerandoLocacao(FILE *arquivoLocacao, FILE *SETCODIGOS_L,FILE *CLIENTE)
{
    cadLocacao cadLoc;
    cliente c;
    int anos, dias, meses, i;
    char nome[50];
    system("CLS");

    if(!feof(arquivoLocacao))
    {

        printf("Digite o nome a pesquisar\n");
        fflush(stdin);
        gets(nome);
        i=localiza_cliente(CLIENTE,nome);
        while(i==-1)
        {
            printf("Nome não encontrado\n");
            printf("Insira o nome novamente: ");
            fflush(stdin);
            gets(nome);
            i=localiza_cliente(CLIENTE,nome);
        }
        strcpy(cadLoc.nomeCliente,nome);

        printf("Modelo: DD/MM/AAAA(ex.:11/08/2020)\n\n");
        printf("---DATA DE RETIRADA---\n");
        fflush(stdin);
        scanf("%d/%d/%d",&cadLoc.diaRetirada,&cadLoc.mesRetirada,&cadLoc.anoRetirada);
        printf("\n---DATA DE DEVOLUÇÃO---\n\n");
        fflush(stdin);
        scanf("%d/%d/%d",&cadLoc.diaDevolucao,&cadLoc.mesDevolucao,&cadLoc.anoDevolucao);
        while(cadLoc.anoDevolucao<cadLoc.anoRetirada)
        {
            system("CLS");
            printf("Dados inválidos, insira novamente.\n");
            printf("Modelo: DD/MM/AAAA(ex.:11/08/2020)\n\n");
            printf("---DATA DE RETIRADA---\n");
            fflush(stdin);
            scanf("%d/%d/%d",&cadLoc.diaRetirada,&cadLoc.mesRetirada,&cadLoc.anoRetirada);
            printf("\n---DATA DE DEVOLUÇÃO---\n\n");
            fflush(stdin);
            scanf("%d/%d/%d",&cadLoc.diaDevolucao,&cadLoc.mesDevolucao,&cadLoc.anoDevolucao);
        }
        anos=cadLoc.anoDevolucao-cadLoc.anoRetirada;
        meses=cadLoc.mesDevolucao-cadLoc.mesRetirada;
        dias=cadLoc.diaDevolucao-cadLoc.diaRetirada;
        while(anos>0)
        {
            anos--;
            meses+=12;
        }
        while(meses>0)
        {
            meses--;
            dias+=30;
        }
        cadLoc.status=0;
        cadLoc.diarias=dias+1;
        printf("\n---DADOS GERAIS---\n");
        cadLoc.codigoLocacao=gerarCodigoLoc(SETCODIGOS_L);
        printf("Quantos ocupantes terão no carro?\n");
        fflush(stdin);
        scanf("%d",&cadLoc.quantOcupantes);
        printf("Gostaria de seguro?(s/n)");
        //permitir o cliente escolher qual carro deseja
        //setar status do carro para indisponível
        fflush(stdin);
        scanf("%c",&cadLoc.seguro);
        printf("Diarias: %d\n",cadLoc.diarias);
        c.fidelidade+=10*cadLoc.diarias;
        fflush(stdin);
        printf("Pontos de fidelidades ganhos: %d\n",c.fidelidade);
        printf("Código de locação: %d\n",cadLoc.codigoLocacao);
    }
    fseek(CLIENTE,(sizeof(c)*i),SEEK_SET);
    fwrite(&c,sizeof(c),1,CLIENTE);
    fflush(CLIENTE);
    fseek(arquivoLocacao,0,SEEK_END);
    fwrite(&cadLoc,sizeof(cadLoc),1,arquivoLocacao);
    fflush(arquivoLocacao);
    printf("\n______________________________________\n");
    system("PAUSE");
    system("CLS");
}
//Fim - Função de Locação
//GERANDO CÓDIGO - INÍCIO

int gerarCodigoLoc(FILE* SETCODIGOS_L)
{
    int n;
    codigo cl;
    fseek(SETCODIGOS_L,0,SEEK_SET);
    fread(&cl,sizeof(cl),1,SETCODIGOS_L);
    fflush(SETCODIGOS_L);
    if(!feof(SETCODIGOS_L))
    {
        cl.cod=cl.cod+1;
    }
    else
    {
        cl.cod=1;
    }
    fseek(SETCODIGOS_L,0,SEEK_SET);
    fwrite(&cl,sizeof(cl),1,SETCODIGOS_L);
    fflush(SETCODIGOS_L);
    n=cl.cod;
    return n;
}

//GERANDO CÓDIGO - FIM

//LISTAR LOCAÇÕES - INÍCIO

void listarLocacao(FILE *arquivoLocacao)
{
    int op;
    char nome[50];
    cadLocacao cl;
    system("CLS");
    printf ("====================================\n");
    printf ("| 01 -    Imprimir todas        |\n");
    printf ("| 02 -    Imprimir por nome     |\n");
    printf ("====================================\n");
    scanf("%d",&op);
    if(op==1)
    {
        fseek(arquivoLocacao,0,SEEK_SET);
        fread(&cl, sizeof(cl),1, arquivoLocacao);
        printf("Imprimindo locação\n");
        while (!feof(arquivoLocacao))
        {
            printf("\nCodigo: %d\n",cl.codigoLocacao);
            if(cl.status==0)
            {
                printf("Status: Em execução\n");
            }
            else
            {
                if(cl.status==1)
                {
                    printf("Status: Locação finalizada\n");
                }
            }
            printf("Nome do cliente:%s\n",cl.nomeCliente);
            printf("Seguro: %c\n",cl.seguro);
            printf("Diárias: %d\n",cl.diarias);
            printf("Data retirada: %d/%d/%d \n",cl.diaRetirada,cl.mesRetirada,cl.anoRetirada);
            printf("Data devolução: %d/%d/%d \n",cl.diaDevolucao,cl.mesDevolucao,cl.anoDevolucao);
            printf("Número de Ocupantes: %d\n",cl.quantOcupantes);
            fread(&cl, sizeof(cl),1, arquivoLocacao);
            printf("\n______________________________________\n");
            system("PAUSE");
            system("CLS");
        }
        fseek(arquivoLocacao,0,SEEK_END);
    }
    if(op==2)
    {
        printf("Digite o nome a pesquisar");
        fflush(stdin);
        gets(nome);
        localiza_locacao(arquivoLocacao,nome);


        printf("\n______________________________________\n");
        system("PAUSE");
        system("CLS");
    }


}

//LISTAR LOCAÇÕES - FIM

int localizaDado(FILE *arquivoLocacao, int codigo)
{
    int posicao=-1, achou=0;
    cadLocacao cl;
    fseek(arquivoLocacao,0,SEEK_SET);
    fread(&cl, sizeof(cl),1, arquivoLocacao);
    while((!feof(arquivoLocacao)) && (achou==0))
    {
        posicao++;
        if (cl.codigoLocacao==codigo)
        {
            achou=1;
        }
        fread(&cl, sizeof(cl),1, arquivoLocacao);
    }
    if (achou==1)
    {
        return posicao;
    }
    else
    {
        return -1;
    }
}

//LOCALIZAR - FIM

//DAR BAIXA - INÍCIO

void baixarLocacao(FILE *arquivoLocacao,FILE *CLIENTE,FILE *SETCODIGO_C)
{
    cliente c;
    char nome[50];
    int op,i;
    float custo=0;
    int nCodigo, posicao;
    int diaAtual, mesAtual, anoAtual;
    int compDia,compMes,compAno;
    int diasExtras;
    cadLocacao cl;
    system("CLS");
    fseek(CLIENTE,0,SEEK_SET);
    fread(&c, sizeof(c),1, CLIENTE);
    printf("Insira o nome do cliente\n");
    fflush(stdin);
    gets(nome);
    i=localiza_cliente(CLIENTE,nome);
    strcpy(cl.nomeCliente,c.nome);
    if(i!=-1)
    {
        c.numero_de_locacoes=c.numero_de_locacoes+1;
        printf("Insira o código da locação que gostaria de dar baixa: ");
        scanf("%d",&nCodigo);
        posicao=localizaDado(arquivoLocacao, nCodigo);
        while(posicao==-1)
        {
            printf("Código inexistente. Insira novamente:");
            scanf("%d",&nCodigo);
            posicao=localizaDado(arquivoLocacao, nCodigo);
            printf("Posicao: %d",posicao);
        }
        fseek(arquivoLocacao,(sizeof(cl)*(posicao)),SEEK_SET);
        fread(&cl,sizeof(cl),1,arquivoLocacao);
        cl.status=1;
        custo=5*cl.diarias;
        printf("Insira a data atual(DD/MM/AAAA): ");
        scanf("%d/%d/%d",&diaAtual,&mesAtual,&anoAtual);
        printf("\n\n---DADOS DA LOCAÇÃO---\n");
        printf("Nome do cliente:%s \n",c.nome);
        printf("Seguro: %c\n",cl.seguro);
        printf("Diárias: %d\n",cl.diarias);
        printf("Data retirada: %d/%d/%d \n",cl.diaRetirada,cl.mesRetirada,cl.anoRetirada);
        printf("Data devolução prevista: %d/%d/%d \n",cl.diaDevolucao,cl.mesDevolucao,cl.anoDevolucao);
        printf("Número de Ocupantes: %d\n",cl.quantOcupantes);
        compAno=cl.anoDevolucao;
        compMes=cl.mesDevolucao;
        compDia=cl.diaDevolucao;
        while(compAno>0)
        {
            compAno--;
            compMes+=12;
        }
        while(compMes>0)
        {
            compMes--;
            compDia+=30;
        }
        compDia+=1;
        while(anoAtual>0)
        {
            anoAtual--;
            mesAtual+=12;
        }
        while(mesAtual>0)
        {
            mesAtual--;
            diaAtual+=30;
        }
        printf("diarias=%d\n",cl.diarias);
        diasExtras=diaAtual-compDia;
        printf("dias extras=%d\n",diasExtras);
        if(cl.seguro=='s')
        {
            custo+=50;
        }
        printf("Custo parcial: %.2f\n",custo);
        if(diasExtras>0)
        {
            printf("Excedeu a data esperada de entrega em %d dias, será aplicada multa ao valor total.\n",diasExtras);
            custo*=1.05;
            custo+=(diasExtras*30);
        }
        printf("Custo total: %.2f",custo);
        //setar status do carro para disponível
        fseek(arquivoLocacao,(sizeof(cl)*(posicao)),SEEK_SET);
        fwrite(&cl,sizeof(cl),1,arquivoLocacao);
        fseek(arquivoLocacao,0,SEEK_END);
        fflush(arquivoLocacao);
        printf("\n______________________________________\n");
        system("PAUSE");
        system("CLS");
    }

    printf ("====================================\n");
    printf ("| Deseja avaliar nossa empresa?    |\n");
    printf ("| 01 -          SIM                |\n");
    printf ("| 02 -          NÃO                |\n");
    printf ("====================================");
    op=getch();
    switch (op)
    {
    case '1':
        avaliar(CLIENTE,SETCODIGO_C);
        break;
    case '2':
        main();
        break;
    }
}
//DAR BAIXA - FIM
void avaliar(FILE *CLIENTE,FILE *SETCODIGO_C)//NOSSA FUNÇÃO
{
    int posicao;
    cliente c;
    fseek(CLIENTE,0,SEEK_SET);
    fread(&c, sizeof(c),1,CLIENTE);
    c.codigo=gera_codigo_clientes(SETCODIGO_C);
    posicao=localiza_dado(CLIENTE,c.codigo);
    if (posicao==-1)
    {
        printf("De 0 a 5 como foi o atendimento recebido?\n");
        scanf("%d",&c.avaliacaoatendimento);
        printf("De 0 a 5 voce recomendaria nossa empresa para um amigo?v");
        scanf("%d",&c.recomendado);
        printf("De 0 a 5 como foi a experiencia com o carro?\n");
        scanf("%d",&c.avaliacaocarro);
        printf("Opcional, caso não queira aperte ENTER\n");
        printf("Insira um preve texto sobre o atendimento recebido\n");
        fflush(stdin);
        gets(c.avaliacao_atendimento);
        printf("Opcional, caso não queira aperte ENTER\n");
        printf("Insira um preve texto sobre a experiencia com o carro\n");
        fflush(stdin);
        gets(c.avaliacao_carro);
        printf("Opcional, caso não queira aperte ENTER\n");
        printf("Você recomendaria a empresa para um amigo? Se sim porque\n");
        fflush(stdin);
        gets(c.recomendar);
        fwrite(&c,sizeof(c),1,  CLIENTE);
        fseek(CLIENTE,0,SEEK_END);
    }
    else
    {
        printf("entrou no else\n\n\n");
    }

    printf("\n______________________________________\n");
    system("PAUSE");
    system("CLS");
}
//Adciona veiculo INICIO
void incluirDadosVeiculo(FILE *ARQUIVO_VEICULO,FILE *CODIGO_V)
{
    veiculo v;
    int posicao,tentativa;
    v.codigo_do_veiculo=gerarCodigoLoc_veiculo(CODIGO_V);
    printf("\ndigite o modelo:");
    fflush(stdin);
    gets(v.modelo);
    posicao=localiza_modelo(ARQUIVO_VEICULO,v.modelo);
    if(posicao==-1)
    {
        v.status=1;//1 para carro disponivel
        printf("digite a descrição:");
        gets(v.descricao);
        fflush(stdin);
        printf("digite a cor:");
        gets(v.cor);
        fflush(stdin);
        printf("digite a placa:");
        gets(v.placa);
        fflush(stdin);
        printf("digite a diaria do carro:");
        scanf("%f",&v.valor_diario);
        fflush(stdin);
        printf("digite a quantidade de ocupante(s):");
        scanf("%d",&v.quantidade_de_ocupante);
        fflush(stdin);
        strcpy(v.disponibilidade,"Disponivel");
        fseek(ARQUIVO_VEICULO,0,SEEK_END);
        fwrite(&v,sizeof(v),1,ARQUIVO_VEICULO);
        fflush(ARQUIVO_VEICULO);
    }
    else
    {
        v.status=0;//0 para indisponivel
        strcpy(v.disponibilidade,"indisponivel");
        printf("\no modelo do veiculo %s ja existe no arquivo.\n\nSTATUS INDISPONIVEL \n\n",v.modelo);
        printf("se deseja tentar outro veiculo digite <1> se não digite <0>");
        tentativa=getch();
        switch (tentativa)
        {
        case '1':
            system("cls");
            incluirDadosVeiculo(ARQUIVO_VEICULO,CODIGO_V);
            break;
        case '0':
            main();
            break;

        }
    }

}
//Adciona veiculo FIM

//GERA CODIGO E LOCALIZA VEICULO INICIO
int gerarCodigoLoc_veiculo(FILE *banco_codigo)
{
    int n;
    veiculo v;
    fseek(banco_codigo,0,SEEK_SET);
    fread(&v,sizeof(v),1,banco_codigo);
    if (!feof(banco_codigo))
    {
        v.codigo_do_veiculo++;
    }
    else
    {
        v.codigo_do_veiculo=1;
    }
    fseek(banco_codigo,0,SEEK_SET);
    fwrite(&v,sizeof(v),1,banco_codigo);
    fflush(banco_codigo);
    n=v.codigo_do_veiculo;
    return n;
}


int localiza_modelo(FILE *banco_loca,char modelo[100])
{
    int posicao=-1,achou=0;
    veiculo v;
    fseek(banco_loca,0,SEEK_SET);
    {
        fread(&v,sizeof(v),1,banco_loca);
        while (!feof(banco_loca)&&!achou)
        {
            posicao++;
            if (strcasecmp(v.modelo,modelo)==0)
            {
                achou=1;
            }
            fread(&v,sizeof(v),1,banco_loca);
        }
        if (achou)
        {
            return posicao;
        }
        else
        {
            return -1;
        }
    }
}
//GERA CODIGO E LOCALIZA VEICULO FIM
void listar_carro(FILE *banco_loca)
{
    veiculo v;
    fseek(banco_loca,0,SEEK_SET);
    fread(&v, sizeof(v),1, banco_loca);
    printf("Imprimindo clinetes\n");
    while (!feof(banco_loca))
    {
        printf("\nModelo:%s \n",v.modelo);
        printf("Placa:%s \n",v.placa);
        printf("Cor:%s \n",v.cor);
        printf("Descrição:%s \n",v.descricao);
        printf("Disponibilidade:%s \n",v.disponibilidade);
        printf("Valor diario:%.2f \n",v.valor_diario);
        printf("Numero de passageiros:%d \n",v.quantidade_de_ocupante);
        printf("Codigo do veiculo:%d \n",v.codigo_do_veiculo);
        fread(&v, sizeof(v),1, banco_loca);
    }
    printf("\n_______________________________________\n");
    system("PAUSE");
    system("CLS");

}

// PONTOS DE FIDELIDADE - INÍCIO

void pontosFidelidade(FILE *CLIENTE)
{
    cliente c;
    system("CLS");
    printf("Imprimindo clientes\n");
    fseek(CLIENTE,0,SEEK_SET);
    fread(&c, sizeof(c),1, CLIENTE);
    while (!feof(CLIENTE))
    {
        if(c.fidelidade>=500)
        {
            printf("\nNome:%s \n",c.nome);
            printf("Codigo:%d \n",c.codigo);
            printf("Telefone:%s \n",c.telefone);
            printf("Endereço:%s \n",c.endereco);
            printf("Pontos de Fidelidade:%d\n",c.fidelidade);
            fflush(stdin);
        }

        fread(&c, sizeof(c),1, CLIENTE);
    }
    fseek(CLIENTE,0,SEEK_END);
    printf("\n_______________________________________\n");
    system("PAUSE");
    system("CLS");
}

// PONTOS DE FIDELIDADE - INÍCIO

