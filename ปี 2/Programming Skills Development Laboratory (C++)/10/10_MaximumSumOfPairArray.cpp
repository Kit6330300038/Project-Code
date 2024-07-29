#include <bits/stdc++.h>
using namespace std;

int main()
{   int a,i,j,n,total=0;
    cin >> a;
    int b[a];
    for(i=0;i<a;i++)
        cin >> b[i];
    for(i=0;i<a-1;i++)
        for(j=i+1;j<a;j++)
            if(b[i]>b[j])
            {   n=b[i];
                b[i]=b[j];
                b[j]=n;
            }
    i=0;
    while(b[i]<0&&i+1<a)
    {   total += b[i]*b[i+1];
        i+=2;
    }
    if(a%2==1)
    {   if(b[i+1]>0)
        {   total+=b[i];
            i++;
        }
        else
            i+=2;
    }
    while(i+1<a)
    {   total += b[i]*b[i+1];
        i+=2;
    }
    cout << total;
}
