public class BinarySearch
{
    public static void main(String[] args) 
    {
        int[] a = new int[]{1,2,4,5,7,8,11,13};
        int[] b = new int[]{5,13,10};
        int i ,j, mid;

        for (int k =0; k<b.length ; k++){
            i = 0;
            j = a.length;
            while ( i<j )
            {
                mid = (i+j)/2;
                if( b[k] < a[mid])
                {
                    j=mid;
                }
                else if( b[k] > a[mid])
                {
                    i=mid+1;
                }
                else
                {
                    System.out.println(mid);
                    break;
                }
                
            }
            mid = (i+j)/2;
            if( b[k] != a[mid])
            {
                System.out.println("None");
            }
        }
    }    
}