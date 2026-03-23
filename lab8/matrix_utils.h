#ifndef MATRIX_UTILS_H
#define MATRIX_UTILS_H

#include <string>
using namespace std;

const int MAX_ROWS = 20;
const int MAX_COLS = 20;

// Зчитування матриці з файлу
bool getMatrixFromFile(const string& filename, int matrix[][MAX_COLS], int& m, int& n);

// Дописування матриці та результату у файл
void appendMatrixAndResultToFile(const string& filename, const int matrix[][MAX_COLS], int m, int n, int result);

// Завдання 2: максимальний серед мінімальних елементів рядків
int maxOfRowMins(const int matrix[][MAX_COLS], int m, int n);

#endif