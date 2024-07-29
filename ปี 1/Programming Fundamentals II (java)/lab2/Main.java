import java.util.*;
public class Main
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        String a ;
        int b,c,d,e,income ;
        System.out.print("Enter salary: ");
        b = input.nextInt();
        System.out.print("Enter Year cost: ");
        c = input.nextInt();
        System.out.print("Enter Tax deduction: ");
        d = input.nextInt();
        System.out.println();
        System.out.print("You have orther income?: ");
        a = input.next();
        System.out.println();
        income = (b*12)-(c+d);
        char o = a.charAt(0);
        if(o != 'N')
            {
            System.out.print("Enter orther income? :");
            e = input.nextInt();
            income = income + e;
            System.out.println("Income : ("+b+"x12) - "+c+" - "+d+" + "+e+" = "+income);
            }
        else
            {
            System.out.println("Income : ("+b+"x12) - "+c+" - "+d+" = "+income);
            }
        if(income <= 150000)
            {
            System.out.println("Tax is 0 %");
            System.out.println("Your tax = free Tax");
            }
        else if (income <=  300000) 
            {
            System.out.println("Tax is 5 %");
            System.out.println("Cal Tax " + income+" - 150000 = "+(income-150000)+" * 5% = "+(int)((income-150000)*0.05));
            System.out.println("Your tax = "+(int)((income-150000)*0.05));
            } 
        else if (income <=  500000) 
            {
            System.out.println("Tax is 10 %");
            System.out.println("Step 2");
            System.out.println("Cal Tax " + income+" - 300000 = "+(income-300000)+" * 10% = "+(int)((income-300000)*0.10));
            System.out.println("Step 1");
            System.out.println("Cal Tax 150000 * 5% = "+(int)(150000*0.05));
            System.out.println("Your tax = "+(int)((income-300000)*0.1+7500));
            } 
        else if (income <=  750000) 
            {
            System.out.println("Tax is 15 %");
            System.out.println("Step 3");
            System.out.println("Cal Tax " + income+" - 500000 = "+(income-500000)+" * 15% = "+(int)((income-500000)*0.15));
            System.out.println("Step 2");
            System.out.println("Cal Tax 150000 * 10% = "+(int)(150000*0.1));
            System.out.println("Step 1");
            System.out.println("Cal Tax 150000 * 5% = "+(int)(150000*0.05));
            System.out.println("Your tax = "+(int)((income-500000)*0.15+7500+15000));
            } 
        else if (income <=  1000000) 
            {
            System.out.println("Tax is 20 %");
            System.out.println("Step 4");
            System.out.println("Cal Tax " + income+" - 750000 = "+(income-750000)+" * 20% = "+(int)((income-750000)*0.20));
            System.out.println("Step 3");
            System.out.println("Cal Tax 200000 * 15% = "+(int)(200000*0.15));
            System.out.println("Step 2");
            System.out.println("Cal Tax 150000 * 10% = "+(int)(150000*0.10));
            System.out.println("Step 1");
            System.out.println("Cal Tax 150000 * 5% = "+(int)(150000*0.05));
            System.out.println("Your tax = "+(int)((income-750000)*0.20+7500+15000+30000));
            } 
        else if (income <=  2000000) 
            {
            System.out.println("Tax is 25 %");
            System.out.println("Step 5");
            System.out.println("Cal Tax " + income+" - 1000000 = "+(income-1000000)+" * 25% = "+(int)((income-1000000)*0.25));
            System.out.println("Step 4");
            System.out.println("Cal Tax 250000 * 20% = "+(int)(250000*0.20));
            System.out.println("Step 3");
            System.out.println("Cal Tax 200000 * 15% = "+(int)(200000*0.15));
            System.out.println("Step 2");
            System.out.println("Cal Tax 150000 * 10% = "+(int)(150000*0.10));
            System.out.println("Step 1");
            System.out.println("Cal Tax 150000 * 5% = "+(int)(150000*0.05));
            System.out.println("Your tax = "+(int)((income-1000000)*0.25+7500+15000+30000+50000));
            } 
        else if (income <=  5000000) 
            {
            System.out.println("Tax is 30 %");
            System.out.println("Step 6");
            System.out.println("Cal Tax " + income+" - 2000000 = "+(income-2000000)+" * 30% = "+(int)((income-2000000)*0.30));
            System.out.println("Step 5");
            System.out.println("Cal Tax 250000 * 25% = "+(int)(250000*0.25));
            System.out.println("Step 4");
            System.out.println("Cal Tax 250000 * 20% = "+(int)(250000*0.20));
            System.out.println("Step 3");
            System.out.println("Cal Tax 200000 * 15% = "+(int)(200000*0.15));
            System.out.println("Step 2");
            System.out.println("Cal Tax 150000 * 10% = "+(int)(150000*0.10));
            System.out.println("Step 1");
            System.out.println("Cal Tax 150000 * 5% = "+(int)(150000*0.05));
            System.out.println("Your tax = "+(int)((income-2000000)*0.30+7500+15000+30000+50000+62500));
            } 
        else
            {
            System.out.println("Tax is 35 %");
            System.out.println("Step 7");
            System.out.println("Cal Tax " + income+" - 5000000 = "+(income-5000000)+" * 35% = "+(int)((income-5000000)*0.35));
            System.out.println("Step 6");
            System.out.println("Cal Tax 300000 * 30% = "+(int)(300000*0.30));
            System.out.println("Step 5");
            System.out.println("Cal Tax 250000 * 25% = "+(int)(250000*0.25));
            System.out.println("Step 4");
            System.out.println("Cal Tax 250000 * 20% = "+(int)(250000*0.20));
            System.out.println("Step 3");
            System.out.println("Cal Tax 200000 * 15% = "+(int)(200000*0.15));
            System.out.println("Step 2");
            System.out.println("Cal Tax 150000 * 10% = "+(int)(150000*0.10));
            System.out.println("Step 1");
            System.out.println("Cal Tax 150000 * 5% = "+(int)(150000*0.05));
            System.out.println("Your tax = "+(int)((income-5000000)*0.35+7500+15000+30000+50000+62500+90000));
            } 
    }
}
