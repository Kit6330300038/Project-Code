class MyDog extends Dog implements CanBark,CanFetch,CanSwim 
{
    MyDog(String name)
    {
        super(name);
    }
    public void swim() 
    {
        System.out.printf("%s is swiming.\n", super.getName());
    }
    public void fetch() 
    {
        System.out.printf("%s is fetching.\n", super.getName());
    }
}
