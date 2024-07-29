#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[3],i;
    for(i=0;i<3 ;i++){cin >> a[i];}
    int b[a[2]],ct=0,hi;
    for(i=0;i<a[2];i++)
    {
        cin >> b[i];
        hi=0;
        while(hi<b[i])
        {
            if(hi+a[0] >= b[i]){ct++;break;}
            else{ct++;hi+=a[0]-a[1];}
        }
    }
    cout << ct;
    return 0;
}
