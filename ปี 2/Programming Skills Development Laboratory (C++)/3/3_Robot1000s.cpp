#include <bits/stdc++.h>
using namespace std;

int Max(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int Min(int a,int b)
{
    if(a>b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

int main()
{
    string a;
    int n=0,w=0,e=0,s=0,i,k;
    cin >> a;
    for(i=0; i<a.length(); i++)
    {
        switch(a.at(i))
        {
            case 'N':
                n++;
                break;
            case 'S':
                s++;
                break;
            case 'E':
                e++;
                break;
            case 'W':
                w++;
                break;
        }
    }
    cin >> k;
    i = min(s,n)+ min(e,w);
    if(i > k)
    {
        cout << (max(n,s)+max(e,w)-(i-k))*2;
    }
    else
    {
        cout << (max(n,s)+max(e,w)-(k-i))*2;
    }
    return 0;
}

