#include <bits/stdc++.h>
using namespace std;

int coloring(vector<int> arr[],int pos,int color[])
{   int i,t=1;
    for(i=0; i<arr[pos].size(); i++)
    {   if(color[arr[pos].at(i)]==-1)
        {   if(color[pos])
            {   color[arr[pos].at(i)]=0;
            }else
            {   color[arr[pos].at(i)]=1;
            }
            t = coloring(arr,arr[pos].at(i),color);
        }else if(color[arr[pos].at(i)]==color[pos])
            return 0;
    }
    return t;
}

int main()
{   int a,b,c,d,e,i,j;
    cin >> a;
    int ans[a];
    for(i=0 ;i<a ;i++)
    {   cin >> b >> c;
        vector<int> arr[b];
        int color[b],t;
        for(j=0 ;j<c ;j++)
        {   cin >> d >> e;
            arr[d-1].push_back(e-1);
            arr[e-1].push_back(d-1);
        }
        for(j=0 ;j<b ;j++)
            color[j]=-1;
        for(j=0 ;j<b ;j++)
        {   if(color[j]==-1)
            {   color[j]=0;
                t = coloring(arr,j,color);
            }
            if(!t)
                break;
        }
        ans[i]=t;
    }
    for(i=0 ;i<a ;i++)
    {   if(ans[i])
        {   cout << "yes\n";
        }else
        {   cout << "no\n";
        }
    }
}
