#include <bits/stdc++.h>
using namespace std;

struct Node
{   int value;
    struct Node *Next;
};
struct Node *adj[8]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};;
string matrix[8][8];

struct Node *insert(int i,struct Node *a)
{   struct Node *p,*n;
    if(a==NULL)
    {   p=new struct Node;
        p->value = i;
        p->Next = NULL;
        return p;
    }else if(i<a->value)
    {   p=new struct Node;
        p->value = i;
        p->Next = a;
        return p;
    }else
    {   n=a;
        while(n->Next!=NULL&&i>n->Next->value)
            n=n->Next;
        p=new struct Node;
        p->value = i;
        p->Next = n->Next;
        n->Next = p;
        return a;
    }
}
void insert_matrix(int a,int b)
{   matrix[a][b]="1";
}

void one()
{   string a,word;
    int i;
    cin.ignore();
    for(i=0;i<8;i++)
    {   cout << " #" << i <<" : ";
        getline(cin,a);
        istringstream iss(a);
        while(iss >> word)
        {   adj[i]=insert(stoi(word),adj[i]);
            insert_matrix(i,stoi(word));
        }
    }

}
void two()
{   int i;
    struct Node *p;
    for(i=0;i<8;i++)
    {   cout << " list[" << i << "] = ";
        p=adj[i];
        while(p!=NULL)
        {   cout << p->value << " ";
            p=p->Next;
        }
        cout << "\n";
    }
}
void three()
{   int i,j;
    cout << "     0  1  2  3  4  5  6  7\n";
    cout << "-----------------------------\n";
    for(i=0;i<8;i++)
    {   cout << i << " |  ";
        for(j=0;j<8;j++)
        {   cout << matrix[i][j] << "  ";
        }
        cout << "\n";
    }

}

int menu()
{   int a;
    cout << "=============Menu===========\n";
    cout << " 1) Insert Graph\n";
    cout << " 2) Print graph from adjacency list\n";
    cout << " 3) Print graph from adjacency matrix\n";
    cout << " 4) Exit\n";
    cout << " Please choose > ";
    cin >> a;
    return a;
}

int main()
{   int i,j;
    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            matrix[i][j]="0";
    while(1)
    {   switch(menu())
        {   case 1:
                one();
                break;
            case 2:
                two();
                break;
            case 3:
                three();
                break;
            case 4:
                exit(1);
        }

    }

}
