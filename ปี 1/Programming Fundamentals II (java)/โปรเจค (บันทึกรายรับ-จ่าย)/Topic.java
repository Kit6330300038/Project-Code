// กฤษณพงษ์ เพ็งบุญ 6330300038
import java.util.ArrayList;
class Topic
{
    private String topic;
    private ArrayList<Money> list = new ArrayList<Money>();
    Topic(String topic)
    {
        this.topic = topic;
    } 
    public void addincome(Money a) 
    {
        this.list.add(a);
    }
    public int getlistlenght() 
    {
        return this.list.size();    
    }
    public String gettopic() 
    {
        return this.topic;
    }
    public Money getmoney(int i) 
    {
        return this.list.get(i);
    }
    public double allincome() 
    {
        double allin = 0;
        for (int i = 0; i < this.list.size(); i++) 
        {
            allin += this.getmoney(i).gettotal();
        }
        return allin;
    }
    // ข้อ 1 เพิ่ม method ตรงนี้
}