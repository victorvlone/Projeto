#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define TAM 3

void limpar_entrada() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void ler_texto(char *buffer, int length) {
    fgets(buffer, length, stdin);
    strtok(buffer, "\n");
}

struct Alunos{
    char NomeAluno[1000];
    char SexoAluno[10];
    int CPFAluno;
    int NumerodeMatricula;
    int DiadeNascimentoAluno;
    int MesdeNascimentoAluno;
    int AnodeNascimentoAluno;
};

struct Professores{
    char NomeProfessor[1000];
    char SexoProfessor[10];
    int CPFProfessor;
    int NumerodeMatricula;
    int DiadeNascimentoProfessor;
    int MesdeNascimentoProfessor;
    int AnodeNascimentoProfessor;
};

struct Disciplinas{
    char NomedaDisciplina[1000];
    int codigodaDisciplina;
    int Semestre;
    char professor[1000];
};

int main () {


    char respostaMENU[100];
    char resposta;
    int i = 0;

    struct Alunos Aluno[TAM];
    struct Professores Professor[TAM];
    struct Disciplinas Disciplina[TAM];

    system("cls || clear");
    printf("         MENU\n\n");
    printf("  Listas | Cadastros\n\n");

    printf("Como deseja prosseguir? ");
    ler_texto(respostaMENU, 100);
    system("cls || clear");

    respostaMENU[0] = toupper(respostaMENU[0]);

    if (strcmp("Cadastros", respostaMENU) == 0){

        printf("1. Cadastrar Alunos\n");
        printf("2. Cadastrar professores\n");
        printf("3. Cadastrar disciplinas\n\n");
        printf("O que deseja cadastrar primeiro? ");
        scanf("%c", &resposta);
        system("cls || clear");

        while(resposta != '0'){

            if(resposta == '1'){  

                do{

                    printf("CADASTRO DE ALUNOS\n\n");

                    printf("NOME COMPLETO: ");
                    ler_texto(Aluno[i].NomeAluno, 1000);
                    limpar_entrada();

                    printf("SEXO: ");
                    ler_texto(Aluno[i].SexoAluno, 10);

                    Aluno[i].SexoAluno[0] = toupper(Aluno[i].SexoAluno[0]);
                    while(strcmp("Masculino", Aluno[i].SexoAluno) != 0 && strcmp("Feminino", Aluno[i].SexoAluno) != 0){

                        system("cls || clear");
                        printf("Opção invalida! Tente novamente:\n");
                        ler_texto(Aluno[i].SexoAluno, 10);
                        system("cls || clear");
                    
                    }

                    printf("DIA DE NASCIMENTO: ");
                    scanf("%d", &Aluno[i].DiadeNascimentoAluno);

                    while (Aluno[i].DiadeNascimentoAluno > 31 || Aluno[i].DiadeNascimentoAluno < 1){
                        
                        system("cls || clear");
                        printf("invalido! Tente novamente:\n");
                        scanf("%d", &Aluno[i].DiadeNascimentoAluno);
                        system("cls || clear");

                    }
                    
                    printf("MẼS DE NASCIMENTO: ");
                    scanf("%d", &Aluno[i].MesdeNascimentoAluno);

                    while (Aluno[i].MesdeNascimentoAluno > 12 || Aluno[i].MesdeNascimentoAluno < 1){
                        
                        system("cls || clear");
                        printf("invalido! Tente novamente:\n");
                        scanf("%d", &Aluno[i].MesdeNascimentoAluno);
                        system("cls || clear");

                    }

                    printf("ANO DE NASCIMENTO: ");
                    scanf("%d", &Aluno[i].AnodeNascimentoAluno);

                    while (Aluno[i].AnodeNascimentoAluno > 2017 || Aluno[i].AnodeNascimentoAluno < 2006){

                        system("cls || clear");
                        limpar_entrada();
                        printf("\nNão aceitamos alunos com menos de sete ou com mais de dezoito anos.\n");
                        printf("Mesmo prosseguindo, o cadastro não será realizado.\n\n");
                        printf("Deseja corrigir? ");
                        ler_texto(respostaMENU, 100);
                        system("cls || clear");

                        respostaMENU[0] = toupper(respostaMENU[0]);
                        if(strcmp("Sim", respostaMENU) == 0){

                            printf("\nANO DE NASCIMENTO: ");
                            scanf("%d", &Aluno[i].AnodeNascimentoAluno);

                        } else if(strcmp("Não", respostaMENU) == 0){
                            break;
                        }
                    }

                    printf("CPF(sem pontuaçâo): ");
                    scanf("%d", &Aluno[i].CPFAluno);

                    printf("Número de matrícula: ");
                    scanf("%d", &Aluno[i].NumerodeMatricula);
                    system("cls || clear");
                    i++;

                    if (i < TAM){

                        printf("Aperte a tecla 1 para cadastrar mais um\n");
                        printf("aluno ou a tecla 2 para cadastrar um professor:\n");
                        scanf("%c", &resposta);
                        system("cls || clear");

                    }else{
                        resposta = '2';
                    }

                } while(resposta == '1');

            }else if (resposta == '2'){

                do{
    
                    printf("CADASTRO DE PROFESSORES\n\n");

                    printf("Nome completo: ");
                    ler_texto(Professor[i].NomeProfessor, 1000);
                    system("cls || clear");

                    printf("CADASTRO DE PROFESSORES\n\n");

                    printf("Sexo: ");
                    ler_texto(Professor[i].SexoProfessor, 10);
                    system("cls || clear");

                    printf("CADASTRO DE PROFESSORES\n");

                    printf("Data de nascimento\n\n");
                    printf("Dia: ");
                    scanf("%d", &Professor[i].DiadeNascimentoProfessor);
                    printf("Mês: ");
                    scanf("%d", &Professor[i].MesdeNascimentoProfessor);
                    printf("Ano: ");
                    scanf("%d", &Professor[i].AnodeNascimentoProfessor);
                    system("cls || clear");
                    
                    printf("CADASTRO DE PROFESSORES\n\n");

                    printf("CPF: ");
                    scanf("%d", &Professor[i].CPFProfessor);
                    system("cls || clear");

                    printf("CADASTRO DE PROFESSORES\n\n");

                    printf("Número de matrícula");
                    scanf("%d", &Professor[i].NumerodeMatricula);
                    system("cls || clear");
                    i++;

                    if (i < TAM){

                        printf("Aperte a tecla 2 para cadastrar mais um professor\n");
                        printf("aperte a tecla 3 para cadastrar uma disciplina,\n");
                        printf("ou aperte a tecla 0 para encerrar os cadastros:\n");
                        scanf("%c", &resposta);
                        system("cls || clear");

                    }else{
                        resposta = '3';
                    }

                } while(resposta == '2');

            } else if (resposta == '3'){

                do{
                    printf("CADASTRO DE DISCIPLINAS\n\n");

                    printf("Nome: ");
                    ler_texto(Disciplina[i].NomedaDisciplina, 1000);    
                    printf("Código: ");
                    scanf("%d", &Disciplina[i].codigodaDisciplina);
                    printf("Semestre: ");
                    scanf("%d", &Disciplina[i].Semestre);
                    printf("Professor: ");
                    ler_texto(Disciplina[i].professor, 1000);

                    if (i < TAM){

                        printf("Aperte a tecla 3 para cadastrar mais um professor\n");
                        printf("ou aperte a tecla 0 para encerrar os cadastros:\n");
                        scanf("%c", &resposta);
                        system("cls || clear");

                    }else{
                        resposta = '0';
                    }

                } while (resposta == '3');
                
            } else{

                printf("Opção invalida! aperte a tecla 1 se deseja adicionar\n");
                printf("mais um aluno, 2 para adicionar mais um professor, 3\n");
                printf("para adicionar mais uma disciplina ou 0 para encerrar:\n");
                scanf("%c", &resposta);
                system("cls || clear");
                
            }
        }
    }

    return 0;
}

    return 0;
}
