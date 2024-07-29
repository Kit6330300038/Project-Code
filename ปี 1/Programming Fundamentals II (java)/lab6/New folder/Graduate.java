public class Graduate extends Student
{
    public Graduate(int score) 
    {
        super(score);
    }
    @Override
    public String calculateGrade()
    {
        int score = getScore(); 
        if(score >= 70)
        {
            return "PASS";
        }
        else
        {
             return "FALL";
        }
        
    }
}
