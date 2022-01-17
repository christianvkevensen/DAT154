// Lecture3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void SquareTwo(int* px, int* py) {
	*px = *px * *px;
	*py = *py * *py;
}

int main()
{
	//Example 2
	/*char s[] = "Its a nice day, my house is on fire";
	char* p = s;
	int n = 0;

	for (; *p != 0; p++)
	{
		if (*p == 'e')
			n++;
	}

	cout << "Number of e: " << n << endl;*/

	//Example 3
	int x = 10;
	int y = 20;

	SquareTwo(&x, &y);

	cout << "x2 = " << x << " y2 = " << y << endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
