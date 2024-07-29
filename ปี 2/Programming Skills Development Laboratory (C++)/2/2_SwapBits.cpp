#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int a;
	cin >> a;
	cout << ((a&0b10101010)>>1|(a&0b01010101)<<1);
	return 0;
}

