public class Dog
{
    String name;
    Dog(String name) 
    {
        this.name = name;
    }
    public String getName() 
    {
        return this.name;
    }
    public void setName(String color) 
    {
        this.name = color;
    }
    public void bark() 
    {
        System.out.println("Woof Woof"); 
    }
}
