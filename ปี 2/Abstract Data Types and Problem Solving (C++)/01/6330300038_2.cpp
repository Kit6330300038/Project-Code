#include <bits/stdc++.h>
using namespace std;

string a[4][4] ={{"T","H","I","S"},
                {"W","A","T","S"},
                {"O","A","H","G"},
                {"F","G","D","T"}};
void a1(int b)
{
    int i,j,k;
    for(i=0 ;i<4 ;i++)
    {
        for(j=i ;j<4 ;j++)
        {
            for(k=i ;k<=j ;k++)
            {
                cout << a[b][k];
            }
            cout << " ";
        }
    }
}
void a2(int b)
{
    int i,j,k;
    for(i=3 ;i>=0 ;i--)
    {
        for(j=i ;j>=0 ;j--)
        {
            for(k=i ;k>=j ;k--)
            {
                cout << a[b][k];
            }
            cout << " ";
        }
    }
}
void a3(int b)
{
    int i,j,k;
    for(i=0 ;i<=b ;i++)
    {
        for(j=i ;j<=b ;j++)
        {
            for(k=i ;k<=j ;k++)
            {
                cout << a[b-k][k];
            }
            cout << " ";
        }
    }
}
void a4(int b)
{
    int i,j,k;
    for(i=0 ;i<=b ;i++)
    {
        for(j=i ;j<=b ;j++)
        {
            for(k=i ;k<=j ;k++)
            {
                cout << a[k][b-k];
            }
            cout << " ";
        }
    }
}
int main()
{

    for(int i=0;i<4;i++)
    {
        a1(i);
        cout << "\n";
    }
    cout << "\n\n";
    for(int i=0;i<4;i++)
    {
        a2(i);
        cout << "\n";
    }
    cout << "\n\n";
    for(int i=0;i<4;i++)
    {
        a3(i);
        cout << "\n";
    }
        cout << "\n\n";
    for(int i=0;i<4;i++)
    {
        a4(i);
        cout << "\n";
    }
}

