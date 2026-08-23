package java_curso;

public class Humano extends SerVivo{

    public Humano() {
        super("30 anos");
    }
    
    @Override
    public void respirar() {
        System.out.println("Humano respirando...");
    }

    @Override
    public void comer() {
        System.out.println("Humano comendo...");
    }

}
