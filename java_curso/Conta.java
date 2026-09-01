/* package java_curso;

public class Conta {
    private String titular;
    private double saldo;
    
    public Conta(String titular, double saldo){
        this.titular = titular;
        this.saldo = saldo;
    }

    public void depositar(double valor){
        if (valor > 0){
            this.saldo += valor;
            System.out.println("Depósito efetuado com sucesso.\n(+)R$" + valor);

        } else {
            System.out.println("Valor inválido. Tente Novamente");
        }
    }

    public void sacar(double valor){
        if (valor > 0 && valor <= this.saldo){
            this.saldo -= valor;
            System.out.println("Saque de R$" + valor + " realizado com sucesso.");

        } else if (valor > this.saldo) {
            System.out.println("Saldo insuficiente.");
        } else {
            System.out.println("Valor inválido. Tente novamente");
        }
    }

    public void mostrarSaldo(){
        System.out.println("SALDO ATUAL: R$" + this.saldo);
    }

} */
