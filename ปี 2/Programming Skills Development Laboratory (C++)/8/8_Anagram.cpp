#include <bits/stdc++.h>
using namespace std;

int main()
{   int a,i,j,k,tf=0,lenb,lenc;
    string b,c,t1,t2;
    cin >> a;
    for(i=0; i<a; i++)
    {   cin >> b;
        cin >> c;
        lenb=b.length();
        lenc=c.length();
        if(lenb!=lenc)
        {   cout << "NOT ANAGRAM\n";
            lenb=0;
        }
        for(j=0; j<lenb; j++)
        {   t1=b.at(j);
            tf=0;
            for(k=0; k<lenc; k++)
            {   t2=c.at(k);
                if(!t1.compare(t2)){tf=1;c.erase(k,1);lenc--;break;}
            }
            if(!tf)
            {   cout << "NOT ANAGRAM\n";
                break;
            }
        }
        if(tf)
        {    cout << "ANAGRAM\n";
        }
    }
    return 0;
}
