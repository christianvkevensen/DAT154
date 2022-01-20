// BilApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Bil {
public:
    string color;
};


int main()
{
    cout << "1. Drive a red car into the garage" << endl;
    cout << "2. Drive a blue car into the garage" << endl;
    cout << "3. Drive a green car into the garage" << endl;
    cout << "4. Drive a car out of the garage" << endl;
    cout << "5. Quit" << endl;

    bool quit = false;
    vector <Bil> garasje;

    while (!quit) {

        int inp;
        cin >> inp;

        switch (inp) {
        case 1:
            if (garasje.size() == 4) {
                cout << "Garasjen er full" << endl;
                break;
            }
            else {
                Bil bil;
                bil.color = "Rod";
                garasje.push_back(bil);
                cout << "Rod bil er lagt inn" << endl;
                break;
            }
        case 2:
            if (garasje.size() == 4) {
                cout << "Garasjen er full" << endl;
                break;
            }
            else {
                Bil bil;
                bil.color = "Bla";
                garasje.push_back(bil);
                cout << "Bla bil er lagt inn" << endl;
                break;
            }

        case 3:
            if (garasje.size() == 4) {
                cout << "Garasjen er full" << endl;
                break;
            }
            else {
                Bil bil;
                bil.color = "Gronn";
                garasje.push_back(bil);
                cout << "Gronn bil er lagt inn" << endl;
                break;
            }
        case 4:
            if (garasje.size() == 0) {
                cout << "Garasjen er tom" << endl;
                break;
            }
            else {
                Bil fjernetBil = garasje.front();
                cout << "Du kjørte ut " << fjernetBil.color << " bil" << endl;
                garasje.erase(garasje.begin());
                break;
            }
        case 5: 
            quit = true;
            break;
        default:
            cout << "Feil input" << endl;
            break;
        }

    }
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
