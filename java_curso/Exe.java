package java_curso;

public class Exe {

    public void main(String[] args) {
        ContaBancaria conta1 = new ContaBancaria("Alayne", 500000);

        conta1.mostrarSaldo();
        conta1.sacar(350000);
        conta1.mostrarSaldo();
        conta1.depositar(30000);
        conta1.mostrarSaldo();
        conta1.sacar(200000);
        conta1.depositar(20000);
        conta1.mostrarSaldo();
    }

    public class ContaBancaria{
        String titular;
        int saldo;

        public ContaBancaria(String titular, int saldo){
            this.titular = titular;
            this.saldo = saldo;
        }

        public void depositar(int deposito){
            this.saldo += deposito;
        }

        public void sacar(int saque){
            if (saque > this.saldo){
                System.out.println("Saldo insuficiente! Valor em conta: R$" + this.saldo);
            } else{
                this.saldo -= saque;
            }
        }

        public void mostrarSaldo(){
            System.out.println("SALDO ATUAL: R$" + this.saldo);
        }
    }
    
}

