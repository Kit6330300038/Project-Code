public class InvoiceTest 
{
    public static void main(String[] args) 
    {   
        Customer living1 = new Customer("001","VigritV.1","Jidlorn");                     
        Customer living2 = new Customer("010","VigritV.2","Jidlorn");                    
        Invoice num1 = new Invoice("2256",living1);                                     
        Invoice num2 = new Invoice("1478",living2);                                   
        Invoice num3 = new Invoice("14689",new Customer("100","VigritV.3","Jidlorn"));
        Invoice num4 = new Invoice("14689",new Customer("1000","VigritV.4","Jidlorn")); 
        PlanPayment plan1 = new PlanPayment(50, 5);
        plan1.setInstallment(0,new CashPayment(10.0, 20.0));
        plan1.setInstallment(1,new CreditPayment(10.0,"88888888888"));
        plan1.setInstallment(2,new CreditPayment(10.0,"88888888888"));
        num2.setPayment(new CashPayment(50.0, 100.0));
        num3.setPayment(new CreditPayment(75.0,"111111111111"));
        num4.setPayment(plan1);
        num1.print();
        num2.print();
        num3.print();
        num4.print();
    }
}
