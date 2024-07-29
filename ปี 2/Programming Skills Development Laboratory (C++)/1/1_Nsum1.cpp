#include <stdio.h>
#include <Iostream>
using namespace std;
int main()
{ 
	int a,b=0;
	cin >> a;
	for(int i=1; i<=a;i++)
	{
		b += i;
	}
	cout << b;
	return 0;
}
