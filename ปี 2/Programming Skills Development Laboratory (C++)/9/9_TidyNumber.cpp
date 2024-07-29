#include <bits/stdc++.h>
using namespace std;

int check(char a,char b)
{   if((int) a > (int) b)
    return 1;
    return 0;
}

string sets(string a,int b)
{   int i,len=a.length();
    string s="";
    if(a.at(b-1)=='1')
    {   for(i=0;i<len-1;i++)
        {   s += "9";
        }
        return s;
    }
    else
    {   if(b>=2)
        {   while(b>1&&a.at(b-1)==a.at(b-2))
                b--;
            if(b==1&&a.at(b-1)==a.at(b))
            {   s += (char)(a.at(b-1)-1);
            }else
            {   s += a.substr(0,b-1);
                s += (char)(a.at(b-1)-1);
            }
            for(i=b;i<len;i++)
            {   s += "9";
            }return s;
        }
        s += a.substr(0,b-1);
        s += (char)(a.at(b-1)-1);
        for(i=b;i<len;i++)
        {   s += "9";
        }
        return s;
    }
}

int main()
{   string a,ret;
    int z,i,j,len,ck;
    cin >> z;
    for(i=0;i<z;i++)
    {   cin >> a;
        ret="";ck=1;
        len = a.length();
        for(j=1 ;j<len ;j++)
        {   if(check(a.at(j-1),a.at(j)))
            {   ret = sets(a,j);
                ck=0;break;
            }
        }
        if(ck)
        {   ret=a;
        }
        cout << "Case #"<< i+1 << ": "<<ret << "\n";
    }




}
