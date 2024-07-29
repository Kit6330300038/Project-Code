#include <bits/stdc++.h>
using namespace std;

string num(int a)
{   if(a==9)return "-nine";
    if(a==8)return "-eight";
    if(a==7)return "-seven";
    if(a==6)return "-six";
    if(a==5)return "-five";
    if(a==4)return "-four";
    if(a==3)return "-three";
    if(a==2)return "-two";
    if(a==1)return "-one";
    if(a==0)return "";
}
string numo(int a)
{   if(a==9)return "nine";
    if(a==8)return "eight";
    if(a==7)return "seven";
    if(a==6)return "six";
    if(a==5)return "five";
    if(a==4)return "four";
    if(a==3)return "three";
    if(a==2)return "two";
    if(a==1)return "one";
    if(a==0)return "";
}
string ty(int a)
{   int b=a/10;
    if(b==9)return "ninety"+ num(a%10);
    if(b==8)return "eighty"+ num(a%10);
    if(b==7)return "seventy"+ num(a%10);
    if(b==6)return "sixty"+ num(a%10);
    if(b==5)return "fifty"+ num(a%10);
    if(b==4)return "forty"+ num(a%10);
    if(b==3)return "thirty"+ num(a%10);
    if(b==2)return "twenty"+ num(a%10);
    if(b==1)
    {   if(a==19)return "nineteen";
        if(a==18)return "eighteen";
        if(a==17)return "seventeen";
        if(a==16)return "sixteen";
        if(a==15)return "fifteen";
        if(a==14)return "fourteen";
        if(a==13)return "thirteen";
        if(a==12)return "twelve";
        if(a==11)return "eleven";
        if(a==10)return "ten";
    }
    if(b==0)return numo(a);
}
string hun(int a)
{   int b=a/100;
    if(b==9)return "nine hundred "+ ty(a%100);
    if(b==8)return "eight hundred "+ ty(a%100);
    if(b==7)return "seven hundred "+ ty(a%100);
    if(b==6)return "six hundred "+ ty(a%100);
    if(b==5)return "five hundred "+ ty(a%100);
    if(b==4)return "four hundred "+ ty(a%100);
    if(b==3)return "three hundred "+ ty(a%100);
    if(b==2)return "two hundred "+ ty(a%100);
    if(b==1)return "one hundred "+ ty(a%100);
    if(b==0)return ty(a);
}
string thou(int a)
{   int b = a/1000;
    if(a==0)return "zero";
    if(b==10)return "ten thousand ";
    if(b==9)return "nine thousand "+ hun(a%1000);
    if(b==8)return "eight thousand "+ hun(a%1000);
    if(b==7)return "seven thousand "+ hun(a%1000);
    if(b==6)return "six thousand "+ hun(a%1000);
    if(b==5)return "five thousand "+ hun(a%1000);
    if(b==4)return "four thousand "+ hun(a%1000);
    if(b==3)return "three thousand "+ hun(a%1000);
    if(b==2)return "two thousand "+ hun(a%1000);
    if(b==1)return "one thousand "+ hun(a%1000);
    if(b==0)return hun(a);
}


int main()
{   int a,b,i;
    string s;
    cin >> a;
    for(i=0;i<a;i++)
    {   cin >> b;
        cout << thou(b) << "\n";
    }
}
