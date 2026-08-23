package java_curso;

public class Main {
    public static void main(String[] args) {
        Caneta caneta1 = new Bic("Bic", "azul");
        Caneta caneta2 = new Bic("Bic", "vermelha");

        SerVivo pessoa = new Humano();

        caneta1.destampar();
        caneta2.destampar();

        caneta1.escrever();
        caneta2.escrever();

        pessoa.respirar();
        pessoa.comer();
    }

}
