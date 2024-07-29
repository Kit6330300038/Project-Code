#include <bits/stdc++.h>
using namespace std;

int arr1[26],arr2[26];

int main()
{   int a,i,j,len,t;
    string b,c;
    cin >> a;
    for(i=0; i<a; i++)
    {   for(j=0;j<26;j++)
        {   arr1[j]=0;
            arr2[j]=0;
        }
        cin >> b;
        cin >> c;
        len = b.length();
        for(j=0; j<len; j++)
        {    arr1[((int) b.at(j))-97]++;
        }
        len = c.length();
        for(j=0; j<len; j++)
        {    arr2[((int) c.at(j))-97]++;
        }
        t=1;
        for(j=0;j<26;j++)
        {   if(arr1[j]!=arr2[j])
            {   cout << "NOT ANAGRAM\n";
                t=0;
                break;
            }
        }
        if(t)
        {   cout << "ANAGRAM\n";
        }
    }
    return 0;
}
