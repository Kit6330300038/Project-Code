#include <bits/stdc++.h>
using namespace std;

int medi5(int a[5])
{   int i,j,b;
    for(i=0;i<5;i++)
    {   for(j=i+1;j<5;j++)
        {   if(a[i] > a[j]){b=a[i];a[i]=a[j];a[j]=b;}
        }
    }
    return a[2];
}
int medi9(int a[9])
{   int i,j,b;
    for(i=0;i<9;i++)
    {   for(j=i+1;j<9;j++)
        {   if(a[i] > a[j]){b=a[i];a[i]=a[j];a[j]=b;}
        }
    }
    return a[4];
}

int main()
{   int a,b,mode,i,j;
    cin >> a;
    cin >> b;
    cin >> mode;
    int arr1[b+2][a+2],med5[5],med9[9];
    for(i=0;i<a+2;i++)
    {   arr1[0][i] = 0;
    }
    for(i=0;i<b+2;i++)
    {   arr1[i][0] = 0;
    }
    for(i=0;i<b+2;i++)
    {   arr1[i][a+1] = 0;
    }
    for(i=0;i<a+2;i++)
    {   arr1[b+1][i] = 0;
    }
    for(i=0;i<b;i++)
    {   for(j=0;j<a;j++)
        {   cin >> arr1[i+1][j+1];
        }
    }

    if(mode == 4)
    {   for(i=1;i<b+1;i++)
        {   for(j=1;j<a+1;j++)
            {   med5[0]=arr1[i][j];
                med5[1]=arr1[i+1][j];
                med5[2]=arr1[i-1][j];
                med5[3]=arr1[i][j+1];
                med5[4]=arr1[i][j-1];
                cout << medi5(med5) << " ";
            }
        cout << "\n";
        }
    }else
    {   for(i=1;i<b+1;i++)
        {   for(j=1;j<a+1;j++)
            {   med9[0]=arr1[i][j];
                med9[1]=arr1[i][j-1];
                med9[2]=arr1[i][j+1];
                med9[3]=arr1[i+1][j];
                med9[4]=arr1[i+1][j-1];
                med9[5]=arr1[i+1][j+1];
                med9[6]=arr1[i-1][j];
                med9[7]=arr1[i-1][j-1];
                med9[8]=arr1[i-1][j+1];
                cout << medi9(med9) << " ";
            }
        cout << "\n";
        }
    }
    return 0;
}


