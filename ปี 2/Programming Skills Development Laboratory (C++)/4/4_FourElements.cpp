#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,c,i,j,k,l;
    cin >> a;
    int b[a];
    for(i=0;i<a;i++)
    {
        cin >> b[i];
    }
    cin >> c;
    for(i=0;i<a;i++)
    {
        for(j=i+1;j<a;j++)
        {
            for(k=j+1;k<a;k++)
            {
                for(l=k+1;l<a;l++)
                {
                    if(b[i]+b[j]+b[k]+b[l]==c)
                    {
                        cout << "YES";
                        return 0;
                    }
                }
            }
        }
    }
    cout << "NO";
    return 0;

}
