#include <bits/stdc++.h>
using namespace std;

struct Node
{   int value;
    struct Node *Next;
};
struct Node *adj[8]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
int pass[8],d[8],f[8],pred[8],Time=0;

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

void p_d(int a)
{   if(a<7)
    {   cout << d[a] << ", ";
        p_d(a+1);
        return;
    }
    cout << d[a] << "\n";
    return;
}
void p_f(int a)
{   if(a<7)
    {   cout << f[a] << ", ";
        p_f(a+1);
        return;
    }
    cout << f[a] << "\n";
}
void p_pred(int a)
{   if(a<7)
    {   cout << pred[a] << ", ";
        p_pred(a+1);
        return;
    }
    cout << pred[a] << "\n";
}

void DFS(int a)
{   int i;
    Time=0;
    for(i=0;i<8;i++)
    {   pass[i]=0;
        pred[i]=-1;
    }
    DFS_Visit(a);
    for(i=0;i<8;i++)
    {   if(pass[i]==0)
        {   DFS_Visit(i);
        }
    }
    cout << " D = ";
    p_d(0);
    cout << " F = ";
    p_f(0);
    cout << " Pred = ";
    p_pred(0);
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

int menu()
{   int a;
    cout << "=============Menu===========\n";
    cout << " 1) Insert Graph\n";
    cout << " 2) Print adjacency List\n";
    cout << " 3) DFS\n";
    cout << " 4) Exit\n";
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
                cout << " Input source vertex : ";
                cin >> a;
                DFS(a);
                break;
            case 4:
                exit(1);
        }
    }
}
