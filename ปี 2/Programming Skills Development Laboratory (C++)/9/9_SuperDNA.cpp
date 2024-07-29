#include <bits/stdc++.h>
using namespace std;

string a,b;
string l()
{   if(a.length()>b.length())
    return a;
    return b;
}
string s()
{   if(a.length()>b.length())
    return b;
    return a;
}

int main()
{   int r,len_l,len_s,i,j,tf,n,len1,len2;
    string lg,st,inf,inb;
    cin >> r;
    for(i=0;i<r;i++)
    {   inf="";inb="";
        cin >> a;
        cin >> b;
        lg=l();
        len_l=lg.length();
        st=s();
        len_s=st.length();
        for(j=0;j<len_l;j++)
        {   if(lg.at(j)==st.at(0))
            {   tf=1;n=1;
                while(j+n<len_l&&n<len_s)
                {   if(lg.at(j+n)!=st.at(n))
                    {   tf=0;
                        break;
                    }n++;
                }
                if(tf)
                {   inb=lg.substr(0,j)+st;
                    len1=inb.length();
                    if(len1<len_l)
                        inb+=lg.substr(len1,len_l-len1);
                    break;
                }
            }
        }
        if(inb=="")
            inb=lg+st;
        for(j=len_l-1;j>=0;j--)
        {   if(lg.at(j)==st.at(len_s-1))
            {   tf=1;n=1;
                while(j-n>=0&&n<len_s)
                {   if(lg.at(j-n)!=st.at(len_s-1-n))
                    {   tf=0;
                        break;
                    }n++;
                }
                if(tf)
                {   inf=st+lg.substr(j+1,len_l-j);
                    len1=inf.length();
                    if(len1<len_l)
                        inf=lg.substr(0,j)+inf;
                    break;
                }
            }
        }
        if(inf=="")
            inf=st+lg;
        len1=inf.length();
        len2=inb.length();
        if(len1<len2)
            cout << inf << "\n";
        else if(len1>len2)
            cout << inb << "\n";
        else
        {   n=0;len1=inb.length();
            while(n<len1)
            {   if((int)(inb.at(n))>(int)(inf.at(n)))
                {   cout << inf << "\n";
                    break;
                }else if((int)(inb.at(n))<(int)(inf.at(n)))
                {   cout << inb << "\n";
                    break;
                }n++;
            }
            if(n==len1)
                cout << inb << "\n";
        }
    }
}
