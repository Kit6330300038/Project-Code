#include <bits/stdc++.h>
using namespace std;

struct A
{   int s,e,w;
};

int findnext(A arr[],int pos)
{   int posf=0,posb=pos,i;
    while(posf <= posb)
    {   i = (posb+posf)/2;
        if(arr[i].e <= arr[pos].s)
        {   if(arr[i+1].e <= arr[pos].s)
                posf = i+1;
            else
                return i;
        }
        else
            posb = i-1;
    }
    return -1;
}

int maxweight(A arr[],int pos,int limit)
{
    if(pos==0)
        return arr[pos].w;
    if(limit>=pos)
        return 0;

    int total_i=arr[pos].w,next=findnext(arr,pos);
    if(limit==-2)
        limit=next;
    if(next!=-1)
        total_i += maxweight(arr,next,-2);

    int total_x = maxweight(arr,pos-1,limit);

    return max(total_i,total_x);
}

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

int main()
{   int a,s,e,w,i,ans;
    cin >> a;
    A arr[a];
    for(i=0 ;i<a ;i++)
    {   cin >> s >> e >> w;
        arr[i]={s,e,w};
    }
    qsort(arr,0,a-1,(a-1)/2);
    ans = maxweight(arr,a-1,-2);
    cout << ans;
}
