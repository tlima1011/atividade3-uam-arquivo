#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 10

void limpar_entrada() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int opcao = 0, i = 0, tamanhobuffer;

struct cliente{
    char nome[50];
    int anoNascimento;
    float montante;
};

struct cliente cli;

void menu(){
    printf("\n-----------------------------CADASTRO DE CLIENTES-------------------------------");
    printf("\n[ 1 ] - Incluir um novo cliente ");
    printf("\n[ 2 ] - Remover cliente");
    printf("\n[ 3 ] - Zerar todos os montantes de compras por ocasião da virada de mês");
    printf("\n[ 4 ] - Exibir um montante de compras de um cliente específico");
    printf("\n[ 5 ] - Listar clientes");
    printf("\n[ 6 ] - Informar melhor comprador");
    printf("\n[ 7 ] - Sair\n");
    printf("----------------------------------------------------------------------------------\n");
    printf("Opção: ");
}

void incluirCliente(){
    system("cls");
    FILE *arq;
    arq = fopen("C:\\Users\\thiag\\Desktop\\TesteArquivo\\Cliente\\cliente.txt","wb+");

    if(arq ==NULL){
        printf("Falha na abertura de arquivo.\n");
        return 0;
    }
    //int i = 0;
    char cont;

    while(i < TAM){
        printf("Dados do %d cliente: \n", i + 1);
        printf("Nome: ");
        scanf("%s", cli.nome);
        printf("Ano Nascimento: ");
        scanf("%d", &cli.anoNascimento);
        printf("Montante em R$");
        scanf("%.2f", &cli.montante);
        //fscanf(arq,"%s;%d;%f", &lista[i].nome, &lista[i].anoNascimento,&lista[i].montante);
        fwrite(&cli, sizeof(struct cliente),1,arq);
        limpar_entrada();
        printf("Deseja incluir mais um cliente [s][n]");
        scanf("%c",&cont);
        if(cont =='n' || cont == 'N'){
            break;
        }
        if(i > TAM){
            printf("Todos clientes ocupados não permitido adicao de mais");
            break;
        }
        i++;
    }
    fclose(arq);
}

void listarClientes(*cliente){
    //struct cliente cli1;
    tamanhobuffer = sizeof(cli);

    FILE *arq;
    arq = fopen("C:\\Users\\thiag\\Desktop\\TesteArquivo\\Cliente\\cliente.txt","r");

    if(arq ==NULL){
        printf("Falha na abertura de arquivo.\n");
        return 0;
    }

    for(i = 0; i < TAM;i++){
        //printf("Nome: %s - Ano Nascimendo: %d - Montante R$%.2f\n", lista[i].nome, lista[i].anoNascimento, lista[i].montante);
        fseek(arq,i*tamanhobuffer,SEEK_SET);
        fread(&cli1,sizeof(cliente),1,arq);
        printf("\n\tNome: %s - Ano Nascimento: %d - Montante %.2f",cli.nome, cli.anoNascimento, cli.montante);
    }

    fclose(arq);
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    do{
        menu();
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                incluirCliente();
            break;
            case 2:

            break;
            case 3:

            break;
            case 4:

            break;
            case 5:
                listarClientes(&cliente);
            break;
    }
    }while(opcao != 7);

    return 0;
}
