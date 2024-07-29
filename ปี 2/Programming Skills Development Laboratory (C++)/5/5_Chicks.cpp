#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,i,chi[21],born[21];
    cin >> a;
    chi[0]=0;chi[1]=1;
    born[1]=1;
    for(i=1;i<a;i++)
    {
        if(i<6)
        {
            chi[i+1] = chi[i]*3;
            born[i+1] = chi[i+1]-chi[i];
        }
        else
        {
            chi[i+1]=(chi[i]-(born[i-5]))*3;
            born[i+1]=(chi[i]-(born[i-5]))*2;
        }

    }
    cout << chi[a];
    return 0;
}
