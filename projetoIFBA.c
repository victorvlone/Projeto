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

    char resposta;
    int i = 0;
    char SexoMasculino[] = "Masculino";
    char SexoFeminino[] = "Feminino";

    struct Alunos Aluno[TAM];
    struct Professores Professor[TAM];
    struct Disciplinas Disciplina[TAM];

    printf("CADASTRO DE ALUNOS\n\n");

    printf("Nome completo: ");
    ler_texto(Aluno[i].NomeAluno, 1000);

    printf("Sexo: ");
    ler_texto(Aluno[i].SexoAluno, 10);
    limpar_entrada();

    Aluno[i].SexoAluno[0] = toupper(Aluno[i].SexoAluno[0]);
    if (strcmp("Masculino", Aluno[i].SexoAluno) != 0 && strcmp("Feminino", Aluno[i].SexoAluno) != 0){
        /* code */
    }
    

    printf("DIA DE NASCIMENTO: ");
    scanf("%d", &Aluno[i].DiadeNascimentoAluno);
    limpar_entrada();
    printf("MÊS DE NASCIMENTO: ");
    scanf("%d", &Aluno[i].MesdeNascimentoAluno);
    limpar_entrada();
    printf("ANO DE NASCIMENTO: ");
    scanf("%d", &Aluno[i].AnodeNascimentoAluno);
    limpar_entrada();

    printf("CPF(sem pontuaçâo): ");
    scanf("%d", &Aluno[i].CPFAluno);
    limpar_entrada();
    
    printf("Número de matrícula: ");
    scanf("%d", &Aluno[i].NumerodeMatricula);
    limpar_entrada();
    system("cls || clear");

    printf("Aperte a tecla 1 para cadastrar mais um\n");
    printf("aluno ou a tecla 2 para cadastrar um professor:\n");
    scanf("%c", &resposta);
    system("cls || clear");

    while(resposta != '0'){
        i = 1;
        if(resposta == '1'){  

            do{

                printf("CADASTRO DE ALUNOS\n\n");

                printf("NOME COMPLETO: ");
                ler_texto(Aluno[i].NomeAluno, 1000);
                limpar_entrada();

                printf("SEXO: ");
                ler_texto(Aluno[i].SexoAluno, 10);

                printf("DATA DE NASCIMENTO\n");
                printf("DIA: ");
                scanf("%d", &Aluno[i].DiadeNascimentoAluno);
                printf("MẼS: ");
                scanf("%d", &Aluno[i].MesdeNascimentoAluno);
                printf("ANO: ");
                scanf("%d", &Aluno[i].AnodeNascimentoAluno);

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


    printf("1. LISTA DE ALUNOS\n");
    printf("2. LISTA DE PROFESSORES\n");
    printf("3. LISTA DE DISCIPLINAS\n");
    printf("4. ");
    for (i = 0; i < TAM; i++){
        printf("%s\n", &Aluno[i].NomeAluno);
    }
    


    return 0;
}