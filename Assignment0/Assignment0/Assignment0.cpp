// Assignment0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;



//int Myfunction(const char* p) {
//    int i = 0;
//    for (; *p; p++) {
//        i++;
//    }
//
//    return i;
//}


int main() {

	cout << "this is a test: ";

	vector<string> words;
	string word = "Default";

	while (word != "q")
	{
		cin >> word;

		if (word != "q")
			words.push_back(word);
	}

	sort(words.begin(), words.end());


	cout << "this vector contains : " << endl;

	for (int i = 0; i < words.size(); i++)
		cout << words[i] << " ";
	cout << endl;

}


//void DoubleP(int& p) {
//    p = p * 2;
//}
//
//int main()
//{
//    int inp = 10;
//    //cout << "Enter a number: ";
//    //cin >> inp;
//    DoubleP(inp);
//    cout << inp;
//    /*char buffer[25];
//
//    cout << "Enter a word: ";
//    cin >> buffer;
//
//    cout << buffer << "\n";
//    cout << Myfunction(buffer) << "\n";*/
//
//
//}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
