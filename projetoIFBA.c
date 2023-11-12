#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define TAM 3

//FUNÇÃO PARA VERIFICAR SE A DATA ESTA NO FORMATO CORRETO.
int verificacaoData(const char *data) {
    for (int i = 0; i < 10; i++) {
        if ((i == 2 || i == 5) && data[i] != '/') {
            return 0;
        } else if ((i != 2 && i != 5) && !isdigit(data[i])) {
            return 0;
        }
    }
    return 1;
}

//FUNÇÃO PARA VERIFICAR SE O CPF ESTA NO FORMATO CORRETO.
int verificacaoCPF(const char *cpf) {
    for (int i = 0; i < 14; i++) {
        if ((i == 3 || i == 7) && cpf[i] != '.') {
            return 0;
        } else if (i == 11 && cpf[i] != '-'){
            return 0;
        } else if ((i != 2 && i != 5) && !isdigit(data[i])) {
            return 0;
        }
    }
    return 1;
}

//FUNÇÃO PARA VERIFICAR SE O NÚMERO DE MATRICULA ESTA NO FORMATO CORRETO.
int verificacaoMatricula(const char *matricula) {
    for (int i = 0; i < 10; i++) {
        if (i == 3 && matricula[i] != '.') {
            return 0;
        } else if (i != 3 && !isdigit(matricula[i])) {
            return 0;
        }
    }
    return 1;
}

//FUNÇÃO PARA TORNAR TODAS AS LETRAS DA STRING EM MAIUSCULAS.
void maiusculo(const char *string){
    int i;
    for(i = 0; string[i] != '\0'; i++){
        string[i] = toupper(string[i]);
    }
}

//FUNÇAO PARA VERIFICAR SE TODOS OS CARACTERES DA STRING SÃO LETRAS.
int letras(const char *string) {
    int i;
    for(i = 0; string[i] != '\0'; i++) {
        if(!isalpha((unsigned char)string[i]) && string[i] != ' ') {
            return 0;
        }
    }
    return 1;
}

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
    char CPFAluno[15];
    char NumerodeMatricula[11];
    char DatadeNascimentoAluno[11];
};

struct Professores{
    char NomeProfessor[1000];
    char SexoProfessor[10];
    char CPFProfessor[15];
    char NumerodeMatricula[11]
    char DatadeNascimentoProfessor[11];
};

struct Disciplinas{
    char NomedaDisciplina[1000];
    int codigodaDisciplina;
    int Semestre;
    char professor[1000];
};

int main () {
    
    setlocale(LC_ALL, "portuguese");

    char respostaMENU[100];
    char resposta;
    int i = 0;

    struct Alunos Aluno[TAM];
    struct Professores Professor[TAM];
    struct Disciplinas Disciplina[TAM];

    system("cls || clear");
    printf("  Listas | Cadastros\n\n");

    printf("Como deseja prosseguir? ");
    ler_texto(respostaMENU, 100);
    system("cls || clear");

    maiusculo(respostaMENU);

            if (strcmp("CADASTROS", respostaMENU) == 0){

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
                    
                    while(!letras(Aluno[i].NomeAluno)){
                        
                        system("cls || clear");
                        printf("Digite apenas letras e sem acentuação.\n");
                        sleep(2);
                        printf("NOME COMPLETO: ");
                        ler_texto(Aluno[i].NomeAluno, 1000);
                        
                    }
                    maiusculo(Aluno[i].NomeAluno);

                    printf("SEXO: ");
                    ler_texto(Aluno[i].SexoAluno, 10);

                    maiusculo(Aluno[i].SexoAluno);
                    while(strcmp("MASCULINO", Aluno[i].SexoAluno) != 0 && strcmp("FEMININO", Aluno[i].SexoAluno) != 0){

                        system("cls || clear");
                        printf("Opção invalida! Tente novamente:\n");
                        ler_texto(Aluno[i].SexoAluno, 10);
                        system("cls || clear");
                    
                    }
                    
                    limpar_entrada();
                    printf("DATA DE NASCIMENTO: ");
                    ler_texto(Aluno[i].DatadeNascimentoAluno, 11);
                    
                    while(!verificacaoData(Aluno[i].DatadeNascimentoAluno)){
                        
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
                        limpar_entrada();
                        printf("CPF: ");
                        ler_texto(Aluno[i].CPFAluno, 15);
                        
                    }

                    limpar_entrada();
                    printf("Número de matrícula: ");
                    ler_texto(Aluno[i].NumerodeMatricula, 11);
                    system("cls || clear");
                    
                    while(!verificacaoMatricula(Aluno[i].NumerodeMatricula)){
                        
                        printf("inválido! O número de matrícula deve estar no formato 000.000000.\n");
                        sleep(2);
                        system("cls || clear");
                        printf("Número de matrícula: ");
                        ler_texto(Aluno[i].NumerodeMatricula, 11);
                        
                    }
                    i++;

                    if (i < TAM){

                        limpar_entrada();
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
                    
                    limpar_entrada();
                    printf("NOME COMPLETO: ");
                    ler_texto(Professor[i].NomeProfessor, 1000);

                    limpar_entrada();
                    printf("SEXO: ");
                    ler_texto(Professor[i].SexoProfessor, 10);

                    maiusculo(Professor[i].SexoProfessor);
                    while(strcmp("MASCULINO", Professor[i].SexoProfessor) != 0 && strcmp("FEMININO", Professor[i].SexoProfessor) != 0){

                        system("cls || clear");
                        printf("Opção invalida! Tente novamente:\n");
                        ler_texto(Professor[i].SexoProfessor, 10);
                        system("cls || clear");
                    
                    }

                    limpar_entrada();
                    printf("DATA DE NASCIMENTO: ");
                    ler_texto(Professor[i].DatadeNascimentoProfessor, 11);
                    
                    while(!verificacaoData(Professor[i].DatadeNascimentoProfessor)){
                        
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
                    
                    while(!verificacaoMatricula(Professor[i].NumerodeMatricula)){
                        
                        printf("inválido! O número de matrícula deve estar no formato 000.000000.\n");
                        sleep(2);
                        system("cls || clear");
                        printf("Número de matrícula: ");
                        ler_texto(Professor[i].NumerodeMatricula, 11);
                        
                    }
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

                limpar_entrada();
                printf("Opção invalida! aperte a tecla 1 se deseja adicionar\n");
                printf("um aluno, 2 para um professor, 3 para adicionar uma\n");
                printf("disciplina ou 0 para encerrar: ");
                scanf("%c", &resposta);
                system("cls || clear");
                
            }
        }
    }

    return 0;
}
