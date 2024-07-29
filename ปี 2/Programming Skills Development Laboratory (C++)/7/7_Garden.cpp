#include <bits/stdc++.h>
using namespace std;

int main()
{   int W,H,i,j,tf;
    cin >> H;
    cin >> W;
    int arr[H+2][W+2];
    for(i=0;i<H+2;i++)
    {   arr[i][W+1]=0;
        arr[i][0]=0;
    }
    for(i=0;i<W+2;i++)
    {   arr[H+1][i]=0;
        arr[0][i]=0;
    }
    for(i=1;i<=H;i++)
    {   for(j=1;j<=W;j++)
        {   cin >> arr[i][j];
        }
    }
    for(i=0;i<H;i++)
    {   for(j=0;j<W;j++)
        {   tf=1;
            if(arr[i-1][j]<=arr[i][j] && arr[i+1][j]<=arr[i][j])tf=0;
            if(arr[i][j-1]<=arr[i][j] && arr[i][j+1]<=arr[i][j])tf=0;
            if(tf)
            {   cout << "NO";return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}
