// กฤษณพงษ์ เพ็งบุญ 6330300038
public class Money 
{
    private double total;
    private String note;
    Money(double total, String note)
    {
        this.total = total;
        this.note = note;
    }     
    public double gettotal() 
    {
        return this.total;    
    }
    public String getnote() 
    {
        return this.note;
    }
    public String getcardnum() 
    {
        return "";    
    }
}