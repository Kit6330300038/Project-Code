#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,total,b=0;
    cin >> a;
    total = a;
    if(a%2==0)
    {
        b++;
    }
    while(a>2)
    {
        total += a/3;
        a = (a/3)+(a%3);
    }
    cout << total+b;
    return 0;
}
