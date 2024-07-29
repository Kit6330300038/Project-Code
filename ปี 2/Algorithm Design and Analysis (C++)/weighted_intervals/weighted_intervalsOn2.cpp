#include <bits/stdc++.h>
using namespace std;

struct A
{   int s,e,w;
};

void swap(A arr[],int i,int j)
{   A a=arr[i];
    arr[i]=arr[j];
    arr[j]=a;
}

void qsort(A arr[],int left,int right,int center)
{   if(left-right==1||left-right==0)
        return;
    int v=arr[center].e,i=left,j=right;
    swap(arr,j--,center);
    while(i <= j)
    {   if(arr[i].e < v)
            i++;
        else if(arr[j].e >=v)
            j--;
        else
            swap(arr,i,j);
    }
    swap(arr,i,right);
    qsort(arr,i+1,right,(i+right+1)/2);
    qsort(arr,left,i-1,(i+left-1)/2);
}

int findmax(A arr[],int pos)
{   int f=0,b=pos,m;
    while(f<=b)
    {   m=(f+b)/2;
        if(arr[m].e <= arr[pos].s)
        {   if(arr[m+1].e <= arr[pos].s)
                f=m+1;
            else
                return m;
        }
        else
            b=m-1;
    }
    return -1;
}

int main()
{   int a,s,e,w,i,j;
    cin >> a;
    A arr[a];
    int mw[a];
    for(i=0 ;i<a ;i++)
    {   cin >> s >> e >> w;
        arr[i]={s,e,w};
    }
    qsort(arr,0,a-1,(a-1)/2);
    s=1;
    mw[0]=arr[0].w;
    for(i=1;i<a;i++)
    {   w=findmax(arr,i);
        if(w==-1)
            mw[i]=arr[i].w;
        else
            mw[i]=arr[i].w + mw[w];
        mw[i]=max(mw[i],mw[i-1]);
    }
    cout << mw[a-1];
}

