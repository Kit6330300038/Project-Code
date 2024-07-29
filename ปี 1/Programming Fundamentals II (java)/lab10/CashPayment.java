public class CashPayment extends Payment
{
    private double tendered;

    CashPayment(double amount, double tendered)
    {
        super(amount);
        this.tendered = tendered;
    }
    public double getTendered()
    {
        return this.tendered;
    }
    public double getChange()
    {
        return this.tendered - this.getAmount();
    }
    public String toString()
    {       
        return "Amount: "+ (String)(this.getAmount()+"")+" Tendered: "+(String)(this.tendered+"")
        +" Change: "+(String)(this.getChange()+"");
    }
}
