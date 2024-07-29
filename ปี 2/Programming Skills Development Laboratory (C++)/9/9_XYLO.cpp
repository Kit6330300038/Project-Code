#include <bits/stdc++.h>
using namespace std;

char arr[7]={'D','R','M','F','S','L','T'};

int main()
{   int a,i,j,k,l,found,len;
    string b,ft,bk;
    cin >> a;
    for(i=0;i<a;i++)
    {   cin >> b;
        len = b.length();
        ft="T";bk="T";
        while(1)
        {   for(k=0;k<7;k++)
            {   found=0;
                for(l=0;l<len;l++)
                {   if(b.at(l)==arr[k])
                    {   found = 1;
                        bk=arr[k];b.erase(l,1);len--;
                        break;
                    }
                }
                if(!found)
                {   break;
                }
            }
            if(!found)
            {   break;
            }
        }
        if(b==""&&!bk.compare("T"))
            cout << "YES MANY\n";
        else if(bk.compare("T"))
        {   ft="D";
            for(k=6;k>=0;k--)
            {   found=-1;
                for(l=0;l<len;l++)
                {   if(b.at(l)==arr[k])
                    {   found = l;
                        ft=arr[k];b.erase(l,1);len--;
                        break;
                    }
                }
                if(found==-1)
                    break;
            }
            if(b=="")
                cout << "YES " << ft << " " << bk << "\n";
            else
                cout << "NO\n";
        }
        else
        {
            ft="A";
            for(k=0;k<7;k++)
            {   found = -1;
                for(l=0;l<len;l++)
                {   if(b.at(l)==arr[k])
                    {   found = l;
                        if(!ft.compare("A"))
                            ft=arr[k];
                        b.erase(l,1);len--;
                        break;
                    }
                }
                if(found==-1&&ft.compare("A"))
                {   bk=arr[k-1];
                    break;
                }
                else if(found>-1&&k==6)
                {   bk=arr[k];
                    break;
                }

            }

            if(b=="")
                cout << "YES " << ft << " " << bk << "\n";
            else
                cout << "NO\n";
        }
    }
}
