#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define TAM 2

int verificacaoData(const char *data){
    int i;
    for (i = 0; i < 10; i++){
        if ((i == 2 || i == 5) && data[i] != '/'){
            return 0;
        }
        else if ((i != 2 && i != 5) && !isdigit(data[i])){
            return 0;
        }
    }
    return 1;
}

int verificacaoCPF(const char *cpf){
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


int verificacaoMatricula(const char *matricula){
    int i;
    for (i = 0; i < 10; i++){
        if (i == 3 && matricula[i] != '.'){
            return 0;
        }
        else if (i != 3 && !isdigit(matricula[i])){
            return 0;
        }
    }
    return 1;
}

void maiusculo(char *string){
    int i;
    for (i = 0; string[i] != '\0'; i++){
        string[i] = toupper(string[i]);
    }
}

int letras(const char *string){
    int i;
    for (i = 0; string[i] != '\0'; i++){
        if (!isalpha((unsigned char)string[i]) && string[i] != ' '){
            return 0;
        }
    }
    return 1;
}

void limpar_entrada(){
    char c;
    while ((c = getchar()) != '\n' && c != EOF){
    }
}

void ler_texto(char *buffer, int length){
    fgets(buffer, length, stdin);
    strtok(buffer, "\n");
}

struct Alunos{
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

};

struct Disciplinas{
    char NomedaDisciplina[1000];
    char codigodaDisciplina[9];
    char Semestre;
    char professor[1000];
};

int main(){

    setlocale(LC_ALL, "portuguese");

    char respostaMENU[100];
    char respostaInicial[100];
    int i = 0;
    char vazio[1000];

    struct Alunos Aluno[TAM];
    struct Professores Professor[TAM];
    struct Disciplinas Disciplina[TAM];

    printf("1. Cadastros\n");
    printf("2. Listas\n");
    printf("3. Sair\n\n");
    printf("Como deseja prosseguir? ");
    ler_texto(respostaInicial, 100);
    maiusculo(respostaInicial);

    while (strcmp("CADASTROS", respostaInicial) == 0){

        system("cls || clear");
        printf(" Professores | Alunos | Disciplinas | Sair\n\n");

        printf("O que deseja cadastrar primeiro? ");
        ler_texto(respostaMENU, 100);
        system("cls || clear");

        maiusculo(respostaMENU);

        while (strcmp("SAIR", respostaMENU) != 0){

            if (strcmp("ALUNOS", respostaMENU) == 0){

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

                        printf("Aperte a tecla 1 para adicionar\n");
                        printf("mais um aluno ou 2 para voltar ao menu: ");
                        ler_texto(respostaMENU, 100);

                        if (strcmp("1", respostaMENU) == 0){

                            strcpy(respostaMENU, "ALUNOS");

                        } else if(strcmp("2", respostaMENU) == 0){

                            strcpy(respostaMENU, "MENU");

                        }
                        
                    }else{
                        strcpy(respostaMENU, "MENU");
                    }
                    limpar_entrada();

                } while (strcmp("ALUNOS", respostaMENU) == 0);

            }else if (strcmp("PROFESSORES", respostaMENU) == 0) {

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
                    i++;

                    if (i < TAM){
                        strcpy(respostaMENU, "PROFESSORES");
                    
                    }else{
                        strcpy(respostaMENU, "MENU");
                    }

                } while (strcmp("PROFESSORES", respostaMENU) == 0);

            }else if(strcmp("DISCIPLINAS", respostaMENU) == 0){

                do{

                    printf("CADASTRO DE DISCIPLINAS\n\n");

                    printf("DISCIPLINA: ");
                    ler_texto(Disciplina[i].NomedaDisciplina, 1000);
                    
                    while (!letras(Disciplina[i].NomedaDisciplina)){

                        system("cls || clear");
                        printf("Digite apenas letras e sem acentuação.\n");
                        sleep(2);
                        system("cls || clear");
                        printf("DISCIPLINA: ");
                        ler_texto(Disciplina[i].NomedaDisciplina, 1000);
                    }
                    maiusculo(Disciplina[i].NomedaDisciplina);

                    printf("SEMESTRE: ");
                    scanf("%c", &Disciplina[i].Semestre);

                    while (!isdigit(Disciplina[i].Semestre) || Disciplina[i].Semestre > '4'){

                        limpar_entrada();
                        system("cls || clear");
                        printf("inválido! Digite de 1 a 4.\n");
                        sleep(2);
                        system("cls || clear");
                        printf("SEMESTRE: ");
                        scanf("%c", &Disciplina[i].Semestre);

                    }
                    
                    limpar_entrada();
                    printf("CÓDIGO: ");
                    ler_texto(Disciplina[i].codigodaDisciplina, 9);

                    printf("PROFESSOR: ");
                    ler_texto(Disciplina[i].professor, 1000);
                    maiusculo(Disciplina[i].professor);

                    int j;
                    for (j = 0; j < TAM; j++){ 

                        if (strcmp(Disciplina[i].professor, Professor[j].NomeProfessor) != 0) {

                            system("cls || clear");
                            printf("PROFESSOR NÃO CADASTRADO!");
                            sleep(2);
                            system("cls || clear");
                            printf("PROFESSOR: ");
                            ler_texto(Disciplina[i].professor, 1000);
                        }
                        
                    }
                    i++;

                    if (i < TAM){
                        strcpy(respostaMENU, "DISCIPLINAS");
                    
                    }else{
                        strcpy(respostaMENU, "MENU");
                    }

                } while (strcmp("DISCIPLINAS", respostaMENU) == 0);

            }else if(strcmp("MENU", respostaMENU) == 0){

                    printf("1. Cadastros\n");
                    printf("2. Listas\n");
                    printf("3. Sair\n\n");
                    printf("Como deseja prosseguir? ");
                    ler_texto(respostaInicial, 100);
                    maiusculo(respostaInicial);

                    strcpy(respostaMENU, "SAIR");

            } else{

                printf("Não entendi o que você quis dizer :(");
                sleep(3);
                system("cls || clear");
                strcpy(respostaMENU, "MENU");

            }

        }

    } while (strcmp("LISTAS", respostaInicial) == 0){

        system("cls || clear");

        printf("1. Alunos ordenados por nome                       5. Professores ordenados por nome\n");
        printf("2. Alunos ordenados por sexo                       6. Professores ordenados por sexo\n");
        printf("3. Alunos por ordem de cadastro                    7. Professores por ordem de cadastro\n");
        printf("4. Alunos ordenados por data de nascimento         8. Professores ordenados por data de nascimento\n\n");

        printf("Que lista vocẽ deseja verificar? ");
        ler_texto(respostaMENU, 100);
        system("cls || clear");

        maiusculo(respostaMENU);

        while (strcmp("SAIR", respostaMENU) != 0){

            if(strcmp("ALUNOS ORDENADOS POR SEXO", respostaMENU) == 0 || strcmp("2", respostaMENU) == 0){

                printf("MASCULINO:\n\n");

                for (i = 0; i < TAM; i++){

                    if (strcmp("MASCULINO", Aluno[i].SexoAluno) == 0){
                        printf("%d. %s\n", i+1, Aluno[i].NomeAluno);
                    }
                    
                }

                printf("\nFEMININO:\n\n");

                for (i = 0; i < TAM; i++){

                    if (strcmp("FEMININO", Aluno[i].SexoAluno) == 0){
                        printf("%d. %s\n", i+1, Aluno[i].NomeAluno);
                    }
                    
                }

                getchar();
                strcpy(respostaMENU, "SAIR");

            } else if(strcmp("ALUNOS ORDENADOS POR ORDEM DE CADASTRO", respostaMENU) == 0 || strcmp("3", respostaMENU) == 0){

                printf("LISTA DE ALUNOS POR ORDEM DE CADASTRO\n\n");

                for (i = 0; i < TAM; i++){

                    printf("Nome completo: %s\n", Aluno[i].NomeAluno);
                    printf("Data de nascimento: %s\n", Aluno[i].DatadeNascimentoAluno);
                    printf("CPF: %s\n", Aluno[i].CPFAluno);
                    printf("Sexo: %s\n\n", Aluno[i].SexoAluno);
                }

                getchar();
                strcpy(respostaMENU, "SAIR");

            } else if(strcmp("PROFESSORES ORDENADOS POR ORDEM DE CADASTRO", respostaMENU) == 0 || strcmp("7", respostaMENU) == 0){

                printf("LISTA DE PROFESSORES POR ORDEM DE CADASTRO\n\n");

                for (i = 0; i < TAM; i++){

                    printf("Nome completo: %s\n", Professor[i].NomeProfessor);
                    printf("Data de nascimento: %s\n", Professor[i].DatadeNascimentoProfessor);
                    printf("CPF: %s\n", Professor[i].CPFProfessor);
                    printf("Sexo: %s\n", Professor[i].SexoProfessor);
                }

                getchar();
                strcpy(respostaMENU, "SAIR");

            }else{

                printf("Não entendi o que você quis dizer :(");
                sleep(3);
                system("cls || clear");
                strcpy(respostaMENU, "MENU");

            }

        }

    }

    return 0;
}
