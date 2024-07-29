#include <bits/stdc++.h>
using namespace std;

int isin(string a,int b)
{   string c[6]={"A","B","C","D","E","F"};
    a=a.at(b);
    for(int i=0; i<6 ; i++)
    {   if(a==c[i])return 1;
    }
    return 0;
}

int main()
{   string a;
    int pos=1,len;
    cin >> a;
    len=a.length();
    if(len>2&&isin(a,0))
    {   while(pos<len &&a.at(pos)=='A')
        {   pos++;
        }
        if(a.at(pos)=='F'&&a.at(pos-1)=='A')
        {   while(pos<len && a.at(pos)=='F')
            {   pos++;
            }
            if(a.at(pos)=='C')
            {   while(pos<len && a.at(pos)=='C')
                {   pos++;
                }
                if(pos==len||isin(a,pos))
                {   cout << "Infected!";
                    return 0;
                }
            }
        }
    }
    cout << "Good";
    return 0;
}
