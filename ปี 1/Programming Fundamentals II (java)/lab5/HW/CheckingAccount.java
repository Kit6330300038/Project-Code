class CheckingAccount extends BankAccount
{
    protected double overdraftFee ;
    public CheckingAccount(String customerName, String accountNumber, double balance, double overdraftFee)
    {
        super(customerName, accountNumber, balance);
        this.overdraftFee = overdraftFee;
    }
    public double getOverdraftFee()
    {
        return(this.overdraftFee);
    }
    public void setOverdraftFee(double fee)
    {
        this.overdraftFee = fee;
    }
    public void withdraw(double amount)
    {
        if (this.balance >= amount)
        {
            System.out.println("Withdraw Complete!!");
            this.balance = this.balance-this.overdraftFee-amount;
            System.out.println(this.accountNumber+" Max Withdraw "+amount+" Fee "+this.overdraftFee+" balance "+this.balance);
            System.out.println("########");
        }
        else 
        {
            System.out.println("Withdraw Fail!!");
            System.out.println("########");
        }
    }
    // Method นี้จะต้องน ำค่ำธรรมเนียมมำประกอบกำรค ำนวณ ให้ยอดโอน + ค่ำธรรมเนียม ต้องมีเพียงพอที่
    // สำมำรถถอนเงินออกจำกบัญชีได้ ถ้ำมีไม่เพียงพอจะต้องมีกำรแจ้งเตือน
    
}
