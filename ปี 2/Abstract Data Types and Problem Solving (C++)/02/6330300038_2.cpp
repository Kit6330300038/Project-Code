#include <bits/stdc++.h>
using namespace std;

int sum(int a)
{
    if(a==1)
    {
        return 1;
    }
    else if(a>1)
    {
        return a+sum(a-1);
    }
    else
    {
        return 0;
    }
}

int main()
{
    int a;
    cout << "Enter : ";
    cin >> a;
    cout << sum(a);
}
