#include <bits/stdc++.h>
using namespace std;

int main()
{   int a,i,hp,j,m,co=0;
    cin >> a;
    int arr[a];
    for(i=0;i<a;i++)
        cin >> arr[i];
    cin >> hp;
    i=a;
    while(i>0&&hp>=0)
    {   m=0;
        for(j=1;j<i;j++)
            if(arr[m]<arr[j])
                m=j;
        hp -= arr[m];
        arr[m]=arr[i-1];
        co++;i--;
    }
    if(hp>=0)
        cout << "YOU DIE";
    else
        cout << co;
}
