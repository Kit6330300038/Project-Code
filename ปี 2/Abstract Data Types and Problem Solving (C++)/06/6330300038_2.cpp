#include <bits/stdc++.h>
using namespace std;

struct record
{   int value;
    struct record *next;
};

struct record *head1=NULL ,*head2=NULL ,*head3=NULL ,*head4=NULL;
int open[4]={-1,-1,-1,-1},num=1;

void insert(int data)
{   struct record *p,*node;
    if(data==0)
    {   if(head1==NULL)
        {   head1= new struct record;
            head1-> value = num;
            head1-> next = NULL;
            num++;open[0]++;
        }else
        {   p=head1;
            while(p->next!=NULL){p=p->next;}
            node=new struct record;
            node->value = num;
            node->next = NULL;
            p->next = node;
            num++;open[0]++;
        }
    }else if(data==1)
    {   if(head2==NULL)
        {   head2= new struct record;
            head2-> value = num;
            head2-> next = NULL;
            num++;open[1]++;
        }else
        {   p=head2;
            while(p->next!=NULL){p=p->next;}
            node=new struct record;
            node->value = num;
            node->next = NULL;
            p->next = node;
            num++;open[1]++;
        }
    }else if(data==2)
    {   if(head3==NULL)
        {   head3= new struct record;
            head3-> value = num;
            head3-> next = NULL;
            num++;open[2]++;
        }else
        {   p=head3;
            while(p->next!=NULL){p=p->next;}
            node=new struct record;
            node->value = num;
            node->next = NULL;
            p->next = node;
            num++;open[2]++;
        }
    }else if(data==3)
    {   if(head4==NULL)
        {   head4= new struct record;
            head4-> value = num;
            head4-> next = NULL;
            num++;open[3]++;
        }else
        {   p=head4;
            while(p->next!=NULL){p=p->next;}
            node=new struct record;
            node->value = num;
            node->next = NULL;
            p->next = node;
            num++;open[3]++;
        }
    }
}

void Delete(int amount,int row)
{   struct record *node;
    int i;
    if(row==0)
    {   for(i=0;i<amount;i++)
        {   if(head1!=NULL)
            {   node = head1;
                head1=head1->next;
                delete node;
                open[0]--;
            }
        }
    }else if(row==1)
    {   for(i=0;i<amount;i++)
        {   if(head2!=NULL)
            {   node = head2;
                head2=head2->next;
                delete node;
                open[1]--;
            }
        }
    }else if(row==2)
    {   for(i=0;i<amount;i++)
        {   if(head3!=NULL)
            {   node = head3;
                head3=head3->next;
                delete node;
                open[2]--;
            }
        }
    }else if(row==3)
    {   for(i=0;i<amount;i++)
        {   if(head4!=NULL)
            {   node = head4;
                head4=head4->next;
                delete node;
                open[3]--;
            }
        }
    }
};

int newr()
{   int i;
    for(i=0;i<4;i++)
    {   if(open[i]==-1){open[i]=0;return i;}
    }
    return 5;
}
void is2()
{   int co=0,i;
    for(i=0;i<4;i++)
    {   if(open[i]!=-1)co++;
    }
    i=0;
    while(co<2)
    {   if(open[i]==-1){open[i]=0;co++;}i++;
    }
}
int shortest()
{   int i,ret=6,lo=6;
    for(i=0;i<4;i++){if(open[i]<lo &&open[i]!=-1){lo=open[i];ret=i;}}
    return ret;
}

void CE()
{   int a,s,i;
    cout << " Enter number : ";
    cin >> a;
    is2();
    for(i=0;i<a;i++)
    {   s=shortest();
        if(open[s]<5)
        {   insert(s);
        }else
        {   s = newr();
            if(s != 5){insert(s);}
            else
            {   cout << " FULL \n";return;
            }
        }
    }
}

void printq()
{   struct record *p;
    if(open[0]!=-1)
    {   cout << "POS 0 |";
        p = head1;
        while(p!=NULL)
        {   cout << " " << p->value;
            p=p->next;
        }cout << "\n";
    }if(open[1]!=-1)
    {   cout << "POS 1 |";
        p = head2;
        while(p!=NULL)
        {   cout << " " << p->value;
            p=p->next;
        }cout << "\n";
    }if(open[2]!=-1)
    {   cout << "POS 2 |";
        p = head3;
        while(p!=NULL)
        {   cout << " " << p->value;
            p=p->next;
        }cout << "\n";
    }if(open[3]!=-1)
    {   cout << "POS 3 |";
        p = head4;
        while(p!=NULL)
        {   cout << " " << p->value;
            p=p->next;
        }cout << "\n";
    }
}

void close()
{   int i,a=0;
    for(i=0;i<4;i++)
    {   if(open[i]!=-1){a++;}
    }
    if(a>2)
    {   for(i=0;i<4;i++)
        {   if(open[i]==0){open[i]=-1;}
        }
    }
}

int menu()
{   int a;
    cout << "=============Menu===========\n";
    cout << " 1) Customer Enqueue\n";
    cout << " 2) Cashier work\n";
    cout << " 3) Exit\n";
    cout << " Please choose > ";
    cin >> a;
    return a;
}

int main()
{   int a,b,c;
    while(1)
    {   a = menu();
        switch(a)
        {   case 1:
                CE();
                printq();
                break;
            case 2:
                cout << " Queue : ";
                cin >> b;
                cout << "Number : ";
                cin >> c;
                Delete(c,b);
                close();
                printq();
                break;
            case 3:
                exit(1);
        }
    }
}
