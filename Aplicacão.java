package Escola.main;

import java.util.Scanner;
import Escola.util.Alunos;
import Escola.util.Professores;

public class Aplicacão {
    public static void main(String[] args){

        Scanner scanner = new Scanner(System.in);
        Alunos[] alunos = new Alunos[40];
        Professores professores;

        int i = 0;

        System.out.print("Professores | Alunos | Disciplinas | Sair\n\n");

        System.out.print("O que deseja cadastrar primeiro? ");
        String respostaMENU = scanner.nextLine();
        respostaMENU = respostaMENU.toUpperCase();

        while (!respostaMENU.equals("SAIR")) {
            
            if (respostaMENU.equals("ALUNOS")) {
                
                do {

                    System.out.println("CADASTRO DE ALUNOS\n\n");

                    System.out.print("NOME COMPLETO: ");
                    String nome = scanner.nextLine();
                    nome = nome.toUpperCase();

                    while (numeros(nome)) {
                        System.out.print("Digite apenas letras: ");
                        nome = scanner.nextLine();
                        nome = nome.toUpperCase();
                    }

                    System.out.print("SEXO: ");
                    String sexo = scanner.nextLine();
                    sexo = sexo.toUpperCase();

                    while (!respostaMENU.equals("MASCULINO") && !respostaMENU.equals("FEMININO")) {                     
                        System.out.print("Opção invalida! Tente novamente: ");
                        sexo = scanner.nextLine();
                        sexo = sexo.toUpperCase();
                    }

                    System.out.print("DATA DE NASCIMENTO: ");
                    String datadeNascimento = scanner.nextLine();

                    while (datadeNascimento.length() != 8) {
                        System.out.println("Digite apenas números: ");
                        datadeNascimento = scanner.nextLine();
                    }

                    System.out.print("CPF: ");
                    String cpf = scanner.nextLine();

                    while (cpf.length() != 11) {
                        System.out.println("Digite apenas números: ");
                        cpf = scanner.nextLine();
                    }

                    System.out.print("NÚMERO DE MATRÍCULA: ");
                    String numerodeMatricula = scanner.nextLine();

                    while (numerodeMatricula.length() != 9) {
                        System.out.println("Digite apenas números: ");
                        numerodeMatricula = scanner.nextLine();
                    }

                    i++;

                    if (i < 40) {
                        
                        alunos[i] = new Alunos(nome, sexo, datadeNascimento, cpf, numerodeMatricula);

                        System.out.println("Digite a tecla 1 para adicionar mais\n");
                        System.out.println("um aluno, ou 2 para vvoltar ao menu: ");
                        respostaMENU = scanner.nextLine();

                        if (respostaMENU.equals("1")) {

                            respostaMENU = "ALUNOS";

                        } else if (respostaMENU.equals("2")) {

                            respostaMENU = "MENU";
                        }
                        
                    } else {

                        System.out.println("Limite de alunos atingido. Voltando para o MENU.");
                        respostaMENU = "MENU";
                        
                    }
                    
                } while (respostaMENU.equals("ALUNOS"));

            } else if (respostaMENU.equals("PROFESSORES")) {

                do {

                    System.out.println("CADASTRO DE PROFESSORES\n\n");

                    System.out.print("NOME COMPLETO: ");
                    String nome = scanner.nextLine();
                    System.out.print("SEXO: ");
                    String sexo = scanner.nextLine();
                    System.out.print("DATA DE NASCIMENTO: ");
                    String datadeNascimento = scanner.nextLine();
                    System.out.print("CPF: ");
                    String cpf = scanner.nextLine();
                    System.out.print("NÚMERO DE INSCRIÇÃO: ");
                    String numerodeInscricao = scanner.nextLine();
                    
                } while (respostaMENU.equals("PROFESSORES"));

            } else if (respostaMENU.equals("DISCIPLINAS")){

                do {
                    
                    System.out.println("CADASTRO DE DISCIPLINAS\n\n");

                    System.out.println("DISCIPLINA: ");
                    System.out.println("SEMESTRE: ");
                    System.out.println("CÓDIGO: ");
                    System.out.println("PROFESSOR: ");

                } while (respostaMENU.equals("DISCIPLINAS"));
                
            }
        }

        scanner.close();
    }

    public static boolean numeros(String str){
        for(char caracteres : str.toCharArray()){
            if(Character.isDigit(caracteres)){
                return true;
            }
        }
        return false;
    }

    public static boolean letras(String str){
        for(char caracteres : str.toCharArray()){
            if(Character.isAlphabetic(caracteres)){
                return true;
            }
        }
        return false;
    }
}
