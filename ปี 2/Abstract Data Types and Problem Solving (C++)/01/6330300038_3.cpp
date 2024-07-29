#include <bits/stdc++.h>
using namespace std;

int a[5]={0,0,0,0,0};
void add(int b)
{
    int pos=0,i,j;
    for(i=0;i<5;i++)
    {
        if(a[i]>b&&a[i]!=0)
        {
            pos=i;
            for(j=3;j>=pos;j--)
            {
                a[j+1]=a[j];
            }
            a[pos]=b;
            break;
        }else if(a[i]==0)
        {
            a[i]=b;
            break;
        }else{;}
    }

}
void c1()
{
    int b,i;
    cout << "Enter insert data : ";
    cin >> b;
    if(a[0]==0)
    {
        a[0]=b;
        cout << "list : " << a[0] <<"\n";
    }
    else if(a[4] != 0)
    {
        cout << "List full";
    }
    else
    {
        add(b);
        cout << "list :";
        for(i=0;i<5;i++)
        {
            if(a[i]==0)
            {
                break;
            }
            else
            {
                cout << " " << a[i];
            }
        }
    cout << "\n;";
    }

}
void c2()
{
    int b,pos,i;
    if(a[0]==0)
    {
        cout << "Empty list";
    }else{
    cout << "Delete : ";
    cin >> b;
    for(i=0;i<5;i++)
    {
        if(b==a[i])
        {
            pos=i;break;
        }else{;}
    }

    for(i=pos;i<4;i++)
    {
        a[i]=a[i+1];
    }
    a[4]=0;
    cout << "list :";
    for(i=0;i<5;i++)
    {
        if(a[i]==0)
        {
            break;
        }
        else
        {
            cout << " " << a[i];
        }
    }}
    cout << "\n;";

}
int main()
{
    int b;
    while(1)
    {
        cout << "======== MENU ========\n"
            << "1. Insert\n"
            << "2. Delete\n"
            << "3. Exit\n"
            << "Please choose > ";
        cin >> b;
        if(b == 1)
        {
            c1();
        }
        else if(b == 2)
        {
            c2();
        }
        else
        {
            break;
        }
    }
}
