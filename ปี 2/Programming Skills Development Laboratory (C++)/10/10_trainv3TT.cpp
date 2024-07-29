#include <bits/stdc++.h>
using namespace std;

struct linklist
{   int value;
    struct linklist *next,*prev;
};

int main()
{   int a,b,c,d,i;
    cin >> a;
    cin >> b;
    struct linklist *head=NULL,*arr[a],*p,*ft,*bk,*tail;
    head=new struct linklist;
    head->value=a;
    head->next=NULL;
    arr[a-1]=head;
    tail=head;
    for(i=1;i<a;i++)
    {   p=new struct linklist;
        p->value=a-i;
        p->next=head;
        head->prev=p;
        arr[a-1-i]=p;
        head=p;
    }
    head->prev=NULL;
    for(i=0;i<b;i++)
    {   cin >> c;
        cin >> d;
        ft=arr[c-1];
        bk=arr[d-1];
        if(ft->prev!=NULL)
        {   if(bk->next!=NULL)
            {   ft->prev->next=bk->next;
                bk->next->prev=ft->prev;
                ft->prev=tail;
                tail->next=ft;
                bk->next=NULL;
                tail=bk;
            }
        }else
        {   if(bk->next!=NULL)
            {   head->prev=tail;
                tail->next=head;
                bk->next->prev=NULL;
                head=bk->next;
                bk->next=NULL;
                tail=bk;
            }
        }
    }
    while(head!=NULL)
    {   cout << head->value << "\n";
        head=head->next;
    }
}
