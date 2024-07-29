#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,i,j,k,l,si;
    cin >> a;
    bool tf;
    char arr[a][a];
    for(i=0;i<a;i++)
    {   for(j=0;j<a;j++)
        {   cin >> arr[i][j];
        }
    }for(si=a;si>0;si--)
    {   for(i=0;i<=a-si;i++)
        {   for(j=0;j<=a-si;j++)
            {   tf=true;
                if(arr[i][j] != '0')
                {
                    for(k=i; k<i+si; k++)
                    {   for(l=j; l<j+si; l++)
                        {   if(arr[k][l]== '0')
                            {   tf=false;break;break;
                            }
                        }
                    }
                    if(tf)
                    {   cout << i+1<<" " << j+1<<"\n";
                        cout << si*si;return 0;
                    }
                }
            }
        }
    }

}

