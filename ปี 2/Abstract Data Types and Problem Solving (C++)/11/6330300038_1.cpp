#include <bits/stdc++.h>
using namespace std;

struct Node
{   int value;
    struct Node *Next;
};
struct Node *adj[8]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},*adjT[8]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
int pass[8],d[8],f[8],pred[8],Time=0;

void p_pred(int a)
{   if(a<7)
    {   cout << pred[a] << ", ";
        p_pred(a+1);
        return;
    }
    cout << pred[a] << "\n";
}
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
void DFS_VisitT(int u)
{   struct Node *p;
    pass[u]=1;
    p=adjT[u];
    cout << "( " << u << " ";
    while(p!=NULL)
    {   if(pass[p->value] == 0)
        {   DFS_VisitT(p->value);
        }
        p=p->Next;
    }
    cout << u << " ) " ;
}

void DFS()
{   int i,j,m;
    Time=0;
    for(i=0;i<8;i++)
    {   pass[i]=0;
        pred[i]=-1;
    }
    for(i=0;i<8;i++)
    {   if(pass[i]==0)
        {   DFS_Visit(i);
        }
    }
    cout << " Pred = ";
    p_pred(0);
    for(i=0;i<8;i++)
    {   pass[i]=0;
    }
    for(i=0;i<8;i++)
    {   m=0;
        for(j=1;j<8;j++)
        {   if(f[m]<f[j]&&pass[j]==0)
            {   m=j;
            }
        }
        if(pass[m]==0)
        {   cout <<" "<< i+1 << "  ";
            DFS_VisitT(m);
            cout << "\n";
            f[m]=-2;
        }else
        {   break;
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
    for(i=0;i<8;i++)
    {   cout << " #" << i <<" : ";
        getline(cin,a);
        istringstream iss(a);
        while(iss >> word)
            adj[i]=insert(stoi(word),adj[i]);
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
void T()
{   struct Node *p;
    int i;
    for(i=0;i<8;i++)
    {   p=adj[i];
        while(p!=NULL)
        {   adjT[p->value]=insert(i,adjT[p->value]);
            p=p->Next;
        }
    }
}

void three()
{   int i;
    struct Node *p;
    for(i=0;i<8;i++)
    {   cout << " list[" << i << "] = ";
        p=adjT[i];
        while(p!=NULL)
        {   cout << p->value << " ";
            p=p->Next;
        }
        cout << "\n";
    }
}

int menu()
{   int a;
    cout << "=============Menu===========\n";
    cout << " 1) Insert Graph\n";
    cout << " 2) Print Graph in adj\n";
    cout << " 3) Print Graph transpose in adjT\n";
    cout << " 4) Decompose\n";
    cout << " 5) Exit\n";
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
                T();
                break;
            case 2:
                two();
                break;
            case 3:
                three();
                break;
            case 4:
                DFS();
                break;
            case 5:
                exit(1);
        }
    }
}
