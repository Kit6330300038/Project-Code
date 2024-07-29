#include <bits/stdc++.h>
using namespace std;

struct node
{   int value;
    int height;
    struct node *left;
    struct node *right;
};

int fheight(struct node *P)
{   if(P==NULL) return  -1;
    else return P->height;
}

struct node *srleft(struct node *k2)
{   struct node *k1;
    k1=k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(fheight(k2->left), fheight(k2->right)) + 1;
    k1->height = max(fheight(k1->left), k2->height) + 1;
    return k1;
}

struct node *srright(struct node *k2)
{   struct node *k1;
    k1=k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = max(fheight(k2->left), fheight(k2->right)) + 1;
    k1->height = max(fheight(k1->right), k2->height) + 1;
    return k1;
}

struct node *drleft(struct node *k3)
{   k3->left = srright(k3->left);
    return srleft(k3);
}

struct node *drright(struct node *k3)
{   k3->right = srleft(k3->right);
    return srright(k3);
}

void printpre(struct node *tree)
{   if( tree == NULL )return;
    else
    {   cout<< tree->value << " ";
        printpre(tree->left);
        printpre(tree->right);
    }   return;
}

struct node *insert(int x,struct node *T)
{   if(T == NULL)
    {   T=new struct node;
        T->value=x;
        T->left=T->right=NULL;
        T->height=0;
    }else if(x < T->value)
    {   T->left = insert(x,T->left);
        if(fheight(T->left)-fheight(T->right) == 2)
            if( x < T->left->value)
                T=srleft(T);
            else
                T=drleft(T);
    }else if(x > T->value )
    {   T->right = insert(x,T->right);
        if(fheight(T->right)-fheight(T->left) == 2)
            if( x > T->right->value)
                T=srright(T);
            else
                T=drright(T);
    }
    T->height = max(fheight(T->left),fheight(T->right)) + 1;
    return T;
}

int menu()
{   int a;
    cout << "=============Menu===========\n";
    cout << " 1) Insert\n";
    cout << " 2) Print\n";
    cout << " 3) Exit\n";
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
                t = insert(b,t);
                break;
            case 2:
                cout << " Preorder : ";
                printpre(t);
                cout << "\n";
                break;
            case 3:
                exit(1);
        }
    }

}
