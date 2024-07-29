#include <bits/stdc++.h>
using namespace std;

struct record
{   string value;
    struct record *left;
    struct record *right;
};
struct Node
{   struct record *t;
    struct Node *Next;
};
typedef struct Node *Stack;

Stack CreateStack(void)
{   Stack S;
    S = new struct Node;
    if (S== NULL)
        cout <<"Out of space!!!"<<endl;
    S->Next=NULL;
    return S;
}

void Push(struct record *X,Stack S)
{   Stack TmpCell;
    TmpCell = new struct Node;
    if(TmpCell == NULL)
        cout << "Out of space!!!";
    else
    {   TmpCell->t = X;
        TmpCell->Next = S->Next;
        S->Next = TmpCell;
    }
}

int IsEmpty(Stack S)
{   return S->Next == NULL;
}

struct record *Top(Stack S)
{   return S->Next->t;}

void Pop(Stack S)
{   Stack FirstCell;
    if(IsEmpty(S))
        cout << " Empty Stack!!!\n";
    else
    {   FirstCell = S->Next;
        S->Next = S->Next->Next;
        delete(FirstCell);
    }
}

struct record *insert(struct record *tree, string x)
{   if(tree==NULL)
    {   tree = new struct record;
        tree->value = x;
        tree->left = tree->right = NULL;
    }else
    {   if( x < tree->value )
            tree->left = insert(tree->left, x);
        else if(x > tree->value)
            tree->right = insert(tree->right, x);
        return tree;
    }
}

void addt(Stack S)
{   struct record *t;
    string a,word;
    cout << " Input : ";
    cin.ignore();
    getline(cin,a);
    istringstream iss(a);
    while(iss >> word)
    {   t = NULL;
        t = insert(t,word.c_str());
        Push(t,S);
    }cout << " Push Success!\n";
}

void popout(Stack S)
{   if(!IsEmpty(S))
    {   cout << " Top = " << Top(S)->value << "\n";
        Pop(S);
        cout << " Pop success!\n";
    }
}

int menu()
{   int a;
    cout << "=============Menu===========\n";
    cout << " 1) Input \n";
    cout << " 2) Pop \n";
    cout << " 3) Exit\n";
    cout << " Please choose > ";
    cin >> a;
    return a;
}

int main()
{   Stack S=CreateStack();
    int a,b,c;
    struct node *t=NULL;
    while(1)
    {   a = menu();
        switch(a)
        {   case 1:
                addt(S);
                break;
            case 2:
                popout(S);
                break;
            case 3:
                exit(1);
        }
    }
}
