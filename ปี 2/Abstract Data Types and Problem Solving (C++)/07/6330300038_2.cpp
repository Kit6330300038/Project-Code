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

void printin(struct node *tree)
{   if( tree == NULL )return;
    else
    {   printin(tree->left);
        cout<< tree->value << " ";
        printin(tree->right);
    }   return;
}

struct node *find_min(struct node *tree)
{   if(tree==NULL)return NULL;
    else if( tree->left == NULL )return tree;
    else return (find_min(tree->left));
}

struct node *dTree(struct node *tree,int x)
{   struct node *tmpcell, *child;
    if ( tree==NULL)
        printf("No Node\n");
    else
    {   if( x < tree->value)
            tree->left = dTree(tree->left, x);
        else
            if( x > tree->value)
                tree->right=dTree(tree->right,x );
            else
                if( tree->left && tree->right)
                {   tmpcell=find_min(tree->right);
                    tree->value = tmpcell->value;
                    tree->right = dTree(tree->right,tree->value );
                }
                else
                {   tmpcell=tree;
                    if( tree->left == NULL )
                        child = tree->right;
                    if(tree->right ==NULL)
                        child = tree->left;
                    delete(tmpcell);
                    cout << " Delete Success!\n";
                    return child;
                }
    }
    return tree;
}

void pleaves(struct node *t)
{   if(t==NULL)return;
    else if(t->left==NULL&&t->right==NULL)cout << t->value << " ";
    else
    {   pleaves(t->left);
        pleaves(t->right);
    }return;
};

void pnonleaves(struct node *t)
{   if(t==NULL)return;
    else if(t->left!=NULL&&t->right!=NULL)cout << t->value << " ";
    else
    {   pleaves(t->left);
        pleaves(t->right);
    }return;
};

int menu()
{   int a;
    cout << "=============Menu===========\n";
    cout << " 1) Insert\n";
    cout << " 2) Delete\n";
    cout << " 3) Print Inorder\n";
    cout << " 4) Print leave node, nonleave\n";
    cout << " 5) Exit\n";
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
                cout << " Delete : ";
                cin >> b;
                t = dTree(t,b);
                break;
            case 3:
                cout << " Inorder : ";
                printin(t);
                cout << "\n";
                break;
            case 4:
                cout << " Leaves node : ";
                pleaves(t);
                cout << "\n Nonleaves node : ";
                pnonleaves(t);
                cout << "\n";
                break;
            case 5:
                exit(1);
        }
    }
}
