#include <bits/stdc++.h>
using namespace std;

int main()
{   string a,ret="";
    int b[100],i,c,len,d;
    cin >> a;
    len=a.length();
    for(i=0;i<len;i++)
    {   cin >> b[i];
    }
    cin >> d;
    cin >> c;
    while(d-->1)
    {   if(b[c-1]<=0||b[c-1]>len){cout << "No";return 0;}
        else
        {   ret+= a.at(c-1);
            c = b[c-1];
        }
    }
    ret+= a.at(c-1);
    cout << ret;
    return 0;
}
