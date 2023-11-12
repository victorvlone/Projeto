#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define TAM 3

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

void maiusculo(const char *string){
    int i;
    for(i = 0; string[i] != '\0'; i++){
        string[i] = toupper(string[i]);
    }
}

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
    char CPFAluno[12];
    char NumerodeMatricula[10];
    char DatadeNascimentoAluno[9];
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

                    Aluno[i].SexoAluno[0] = toupper(Aluno[i].SexoAluno[0]);
                    while(strcmp("MASCULINO", Aluno[i].SexoAluno) != 0 && strcmp("FEMININO", Aluno[i].SexoAluno) != 0){

                        system("cls || clear");
                        printf("Opção invalida! Tente novamente:\n");
                        ler_texto(Aluno[i].SexoAluno, 10);
                        system("cls || clear");
                    
                    }
                    
                    limpar_entrada();
                    printf("DATA DE NASCIMENTO: ");
                    ler_texto(Aluno[i].DatadeNascimentoAluno, 9);
                    
                    while(!Numeros(Aluno[i].DatadeNascimentoAluno)){
                        
                        system("cls || clear");
                        printf("Digite apenas números.\n");
                        sleep(2);
                        system("cls || clear");
                        printf("DATA DE NASCIMENTO: ");
                        ler_texto(Aluno[i].DatadeNascimentoAluno, 9);
                    }
                    
                    limpar_entrada();
                    printf("CPF: ");
                    ler_texto(Aluno[i].CPFAluno, 12);
                    
                    
                    
                    while (!Numeros(Aluno[i].CPFAluno)){
                       
                        system("cls || clear");
                        printf("CPF invalido! Digite apenas números.\n");
                        sleep(2);
                        system("cls || clear");
                        limpar_entrada();
                        printf("CPF: ");
                        ler_texto(Aluno[i].CPFAluno, 12);
                        
                    }

                    limpar_entrada();
                    printf("Número de matrícula: ");
                    ler_texto(Aluno[i].NumerodeMatricula, 10);
                    system("cls || clear");
                    
                   
                    
                    while(!Numeros(Aluno[i].NumerodeMatricula)){
                        
                        printf("Apenas números.\n");
                        sleep(2);
                        system("cls || clear");
                        printf("Número de matrícula: ");
                        ler_texto(Aluno[i].NumerodeMatricula, 10);
                        
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
