#include <bits/stdc++.h>
using namespace std;

struct record
{   int value;
    struct record *next;
    struct record *prev;
};

struct record *insert(struct record *head, int data,int pow)
{   struct record *p,*p1,*node;
    if(head==NULL)
    {   p=new struct record;
        p->value=data;
        head=new struct record;
        head->value=pow;
        head->next=NULL;
        head->prev=p;
    }
    else if( pow >= head->value)
    {   if(pow == head->value){head->prev->value += data;}
        else
        {   p=new struct record;
            p->value=data;
            p1=new struct record;
            p1->value=pow;
            p1->next=head;
            p1->prev=p;
            head=p1;
        }
    }
    else
    {   node=head;
        while(node->next != NULL)
        {   if(node->next->value <= pow){break;}
            node=node->next;
        }
        if(node->next != NULL && node->next->value == pow)
        {   node=node->next;node->prev->value+=data;
        }
        else
        {   p=new struct record;
            p->value=data;
            p1=new struct record;
            p1->value=pow;
            p1->next=node->next;
            node->next=p1;
            p1->prev=p;
        }
    }
    return head;
};

void *printList(struct record *head)
{   struct record *p=head;
    while(p !=NULL)
    {   if(p->value != 1&&p->value != 0)
        {   if(p != head)
            {   cout << " + "<< p->prev->value << "x^"<< p->value;
            }else
            {   cout <<  p->prev->value << "x^" << p->value;
            }
        }else
        {   if(p->value == 0&&p!=head)
            {   cout << " + " << p->prev->value;
            }else if(p->value == 1&&p!=head)
            {   cout << " + " << p->prev->value << "x";
            }else if(p->value == 0&&p==head)
            {   cout << p->prev->value;
            }else
            {   cout << p->prev->value << "x";
            }
        }
        p=p->next;
    }
};

int main()
{
    struct record *head=NULL;
    int data,pow;
    cout << "Input P1 : ";
    while(1)
    {   cin >> data;
        if(data == -99){break;}
        cin >> pow;
        head=insert(head,data,pow);
    }
    cout << "Input P2 : ";
    while(1)
    {   cin >> data;
        if(data == -99){break;}
        cin >> pow;
        head=insert(head,data,pow);
    }
    cout << "Output : ";
    printList(head);
}
