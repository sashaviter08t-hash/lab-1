#include "task1.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Власна функція пошуку останнього входження символу в char[]
int myFindLastOf(const char s[], char c) {
    int lastPos = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) {
            lastPos = i;
        }
    }

    return lastPos;
}

void task1() {
    const int MAX_LEN = 256;
    char cstr[MAX_LEN];
    string str;
    char target;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "===== TASK 1 =====\n";
    cout << "Enter a string: ";
    cin.getline(cstr, MAX_LEN);

    str = cstr;

    cout << "Enter a symbol to search: ";
    cin >> target;

    // Власна функція
    int myPos = myFindLastOf(cstr, target);

    // Метод string
    size_t stdPos = str.find_last_of(target);

    cout << "\nResult of myFindLastOf(): ";
    if (myPos == -1)
        cout << "symbol not found\n";
    else
        cout << "last position = " << myPos << endl;

    cout << "Result of string::find_last_of(): ";
    if (stdPos == string::npos)
        cout << "symbol not found\n";
    else
        cout << "last position = " << stdPos << endl;
}