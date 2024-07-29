#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,i,j,co;
    cin >> a;
    cin >> b;
    int arr[a];
    for(i=0;i<a;i++)
    {   cin >> arr[i];
    }
    for(i=0;i<b;i++)
    {   cin >> c;
        co=0;
        for(j=0;j<a;j++)
        {   if(arr[j]>c)
            {   co++;
                arr[j]=-1;
                if(j!=0 && j!=a-1)
                {   if(0<arr[j-1]&&arr[j-1]<=c)
                    {   co++;
                        arr[j-1]=-1;
                    }
                    if(0<arr[j+1]&&arr[j+1]<=c)
                    {   co++;
                        arr[j+1]=-1;
                    }
                }else if(j!=0)
                {   if(0<arr[j-1]&&arr[j-1]<=c)
                    {   co++;
                        arr[j-1]=-1;
                    }
                }else
                {   if(0<arr[j+1]&&arr[j+1]<=c)
                    {   co++;
                        arr[j+1]=-1;
                    }
                }
            }
        }
        cout << co <<"\n";
    }
}
