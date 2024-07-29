#include <bits/stdc++.h>
using namespace std;

int amounth=2000000;

void one()
{   ofstream cout("data.txt");
    for (int i=0 ; i<amounth ; i++)
    {   cout << rand()%10000 << "\n";
    }
}
void two()
{   ifstream cin("data.txt");
    ofstream cout("s.txt");
    int i,j,m;
    int* arr = new int[amounth];
    for(i=0 ; i<amounth ; i++)
    {   cin >> arr[i];
    }
    for(i=0 ; i<amounth ; i++)
    {   m=i;
        for(j=i+1 ; j<amounth ; j++)
        {   if(arr[m]>arr[j])
                m=j;
        }
        j=arr[m];
        arr[m]=arr[i];
        arr[i]=j;
        cout << j << "\n";
    }
}
void three()
{   ifstream cin("data.txt");
    ofstream cout("b.txt");
    int i,j,n;
    int* arr = new int[amounth];
    for(i=0 ; i<amounth ; i++)
    {   cin >> arr[i];
    }
    for(i=0 ; i<amounth ; i++)
    {   for(j=amounth-1 ; j>0 ; j--)
        {   if(arr[j-1]>arr[j])
            {   n=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=n;
            }
        }
        cout << arr[i] << "\n";
    }
}
void four()
{   ifstream cin("data.txt");
    ofstream cout("i.txt");
    int i,j,n;
    int* arr = new int[amounth];
    for(i=0 ; i<amounth ; i++)
    {   cin >> arr[i];
    }
    for(i=1 ; i<amounth ; i++)
    {   j=i;
        while(j&&arr[j]<arr[j-1])
        {   n=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=n;
            j--;
        }
    }
    for(i=0 ; i<amounth ; i++)
    {   cout << arr[i] << "\n";
    }
}
int parents(int i)
{   return i/2;
}
int left(int i)
{   return 2*i;
}
int right(int i)
{   return 2*i+1;
}
void exchange(int A[],int a,int b)
{   int c;
    c=A[a];
    A[a]=A[b];
    A[b]=c;
}
void Heapify(int A[],int i,int s)
{   int l=left(i),r=right(i),largest;
    if(l <= s && A[l] > A[i])
    {   largest = l;
    }else
    {   largest = i;
    }
    if(r <= s && A[r] > A[largest])
    {   largest =r;
    }
    if(largest != i)
    {   exchange(A,i,largest);
        Heapify(A,largest,s);
    }
}
void Build_heap(int A[])
{   for(int i=amounth/2;i>=1;i--)
    {   Heapify(A,i,amounth);
    }
}
void Heapsort(int A[])
{   Build_heap(A);
    int s=amounth;
    for(int i=amounth;i>=2;i--)
    {   exchange(A,1,i);
        Heapify(A,1,--s);
    }
}
void five()
{   ifstream cin("data.txt");
    ofstream cout("h.txt");
    int i,j,n;
    int* arr = new int[amounth+1];
    for(i=1 ; i<=amounth ; i++)
    {   cin >> arr[i];
    }
    Heapsort(arr);
    for(i=1;i<=amounth;i++)
        cout << arr[i] << "\n";
}
struct l_list
{   struct l_list *next;
    int data;
};
struct l_list *arr1f[10]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
              *arr1b[10]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
              *arr2f[10]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
              *arr2b[10]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
void insert(int a,int b)
{   struct l_list *n,*p;
    if(arr1b[a]==NULL)
    {   p=new struct l_list;
        p->data=b;
        p->next=NULL;
        arr1f[a]=arr1b[a]=p;
    }else
    {   p=arr1b[a];
        n=new struct l_list;
        n->data=b;
        n->next=NULL;
        p->next=n;
        arr1b[a]=n;
    }
}
void move(int a,int d)
{   struct l_list *p=arr1f[a],*n=p->next;
    int pos=(p->data/d)%10;
    arr1f[a]=n;
    if(arr2b[pos]==NULL)
    {   p->next=NULL;
        arr2f[pos]=arr2b[pos]=p;
    }else
    {   n=arr2b[pos];
        n->next=p;
        p->next=NULL;
        arr2b[pos]=p;
    }
}
void six()
{   ifstream cin("data.txt");
    ofstream cout("r.txt");
    int i,j,n;
    struct l_list *p;
    for(i=0 ; i<amounth ; i++)
    {   cin >> n;
        insert(n%10,n);
    }
    n=1;
    for(i=0 ; i<4 ; i++)
    {   n*=10;
        for(j=0 ; j<10 ;j++)
        {   while(arr1f[j]!=NULL)
            {   move(j,n);
            }
        }
        for(j=0 ; j<10 ;j++)
        {   arr1b[j]=arr2b[j];arr2b[j]=NULL;
            arr1f[j]=arr2f[j];arr2f[j]=NULL;
        }
    }
    p=arr1f[0];
    while(p!=NULL)
    {   cout << p->data << "\n";
        p=p->next;
    }
}
int menu()
{   int a;
    cout << "=============Menu===========\n";
    cout << " 1) Create data file\n";
    cout << " 2) Selection Sort\n";
    cout << " 3) Bubble Sort\n";
    cout << " 4) Insertion Sort\n";
    cout << " 5) Heap Sort\n";
    cout << " 6) Radix Sort\n";
    cout << " 7) Exit\n";
    cout << " Please choose > ";
    cin >> a;
    return a;
}

int main()
{   int a;
    while(1)
    {   switch(menu())
        {   case 1:
                one();
                cout << " Create file success!!\n";
                break;
            case 2:
                two();
                break;
            case 3:
                three();
                break;
            case 4:
                four();
                break;
            case 5:
                five();
                break;
            case 6:
                six();
                break;
            case 7:
                exit(1);
        }
    }
}
