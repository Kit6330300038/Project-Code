#include <bits/stdc++.h>
using namespace std;

struct Node
{   int value;
    struct Node *Next;
};
struct Node *adj[8]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},*q=NULL;

void Enqueue(int a)
{   if(q==NULL)
    {   q=new struct Node;
        q->value = a;
        q->Next = NULL;
        return;
    }else
    {   struct Node *p=q,*n;
        while(p->Next!=NULL)
            p=p->Next;
        n=new struct Node;
        n->value = a;
        n->Next = NULL;
        p->Next = n;
        return;
    }
}
void dequeue()
{   struct Node *p=q;
    q=q->Next;
    delete p;
    return;
}
int queuesize()
{   if(q!=NULL)
        return 1;
    return 0;
}
int head(struct Node *a)
{   return a->value;
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
void path(int a,int b[8],int c)
{   if(b[c]!=a)
    {   path(a,b,b[c]);
        cout << ",";
    }
    cout << "(" << b[c] << "," << c << ")";
}
void two()
{   struct Node *node;
    int s,i,u,v,pass[8],d[8],pred[8];
    for(i=0;i<8;i++)
    {   pass[i]=0;d[i]=0;pred[i]=0;
    }
    cout << " Input source vertex : ";
    cin >> s;
    Enqueue(s);
    while(queuesize()!= 0)
    {   u = head(q);
        node=adj[u];
        while( node!= NULL)
        {   v= node->value;
            if(!pass[v])
            {   pass[v] = 1;
                d[v] = d[u]+1;
                pred[v] = u;
                Enqueue(v);
            }
            node=node->Next;
        }
        dequeue();
    }
    cout << " Distance\n ";
    for(i=0;i<8;i++)
        cout << s << "->" << i << " = " << d[i] << "\n ";
    cout << "Path\n ";
    for(i=0;i<8;i++)
    {   cout << s << "->" << i << " = ";
        path(s,pred,i);
        cout << "\n ";
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

int menu()
{   int a;
    cout << "=============Menu===========\n";
    cout << " 1) Insert Graph\n";
    cout << " 2) BFS\n";
    cout << " 3) Exit\n";
    cout << " Please choose > ";
    cin >> a;
    return a;
}

int main()
{   while(1)
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
