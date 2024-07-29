import java.util.Random;
public class Main
{
    public static void main(String[] args)
    {
        Random random = new Random();
        double a = 0.0 + 50.0 *random.nextDouble();
        double b = 0.0 + 50.0 *random.nextDouble();
        double c = a + b;
        System.out.println("Sum of " + a + " + " + b + " = " + c);
        if (c <= 50){
            System.out.println("Value = Not PASS");
        }else{
            System.out.println("Value = PASS");
        }

    }
}
