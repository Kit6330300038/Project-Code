public abstract class Payment 
{
    private double amount;
    public Payment(double amount) 
    {
        if (amount < 0)
        {
            this.amount = 0;
        }
        else
        {
            this.amount = amount;
        }
    }
    public double getAmount() 
    {
        return this.amount;    
    }
}
