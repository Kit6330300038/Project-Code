#include <bits/stdc++.h>
using namespace std;

int prv[26];

int main()
{   string a;
    cin >> a;
    int len=a.length(),i,t=0;
    for(i=0;i<26;i++)
        prv[i]=-1;
    for(i=0;i<len;i++)
    {   if(prv[((int)a.at(i))-65]==-1)
            prv[((int)a.at(i))-65]=i;
        else if(prv[((int)a.at(i))-65]==i-1)
            prv[((int)a.at(i))-65]=i;
        else
        {   t=1;
            break;
        }
    }
    if(t)
        cout << "YES";
    else
        cout << "NO";
}
