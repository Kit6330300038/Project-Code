#include <bits/stdc++.h>
using namespace std;

int main()
{   int a,b,c;
    string ans;
    cin >> a;
    while(a--)
    {   ans="";
        cin >> b;
        cin >> c;
        while(b)
        {   ans = (char)(b%c+48)+ans;
            b/=c;
        }
        if(ans=="")
            cout << "0\n";
        else
            cout << ans << "\n";
    }

}
