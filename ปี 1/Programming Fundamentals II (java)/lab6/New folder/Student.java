public abstract class Student 
{ 
private int score; 
public Student(int score) 
{
this.setScore(score);
}
// Getter/Setter Score 
public int getScore() 
{
return score;
}
public void setScore(int score) 
{
this.score = score;
}
// Abstract Method 
public abstract String calculateGrade(); 
} 