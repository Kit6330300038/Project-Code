#include <bits/stdc++.h>
using namespace std;

int main()
{   int len,i,a,b,shortest,removed,ans=0;
    cin >> len ;
    vector<int> arr[2];
    for(i=0;i<len;i++)
    {   cin >> a >> b;
        arr[0].push_back(a);
        arr[1].push_back(b);
    }
    while(len!=0)
    {   shortest=0;
        for(i=1;i<len;i++)
        {   if(arr[1].at(i)<arr[1].at(shortest))
                shortest=i;
        }
        shortest=arr[1].at(shortest);
        i=removed=0;
        while(i+removed<len)
        {   if(arr[0].at(i)<shortest)
            {   arr[0].erase(arr[0].begin()+i);
                arr[1].erase(arr[1].begin()+i);
                removed++;
            }else
                i++;
        }
        if(i||(removed>0&&!i))
            ans++;
        len=i;
    }
    cout << ans;
}
