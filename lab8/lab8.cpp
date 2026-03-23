#include <iostream>
#include <string>
#include <fstream>
#include "array_utils.h"
#include "matrix_utils.h"

using namespace std;

// -------------------- Task 1 --------------------
void task1() {
    string inFile, outFile;
    int arr[MAX_SIZE];
    int n, k;

    cout << "TASK 1 - Array101" << endl;
    cout << "Enter input filename: ";
    cin >> inFile;
    cout << "Enter output filename: ";
    cin >> outFile;
    cout << "Enter K (1 <= K <= N): ";
    cin >> k;

    if (!getArrayFromFile(inFile, arr, n)) {
        cout << "Error reading array from file!" << endl;
        return;
    }

    ofstream clearFile(outFile); // очистити файл перед записом
    clearFile.close();

    showArrayToFile(outFile, arr, n, "Original array:");

    if (!insertZeroBeforeK(arr, n, k)) {
        cout << "Error: incorrect K or array overflow!" << endl;
        return;
    }

    showArrayToFile(outFile, arr, n, "Array after inserting 0 before K-th element:");

    cout << "Task 1 completed. Result written to file." << endl;
}

// -------------------- Task 2 --------------------
void task2() {
    string inFile;
    int matrix[MAX_ROWS][MAX_COLS];
    int m, n;

    cout << "\nTASK 2 - Matrix27" << endl;
    cout << "Enter matrix filename: ";
    cin >> inFile;

    if (!getMatrixFromFile(inFile, matrix, m, n)) {
        cout << "Error reading matrix from file!" << endl;
        return;
    }

    int result = maxOfRowMins(matrix, m, n);
    appendMatrixAndResultToFile(inFile, matrix, m, n, result);

    cout << "Task 2 completed. Result appended to the same file." << endl;
}

// -------------------- Task 3 --------------------
void task3() {
    string inFile, outFile;
    int arr[MAX_SIZE];
    int n;

    cout << "\nTASK 3 - Selection sort descending" << endl;
    cout << "Enter input filename: ";
    cin >> inFile;
    cout << "Enter output filename: ";
    cin >> outFile;

    if (!getArrayFromFile(inFile, arr, n)) {
        cout << "Error reading array from file!" << endl;
        return;
    }

    ofstream clearFile(outFile);
    clearFile.close();

    showArrayToFile(outFile, arr, n, "Original array:");

    selectionSortDescending(arr, n);

    showArrayToFile(outFile, arr, n, "Sorted array (descending, selection sort):");

    cout << "Task 3 completed. Result written to file." << endl;
}

// -------------------- Main --------------------
int main() {
    int choice;

    do {
        cout << "\n========== MENU ==========" << endl;
        cout << "1 - Task 1 (Array101)" << endl;
        cout << "2 - Task 2 (Matrix27)" << endl;
        cout << "3 - Task 3 (Selection sort)" << endl;
        cout << "0 - Exit" << endl;
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        case 0:
            cout << "Program finished." << endl;
            break;
        default:
            cout << "Incorrect choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}
