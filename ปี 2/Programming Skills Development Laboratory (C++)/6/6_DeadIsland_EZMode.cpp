#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,i,j,k,l,co;
    cin >> a;
    cin >> b;
    int arr[b][a];
    for(i=0; i<b; i++)
    {   for(j=0; j<a; j++)
        {   cin >> arr[i][j];
        }
    }
    for(i=1; i<b-1; i++)
    {   for(j=1; j<a-1; j++)
        {   if(arr[i][j]==1)
            {   co=0;
                for(k=i-1;k<=i+1;k++)
                {   for(l=j-1;l<=j+1;l++)
                    {   if(arr[k][l]==1){co++;}
                    }
                }
                if(co<3){cout << "No";return 0;}
            }
        }
    }
    cout << "Yes";
    return 0;
}
