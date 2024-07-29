#include <bits/stdc++.h>
using namespace std;

int main()
{   int a,b,i,len,total=0,j,p;
    string c;
    cin >> a;
    while(a--)
    {   total=0;
        cin >> b;
        cin >> c;
        len =c.length();
        for(i=len-1;i>=0;i--)
        {   j=len-i;
            p=c.at(i)-48;
                while(--j)
            p*= b;
            total+=p;
        }
        cout << total << "\n";
    }
}
