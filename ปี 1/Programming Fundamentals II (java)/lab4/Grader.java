import java.util.ArrayList;

public class Grader
{
    private String name;
    private ArrayList<Double> score = new ArrayList<Double>();
    public Grader(String name) 
    {
        this.name = name;
    }
    public void addScore(double score) 
    {
        this.score.add(score);
    }
    public int countStudent()
    {
        return (int) (this.score.size());               //return amount of student
    }
    public Double mean()
    {
        double mean = 0;
        for (int i = 0; i < this.score.size(); i++) 
        {
            mean = mean + this.score.get(i);            //find the sum of all score
        }
        return (Double) (mean/countStudent());          //return mean
    }
    public int belowMean()
    {
        Double mean = mean();                           //call method mean
        int countbelow = 0;
        for (int i = 0; i < this.score.size(); i++) 
        {
            if (this.score.get(i) < mean)               //find amount of score that less than mean
            {
                countbelow++;
            }
        }
        return (int) (countbelow);
    }
    public int aboveMean()
    {
        Double mean = mean();                           //call method mean
        int countabove = 0;
        for (int i = 0; i < this.score.size(); i++) 
        {
            if (this.score.get(i) > mean)               //find amount of score that more than mean
            {
                countabove++;
            }
        }
        return (int) (countabove);
    }
    public void showGrade()                             //method showGrade
    {
        int better = 0, count;
        Double[] score = {80.0,75.0,70.0,65.0,60.0,55.0,50.0,0.0};
        String[] grade = {"A ",", B+ ",", B ",", C+ ",", C ",", D+ ",", D ",", F "};
        System.out.print("Grade : ");
        for (int i = 0; i < grade.length; i++) 
        {
            count = 0;
            for (int j = 0; j < this.score.size(); j++) 
            {
                if (score[i]<=this.score.get(j))        //count the amount of score that more than criterion
                {
                    count++;
                }
            }
            System.out.print(grade[i] + (count-better));
            better = better+(count-better);
            
        } 
        System.out.println();
        System.out.println("####################");
    }
    public String getCourseName()
    {
        return (String) (this.name);                    //return subject name
    }
}