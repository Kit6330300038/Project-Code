#include <bits/stdc++.h>
using namespace std;

int main()
{   int a,i,j,k,n,co=0;
    cin >> a;
    int arr1[a],arr2[a];
    for(i=0;i<a;i++)
    {   cin >> arr1[i];
    }
    for(i=0;i<a;i++)
    {   cin >> arr2[i];
    }
    n = sizeof(arr1)/sizeof(arr1[0]);
    sort(arr1, arr1+n);
    n = sizeof(arr2)/sizeof(arr2[0]);
    sort(arr2, arr2+n);
    i=0;j=0;
    while(i<a&&j<a)
    {   if(arr1[i]==arr2[j])
        {   i++;j++;co++;
        }else if(arr1[i]>arr2[j])
            j++;
        else
            i++;
    }
    cout << co;
}
