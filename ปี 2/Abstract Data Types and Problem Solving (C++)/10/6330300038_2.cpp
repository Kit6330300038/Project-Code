#include <bits/stdc++.h>
using namespace std;

struct Node
{   int value;
    struct Node *Next;
};
struct Node *adj[9]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
int pass[9],d[9],f[9],pred[9],Time=0;
string dress[9]={"undershort","pants","belt","shirt","tie","jacket","socks","shoes","watch"};

void DFS_Visit(int u)
{   struct Node *p;
    pass[u]=1;
    d[u]=++Time;
    p=adj[u];
    while(p!=NULL)
    {   if(pass[p->value] == 0)
        {   pred[p->value] = u;
            DFS_Visit(p->value);
        }
        p=p->Next;
    }
    pass[u]=1;
    f[u]=++Time;
}

void DFS()
{   int i,j,top;
    Time=0;
    for(i=0;i<9;i++)
    {   pass[i]=0;
        pred[i]=-1;
    }
    for(i=0;i<9;i++)
    {   if(pass[i]==0)
        {   DFS_Visit(i);
        }
    }
    cout << " dress : ";
    for(i=0;i<8;i++)
    {   top=0;
        for(j=1;j<9;j++)
        {   if(f[top]<f[j])
            {   top=j;
            }
        }
        f[top]=-1;
        cout << dress[top] << ", ";
    }
    for(i=0;i<9;i++)
    {   if(f[i]!=-1)
        {   cout << dress[i] << endl;
            break;
        }
    }
}

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

void one()
{   string a,word;
    int i;
    cin.ignore();
    for(i=0;i<9;i++)
    {   cout << " #" << i <<" : ";
        getline(cin,a);
        istringstream iss(a);
        while(iss >> word)
            adj[i]=insert(stoi(word),adj[i]);
    }
}

int menu()
{   int a;
    cout << "=============Menu===========\n";
    cout << " 1) Insert Graph\n";
    cout << " 2) Topological Sort\n";
    cout << " 3) Exit\n";
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
                DFS();
                break;
            case 3:
                exit(1);
        }
    }
}
