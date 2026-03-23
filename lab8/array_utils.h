#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#include <string>
using namespace std;

const int MAX_SIZE = 20;

// Зчитування одновимірного масиву з файлу
bool getArrayFromFile(const string& filename, int arr[], int& n);

// Запис масиву у файл
void showArrayToFile(const string& filename, const int arr[], int n, const string& title);

// Завдання 1: перед K-м елементом вставити 0
bool insertZeroBeforeK(int arr[], int& n, int k);

// Завдання 3: сортування вибором за зменшенням
void selectionSortDescending(int arr[], int n);

#endif
