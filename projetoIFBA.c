#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define TAM 3

// FUNÇÃO PARA VERIFICAR SE A DATA ESTA NO FORMATO CORRETO.
int verificacaoData(const char *data)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        if ((i == 2 || i == 5) && data[i] != '/')
        {
            return 0;
        }
        else if ((i != 2 && i != 5) && !isdigit(data[i]))
        {
            return 0;
        }
    }
    return 1;
}

// FUNÇÃO PARA VERIFICAR SE O CPF ESTA NO FORMATO CORRETO.
int verificacaoCPF(const char *cpf)
{
    int i;
    for (i = 0; i < 14; i++){
        if ((i == 3 || i == 7) && cpf[i] != '.'){
            return 0;
        }
        else if (i == 11 && cpf[i] != '-'){
            return 0;
        }
        else if ((i != 3 && i != 7 && i != 11) && !isdigit(cpf[i])){
            return 0;
        }
    }
    return 1;
}

// FUNÇÃO PARA VERIFICAR SE O NÚMERO DE MATRICULA ESTA NO FORMATO CORRETO.
int verificacaoMatricula(const char *matricula)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        if (i == 3 && matricula[i] != '.')
        {
            return 0;
        }
        else if (i != 3 && !isdigit(matricula[i]))
        {
            return 0;
        }
    }
    return 1;
}

// FUNÇÃO PARA TORNAR TODAS AS LETRAS DA STRING EM MAIUSCULAS.
void maiusculo(char *string)
{
    int i;
    for (i = 0; string[i] != '\0'; i++)
    {
        string[i] = toupper(string[i]);
    }
}

// FUNÇAO PARA VERIFICAR SE TODOS OS CARACTERES DA STRING SÃO LETRAS.
int letras(const char *string)
{
    int i;
    for (i = 0; string[i] != '\0'; i++)
    {
        if (!isalpha((unsigned char)string[i]) && string[i] != ' ')
        {
            return 0;
        }
    }
    return 1;
}

void limpar_entrada()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

void ler_texto(char *buffer, int length)
{
    fgets(buffer, length, stdin);
    strtok(buffer, "\n");
}

struct Alunos
{
    char NomeAluno[1000];
    char SexoAluno[10];
    char CPFAluno[15];
    char NumerodeMatricula[11];
    char DatadeNascimentoAluno[11];
};

struct Professores
{
    char NomeProfessor[1000];
    char SexoProfessor[10];
    char CPFProfessor[15];
    char NumerodeMatricula[11];
    char DatadeNascimentoProfessor[11];
    char NomedaDisciplina[1000];
};

struct Disciplinas
{
    char NomedaDisciplina[1000];
    int codigodaDisciplina;
    int Semestre;
    char professor[1000];
};

