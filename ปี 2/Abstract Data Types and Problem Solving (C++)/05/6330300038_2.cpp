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

int Top(Stack S)
{   return S->Next->value;}

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

int menu()
{   int a;
    cout << "============MENU================\n";
    cout << " 1) Input infix expression\n";
    cout << " 2) Input infix expression\n";
    cout << " 3) Postfix\n";
    cout << " 4) Answer\n";
    cout << " 5) Exit\n";
    cout << " Please choose > ";
    cin >> a;
    return a;
}

string converts(int a)//1=+,2=-,3=*,4=/,5=(
{   if(a==1)return "+";
    else if(a==2)return "-";
    else if(a==3)return "*";
    else if(a==4)return "/";
}
int converti(char a)
{   if(a=='+')return 1;
    else if(a=='-')return 2;
    else if(a=='*')return 3;
    else if(a=='/')return 4;
    else if(a=='(')return 5;
}

string Input(Stack S)
{   string t,ret="",word;
    cin.ignore();
    getline(cin,t);
    istringstream iss(t);
    while(iss >> word)
    {   if(word[0] == '+' || word[0] == '-')
        {   if(IsEmpty(S)){Push(converti(word[0]),S);}
            else if(Top(S)==1||Top(S)==2)
            {   ret += converts(Top(S));
                Pop(S);Push(converti(word[0]),S);
            }
            else
            {   ret += converts(Top(S));
                Pop(S);
                if(IsEmpty(S)){Push(converti(word[0]),S);}
                else
                {   ret += " ";ret += converts(Top(S));
                    Pop(S);Push(converti(word[0]),S);
                }
            }
        }
        else if(word[0] == '*' || word[0] == '/' )
        {   if(IsEmpty(S)){Push(converti(word[0]),S);}
            else if(Top(S)==1||Top(S)==2){Push(converti(word[0]),S);}
            else
            {   ret += converts(Top(S));
                Pop(S);
                if(IsEmpty(S)){Push(converti(word[0]),S);}
                else
                {   ret += converts(Top(S));
                    Pop(S);Push(converti(word[0]),S);
                }
            }
        }
        else{ret += word;}
        ret += " ";
    }
    while(!IsEmpty(S))
    {   ret += converts(Top(S));
        Pop(S);
        ret += " ";
    }
    return ret;
}

string Inputhmode(Stack S)
{   string t,ret="",word;
    cin.ignore();
    getline(cin,t);
    istringstream iss(t);
    while(iss >> word)
    {   if(word[0] == '+' || word[0] == '-')
        {   if(IsEmpty(S)){Push(converti(word[0]),S);}
            else if( Top(S)==5 ){Push(converti(word[0]),S);}
            else if(Top(S)==1||Top(S)==2)
            {   ret += converts(Top(S));
                Pop(S);Push(converti(word[0]),S);
            }
            else
            {   ret += converts(Top(S));
                Pop(S);
                if(IsEmpty(S)){Push(converti(word[0]),S);}
                else if(Top(S)==5){Push(converti(word[0]),S);}
                else
                {   ret += " ";ret += converts(Top(S));
                    Pop(S);Push(converti(word[0]),S);
                }
            }
        }
        else if(word[0] == '*' || word[0] == '/' )
        {   if(IsEmpty(S)){Push(converti(word[0]),S);}
            else if(Top(S)==1||Top(S)==2){Push(converti(word[0]),S);}
            else
            {   ret += converts(Top(S));
                Pop(S);
                if(IsEmpty(S) || Top(S)==5){Push(converti(word[0]),S);}
                else
                {   ret += converts(Top(S));
                    Pop(S);Push(converti(word[0]),S);
                }
            }
        }
        else if(word[0] == '('){Push(converti(word[0]),S);}
        else if(word[0] == ')')
        {   while(Top(S)!=5)
            {   ret += converts(Top(S));
                Pop(S);
                ret += " ";
            }
            Pop(S);
        }
        else{ret += word;}
        ret += " ";
    }
    while(!IsEmpty(S))
    {   ret += converts(Top(S));
        Pop(S);
        ret += " ";
    }
    return ret;
}

int total(string a,Stack S)
{
    string word;
    int top,ret,f,b;
    istringstream iss(a);
    while(iss >> word)
    {   if(word[0] == '+' )
        {   b=Top(S);Pop(S);
            f=Top(S);Pop(S);
            Push(f+b,S);
        }
        else if(word[0] == '-' )
        {   b=Top(S);Pop(S);
            f=Top(S);Pop(S);
            Push(f-b,S);
        }
        else if(word[0] == '*' )
        {   b=Top(S);Pop(S);
            f=Top(S);Pop(S);
            Push(f*b,S);
        }
        else if(word[0] == '/' )
        {   b=Top(S);Pop(S);
            f=Top(S);Pop(S);
            Push(f/b,S);
        }
        else{Push(atoi(word.c_str()),S);}
    }
    ret=Top(S);Pop(S);
    return ret;
}

int main()
{   Stack S=CreateStack();
    int data,num=0;
    string postfix,word;
    while(1)
    {   num=menu();
        switch(num)
        {   case 1:
                cout << " Infix : ";
                postfix = Input(S);
                break;
            case 2:
                cout << " Infix (): ";
                postfix = Inputhmode(S);
                break;
            case 3:
            {   cout << " Postfix : ";
                istringstream iss(postfix);
                while(iss >> word){cout <<word<<" ";}
                cout << "\n";
                break;
            }
            case 4:
                cout << " Answer = " << total(postfix,S)<<"\n";
                break;
            case 5:
                exit(1);
        }

    }

}
