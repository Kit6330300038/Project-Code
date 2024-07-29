#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,i,total=3,num1=1,num2=2,b;
    cin >> a;
    if(a==1)
    {
        cout << 1;
    }
    else if(a==2)
    {
        cout << 2;
    }
    else
    {
        for(i=3 ; i<a ;i++)
        {
            b = total;
            total += num2;
            num2 = b;
        }
        cout << total;
    }
    return 0;
}
