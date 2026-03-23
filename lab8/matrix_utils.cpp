#include "matrix_utils.h"
#include <fstream>

bool getMatrixFromFile(const string& filename, int matrix[][MAX_COLS], int& m, int& n) {
    fstream fin(filename);
    if (!fin.is_open()) {
        return false;
    }

    fin >> m >> n;
    if (m < 2 || m > MAX_ROWS || n < 2 || n > MAX_COLS) {
        fin.close();
        return false;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fin >> matrix[i][j];
        }
    }

    fin.close();
    return true;
}

void appendMatrixAndResultToFile(const string& filename, const int matrix[][MAX_COLS], int m, int n, int result) {
    fstream fout(filename, ios::app);
    if (!fout.is_open()) {
        return;
    }

    fout << endl;
    fout << "Matrix:" << endl;
    fout << m << " " << n << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fout << matrix[i][j] << " ";
        }
        fout << endl;
    }

    fout << "Max among row minimums = " << result << endl;

    fout.close();
}

int maxOfRowMins(const int matrix[][MAX_COLS], int m, int n) {
    int maxMin = matrix[0][0];

    for (int i = 0; i < m; i++) {
        int rowMin = matrix[i][0];

        for (int j = 1; j < n; j++) {
            if (matrix[i][j] < rowMin) {
                rowMin = matrix[i][j];
            }
        }

        if (i == 0 || rowMin > maxMin) {
            maxMin = rowMin;
        }
    }

    return maxMin;
}