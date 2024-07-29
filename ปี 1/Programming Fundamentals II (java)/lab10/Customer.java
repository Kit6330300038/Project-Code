public class Customer 
{
    private String id ,firstName , lastName;
    Customer(String id, String firstName, String lastName)
    {
        this.firstName = firstName;
        this.lastName = lastName;
        this.id = id;
    }
    public String getId() 
    {
        return this.id;
    }
    public String getFirstName()
    {
        return this.firstName;
    }
    public String getLastName()
    {
        return this.lastName;
    }
}
