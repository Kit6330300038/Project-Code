import java.util.ArrayList;
public class Invoice 
{
    private String id ;
    private Customer customer;
    private ArrayList <LineItem> items = new ArrayList<LineItem>();
    private Payment payment;
    Invoice(String id, Customer customer)
    {
        this.id = id;
        this.customer = customer;
    }
    public void addItem(Product product, int quantity)
    {
        this.items.add(new LineItem(product, quantity));
    }
    public String getId()
    {
        return this.id;
    }
    public Customer getCustomer()
    {
        return this.customer;
    }
    public LineItem getLineItem(int i)
    {
        return this.items.get(i);
    }
    public double getTotalPrice()
    {
        Double price= 0.0;
        for (int i = 0; i < items.size(); i++) 
        {
            price = items.get(i).getTotalPrice();
        };
        return price;
    }
    public void print()        
    {
        System.out.println("INVOICE : #"+this.id);
        System.out.println("CUSTOMER : "+this.customer.getFirstName());
        System.out.println();
        System.out.println("ITEMS:");
        double total = 0.0;
        for (int i = 0; i < this.items.size(); i++) 
        {
            total += this.items.get(i).getTotalPrice();
            System.out.println((1+i)+". " + this.items.get(i).getProduct().getName() + " x "
            + this.items.get(i).getQuantity() + " = " + this.items.get(i).getTotalPrice());
        }
        System.out.println("TOTAL: " + total);
        if (this.payment != null) 
        {
            System.out.println(this.payment.toString()); 
        }
        else
        {
            
        }
        System.out.println("==========================");
        System.out.println();
    }
    public void setPayment(Payment payment)
    {
        this.payment = payment;
    }
    public Payment getPayment()
    {
        return this.payment;
    }
}