#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int pos[2] = {0,0};
	string command;
	char cal;
	cin >> command;
	for(int i=command.size()-1; i>=0; i--)
	{
		cal = command[i];
		switch(cal)
		{
			case 'N':
				pos[1] +=1;
				break;
			case 'S':
				pos[1] -=1;
				break;
			case 'E':
				pos[0] +=1;
				break;
			case 'W':
				pos[0] -=1;
				break;
			case 'Z' :
				i=0;
				break;
		}
	}
	cout << pos[0] << " " << pos[1];
	return 0;
}
