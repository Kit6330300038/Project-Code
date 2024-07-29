#include <bits/stdc++.h>
using namespace std;

int main()
{   int a,b,c,d,e,i,j,t,k=0;
    cin >> a ;
    int ans[a];
    while(a--)
    {   cin >> b >> c;
        int arr[b][b],color[b];
        for(i=0 ;i<b ;i++)
        {   for(j=0 ;j<b ;j++)
            {   arr[i][j] = 0;
            }
            color[i]=-1;
        }
        for(i=0 ;i<c ;i++)
        {   cin >> d >> e;
            arr[d][e] =  arr[e][d] = 1;
        }
        t=1;
        for(i=0; i<b; i++)
        {   if(color[i]==-1)
            {   color[i]=1;
            }
            for(j=0; j<b ;j++)
            {   if(arr[i][j])
                {   if(color[j]==-1)
                    {   if(color[i]==0)
                        {   color[j]=1;
                        }
                        else
                        {   color[j]=0;
                        }
                    }else if(color[i]==color[j])
                    {   t=0;
                        break;
                    }
                }
            }
            if(!t)
                break;
        }
        ans[k++]=t;
    }
    for(i=0;i<k;i++)
    {   if(ans[i])
            cout << "yes\n";
        else
            cout << "no\n";
    }
}
