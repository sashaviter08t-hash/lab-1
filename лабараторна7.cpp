#include <iostream>
#include <limits>

using namespace std;

const int MAX_R = 20;
const int MAX_C = 20;

// ---------- Utility: safe input ----------
void clearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// ---------- Matrix I/O ----------
void inputMatrix(int a[MAX_R][MAX_C], int& m, int& n)
{
    // Ввід розмірів з перевіркою коректності
    while (true)
    {
        cout << "Enter rows M (2-20): ";
        if (!(cin >> m)) { clearInput(); continue; }

        cout << "Enter cols N (2-20): ";
        if (!(cin >> n)) { clearInput(); continue; }

        if (m >= 2 && m <= MAX_R && n >= 2 && n <= MAX_C) break;
        cout << "Incorrect sizes. Try again.\n";
    }

    // Ввід елементів матриці
    cout << "Enter matrix elements (" << m << "x" << n << "):\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            while (true)
            {
                if (cin >> a[i][j]) break;
                clearInput();
                cout << "Incorrect value. Re-enter a[" << i + 1 << "][" << j + 1 << "]: ";
            }
        }
    }
}

void printMatrix(const int a[MAX_R][MAX_C], int m, int n)
{
    cout << "\nMatrix (" << m << "x" << n << "):\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << "\t";
        cout << "\n";
    }
}

// ---------- Task 1 (Matrix27): max among row minimums ----------
int rowMin(const int a[MAX_R][MAX_C], int row, int n)
{
    int mn = a[row][0];
    for (int j = 1; j < n; j++)
        if (a[row][j] < mn) mn = a[row][j];
    return mn;
}

int maxOfRowMins(const int a[MAX_R][MAX_C], int m, int n)
{
    int best = rowMin(a, 0, n);
    for (int i = 1; i < m; i++)
    {
        int mn = rowMin(a, i, n);
        if (mn > best) best = mn;
    }
    return best;
}

// ---------- Task 2 (Matrix72): insert ones-column before first all-positive column ----------
bool isAllPositiveColumn(const int a[MAX_R][MAX_C], int m, int col)
{
    for (int i = 0; i < m; i++)
        if (a[i][col] <= 0) return false;
    return true;
}

/*
  Вставка стовпця без допоміжної матриці:
  - шукаємо перший стовпець, де всі елементи > 0
  - якщо знайдено і є місце (n < MAX_C): зсуваємо стовпці вправо, вставляємо 1
*/
bool insertOnesColumnBeforeFirstPositive(int a[MAX_R][MAX_C], int m, int& n)
{
    int pos = -1;
    for (int j = 0; j < n; j++)
    {
        if (isAllPositiveColumn(a, m, j))
        {
            pos = j;
            break;
        }
    }

    if (pos == -1) return false;            // Немає потрібного стовпця
    if (n >= MAX_C) return false;           // Немає місця для вставки

    // Зсув вправо (з кінця, щоб не затирати)
    for (int j = n; j > pos; j--)
        for (int i = 0; i < m; i++)
            a[i][j] = a[i][j - 1];

    // Вставка стовпця з одиниць
    for (int i = 0; i < m; i++)
        a[i][pos] = 1;

    n++;
    return true;
}

// ---------- Tasks (must be separate functions WITHOUT parameters) ----------
void task1()
{
    int a[MAX_R][MAX_C];
    int m, n;

    inputMatrix(a, m, n);
    printMatrix(a, m, n);

    int ans = maxOfRowMins(a, m, n);
    cout << "\nTask 1 (Matrix27): max among row minimums = " << ans << "\n";
}

void task2()
{
    int a[MAX_R][MAX_C];
    int m, n;

    inputMatrix(a, m, n);
    printMatrix(a, m, n);

    bool changed = insertOnesColumnBeforeFirstPositive(a, m, n);

    if (changed)
        cout << "\nTask 2 (Matrix72): inserted ones-column.\n";
    else
        cout << "\nTask 2 (Matrix72): no suitable column OR no space, matrix unchanged.\n";

    printMatrix(a, m, n);
}

// ---------- Main menu ----------
int main()
{
    while (true)
    {
        cout << "\n===== LAB 7 MENU =====\n";
        cout << "1 - Task 1 (Matrix27)\n";
        cout << "2 - Task 2 (Matrix72)\n";
        cout << "0 - Exit\n";
        cout << "Choose: ";

        int choice;
        if (!(cin >> choice))
        {
            clearInput();
            continue;
        }

        if (choice == 0) break;
        if (choice == 1) task1();
        else if (choice == 2) task2();
        else cout << "Unknown option.\n";
    }

    return 0;
}