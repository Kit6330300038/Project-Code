#include <bits/stdc++.h>
using namespace std;

struct data
{   string key,f_name,l_name;
};

void one()
{   ifstream cin("data.txt");
    int i=0,j;
    string a,b,c;
    struct data *arr[11],*p;
    while(i<11)
        arr[i++]=NULL;
    while(!cin.eof())
    {   cin >> a >> b >> c;
        p=new struct data;
        p->key=a; p->f_name=b; p->l_name=c;
        i=stoi(a)%11;
        if(arr[i]==NULL)
        {   arr[i]=p;
        }else
        {   j=1;
            while(arr[(i+j)%11]!=NULL&&j<6)
                j++;
            if(j>5)
            {   cout << "Error, can not insert data!\n";
                i=-1;break;
            }
            arr[(i+j)%11]=p;
        }
    }
    cout << "Index\t  value\n";
    for(i=0;i<11;i++)
    {   if(arr[i]!=NULL)
            cout << i <<"\t: " << arr[i]->key << "\t" << arr[i]->f_name << " " << arr[i]->l_name << "\n";
    }
}
void two()
{   ifstream cin("data.txt");
    int i=0,j;
    string a,b,c;
    struct data *arr[11],*p;
    while(i<11)
        arr[i++]=NULL;
    while(!cin.eof())
    {   cin >> a >> b >> c;
        p=new struct data;
        p->key=a; p->f_name=b; p->l_name=c;
        i=stoi(a)%11;
        if(arr[i]==NULL)
        {   arr[i]=p;
        }else
        {   j=1;
            while(arr[(i+j*j)%11]!=NULL&&j<6)
                j++;
            if(j>5)
            {   cout << "Error, can not insert data!\n";
                i=-1;break;
            }
            arr[(i+j)%11]=p;
        }
    }
    cout << "Index\t  value\n";
    for(i=0;i<11;i++)
    {   if(arr[i]!=NULL)
            cout << i <<"\t: " << arr[i]->key << "\t" << arr[i]->f_name << " " << arr[i]->l_name << "\n";
    }
}
int menu()
{   int a;
    cout << "=============Menu===========\n";
    cout << " 1. Insert to table(Linear Probling)\n";
    cout << " 2. Insert to table (Quardratic probling)\n";
    cout << " 3. Exit\n";
    cout << " Please choose > ";
    cin >> a;
    return a;
}

int main()
{   int a;
    while(1)
    {   switch(menu())
        {   case 1:
                one();
                break;
            case 2:
                two();
                break;
            case 3:
                exit(1);
        }
    }
}
