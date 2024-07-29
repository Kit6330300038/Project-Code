#include <bits/stdc++.h>
using namespace std;

int main()
{   stack<char> STACK;
    string a;
    int z,i,j,len,t;
    cin >> z;
    for(i=0;i<z;i++)
    {   cin >> a;
        len=a.length();
        t=0;
        for(j=0;j<len;j++)
        {   if(a.at(j)=='{'||a.at(j)=='('||a.at(j)=='[')
            {   STACK.push(a.at(j));t=1;
            }
            else if(!STACK.empty())
            {   if(a.at(j)=='}')
                {   if(((char) STACK.top())!='{')
                    {   t=0;break;
                    }
                }else if(a.at(j)==')')
                {   if(((char) STACK.top())!='(')
                    {   t=0;break;
                    }
                }else
                {   if(((char) STACK.top())!='[')
                    {   t=0;break;
                    }
                }
                STACK.pop();
            }else
            {   t=0;break;
            }

        }
        if(STACK.empty()&&t)
            cout << "yes\n";
        else
            cout << "no\n";
        while(!STACK.empty())
            STACK.pop();
    }
}
