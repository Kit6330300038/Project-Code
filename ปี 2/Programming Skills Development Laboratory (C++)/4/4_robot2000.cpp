#include <bits/stdc++.h>
using namespace std;

string North(string a)
{
    if(!a.compare("N"))
    {
        return "F";
    }
    else if(!a.compare("S"))
    {
        return "RRF";
    }
    else if(!a.compare("E"))
    {
        return "RRRF";
    }
    else
    {
        return "RF";
    }
}
string South(string a)
{
    if(!a.compare("N"))
    {
        return "RRF";
    }
    else if(!a.compare("S"))
    {
        return "F";
    }
    else if(!a.compare("E"))
    {
        return "RF";
    }
    else
    {
        return "RRRF";
    }
}
string East(string a)
{
    if(!a.compare("N"))
    {
        return "RF";
    }
    else if(!a.compare("S"))
    {
        return "RRRF";
    }
    else if(!a.compare("E"))
    {
        return "F";
    }
    else
    {
        return "RRF";
    }
}
string Wast(string a)
{
    if(!a.compare("N"))
    {
        return "RRRF";
    }
    else if(!a.compare("S"))
    {
        return "RF";
    }
    else if(!a.compare("E"))
    {
        return "RRF";
    }
    else
    {
        return "F";
    }
}
int main()
{
    string a,b,facing="N",ret="";
    cin >> a;
    for(int i=0; i< a.length();i++)
    {
        b=a.at(i);
        if(!b.compare("N"))
        {
            ret+=North(facing);
            facing=b;
        }
        else if(!b.compare("S"))
        {
            ret+=South(facing);
            facing=b;
        }
        else if(!b.compare("E"))
        {
            ret+=East(facing);
            facing=b;
        }
        else if(!b.compare("W"))
        {
            ret+=Wast(facing);
            facing=b;
        }
        else
        {
            ret += "Z";
            facing="N";
        }
    }
    cout << ret;
    return 0;
}
