#include <bits/stdc++.h>
using namespace std;

int main()
{
    while(1)
    {
        int arr[2],a,limit,b=1,i;
        for(i=0;i<2;i++)
        {
            cin >> arr[i];
        }
        if(arr[0]==0||arr[1]==0)
        {
            break;
        }
        limit = arr[1];
        for(i=0;i<arr[0];i++)
        {
            cin >> a;
            if(a <= limit)
            {
                limit -= a;
            }
            else
            {
                b++;
                limit = arr[1]-a;
            }
        }
        cout << b << "\n";
    }
    return 0;
}
