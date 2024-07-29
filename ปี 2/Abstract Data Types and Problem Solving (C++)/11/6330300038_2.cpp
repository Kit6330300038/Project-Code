#include <bits/stdc++.h>
using namespace std;

int A[30],length,heapsize;

int parents(int i)
{   return i/2;
}

int left(int i)
{   return 2*i;
}

int right(int i)
{   return 2*i+1;
}

void exchange(int a,int b)
{   int c,i,j;
    for(i=0;i<30;i++)
    {   if(A[i]==a)
        {   j=i;
            break;
        }
    }
    for(i=0;i<30;i++)
    {   if(A[i]==b)
        {   A[j]=b;
            A[i]=a;
            break;
        }
    }
}

void Heapify(int A[],int i)
{   int l=left(i),r=right(i),largest;
    if(l <= heapsize && A[l] > A[i])
    {   largest = l;
    }else
    {   largest = i;
    }
    if(r <= heapsize && A[r] > A[largest])
    {   largest =r;
    }
    if(largest != i)
    {   exchange(A[i],A[largest]);
        Heapify(A,largest);
    }
}
void Build_heap(int A[])
{   heapsize=length;
    for(int i=length/2;i>=1;i--)
    {   Heapify(A,i);
    }
}
void Heapsort(int A[])
{   Build_heap(A);
    for(int i=length;i>=2;i--)
    {   exchange(A[1],A[i]);
        heapsize--;
        Heapify(A,1);
    }
    cout << "Heap Sort: ";
    for(int i=1;i<=length;i++)
    {   cout << A[i] << " ";
    }
    cout << "\n";

}
int Heap_Exact_Max(int A[])
{   if(heapsize < 1)
    {   cout << " Heap underflow";
        return -1;
    }
    int Max = A[1];
    A[1] = A[heapsize];
    heapsize=--length;
    Heapify(A,1);
    return Max;
}
void one()
{   string a,word;
    int i=1;
    cin.ignore();
    cout << " input : ";
    getline(cin,a);
    istringstream iss(a);
    while(iss >> word)
        A[i++]=stoi(word);
    length=--i;
}
void two()
{   cout << " Heap : ";
    Build_heap(A);
    for(int i=1;i<=length;i++)
    {   cout << A[i] << " ";
    }
    cout << "\n";
}
void Heap_Insert(int A[],int key)
{   Build_heap(A);
    heapsize = ++length;
    A[heapsize]=key;
    cout << " Array : ";
    for(int i=1;i<=length;i++)
    {   cout << A[i] << " ";
    }
    cout << "\n";
}
void Priority_Queue()
{   int key=A[length];
    int i = heapsize;
    while(i>1&& A[parents(i)]<key)
    {   A[i] = A[parents(i)];
        i = parents(i);
        A[i] = key;
    }
    cout << "Heap : ";
    for(int i=1;i<=length;i++)
    {   cout << A[i] << " ";
    }
    cout << "\n";
}

int menu()
{   int a;
    cout << "=============Menu===========\n";
    cout << " 1) Insert data to array\n";
    cout << " 2) Build Heap\n";
    cout << " 3) Heap Sort\n";
    cout << " 4) Heap insert\n";
    cout << " 5) Priority Queue\n";
    cout << " 6) Extract Max\n";
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
                break;
            case 2:
                two();
                break;
            case 3:
                Heapsort(A);
                break;
            case 4:
                cout << " Insert : ";
                cin >> a;
                Heap_Insert(A,a);
                break;
            case 5:
                Priority_Queue();
                break;
            case 6:
                cout << " Max = "<<Heap_Exact_Max(A) << "\n";
                two();
        }
    }
}
