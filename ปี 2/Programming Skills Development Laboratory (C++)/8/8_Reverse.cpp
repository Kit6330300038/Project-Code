#include <bits/stdc++.h>
using namespace std;

string sswap(string a,int b,int c)
{   int len=a.length(),i;
    string ret="";
    ret += a.substr(0,b-1);
    for(i=0;i<=c-b;i++)
    {   ret += a.at(c-i-1);
    }
    ret += a.substr(c,len-c);
    return ret;
}

int main()
{   int a,b,i,j,e,f;
    string c;
    cin >> a;
    for(i=0;i<a;i++)
    {   cin >> c;
        cin >> b;
        for(j=0;j<b;j++)
        {   cin >> e;
            cin >> f;
            c = sswap(c,e,f);
        }
        cout << c << "\n";
    }
}
