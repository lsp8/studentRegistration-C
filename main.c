#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_ALUNOS 50

typedef struct
{
    char nome[50];
    float notas[2];
    int ativo;
}Aluno;
Aluno alunos [MAX_ALUNOS];

void menu();
void cadastroNovoAluno();  
void excluirAluno();
void alunosReprovados();
void pesquisarAluno();
void listarAlunos();
void listaAprovados();

int main(int argc, char const *argv[])
{
    menu();
    return 0;
}

void menu(){
    int opcao;
    do
    {
        system("clear");
        printf("Bem vindo(a) ao Menu de Cadastros de alunos. Escolha uma das opcoes para prosseguir: ");
        printf("\n1 - Cadastrar aluno \n2 - Excluir aluno \n3 - Reprovados\n4 - Pesquisar aluno \n5 - Lista de todos os alunos \n6 - Lista de alunos aprovados \n0 - Sair\n");
        scanf("%d", &opcao);
        getchar();
        switch (opcao)
        {
            case 1:
                cadastroNovoAluno();
            break;
            case 2:
                excluirAluno();
            break;
            case 3:
                alunosReprovados();
                break;
            case 4:
                pesquisarAluno();
            break;
            case 5:
                listarAlunos();
            break;
            case 6:
                listaAprovados();
            break;
        }
        getchar();
    }while(opcao != 0);

}
void cadastroNovoAluno()
{  
    system("clear");
    char nome[50];
    float notas[2];
    int opcao;
    do
    {
        system("clear");
        printf("\n Digite o nome do aluno: ");
        fgets(nome, sizeof(nome), stdin );

        printf("\n Nota G1: ");
        scanf("%f", &notas[0]);

        printf("\n Nota G2: ");
        scanf("%f",&notas[1]);
        for (int i =0; i < MAX_ALUNOS; i++ )
        {
            if(alunos[i].ativo == 0)
            {
                alunos[i].notas[0] = notas[0];
                alunos[i].notas[1] = notas[1];
                strcpy(alunos[i].nome, nome);
                alunos[i].ativo =1;
                break;
            }
        }
        printf("\n1 - Cadastrar outro aluno \n0 - Sair\n ");
        scanf("%d", &opcao);
        getchar();
    } while(opcao !=0 );
}
void excluirAluno()
{
    int matricula;
    listarAlunos();
    printf("\n Digite a matricula do aluno a ser removido: ");
    scanf("%d", &matricula);
    --matricula;
    alunos[matricula].ativo = 0;
    printf("\n Aluno excluido com sucesso. \n");
}
void alunosReprovados()
{
    system("clear");
    float media;
    printf("\nLista de alunos REPROVADOS: \n");
    printf("\n");
    for(int i=0; i< MAX_ALUNOS ; i++)
    {
        if(alunos[i].ativo == 1)
        {
            media =0;
            media = (alunos[i].notas[0]+alunos[i].notas[1])/2;
            if(media <8)
            {  
                printf("Nome do aluno: %s", alunos[i].nome);
                printf("Matricula do aluno: %d \n", i+1);
                printf("Nota G1: %.2f \n", alunos[i].notas[0] );
                printf("Nota G2: %.2f \n", alunos[i].notas[1] );
                printf("Aluno ficou com media %.2f e foi reprovado \n", media);
                printf("---------------------------------\n");
            }
        }

    }
}
void pesquisarAluno()
{
    float media;
    char nome[50];
   int opcao;
   do
   {
    system("clear");
    printf("\n Digite o nome do aluno para pesquisa: ");
    fgets(nome, sizeof(nome) , stdin);
    for( int i=0; i< MAX_ALUNOS; i++)
    {
        if(strstr(alunos[i].nome, nome)!= NULL)
        {  
          media =0;
            media = (alunos[i].notas[0]+alunos[i].notas[1])/2;
            printf("Nome do aluno: %s", alunos[i].nome);
            printf("Matricula do aluno: %d\n", i+1);
            printf("Nota G1: %.2f \n", alunos[i].notas[0] );
            printf("Nota G2: %.2f \n", alunos[i].notas[1] );printf("Aluno ficou com media %.2f \n", media);
            printf("\n----------------------------------------------\n");
        }  
    }
    printf("\n Digite 1 para pesqusiar outro aluno, ou 0 para sair: ");
    scanf("%d", &opcao);
    getchar();
   }while(opcao !=0);
}
void listarAlunos()
{  
    float media;
    system("clear");
    printf("\nLista de alunos: \n");
    printf("\n");
    for(int i=0; i< MAX_ALUNOS ; i++)
    {  
      media =0;
            media = (alunos[i].notas[0]+alunos[i].notas[1])/2;
        if(alunos[i].ativo == 1)
        {
            printf("Nome do aluno: %s", alunos[i].nome);
            printf("Matricula do aluno: %d \n", i+1);
            printf("Nota G1: %.2f \n", alunos[i].notas[0] );
            printf("Nota G2: %.2f \n", alunos[i].notas[1] );
          printf("Nota G2: %.2f \n", alunos[i].notas[1] );printf("Aluno ficou com media: %.2f \n", media);
            printf("---------------------------------\n");
        }

    }
   
}
void listaAprovados()
{
    system("clear");
    float media;
    printf("\nLista de alunos APROVADOS: \n");
    printf("\n");
    for(int i=0; i< MAX_ALUNOS ; i++)
    {
        if(alunos[i].ativo == 1)
        {
            media =0;
            media = (alunos[i].notas[0]+alunos[i].notas[1])/2;
            if(media >=8)
            {  
                printf("Nome do aluno: %s", alunos[i].nome);
                printf("Matricula do aluno: %d \n", i+1);
                printf("Nota G1: %.2f \n", alunos[i].notas[0] );
                printf("Nota G2: %.2f \n", alunos[i].notas[1] );
                printf("Aluno ficou com media %.2f e esta APROVADO!\n", media);
                printf("---------------------------------\n");
            }
        }

    }
}
