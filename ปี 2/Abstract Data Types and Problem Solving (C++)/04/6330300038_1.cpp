#include <bits/stdc++.h>
using namespace std;

struct record
{   int data;
    struct record *next;
    struct record *prev;
};

struct headtail
{
    struct record *ht_head;
    struct record *ht_tail;
};

struct headtail insert(struct record *head, struct record *tail, int data)
{   struct headtail ht;
    struct record *p,*node;
    if(head==NULL && tail==NULL)
    {   head=new struct record;
        head->data=data;
        head->prev=NULL;
        head->next=NULL;
        tail=head;
        ht.ht_head=head;
        ht.ht_tail=tail;
    }else if( data <= head->data)
    {   p=new struct record;
        p->data=data;
        p->prev=NULL;
        p->next=head;
        p->next->prev=p;
        head=p;
        ht.ht_head=head;
        ht.ht_tail=tail;;
    }
    else if( data >= tail->data)
    {   p=new struct record;
        p->data=data;
        p->prev=tail;
        p->next=NULL;
        p->prev->next=p;
        tail=p;
        ht.ht_head=head;
        ht.ht_tail=tail;
    }
    else
    {   node = head;
        p=new struct record;
        p->data=data;
        while(node->next != NULL){if(node->next->data > data){break;}node=node->next;}
        p->prev=node;
        p->next=node->next;
        node->next->prev=p;
        node->next=p;
        ht.ht_head=head;
        ht.ht_tail=tail;
    }
    return ht;
};

struct headtail Delete(struct record *head, struct record *tail, int data)
{   struct headtail ht;
    struct record *p;
    if(head==NULL && tail==NULL){cout << " No data Empty list!\n";}
    else if( data == head->data)
    {
        if(head==tail)
        {   delete head;
            head=NULL;
            tail=NULL;
        }
        else
        {   p=head->next;
            p->prev=NULL;
            delete head;
            head=p;
        }

        cout << data << " Deleted!\n";
    }
    else if( data == tail->data)
    {   if(head==tail)
        {   delete tail;
            head=NULL;
            tail=NULL;
        }else
        {   p=tail->prev;
            p->next=NULL;
            delete tail;
            tail=p;
        }
        cout << data << " Deleted!\n";
    }
    else
    {   p=head;
        while(p->next != NULL){if(p->data >= data){break;}p=p->next;}
        if(p->data==data)
        {   p->prev->next=p->next;
            p->next->prev=p->prev;
            delete p;
            cout << data << " Deleted!\n";
        }
    }
    ht.ht_head=head;
    ht.ht_tail=tail;
    return ht;
};

struct headtail print(struct record *head)
{   struct record *node=head;
    while(node != NULL)
    {
        cout << node->data << " ";
        node=node->next;
    }
    cout << "\n";
};

struct headtail printback(struct record *tail)
{   struct record *node=tail;
    while(node != NULL)
    {
        cout << node->data << " ";
        node=node->prev;
    }
    cout << "\n";
};

struct headtail weirdprint(struct record *head,struct record *tail)
{   struct record *b=tail,*f=head;
    if(head==NULL&&tail==NULL){;}
    else{   while(1)
    {   cout << f->data << " ";
        if(b->data == f->data){break;}
        f=f->next;
        cout << b->data << " ";
        if(b->data ==f->data){break;}
        b=b->prev;
    }}
    cout << "\n";
};

int menu()
{
    int a;
    cout << "=============Menu===========\n";
    cout << " 1) Insert\n";
    cout << " 2) Delete\n";
    cout << " 3) Print min to max & max to min\n";
    cout << " 4) Print\n";
    cout << " 5) Exit\n";
    cout << " Please choose > ";
    cin >> a;
    return a;
}

int main()
{
    struct record *head=NULL,*tail=NULL, *p;
    struct headtail ht;
    int data,num=0;
    while(1)
    {   num=menu();
        switch(num)
        {   case 1:
                cout<< " Enter : ";
                cin>> data;
                ht=insert(head,tail,data);
                head=ht.ht_head;
                tail=ht.ht_tail;
                break;
            case 2:
                cout << " List : ";
                print(head);
                cout << " Delete : ";
                cin >> data;
                ht=Delete(head,tail,data);
                head=ht.ht_head;
                tail=ht.ht_tail;
                break;
            case 3:
                cout << " Min to max : ";
                print(head);
                cout << " Max to min : ";
                printback(tail);
                break;
            case 4:
                cout << " Print : ";
                weirdprint(head,tail);
                break;
            case 5:
                exit(1);
        }
    }
}
