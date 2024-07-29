import java.util.ArrayList;
public class RemoveThirds
{
    public static void main(String[] args) 
    {
        int i;
        ArrayList<Integer> a = new ArrayList<Integer>();
        a.add(1);
        a.add(2);
        a.add(3);
        a.add(2);
        a.add(5);
        a.add(3);
        a.add(1);
        a.add(3);
        a.add(9);
        for (i=0 ; i<a.size() ; i++)
        {
            if ( a.get(i)%3 == 0)
            {
                a.remove(i);
                i--;
            }
        }
        System.out.println(a);
    }    
}

