#include <bits/stdc++.h>
using namespace std;

int main()
{   string a;
    int b,i,tf=1;
    cin >> a;
    b = a.length();
    for(i=0; i<(b/2)+1; i++)
    {   if(a.at(i)!=a.at(b-i-1)&&(int)a.at(i)-32!=(int)a.at(b-i-1)&&(int)a.at(i)+32!=(int)a.at(b-i-1)){cout << "NO";return 0;}
    }
    cout << "YES";
    return 0;
}
