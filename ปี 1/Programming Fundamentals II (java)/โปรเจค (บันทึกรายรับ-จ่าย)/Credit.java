// กฤษณพงษ์ เพ็งบุญ 6330300038
public class Credit extends Money
{
    private String card_num;
    Credit(double total,String note,String card_num)
    {
        super(total, note);
        this.card_num = card_num;
    }
    public String getcardnum() 
    {
        return this.card_num;    
    }
}
