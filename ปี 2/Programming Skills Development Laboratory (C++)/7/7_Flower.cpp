#include <bits/stdc++.h>
using namespace std;

int max(int a,int b)
{   if(a>b)return a;
    return b;
}
int min(int a,int b)
{   if(a<b)return a;
    return b;
}

int main()
{   int a,b,i,j,k,l,counter=0;
    cin >> a;
    int arr[a][a];
    for(i=0; i<a; i++)
    {   for(j=0; j<a; j++)
        {   cin >> arr[i][j];
        }
    }
    for(i=0; i<a; i++)
    {   for(j=0; j<a; j++)
        {   if(arr[i][j] > 0)
            {   b=arr[i][j];
                for(k=max(i-b,0); k<=min(i+b,a-1); k++)
                {   for(l=max(j-b,0); l<=min(j+b,a-1); l++)
                    {   if(arr[k][l]<=0)arr[k][l]=-1;
                    }
                }
            }
        }
    }
    for(i=0;i<a;i++)
    {   for(j=0;j<a;j++)
        {   if(arr[i][j]==0)counter++;
        }
    }
    cout << counter;
}
