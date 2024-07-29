public class AccountTest 
{
    public static void main(String[] args) 
    {
        System.out.println("#1 BankAccount1");
        BankAccount obj1 = new BankAccount("Bob","55879", 101.5);
        System.out.println("NAMR: "+obj1.getCustomerName());
        System.out.println("ADDR: "+obj1.getAccountNumber());
        System.out.println("BALANCE: "+obj1.getBalance());
        System.out.println();
        System.out.println("#2 BankAccount2");
        BankAccount obj2 = new BankAccount("Mary","48537", 100824.5);
        System.out.println("NAMR: "+obj2.getCustomerName());
        System.out.println("ADDR: "+obj2.getAccountNumber());
        System.out.println("BALANCE: "+obj2.getBalance());
        System.out.println();
        System.out.println("#3  CheckingAccount1");
        CheckingAccount obj3 = new  CheckingAccount("Jane", "25837",1253, 15);
        System.out.println("NAMR: "+obj3.getCustomerName());
        System.out.println("ADDR: "+obj3.getAccountNumber());
        System.out.println("BALANCE: "+obj3.getBalance());
        System.out.println("FEE: "+obj3.getOverdraftFee());
        System.out.println();
        System.out.println("#4  CheckingAccount2");
        CheckingAccount obj4 = new  CheckingAccount("Max", "52428",12.251523,0.0007);
        System.out.println("NAMR: "+obj4.getCustomerName());
        System.out.println("ADDR: "+obj4.getAccountNumber());
        System.out.println("BALANCE: "+obj4.getBalance());
        System.out.printf("FEE: %.4f",obj4.getOverdraftFee());
        System.out.println();
        System.out.println();
        System.out.println("Choose Account: "+obj4.accountNumber);
        System.out.println("Choose Action (1. Withdraw 2. Deposit) : 1");
        System.out.println("Value: 1.123");
        obj4.withdraw(1.123);
        System.out.println();
        System.out.println("Choose Account: "+obj1.accountNumber);
        System.out.println("Choose Action (1. Withdraw 2. Deposit) : 1");
        System.out.println("Value: 1100");
        obj4.withdraw(1100);
        System.out.println();
        System.out.println("Choose Account: "+obj4.accountNumber);
        System.out.println("Choose Action (1. Withdraw 2. Deposit) : 2");
        System.out.println("Value: 0.01");
        obj4.deposit(0.01);;
    }
}
