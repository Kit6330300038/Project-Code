#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a[3][3]={{0,0,0},{0,0,0},{0,0,0}};
	cout << "Input\n";
	for(int i=0; i<3; i++)
	{
		cout << "Row"<<i+1<<"   ";
		for (int j=0; j<3; j++)
		{
			cin >> a[i][j];
		}
		cout << "\n";
	}
	cout << "Matrix:\n";
	for(int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "Transpose Matrix:\n";
	for(int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			cout << a[j][i] << " ";
		}
		cout << "\n";
	}
}
