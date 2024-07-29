#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{   if (a == 0)
        return b;
    return gcd(b % a, a);
}
int lcm(int a, int b)
{   return (a / gcd(a, b)) * b;
}

int main()
{   int a,b,i,Lcm;
    cin >> a;
    while(a--)
    {   cin >> b;
        int arr1[b],arr2[b],total[b],amo[b];
        for(i=0;i<b;i++)
            cin >> arr1[i];
        for(i=0;i<b;i++)
            cin >> arr2[i];
        for(i=0;i<b;i++)
        {   total[i]=lcm(arr1[i],arr2[i]);
            amo[i]=total[i]/arr1[i];
        }
        Lcm=1;
        for(i=0;i<b;i++)
        {   Lcm=lcm(amo[i],Lcm);
        }
        cout << Lcm << "\n";
        for(i=0;i<b;i++)
        {   cout << arr1[i]*Lcm/arr2[i] << " ";
        }
        cout << "\n";
    }

}
