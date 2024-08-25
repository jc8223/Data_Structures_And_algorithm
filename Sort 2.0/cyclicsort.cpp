#include <iostream>
using namespace std;

int main()
{
	int arr[] = { 1, 3, 2, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	//cycle Sort
	int i = 0;
	while (i < n)
	{
		int correctIdx = arr[i] - 1;
		if (arr[i] != arr[correctIdx])
			swap(arr[i], arr[correctIdx]);
		else
			i++;
	}
	cout << "After sort : " << endl;
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}