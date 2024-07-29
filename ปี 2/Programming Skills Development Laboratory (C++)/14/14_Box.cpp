#include <bits/stdc++.h>
using namespace std;

int main()
{   int a[3][2],b[3][2],i,area=1;
    for(i=0;i<6;i++)
        cin >> a[i%3][i/3];
    for(i=0;i<6;i++)
        cin >> b[i%3][i/3];
    for(i=0;i<3;i++)
    {   a[i][1]+=a[i][0];
        b[i][1]+=b[i][0];
    }
    for(i=0;i<3;i++)
    {   if(a[i][0]>=b[i][0]&&b[i][1]>a[i][0])
        {   if(a[i][1]>b[i][1])
                area*=(b[i][1]-a[i][0]);
            else
                area*=(a[i][1]-a[i][0]);
        }
        else if(a[i][0]<=b[i][0]&&b[i][0]<a[i][1])
        {   if(a[i][1]>b[i][1])
                area*=(b[i][1]-b[i][0]);
            else
                area*=(a[i][1]-b[i][0]);

        }else
        {   cout << 0;
            return 0;
        }
    }
    cout << area;
}

