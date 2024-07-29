#include <bits/stdc++.h>
using namespace std;

int main()
{   int r,Joy=0,Jaew=0,a;
    cin >> r;
    while(r--)
    {   cin >> a;
        if(a%60)
        {   a/=60;
            if(a%2==0)
            {   Joy++;
            }else
            {   Jaew++;
            }
        }
    }
    cout << Joy << " " << Jaew << "\n";
    if(Jaew>Joy)
        cout << "Jaew";
    else if(Jaew<Joy)
        cout << "Joy";
    else
        cout << "Draw";
}

