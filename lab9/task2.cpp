#include "task2.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// Перевірка: чи символ є пробілом
bool isSpaceChar(char ch) {
    return ch == ' ';
}

// Перевірка для простого варіанта:
// дозволяємо пробіл і байти кирилиці у Windows-1251 / ANSI.
// Для навчальної лабораторної цього достатньо.
bool isUpperCyrillicChar(unsigned char ch) {
    return (ch >= 192 && ch <= 223) || ch == 168; // А-Я, Ё
}

// Перевірка рядка за умовою String51
bool isValidString51(const string& s) {
    if (s.empty()) return false;

    bool hasLetter = false;

    for (size_t i = 0; i < s.size(); i++) {
        unsigned char ch = static_cast<unsigned char>(s[i]);

        if (isSpaceChar(ch)) {
            continue;
        }

        if (!isUpperCyrillicChar(ch)) {
            return false;
        }

        hasLetter = true;
    }

    return hasLetter;
}

// Обробка String51:
// 1) розбиття на слова
// 2) сортування
// 3) складання через один пробіл
string processString51(const string& s) {
    vector<string> words;
    string current = "";

    // Розбити на слова, ігноруючи зайві пробіли
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] != ' ') {
            current += s[i];
        }
        else {
            if (!current.empty()) {
                words.push_back(current);
                current.clear();
            }
        }
    }

    if (!current.empty()) {
        words.push_back(current);
    }

    // Сортування за алфавітом
    sort(words.begin(), words.end());

    // Зібрати рядок назад через один пробіл
    string result = "";
    for (size_t i = 0; i < words.size(); i++) {
        result += words[i];
        if (i + 1 < words.size()) {
            result += ' ';
        }
    }

    return result;
}

void task2() {
    int choice;

    cout << "===== TASK 2 =====\n";
    cout << "1 - Process one line from console\n";
    cout << "2 - Process file line by line\n";
    cout << "Choose: ";
    cin >> choice;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (choice == 1) {
        string s;
        cout << "Enter a string (uppercase Cyrillic words): ";
        getline(cin, s);

        if (!isValidString51(s)) {
            cout << "Wrong string! Only uppercase Cyrillic words and spaces are allowed.\n";
            return;
        }

        string result = processString51(s);
        cout << "Result: " << result << endl;
    }
    else if (choice == 2) {
        string inputFile, outputFile;
        cout << "Enter input file name: ";
        getline(cin, inputFile);
        cout << "Enter output file name: ";
        getline(cin, outputFile);

        ifstream fin(inputFile);
        if (!fin) {
            cout << "Cannot open input file!\n";
            return;
        }

        ofstream fout(outputFile);
        if (!fout) {
            cout << "Cannot open output file!\n";
            fin.close();
            return;
        }

        string line;
        while (getline(fin, line)) {
            if (isValidString51(line)) {
                fout << processString51(line) << endl;
            }
            else {
                fout << "INVALID STRING" << endl;
            }
        }

        fin.close();
        fout.close();

        cout << "File processed successfully.\n";
    }
    else {
        cout << "Wrong menu item!\n";
    }
}