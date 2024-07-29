#include <bits/stdc++.h>
using namespace std;

int main()
{   int a,b,c,mA=200000,mB=200000,i,posA=0,posB=0;
    cin >> c;
    for(i=0;i<c;i++)
    {   cin >> a;
        cin >> b;
        posA +=a;
        posB +=b;
        if(posA>20)posA-=21;
        if(posB>20)posB-=21;
        if(posA%2==0)
        {   mA -= 10*posA;
            mB += 10*posA;
        }
        if(posB%2==1)
        {   mB -= 10*posB;
            mA += 10*posB;
        }
    }
    cout << mA << " " << mB << " ";
    if(mA>mB)cout << "A";
    else cout << "B";
    return 0;
}
