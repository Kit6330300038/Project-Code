#include <bits/stdc++.h>
using namespace std;

int main()
{   int a,b,c,d,i,j,k,l,rag=1,n;
    cin >> a;
    cin >> b;
    int arr[a];
    for(i=0;i<a;i++)
        arr[i]=rag++;
    for(i=0;i<b;i++)
    {   cin >> c;
        cin >> d;
        j=0;
        while(arr[j]!=c)
            j++;
        k=j;
        while(arr[k]!=d)
            k++;
        int arr2[k-j+1];
        for(l=j;l<=k;l++)
            arr2[l-j]=arr[l];
        for(l=0;l<=a-k;l++)
            arr[j+l]=arr[k+l+1];
        for(l=0;l<=k-j;l++)
            arr[l+(a-k)+j-1]=arr2[l];
    }
    for(i=0;i<a;i++)
        cout << arr[i] << "\n";
    return 0;
}
