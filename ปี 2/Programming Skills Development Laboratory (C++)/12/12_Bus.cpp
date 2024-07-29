#include <bits/stdc++.h>
using namespace std;

int main()
{   int a,b,c,i,t,n;
    cin >> a >> b >> c;
    while(a&&b&&c)
    {   t=0;
        int arr1[a],arr2[a];
        for(i=0;i<a;i++)
        {   cin >> arr1[i];
        }for(i=0;i<a;i++)
        {   cin >> arr2[i];
        }
        n = sizeof(arr1)/sizeof(arr1[0]);
        sort(arr1, arr1+n);
        n = sizeof(arr2)/sizeof(arr2[0]);
        sort(arr2, arr2+n);
        i=0;
        while(a-i)
        {   if(arr1[i]+arr2[a-i-1]>b)
            {   t+=(arr1[i]+arr2[a-i-1]-b)*c;
            }i++;
        }
        cout << t << "\n";
        cin >> a >> b >> c;
    }
}
