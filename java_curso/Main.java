/* package java_curso;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);

        Conta c1 = new Conta("Alayne", 0);

        while (true){
            System.out.println("+=+=+=+=+=+=+=MENU+=+=+=+=+=+=++");
            System.out.println("[1] Depositar\n[2] Sacar\n[3] Mostrar saldo\n[4] Sair");
            
            int escolha = scan.nextInt();

            if (escolha == 1){
                System.out.println("Digite o valor a ser depositado: \nR$");
                double valor = scan.nextDouble();
                c1.depositar(valor);
                System.out.println("\n");

            } else if (escolha == 2){
                System.out.println("Digite o valor a ser sacado: \nR$");
                double valor = scan.nextDouble();
                c1.sacar(valor);
                System.out.println("\n");

            } else if (escolha == 3){
                c1.mostrarSaldo();
                System.out.println("\n");
            
            } else if (escolha == 4){
                System.out.println("Obrigado! Volte sempre :)");
                break;
            
            } else {
                System.out.println("Opção inválida!");
            }
            
        }
        
        

        
}
} */
