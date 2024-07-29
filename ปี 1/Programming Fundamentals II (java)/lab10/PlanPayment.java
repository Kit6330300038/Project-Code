public class PlanPayment extends Payment
{
    private Payment[] payments;
    PlanPayment(double amount, int numberOfInstallments)
    {
        super(amount);
        this.payments = new Payment[numberOfInstallments];
    }
    public void setInstallment(int installment, Payment payment)
    {
        this.payments[installment] = payment;
    }
    public Payment getInstallment(int installment)
    {
        return this.payments[installment];
    }
    public String toString()
    {
        String re;
        re = "Amount: "+(String)(this.getAmount()+"")+" Installments: "+
        (String)(payments.length+"")+"\n";
        for (int i = 0; i < payments.length; i++) 
        {
            if(payments[i] != null)
            {
                re += "Installments "+i+": Amount: "+payments[i].getAmount() +
                payments[i].toString()+"\n";
            }
            
        }
        return  re;
    }
}

