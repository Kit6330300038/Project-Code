#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int a,tax=0;
	cin >> a;
	while(a>0)
	{	
		if (a <= 100000)
		{	
			cout << 0 << "\n";
		}
		else if (a <= 1000000)
		{
			tax = (a-100000)*6/100;
			cout << tax << "\n";
		}
		else if (a <= 5000000)
		{
			tax = 54000 + (a-1000000)*12/100;
			cout << tax << "\n";
		}
		else if (a <= 10000000)
		{
			tax = 534000 + (a-5000000)*20/100;
			cout << tax << "\n";
		}
		else 
		{
			tax = 1534000+ (a-10000000)*32/100;
			cout << tax << "\n";
		}	
		cin >> a;
	}
	return 0;
}
