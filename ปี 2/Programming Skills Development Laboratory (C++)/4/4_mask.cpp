#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,c1[2]={0,0},c2[2]={0,0},c3[2]={0,0},c4[2]={0,0},i,t1,t2,t3,t4;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> t1;
        if(t1 > c1[0])
        {
            c1[0]=t1;
            c1[1]=i+1;
        }
    }
    for(i=0;i<n;i++)
    {
        cin >> t2;
        if(t2 > c2[0])
        {
            c2[0]=t2;
            c2[1]=i+n+1;
        }
    }
    for(i=0;i<n;i++)
    {
        cin >> t3;
        if(t3 > c3[0])
        {
            c3[0]=t3;
            c3[1]=i+2*n+1;
        }
    }
    for(i=0;i<n;i++)
    {
        cin >> t4;
        if(t4 > c4[0])
        {
            c4[0]=t4;
            c4[1]=i+3*n+1;
        }
    }
    if(c1[0] > c2[0])
    {
        if(c3[0] > c4[0])
        {
            if(c1[0] > c3[0])
            {
                cout << c1[1] << " " << c3[1]<< " " << c2[1]<< " " << c4[1];
            }
            else
            {
                cout << c3[1] << " " << c1[1] << " " << c2[1] << " " << c4[1];
            }
        }
        else
        {
            if(c1[0] > c4[0])
            {
                cout << c1[1] << " " << c4[1] << " " << c2[1] << " " << c3[1];
            }
            else
            {
                cout << c4[1] << " " << c1[1] << " " << c2[1] << " " << c3[1];
            }
        }
    }
    else
    {
        if(c3[0] > c4[0])
        {
            if(c2[0] > c3[0])
            {
                cout << c2[1] << " " << c3[1] << " " << c1[1] << " " << c4[1];
            }
            else
            {
                cout << c3[1] << " " << c2[1] << " " << c1[1] << " " << c4[1];
            }
        }
        else
        {
            if(c2[0] > c4[0])
            {
                cout << c2[1] << " " << c4[1] << " " << c1[1] << " " << c3[1];
            }
            else
            {
                cout << c4[1] << " " << c2[1] << " " << c1[1] << " " << c3[1];
            }
        }
    }
    return 0;
}

