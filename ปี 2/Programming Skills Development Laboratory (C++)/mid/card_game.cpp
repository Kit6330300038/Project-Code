#include <bits/stdc++.h>
using namespace std;

int main()
{   int a,b1,c1,i,wd=0,wk=0,dd=0,dk=0;
    char b2,c2;
    cin >> a;
    for(i=0;i<a;i++)
    {   cin >> b1;
        cin >> b2;
        cin >> c1;
        cin >> c2;
        if(b1 > c1)
        {   wk+=b1-c1;dk++;
        }else if (c1 > b1)
        {   wd+=c1-b1;dd++;
        }else
        {   if(b2=='S')
            {   dk+=3;
            }else if(b2=='H')
            {   if(c2=='S'){dd+=3;}
                else{dk+=3;}
            }else if(b2=='D')
            {   if(c2=='C'){dk+=3;}
                else{dd+=3;}
            }else
            {   dd+=3;
            }
        }
    }
    cout << wd << " " << dd << "\n";
    cout << wk << " " << dk;
}