int main(){

    setlocale(LC_ALL, "portuguese");

    char respostaMENU[100];
    int i = 0;

    struct Alunos Aluno[TAM];
    struct Professores Professor[TAM];
    struct Disciplinas Disciplina[TAM];

    printf("  Lista de professores | Lista de alunos | Cadastrar professores | Cadastrar Alunos | Sair\n\n");

    printf("Como deseja prosseguir? ");
    ler_texto(respostaMENU, 100);
    system("cls || clear");

    maiusculo(respostaMENU);

    while (strcmp("SAIR", respostaMENU) != 0){

        if (strcmp("CADASTRAR ALUNOS", respostaMENU) == 0){

            do{

                printf("CADASTRO DE ALUNOS\n\n");


                printf("NOME COMPLETO: ");
                ler_texto(Aluno[i].NomeAluno, 1000);


                while (!letras(Aluno[i].NomeAluno)){

                    system("cls || clear");
                    printf("Digite apenas letras e sem acentuação.\n");
                    sleep(2);
                    system("cls || clear");
                    printf("NOME COMPLETO: ");
                    ler_texto(Aluno[i].NomeAluno, 1000);
                }
                maiusculo(Aluno[i].NomeAluno);

                printf("SEXO: ");
                ler_texto(Aluno[i].SexoAluno, 10);
                maiusculo(Aluno[i].SexoAluno);

                while (strcmp("MASCULINO", Aluno[i].SexoAluno) != 0 && strcmp("FEMININO", Aluno[i].SexoAluno) != 0){

                    system("cls || clear");  
                    printf("Opção invalida! Tente novamente.\n");
                    sleep(2);
                    system("cls || clear");
                    printf("SEXO: ");
                    ler_texto(Aluno[i].SexoAluno, 10);
                    maiusculo(Aluno[i].SexoAluno);

                }

                limpar_entrada();
                printf("DATA DE NASCIMENTO: ");
                ler_texto(Aluno[i].DatadeNascimentoAluno, 11);

                while (!verificacaoData(Aluno[i].DatadeNascimentoAluno)){

                    limpar_entrada();
                    system("cls || clear");
                    printf("Digite a data de nascimento no formato DD/MM/AAAA.\n");
                    sleep(2);
                    system("cls || clear");
                    printf("DATA DE NASCIMENTO: ");
                    ler_texto(Aluno[i].DatadeNascimentoAluno, 11);
                }

                limpar_entrada();
                printf("CPF: ");
                ler_texto(Aluno[i].CPFAluno, 15);

                while (!verificacaoCPF(Aluno[i].CPFAluno)){

                    system("cls || clear");
                    printf("inválido! O CPF deve estar no formato 000.000.000-00.\n");
                    sleep(2);
                    system("cls || clear");
                    printf("CPF: ");
                    ler_texto(Aluno[i].CPFAluno, 15);
                }

                limpar_entrada();
                printf("Número de matrícula: ");
                ler_texto(Aluno[i].NumerodeMatricula, 11);

                limpar_entrada();
                while (!verificacaoMatricula(Aluno[i].NumerodeMatricula)){

                    printf("inválido! O número de matrícula deve estar no formato 000.000000.\n");
                    sleep(2);
                    system("cls || clear");
                    printf("Número de matrícula: ");
                    ler_texto(Aluno[i].NumerodeMatricula, 11);
                }
                system("cls || clear");
                i++;

                if (i < TAM){
                    strcpy(respostaMENU, "CADASTRAR ALUNOS");
                }
                else{
                    strcpy(respostaMENU, "MENU");
                }
                limpar_entrada();

            } while (strcmp("CADASTRAR ALUNOS", respostaMENU) == 0);

        }else if (strcmp("CADASTRAR PROFESSORES", respostaMENU) == 0) {

            do{

                printf("CADASTRO DE PROFESSORES\n\n");

                limpar_entrada();
                printf("NOME COMPLETO: ");
                ler_texto(Professor[i].NomeProfessor, 1000);

                limpar_entrada();
                printf("SEXO: ");
                ler_texto(Professor[i].SexoProfessor, 10);

                maiusculo(Professor[i].SexoProfessor);
                while (strcmp("MASCULINO", Professor[i].SexoProfessor) != 0 && strcmp("FEMININO", Professor[i].SexoProfessor) != 0)
                {

                    system("cls || clear");
                    printf("Opção invalida! Tente novamente:\n");
                    ler_texto(Professor[i].SexoProfessor, 10);
                    system("cls || clear");
                }

                limpar_entrada();
                printf("DATA DE NASCIMENTO: ");
                ler_texto(Professor[i].DatadeNascimentoProfessor, 11);

                while (!verificacaoData(Professor[i].DatadeNascimentoProfessor)){

                    system("cls || clear");
                    printf("Digite a data de nascimento no formato DD/MM/AAAA.\n");
                    sleep(2);
                    system("cls || clear");
                    printf("DATA DE NASCIMENTO: ");
                    ler_texto(Professor[i].DatadeNascimentoProfessor, 11);
                }

                printf("CPF: ");
                ler_texto(Professor[i].CPFProfessor, 15);

                while (!verificacaoCPF(Professor[i].CPFProfessor)){

                    system("cls || clear");
                    printf("inválido! O CPF deve estar no formato 000.000.000-00.\n");
                    sleep(2);
                    system("cls || clear");
                    limpar_entrada();
                    printf("CPF: ");
                    ler_texto(Professor[i].CPFProfessor, 15);
                }

                printf("Número de matrícula: ");
                ler_texto(Professor[i].NumerodeMatricula, 11);

                while (!verificacaoMatricula(Professor[i].NumerodeMatricula)){

                    printf("inválido! O número de matrícula deve estar no formato 000.000000.\n");
                    sleep(2);
                    system("cls || clear");
                    printf("Número de matrícula: ");
                    ler_texto(Professor[i].NumerodeMatricula, 11);
                }

                printf("DISCIPLINA: ");
                ler_texto(Professor[i].NomedaDisciplina, 1000);

                printf("SEMESTRE: ");
                scanf("%d", &Disciplina[i].Semestre);
                i++;

                if (i < TAM){
                    strcpy(respostaMENU, "CADASTRAR PROFESSORES");
                
                }else{
                    strcpy(respostaMENU, "MENU");
                }

            } while (strcmp("CADASTRAR PROFESSORES", respostaMENU) == 0);

        }else if(strcmp("MENU", respostaMENU) == 0){

            do{

                limpar_entrada();
                printf("  Lista de professores | Lista de alunos | Cadastrar professores | Cadastrar Alunos | Sair\n\n");
                printf("Como deseja prosseguir? ");
                ler_texto(respostaMENU, 100);
                system("cls || clear");

                maiusculo(respostaMENU);

            }while(strcmp("MENU", respostaMENU) == 0);

        }else{

            printf("Não entendi o que você quis dizer :(");
            sleep(3);
            system("cls || clear");
            strcpy(respostaMENU, "MENU");

        }

    }
    return 0;
}
