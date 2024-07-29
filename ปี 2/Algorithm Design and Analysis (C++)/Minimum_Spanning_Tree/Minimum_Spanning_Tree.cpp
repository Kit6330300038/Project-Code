#include <bits/stdc++.h>
using namespace std;

int *g = new int[1];
vector<int> arr[3];
int a,ag,w=0;

void swap(int i,int j)
{   int a=arr[0].at(i),b=arr[1].at(i),c=arr[2].at(i);
    arr[0].at(i)=arr[0].at(j);arr[1].at(i)=arr[1].at(j);arr[2].at(i)=arr[2].at(j);
    arr[0].at(j)=a;arr[1].at(j)=b;arr[2].at(j)=c;
}

void qsort(int left,int right,int center)
{   if(left-right==1||left-right==0)
        return;
    int v=arr[2].at(center),i=left,j=right;
    swap(j--,center);
    while(i <= j)
    {   if(arr[2].at(i)<v)
            i++;
        else if(arr[2].at(j)>=v)
            j--;
        else
            swap(i,j);
    }
    swap(i,right);
    qsort(i+1,right,(i+right+1)/2);
    qsort(left,i-1,(i+left-1)/2);
}
void f(int pos,int s)
{   int bac,setnum;
    if(g[arr[0].at(pos)]!=g[arr[1].at(pos)])
    {   bac=g[arr[1].at(pos)];
        setnum=g[arr[0].at(pos)];
        for(int i=0;i<s;i++)
        {   if(g[i]==bac)
                g[i]=setnum;
        }
        ag--;
        w+=arr[2].at(pos);
    }
}

int main()
{   int b,i,j,x,y,z,ans=0,s=0;
    cin >> a >> b;
    g = new int[a];
    ag=a;
    for(i=0;i<a;i++)
    {   g[i]=i;
    }
    for(i=0;i<b;i++)
    {   cin >> x >> y >> z;
        arr[0].push_back(x-1);
        arr[1].push_back(y-1);
        arr[2].push_back(z);
        s++;
    }
    qsort(0,b-1,b/2);
    for(i=0 ; i<b && ag>1 ; i++)
    {   f(i,a);
    }
    if(ag>1)
        cout << -1;
    else
        cout << w;
    return 0;
}
