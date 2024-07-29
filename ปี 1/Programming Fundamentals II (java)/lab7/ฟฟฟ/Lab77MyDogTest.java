public class Lab77MyDogTest 
{ 
    public static void main(String[] args) 
    {
        MyDog dog = new MyDog("Deang"); 
        act1(dog); //treat as CanBark
        act2(dog); //treat as CanFetch
        act3(dog); //treat as CanSwim
        act4(dog); //treat as MyDog
    }
    private static void act1(MyDog dog) 
    { 
        dog.bark();
    }
    private static void act2(MyDog dog) 
    {
        dog.fetch();
    }
    private static void act3(MyDog dog) 
    {
        dog.swim();
    }
    private static void act4(MyDog dog) 
    {
        System.out.print(dog.getName()+" is ");
        dog.bark();
    }
}