#include <bits/stdc++.h>
using namespace std;

struct record
{ char value;
 struct record *next;
};

struct record *add(struct record *head,string data)
{
    struct record *prin,*p,*node;
    node = new struct record;
    node->value = data.at(0);
    node->next = NULL;
    head = node;

    for(int i=1; i<data.length(); i++)
    {
        p = head;
        node = new struct record;
        node->value = data.at(i);
        node->next = NULL;
        while(p->next != NULL){p=p->next;}
        p->next = node;
    }
    cout << " List : ";
    prin = head;
    while(prin != NULL)
    {
        cout << prin->value;
        prin=prin->next;
    }
    return head;
};

struct record *encode(struct record *head)
{
    int a=0,i;
    struct record *pf=head,*pb=head;
    while(head != NULL)
    {
        a++;head=head->next;
    }
    for(i=0; i<a/2;i++)
    {
        pb=pb->next;
    }
    cout << "Encode : ";
    while(pb !=NULL)
    {
        cout << pb->value;
        pb=pb->next;
    }
    for(i=0; i<a/2;i++)
    {
        cout << pf->value;
        pf=pf->next;
    }
    cout << "\n";
};

int menu()
{
    int a;
    cout << "=============Menu ===========\n";
    cout << " 1) Encode\n";
    cout << " 2) Show Encode data\n";
    cout << " 3) Exit\n";
    cout << " Please choose > ";
    cin >> a;
    return a;
}

int main()
{
    struct record *head=NULL;
    int a;
    string info;
    while(1)
    {
        a = menu();
        switch(a)
        {
            case 1:
                cout << " Enter code : ";
                cin >> info;
                head = add(head,info);
                cout << "\n";
                break;
            case 2:
                encode(head);
                break;
            case 3:
                exit(1);
        }
    }
}
