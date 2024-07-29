#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i,len,total;
    cin >> len;
    int a[len];
    string b[len-1];
    cin >> a[0];
    for(i=0;i<len-1;i++)
    {
        cin >> b[i];
        cin >> a[i+1];
    }
    total = a[0];
    for(i=0;i<len-1;i++)
    {
        if(b[i]=="+")
        {
            total += a[i+1];
        }
        else
        {
            total -= a[i+1];
        }
    }
    cout << total;
    return 0;
}

