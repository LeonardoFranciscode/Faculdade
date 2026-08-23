package java_curso;

public class Bic implements Caneta {
    private String marca;
    private String cor;

    public Bic(String marca, String cor) {
        this.marca = marca;
        this.cor = cor;
    }

    @Override
    public void escrever() {
            System.out.println("Escrevendo com a caneta " + marca + " de cor " + cor);
    }

    @Override
    public void tampar() {
        System.out.println("Caneta tampada.");
    }

    @Override
    public void destampar() {
        System.out.println("Caneta destampada.");
    }

}
