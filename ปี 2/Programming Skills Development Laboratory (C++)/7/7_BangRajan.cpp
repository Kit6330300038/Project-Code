#include <bits/stdc++.h>
using namespace std;

int main()
{   int a,maxx=0,maxy=0,i,num=0;
    cin >> a;
    int arrx[a],arry[a],val[a];
    for(i=0;i<a;i++)
    {   cin >> arrx[i];
        if(arrx[i]>maxx)maxx=arrx[i];
        cin >> arry[i];
        if(arry[i]>maxy)maxy=arry[i];
        cin >> val[i];
    }
    for(i=0;i<a;i++)
    {   if(arrx[i]==0||arrx[i]==maxx)
        {   if(val[i]==0)
            {   num++;val[i]++;
            }
        }
    }
    for(i=0;i<a;i++)
    {   if(arry[i]==0||arry[i]==maxy)
        {   if(val[i]==0)
            {   num++;val[i]++;
            }
        }
    }
    cout << num;
}
