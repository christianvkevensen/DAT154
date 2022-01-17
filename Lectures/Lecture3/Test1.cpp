int a = 2;
int b = 3;

using namespace std;

void mai|n() {

	int* p = &a;


	cout << "*p" << *p << endl;

	p = &b;
	cout << "*p" << *p << endl;
}