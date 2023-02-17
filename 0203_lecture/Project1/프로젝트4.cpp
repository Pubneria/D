#include <iostream>
#include <cstdlib>
#include<iomanip>
using namespace std;
int main() {
	int n;
	int row, column;
	cout << "�������� �� Ȥ�� ���� ���� Ȧ���� �Է����ּ���: ";
	cin >> n;
	cout << "\n";

	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];

	}
	
	arr[0][(n-1)/2] = 1;
	row = 1;
	column = 1+ ((n - 1) / 2);
	
	for (int i = 2; i < n * n + 1; i++) 
	{
		if (i % n == 1) //i�� n�ǹ���϶�
		{
			row= row%n +1;
			arr[row - 1][column-1] = i;
		}
		else //i�� n�ǹ���� �ƴҶ�
		{
			if (row == 1) 
			{
				row = n;
			}
			else
			{
				row = row - 1;
			}
			if (column == 1)
			{
				column = n;
			}
			else
			{
				column = column - 1;
			}
			arr[row - 1][column - 1] = i;
			
		}

	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(3) << arr[i][j];
			
		}
		std::cout << "\n";
	}

	for (int i = 0; i < n; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;




	return 0;
}
