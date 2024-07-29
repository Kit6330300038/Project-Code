#include <bits/stdc++.h>
using namespace std;

int fib(int a)
{
    if(a==0)
    {
        return 0;
    }
    else if(a==1)
    {
        return 1;
    }
    else
    {
        return fib(a-1) + fib(a-2);
    }
}

int main()
{
    while(1)
    {
        int a;
        cout << "Enter : ";
        cin >> a;
        if(a==-1)
        {
            break;
        }
        cout << fib(a) << "\n";
    }
    cout << "End Program";
}
