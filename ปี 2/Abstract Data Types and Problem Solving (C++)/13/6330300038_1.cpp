#include <bits/stdc++.h>
using namespace std;

int amounth=2000000;

void one()
{   ofstream cout("data.txt");
    for (int i=0 ; i<amounth ; i++)
    {   cout << rand()%10000 << "\n";
    }
}
void merge(int A[], int tmparray[],int lpos,int rpos,int rightend)
{   int i, leftend, numelements,tmppos;
    leftend = rpos -1;
    tmppos = lpos;
    numelements = rightend-lpos +1;
    while(lpos<=leftend && rpos<=rightend)
        if(A[lpos] <= A[rpos])
            tmparray[tmppos++] = A[lpos++];
        else
            tmparray[tmppos++] = A[rpos++];
    while(lpos <= leftend)
        tmparray[tmppos++]= A[lpos++];
    while(rpos <= rightend)
        tmparray[tmppos++]= A[rpos++];
    for(i=0;i<numelements;i++, rightend--)
        A[rightend] = tmparray[rightend];
}

void msort(int A[],int tmparray[],int left, int right)
{   int center;
    if(left < right)
    {   center = (left+right)/2;
        msort(A,tmparray,left,center);
        msort(A,tmparray,center+1,right);
        merge(A,tmparray,left,center+1,right);
    }
}
void swap(int A[],int i,int j)
{   int a=A[i];
    A[i]=A[j];
    A[j]=a;
}

void qsort(int A[],int left,int right,int center)
{   if(left-right==1)
        return;
    int v=A[center],i=left,j=right;
    swap(A,j--,center);
    while(i <= j)
    {   if(A[i]<v)
            i++;
        else if(A[j]>=v)
            j--;
        else
            swap(A,i,j);
    }
    swap(A,i,right);
    qsort(A,i+1,right,(i+right+1)/2);
    qsort(A,left,i-1,(i+left-1)/2);
}

void ssort(int A[],int b)
{   int i=2,j,k,l,m;
    while(i*2<b)
        i*=2;
    i--;
    for(j=0;j<i;j++)
    {   for(k=j;k<b;k+=i)
        {   m=k;
            for(l=k+i;l<b;l+=i)
            {   if(A[m]>A[l])
                    m=l;
            }
            swap(A,m,k);
        }
    }
    int tmp;
    while(i)
    {   i/=2;
        for(j=0;j<i;j++)
        {   for(k=j;k<b;k+=i)
            {   tmp=A[k];
                for(l=k;l>=i&&A[l-i]>tmp;l-=i)
                    A[l]=A[l-i];
                A[l]=tmp;
            }
        }
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
    ssort(arr,amounth);
    for(i=0 ; i<amounth ; i++)
    {   cout << arr[i] << "\n";
    }
}
void three()
{   ifstream cin("data.txt");
    ofstream cout("m.txt");
    int i,j,m;
    int* arr = new int[amounth],*temp= new int[amounth];
    for(i=0 ; i<amounth ; i++)
    {   cin >> arr[i];
    }
    msort(arr,temp,0,amounth);
    for(i=0 ; i<amounth ; i++)
    {   cout << arr[i] << "\n";
    }
}
void four()
{   ifstream cin("data.txt");
    ofstream cout("q.txt");
    int i,j,m;
    int* arr = new int[amounth];
    for(i=0 ; i<amounth ; i++)
    {   cin >> arr[i];
    }
    qsort(arr,0,amounth,amounth/2);
    for(i=0 ; i<amounth ; i++)
    {   cout << arr[i] << "\n";
    }
}


int menu()
{   int a;
    cout << "=============Menu===========\n";
    cout << " 1) Create data file\n";
    cout << " 2) Shell Sort\n";
    cout << " 3) Merge Sort\n";
    cout << " 4) Quick Sort\n";
    cout << " 5) Exit\n";
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
                exit(1);

        }
    }
}
