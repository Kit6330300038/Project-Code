import java.util.Scanner;

public class GraderTest
{
    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter course name: ");
        Grader sub1 = new Grader(scanner.nextLine());   //build new Grader object
        sub(sub1);                                      //call method sub
        System.out.print("Enter course name: ");        
        Grader sub2 = new Grader(scanner.nextLine());   //build new Grader object
        sub(sub2);                                      //call method sub
    }
    public static void sub(Grader sub)                  //method sub
    {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter number of students: ");
        int stu_num = scanner.nextInt();                //recive amount of all student 
        System.out.println();
        System.out.println("Input score");
        for (int i = 0; i < stu_num; i++)               //recive score of all student
        {
            sub.addScore(scanner.nextDouble());
        }
        System.out.printf("\nMean for %s = %.2f\n",sub.getCourseName(),sub.mean());
        System.out.println("Below mean = "+sub.belowMean());
        System.out.println("Above mean = "+sub.aboveMean());
        sub.showGrade();                                //call method showGrade
        System.out.println();
    }
}
