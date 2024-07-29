#include <bits/stdc++.h>
using namespace std;

int gatcha(int a)
{   if(a%6==1||a%6==2||a%6==3)return 1;
    else if(a%6==4||a%6==5)return 2;
    else if(a==6||a==18)return 3;
    else if(a==12)return 4;
    else return 5;
}
int exp(int star)
{   if(star==1)return 1;
    if(star==2)return 2;
    if(star==3)return 4;
    if(star==4)return 8;
    if(star==5)return 16;
    return 0;
}


int main()
{   int a,b,c,up[2],gat,r=1,dong=0,num=0;
    cin >> a;
    cin >> b;
    cin >> c;
    up[1]=c;
    if(a==1)up[0]=5-b;
    else if(a==2)up[0]=10-b;
    else if(a==3)up[0]=20-b;
    else if(a==4)up[0]=40-b;
    else if(a==5)up[0]=80-b;
    else up[0]==160-b;
    while(up[0]>0)
    {   gat=gatcha(r);num++;
        if(gat<=a)
        {   up[0]-=exp(gat);
        }
        else if(gat-1==a)dong++;
        r++;
        if(r>24)r-=24;
    }
    up[1]-= dong*exp(a+1);
    while(up[1]>0)
    {   gat=gatcha(r);num++;
        if(gat<=a+1)
        {   up[1]-=exp(gat);
        }
        r++;
        if(r>24)r-=24;
    }
    cout << num;
    return 0;
}

