#include <bits/stdc++.h>
using namespace std;

int top(int a[8],int b)
{   for(int i=0;i<8;i++)
        if(b<a[i])b=a[i];
    return b;
}
int main()
{   int a,b,c,i,j,num=2,counter=0,isswap,n;
    cin >> a;
    cin >> b;
    int arr[a][b],f[8],dif[a*b/4];
    for(i=0;i<a;i++)
    {   for(j=0;j<b;j++)
        {   cin >> arr[i][j];
        }
    }
    for(i=0;i<a;i++)
    {   for(j=0;j<b;j++)
        {   if(arr[i][j]==1)
            {   arr[i][j]=num;num++;
            }
        }
    }
    while(1)
    {   isswap=0;
        for(i=0;i<a;i++)
        {   for(j=0;j<b;j++)
            {   if(arr[i][j]!=0)
                {   f[0]=arr[i-1][j-1];
                    f[1]=arr[i-1][j];
                    f[2]=arr[i-1][j+1];
                    f[3]=arr[i][j-1];
                    f[4]=arr[i][j+1];
                    f[5]=arr[i+1][j-1];
                    f[6]=arr[i+1][j+1];
                    f[7]=arr[i+1][j];
                    n=top(f,arr[i][j]);
                    if(arr[i][j]!=n)isswap=1;
                    arr[i][j]= n;
                }
            }
        }
        if(!isswap)break;
    }
    for(i=0;i<a;i++)
    {   for(j=0;j<b;j++)
        {   if(arr[i][j]!=0)
            {   isswap=1;
                for(n=0;n<counter;n++)
                {   if(dif[n]==arr[i][j]){isswap=0;break;}
                }
                if(isswap){dif[counter]=arr[i][j];counter++;}
            }
        }
    }
    cout << counter;
}


