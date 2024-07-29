#include <bits/stdc++.h>
using namespace std;

struct record
{
    int value;
    struct record *next;
};
struct record *insert(struct record *head,int data)
{
    struct record *node,*p;
    if(head == NULL)
    {
        head= new struct record;
        head-> value = data;
        head-> next = NULL;
    }else if ( data < head->value)
    {

        if( data < head->value)
        {
            node=new struct record;
            node->value = data;
            node->next = head;
            head = node;
        }
    }
    else
    {

        p=head;
        node=new struct record;
        node-> value = data;
        while( p->next !=NULL)
        {
            if( data > p->next->value)
            p=p->next;
            else
            break;
        }
        node->next=p->next;
        p->next = node;

    }
    return head;
}

struct record *printList(struct record *head)
{
    struct record *node,*p;
    p=head;
    while(p !=NULL)
    {
        cout << p->value << " ";
        p=p->next;
    }
    cout << "\n";
};

struct record *printListback(struct record *head)
{
    if(head==NULL){}
    else if(head->next !=NULL)
    {
        printListback(head->next);
        cout << head->value << " ";
    }
    else
    {
        cout << head->value << " ";
    }
};

struct record *Delete(struct record *head,int data)
{
    struct record *prv=head,*p;
    if(prv==NULL){cout << "No data Empty list!\n";return(head);}
    p = prv->next;
    if (p==NULL&&prv->value==data){cout << prv->value << " Deleted!\n";delete prv;return p;}
    else if(p==NULL){return head;}
    while(p != NULL)
    {
        if(p->value < data && p->next!=NULL)
        {
            p = p->next;prv=prv->next;
        }
        else{break;}
    }
    if(p->value == data)
    {
        prv->next=p->next;
        cout << p->value << " Deleted!\n";
        delete p;
    }
    else{;}
    return head;

};

struct record *Find(struct record *head,int data)
{
    while(head != NULL)
    {
        if( data > head->value)
        head=head->next;
        else
        break;
    }
    if(head == NULL || head->value!=data)
    {
        cout << " Not found!";
    }
    else
    {
        cout << " Found " << data;
    }
};

int menu()
{
    int a;
    cout << "=============Menu ===========\n";
    cout << " 1) Insert\n";
    cout << " 2) Delete\n";
    cout << " 3) Print\n";
    cout << " 4) Print\n";
    cout << " 5) Find\n";
    cout << " 6) Exit\n";
    cout << " Please choose > ";
    cin >> a;
    return a;
}

int main()
{
    struct record *head=NULL;
    int select,info,i;
    while(1)
    {
        select=menu();
        switch(select)
        {
            case 1:
                cout << " Insert : ";
                cin >> info;
                head = insert(head,info);
                break;
            case 2:
                cout << " List : ";
                printList(head);
                cout << " Delete : ";
                cin >> info;
                head = Delete(head,info);
                break;
            case 3:
                cout << " Min to max : ";
                printList(head);
                break;
            case 4:
                cout << " Max to min : ";
                printListback(head);
                cout << "\n";
                break;
            case 5:
                cout << " Find : ";
                cin >> info;
                Find(head,info);
                cout << "\n";
                break;
            case 6:
                exit(1);
        }
    }

}

