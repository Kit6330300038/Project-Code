#include <bits/stdc++.h>
using namespace std;

int main()
{   int r,x,y,range,point=0;
    cin >> r;
    while(r--)
    {   cin >> x >> y;
        range=x*x+y*y;
        if(range<4)
            point+=5;
        else if(range<16)
            point+=4;
        else if(range<36)
            point+=3;
        else if(range<64)
            point+=2;
        else if(range<100)
            point++;
    }
    cout << point;
}

