#include <iostream>

using namespace std;

int main()
{
	int rows, cols;
	cin >> rows;
	cin >> cols;
	int array[rows][cols];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cin >> array[i][j];
		}
	}
	cout << "top to down" << endl;
	for (int i = 0; i < rows; i++)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << array[i][j] << " ";
			}
		}
		else{
			for (int j = cols-1; j >= 0; j--)
			{
				cout << array[i][j] << " ";
			}
		}
	}
	cout << endl;
	cout << "down to top" << endl;
	for (int i = rows-1; i >= 0; i--)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << array[i][j] << " ";
			}
		}
		else{
			for (int j = cols-1; j >= 0; j--)
			{
				cout << array[i][j] << " ";
			}
		}
	}
	cout << endl;
	cout << "Left to Right" << endl;
	for (int j = 0; j < cols; j++)
	{
		if (j%2 == 0){
			for (int i = rows-1; i >= 0; i--){
				cout << array[i][j] << " ";
			}
		}
		else{
			for (int i = 0; i < rows; i++){
				cout << array[i][j] << " ";
			}
		}
	}
	return 0;
}

