class BankAccount 
{
    protected String customerName, accountNumber;
    protected Double balance;
    BankAccount (String customerName, String accountNumber, double balance) 
    {
        this.customerName = customerName;
        this.accountNumber = accountNumber;
        this.balance = balance;
    }
    public String getCustomerName()
    {
        return (this.customerName);
    }
    public void setCustomerName(String name)
    {
        this.customerName = name;
    }
    public String getAccountNumber()
    {
        return (this.accountNumber);
    }
    public void setAccountNumber(String number)
    {
        this.accountNumber = number;
    }
    public double getBalance()
    {
        return (this.balance);
    }
    public void setBalance(double b)
    {
        this.balance = b;
    }
    public void withdraw(double amount)
    {
        if (this.balance >= amount)
        {
            System.out.println("Withdraw Complete!!");
            this.balance = this.balance+amount;
            System.out.println(accountNumber + " Max Withdraw " + amount );
            System.out.println("########");
        }
        else 
        {
            System.out.println("Withdraw Fail!!");
            System.out.println("########");
        }
    }
    public void deposit(double amount)
    {
        if (amount > 0.0)
        {
            System.out.println("Deposit Complete!!");
            this.balance = this.balance+amount;
            System.out.println(accountNumber + " Max Deposit " + amount +" Balance "+this.balance);
            System.out.println("########");
        }
        else
        {
            System.out.println("Deposit Fail!!");
            System.out.println("########");
        }
    }
}
