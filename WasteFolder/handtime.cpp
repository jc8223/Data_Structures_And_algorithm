#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int h, m;
	cin >> h >> m;
	float angle = abs(0.5 * (60 * h - 11 * m));
	if (angle > 180)
		angle = 360 - angle;

	//show 5 digits after decimal point
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(5);
	cout << angle << endl;
	return 0;
}