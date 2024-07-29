#include <bits/stdc++.h>
using namespace std;

struct linklist
{   int value;
    struct linklist *next;
};

struct linklist *last,*head=NULL;
void in(int a)
{   struct linklist *p;
    head=new struct linklist;
    head->value=a;
    head->next=NULL;
    last=head;
    for(int i=1;i<a;i++)
    {   p=new struct linklist;
        p->next=head;
        p->value=a-i;
        head=p;
    }
}
void sw(int st,int en)
{   struct linklist *pf,*pl,*n;
    if(head->value==st)
    {   pl=head;
        while(pl->value!=en)
        {   pl=pl->next;
        }
        if(pl->next!=NULL)
        {   n=pl->next;
            pl->next=NULL;
            last->next=head;
            last=pl;
            head=n;
        }
    }
    else
    {   n=head;
        while(n->next->value!=st)
        {   n=n->next;
        }
        pf=pl=n->next;
        while(pl->value!=en)
        {   pl=pl->next;
        }
        if(pl->next!=NULL)
        {   n->next=pl->next;
            pl->next=NULL;
            last->next=pf;
            last=pl;
        }
    }
}

int main()
{   struct linklist *p;
    int a,b,i;
    cin >> a;
    cin >> b;
    in(a);
    int st[b],ed[b];
    for(i=0;i<b;i++)
    {   cin >> st[i];
        cin >> ed[i];
    }
    i=0;
    while(ed[i]+1==st[i+1])
    {   st[i+1]=st[i];
        st[i]=1;ed[i]=a;
    }
    for(i=0;i<b;i++)
    {   sw(st[i],ed[i]);

    }
    p=head;
    while(p!=NULL)
    {   cout << p->value<< "\n";
        p=p->next;
    }
}
