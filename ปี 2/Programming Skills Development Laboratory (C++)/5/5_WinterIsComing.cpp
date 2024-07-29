#include <bits/stdc++.h>
using namespace std;

int isprime(int a)
{
    if(a==1){return 0;}if(a==2){return 1;}
    int b = (int)sqrt(a),i;
    for(i=2;i<=b;i++)
    {
        if(a%i==0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int a[2],i;
    for(i=0;i<2;i++){cin >> a[i];}
    int b[a[0]],power=a[1];
    for(i=0;i<a[0];i++)
    {
        cin >> b[i];
    }
    for(i=0;i<a[0];i++)
    {
        if(power == 0 && isprime(b[i]) == 0){cout << "NO";return 0;}
        if(isprime(b[i]) == 0){power--;}
        else{power = a[1];}
    }
    cout << "YES";
    return 0;
}
