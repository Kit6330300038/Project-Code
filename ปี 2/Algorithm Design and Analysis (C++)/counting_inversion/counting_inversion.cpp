#include <bits/stdc++.h>
using namespace std;

int c=0;

void mer(int arr1[],int arr2[],int l,int r)
{   int pl=(l+r)/2,pr=r,mid=(l+r)/2+1,p=r;
    while(pl>=l&&pr>=mid)
    {   if(arr1[pr]<arr1[pl])
        {   arr2[p--]=arr1[pl--];c+=pr+1-mid;
        }
        else
        {   arr2[p--]=arr1[pr--];
        }
    }
    while(pl>=l)
    {   arr2[p--]=arr1[pl--];
    }
    while(pr>=mid)
    {   arr2[p--]=arr1[pr--];
    }
    while(r-l>=0)
    {   arr1[r]=arr2[r];r--;
    }
}

void m(int arr1[],int arr2[],int l,int r)
{   if(r-l > 0)
    {   m(arr1,arr2,l,(l+r)/2);
        m(arr1,arr2,(l+r)/2+1,r);
        mer(arr1,arr2,l,r);
    }

}

int main()
{   int a,b,i;
    cin >> a;
    int arr[a],arr2[a];
    for(i=0;i<a;i++)
    {   cin >> b;
        arr[i]=b;
    }
    m(arr,arr2,0,a-1);
    cout << c;
}
