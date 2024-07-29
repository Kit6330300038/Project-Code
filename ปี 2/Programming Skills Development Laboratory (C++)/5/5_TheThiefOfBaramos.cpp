#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[2],i,j;
    for(i=0;i<2;i++){cin >> a[i];}
    int b[a[0]],top,c=0;
    for(i=0;i<a[0];i++){cin >> b[i];}
    for(i=0;i<a[1];i++)
    {
        top = 0;
        for(j=1;j<a[0];j++)
        {
            if(b[j]>=b[top]){top=j;}
        }
        c+=b[top];
        b[top]=0;
    }
    cout << c;
    return 0;
}
