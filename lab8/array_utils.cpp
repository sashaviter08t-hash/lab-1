#include "array_utils.h"
#include <fstream>
#include <iostream>

bool getArrayFromFile(const string& filename, int arr[], int& n) {
    fstream fin(filename);
    if (!fin.is_open()) {
        return false;
    }

    fin >> n;
    if (n < 2 || n > MAX_SIZE) {
        fin.close();
        return false;
    }

    for (int i = 0; i < n; i++) {
        fin >> arr[i];
    }

    fin.close();
    return true;
}

void showArrayToFile(const string& filename, const int arr[], int n, const string& title) {
    fstream fout(filename, ios::app);
    if (!fout.is_open()) {
        return;
    }

    fout << title << endl;
    fout << n << endl;
    for (int i = 0; i < n; i++) {
        fout << arr[i] << " ";
    }
    fout << endl << endl;

    fout.close();
}

bool insertZeroBeforeK(int arr[], int& n, int k) {
    if (n >= MAX_SIZE || k < 1 || k > n) {
        return false;
    }

    for (int i = n; i >= k; i--) {
        arr[i] = arr[i - 1];
    }

    arr[k - 1] = 0;
    n++;

    return true;
}

void selectionSortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }

        if (maxIndex != i) {
            int temp = arr[i];
            arr[i] = arr[maxIndex];
            arr[maxIndex] = temp;
        }
    }
}