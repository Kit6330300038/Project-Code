#include <bits/stdc++.h>
using namespace std;

struct Node
{   int value;
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

void Push(int X,Stack S)
{   Stack TmpCell;
    TmpCell = new struct Node;
    if(TmpCell == NULL)
        cout << "Out of space!!!";
    else
    {   TmpCell->value = X;
        TmpCell->Next = S->Next;
        S->Next = TmpCell;
    }
}

int IsEmpty(Stack S)
{   return S->Next == NULL;
}

void Top(Stack S)
{   if(!IsEmpty(S)){cout << S->Next->value<< endl;}
    else{cout << " Empty Stack!!!\n";}

}
void Pop(Stack S)
{   Stack FirstCell;
    if(IsEmpty(S))
        cout << " Empty Stack!!!\n";
    else
    {   FirstCell = S->Next;
        S->Next = S->Next->Next;
        delete(FirstCell);
        cout << "Pop!\n";
    }
}

int menu()
{
    int a;
    cout << "============MENU================\n";
    cout << " 1) Create Stack\n";
    cout << " 2) Push\n";
    cout << " 3) Pop\n";
    cout << " 4) Top\n";
    cout << " 5) Exit\n";
    cout << " Please choose > ";
    cin >> a;
    return a;
}

int main()
{   int data,a;
    Stack A;
    while(1)
    {
        a=menu();
        switch(a)
        {   case 1:
                A = CreateStack();
                break;
            case 2:
                cout << " Push : ";
                cin >> data;
                Push(data,A);
                break;
            case 3:
                Pop(A);
                break;
            case 4:
                Top(A);
                break;
            case 5:
                exit(1);
        }
    }
}
