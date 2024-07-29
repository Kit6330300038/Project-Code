#include <bits/stdc++.h>
using namespace std;

int main()
{   int a[2],b[2],c[2],maxa,cl;
    cin >> a[0] >> a[1];
    cin >> b[0] >> b[1];
    cin >> c[0] >> c[1];
    maxa=(a[0]-b[0])*(a[1]-c[1]);
    cl=(a[0]-c[0])*(a[1]-b[1]);
    if(cl>maxa)
        maxa=cl;
    if(b[0]+c[0]<a[0]&&b[1]+c[1]<a[1])
    {   cl=(a[0]-b[0]-c[0])*(a[1]-b[1]-c[1]);
        if(cl>maxa)
            maxa=cl;
    }
    if(b[0]+c[0]<a[0])
    {   cl=a[1]*(a[0]-b[0]-c[0]);
        if(cl>maxa)
            maxa=cl;
    }
    if(b[1]+c[1]<a[1])
    {   cl=a[0]*(a[1]-b[1]-c[1]);
        if(cl>maxa)
            maxa=cl;
    }
    cout << maxa;
}
