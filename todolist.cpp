#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> list = {};

void add(string value) {
    list.push_back(value);
    cout << "Added, Choose again: ";
}

void showList() {
    cout << "=======================================\n";
    for (int i = 0; i < list.size(); i++) {
        cout << i+1 << ". " << list.at(i) << "\n";
    }
    cout << "=======================================\n";
    cout << "Showed, Choose again: ";
}

void remove(int id) {
    list.at(id-1) = "REMOVED";
    cout << "Removed, Choose again: ";

}

void edit(int id, string newValue) {
    list.at(id-1) = newValue;
    cout << "Edited, Choose again: ";
}

int main() {
    cout << "Choose: \n1. Add to the list\n2.Remove from the list\n3.Edit from the list\n4.Show the list\n5. To exit\n";
    while (true) {
        int operation, id; cin >> operation;
        string val;
        switch (operation) {
            case 1:
                cout << "Enter the todo: "; cin >> val;
                add(val);
                break;
            case 2:
                cout << "Enter the id of the todo: "; cin >> id;
                if (id <= 0 or id > list.size()) {
                    cout << "Doesn't exist, choose again: ";
                    break;
                }
                remove(id);
                break;
            case 3:
                cout << "Enter the id of the todo: "; cin >> id;
                if (id <= 0 or id > list.size()) {
                    cout << "Doesn't exist, choose again: ";
                    break;
                }
                cout << "\nEnter the new todo: "; cin >> val;
                edit(id, val);
                break;
            case 4:
                showList();
                break;
            case 5:
                return 0;
        }
    }
    return 0;
}