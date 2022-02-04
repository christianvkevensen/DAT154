// CarApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Car
{
public:
	int n;
	Car(int _n) : n(_n)
	{
	}
	void Draw()
	{
		cout << n << ": ()==()" << endl;
	}
};
class CarList
{
public:
	Car* t[1000];
	int m_i;
	CarList()
	{
		m_i = 0;
	}
	void push(Car* pCar)
	{
		t[m_i++] = pCar;
	}
	void Draw()
	{
		for (int k = 0; k < m_i; k++)
			t[k]->Draw(); //  same as (*t[m_i]).Draw();
	}
	void Clear()
	{
		for (int k = 0; k < m_i; k++)
			delete t[k];
	}
};


int main()
{
	CarList list;

	list.push(new Car(1));
	list.push(new Car(2));
	list.push(new Car(3));

	cout << "List for cars"<<endl;
	list.Draw();
	list.Clear();
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
