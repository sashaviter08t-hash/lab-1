#include <iostream>
#include "task1.h"
#include "task2.h"

using namespace std;

void showMenu() {
    cout << "\n========== MENU ==========\n";
    cout << "1 - Task 1\n";
    cout << "2 - Task 2\n";
    cout << "0 - Exit\n";
    cout << "Choose: ";
}

int main() {
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 0:
            cout << "Program finished.\n";
            break;
        default:
            cout << "Wrong menu item!\n";
        }

    } while (choice != 0);

    return 0;
}