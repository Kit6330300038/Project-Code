#include <bits/stdc++.h>
using namespace std;

int main()
{   int a,i=2;
    cin >> a;
    while(a>1)
    {   if(a%i==0)
        {   cout << i <<"\n";
            a/=i;
        }else if(a%(i+1)==0)
        {   cout << ++i <<"\n";
            a/=i;
        }else
            i++;
    }
}
