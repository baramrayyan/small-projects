#include <iostream>
using namespace std;

int main()
{
    double x, y;
    cout << "Enter two numbers: ";
    cin >> x >> y;
    cout << "Choose from the menu: \n [1] + \n [2] - \n [3] * \n [4] / \n";
    while(true) {
        int choice;
        double newValue;
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Value = ";
                newValue = x + y;
                cout << x + y;
                break;
            case 2:
                cout << "Value = ";
                newValue = x - y;
                cout << x - y;
                break;
            case 3:
                cout << "Value = ";
                newValue = x * y;
                cout << x * y;
                break;
            case 4:
                cout << "Value = ";
                newValue = x / y;
                cout << x / y;
                break;
            case -1:
                return 0;
            case -2:
                x = newValue;
                cout << "Enter the other number: ";
                cin >> y;
                cout << endl << "Choose from the menu: \n [1] + \n [2] - \n [3] * \n [4] / \n";
                continue;
            default:
                cout << "A number from 1 to 4 only";
        }
        cout << endl
             << "Choose again (put -1 to exit and -2 to redo the calculator with the new value): ";
    }
}
