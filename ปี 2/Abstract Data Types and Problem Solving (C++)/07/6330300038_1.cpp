#include <bits/stdc++.h>
using namespace std;

struct node
{   int value;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *tree, int x)
{   if(tree==NULL)
    {   tree = new struct node;
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

void printpre(struct node *tree)
{   if( tree == NULL )return;
    else
    {   cout<< tree->value << " ";
        printpre(tree->left);
        printpre(tree->right);
    }   return;
}
void printin(struct node *tree)
{   if( tree == NULL )return;
    else
    {   printin(tree->left);
        cout<< tree->value << " ";
        printin(tree->right);
    }   return;
}
void printpost(struct node *tree)
{   if( tree == NULL )return;
    else
    {   printpost(tree->left);
        printpost(tree->right);
        cout<< tree->value << " ";
    }   return;
}

struct node *find_min(struct node *tree)
{   if(tree==NULL)return NULL;
    else if( tree->left == NULL )return tree;
    else return (find_min(tree->left));
}
struct node *find_max(struct node *tree)
{   if(tree==NULL)return NULL;
    else if( tree->right == NULL )return tree;
    else return (find_max(tree->right));
}

int menu()
{   int a;
    cout << "=============Menu===========\n";
    cout << " 1) Insert\n";
    cout << " 2) Print Preorder, Inorder, PostOrder\n";
    cout << " 3) Print min and max\n";
    cout << " 4) Exit\n";
    cout << " Please choose > ";
    cin >> a;
    return a;
}

int main()
{   int a,b,c;
    struct node *t=NULL;
    while(1)
    {   a = menu();
        switch(a)
        {   case 1:
                cout << " Insert : ";
                cin >> b;
                t = insert(t,b);
                break;
            case 2:
                cout <<   " Preorder : ";
                printpre(t);
                cout << "\n Inorder  : ";
                printin(t);
                cout << "\n Postorder: ";
                printpost(t);
                cout << "\n";
                break;
            case 3:
                cout << " Min = " << find_min(t)->value << "\n";
                cout << " Max = " << find_max(t)->value << "\n";
                break;
            case 4:
                exit(1);
        }
    }
}
