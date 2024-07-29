#include <bits/stdc++.h>
using namespace std;

int main()
{   int a,b,i,j,n,c=0;
    cin >> a >> b;
    int arr1[a],arr2[b];
    for(i=0;i<a;i++)
    {   cin >> arr1[i];
    }for(i=0;i<b;i++)
    {   cin >> arr2[i];
    }
    n = sizeof(arr1)/sizeof(arr1[0]);
    sort(arr1, arr1+n);
    n = sizeof(arr2)/sizeof(arr2[0]);
    sort(arr2, arr2+n);
    i=j=0;
    while(i<a&&j<b)
    {   if(arr1[a-1-i]>=arr2[b-1-j])
        {   c++;
            i++;
        }
        j++;
    }

    cout << c;

}
