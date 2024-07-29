#include <bits/stdc++.h>
using namespace std;

int gatcha(int a)
{   if(a%5==1||a%5==2)return 0;
    else if(a%5==3||a%5==4)return 1;
    else return 2;
}

int main()
{   int star[6]={0,0,0,0,0,0},a,b,r=0,ga,i,hi;
    cin >> a;
    cin >> b;
    star[a-1]++;
    hi=a;
    while(hi<b)
    {   r++;
        ga=gatcha(r);
        star[ga]++;
        for(i=0;i<hi;i++)
        {   if(star[i]==i+2)
            {   star[i+1]++;
                star[i]=0;
                if(i+1==hi)hi++;
            }
        }
    }
    cout << r;
    return 0;
}
