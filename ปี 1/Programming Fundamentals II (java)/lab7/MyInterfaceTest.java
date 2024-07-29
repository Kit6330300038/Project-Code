public class MyInterfaceTest 
{
    public static void main(String[] args) 
    { 
        MyInterface aaa1 = new Lab71();
        aaa1.m1();
        MyInterface aaa2 = new Lab72();
        aaa2.m1();
        InterfaceTest74 aaa3 = new InterfaceTest74();
        aaa3.m2();
        aaa3.m1();
        InterfaceTest75 aaa4 = new InterfaceTest75();
        aaa4.m2();
        InterfaceTest76 aaa5 = new InterfaceTest76();
        aaa5.m1();
    } 
}
class InterfaceTest74 extends Lab74
{
}
class InterfaceTest75 extends Lab75
{
    public void m1(){}
}
class InterfaceTest76 extends Lab76
{
}