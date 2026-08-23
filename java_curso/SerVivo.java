package java_curso;

public abstract class SerVivo {
    protected String idade;

    public SerVivo(String idade) {
        this.idade = idade;
    }


    public abstract void respirar();

    public abstract void comer();

}
