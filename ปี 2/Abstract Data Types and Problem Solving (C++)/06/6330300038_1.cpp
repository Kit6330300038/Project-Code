#include <bits/stdc++.h>
using namespace std;

struct record
{   int value;
    struct record *next;
};
struct record *insert(struct record *head,int data)
{
    struct record *node,*p;
    if(head == NULL)
    {   head= new struct record;
        head-> value = data;
        head-> next = head;
    }else
    {   p=head;
        while(p->next!=head)p=p->next;
        node=new struct record;
        node->value = data;
        node->next = head;
        p->next = node;
    }
    return head;
}

struct record *Delete(struct record *head,int data)
{   struct record *p=head->next,*node;
    int i;
    if(data==0)
    {   while(p->next!=head)
        {   p=p->next;
        }
        p->next = head->next;
        node = head->next;
        delete head;
    }
    else
    {   for(i=1;i<data;i++)
        {   head=head->next;p=p->next;
        }
        head->next=p->next;
        node = p->next;
        delete p;
    }
    return node;
};

int main()
{   int a,b,i;
    struct record *head=NULL;
    cin >> a;
    cin >> b;
    for(i=1;i<=a;i++)
    {   head = insert(head,i);
    }
    while(head->next!=head)
    {   head = Delete(head,b);
    }
    cout << head->value;
}
