package java_curso;
import java.util.Scanner;

public class Idade {

        public static void main(String[] args) {
            Scanner scan = new Scanner(System.in);
        
            while (true) {
                try{
                    System.out.println("Digite sua idade: ");
                    int idade = scan.nextInt();
                    cadastrarPessoa(idade);
                } catch (IllegalArgumentException e){
                    System.out.println(e.getMessage());
                    System.out.println("Tente novamente:");
                    continue;
                }
                break;
            }
            
    }

    public static void cadastrarPessoa(int idade){
        if (idade < 0){
            throw new IllegalArgumentException("Idade inválida");
        } else {
            System.out.println("Pessoa cadastrada com sucesso.");
        }
    }
}
