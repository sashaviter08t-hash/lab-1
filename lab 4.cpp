#include <iostream>
#include <cmath>

using namespace std;

// ==================== ОГОЛОШЕННЯ ФУНКЦІЙ ====================

// ---- Головне меню ----
void show_menu();                 // виведення меню вибору завдання

// ---- Завдання 2 (цілочисельні) – Integer16 ----
bool in_N(int &pN);               // введення N з перевіркою (трицифрове)
int  swap_10_1(int N);            // перестановка цифр десятків і одиниць
void out_res_int16(int res);      // виведення результату
void task_Integer16();            // розв’язання задачі Integer16

// ---- Завдання 1 – Proc13 ----
void SortDec3(double &A, double &B, double &C);   // сортування трійки за спаданням
void task_Proc13();                               // процедура Proc13

// ---- Завдання 1 – Proc44 ----
double TriangleAreaByPoints(double x1, double y1,
                            double x2, double y2,
                            double x3, double y3);   // обчислення площі трикутника
void task_Proc44();                                  // процедура Proc44


// ==================== ФУНКЦІЯ main() ====================
int main()
{
    show_menu();

    int choice;
    cout << "Enter task number: ";
    if (!(cin >> choice)) {
        cerr << "Input error: expected integer value." << endl;
        return 1;
    }

    switch (choice) {
        case 1:
            task_Integer16();
            break;
        case 2:
            task_Proc13();
            break;
        case 3:
            task_Proc44();
            break;
        default:
            cout << "Invalid task number." << endl;
    }

    return 0;
}


// ==================== ВИЗНАЧЕННЯ ФУНКЦІЙ ====================

// ---- Меню ----
void show_menu()
{
    cout << "Lab work No.4 – Functions\n";
    cout << "1 - Integer16 (swap tens and ones digits in a 3-digit number)\n";
    cout << "2 - Proc13 (procedure SortDec3 for two triples of numbers)\n";
    cout << "3 - Proc44 (function TriangleAreaByPoints for 3 triangles)\n";
}

// ----------------------------------------------------------
//  Integer16: дане тризначне число. Вивести число, отримане
//  при перестановці цифр десятків і одиниць.
// ----------------------------------------------------------

void task_Integer16()
{
    int N;

    if (!in_N(N)) {
        cout << "Invalid input: N must be a 3-digit integer." << endl;
    } else {
        int res = swap_10_1(N);
        out_res_int16(res);
    }
}

bool in_N(int &pN)
{
    cout << "\nInteger16." << endl;
    cout << "Enter a three-digit integer N = ";
    cin >> pN;

    if (cin.fail())
        return false;

    int absN = (pN < 0) ? -pN : pN;

    if (absN >= 100 && absN <= 999)
        return true;
    else
        return false;
}

int swap_10_1(int N)
{
    int sign = (N < 0) ? -1 : 1;
    int absN = (N < 0) ? -N : N;

    int hundreds = absN / 100;
    int tens     = (absN / 10) % 10;
    int ones     = absN % 10;

    int res = hundreds * 100 + ones * 10 + tens;
    return sign * res;
}

void out_res_int16(int res)
{
    cout << "Result after swapping digits: N' = " << res << endl;
}

// ----------------------------------------------------------
//  Proc13: процедура SortDec3(A,B,C) впорядковує A,B,C
//  за спаданням. Використати для двох наборів чисел.
// ----------------------------------------------------------

void SortDec3(double &A, double &B, double &C)
{
    double t;
    if (A < B) { t = A; A = B; B = t; }
    if (A < C) { t = A; A = C; C = t; }
    if (B < C) { t = B; B = C; C = t; }
}

void task_Proc13()
{
    double A1, B1, C1;
    double A2, B2, C2;

    cout << "\nProc13. Enter A1, B1, C1: ";
    if (!(cin >> A1 >> B1 >> C1)) {
        cout << "Input error." << endl;
        return;
    }

    cout << "Enter A2, B2, C2: ";
    if (!(cin >> A2 >> B2 >> C2)) {
        cout << "Input error." << endl;
        return;
    }

    if (A1 < -100 || A1 > 100 ||
        B1 < -100 || B1 > 100 ||
        C1 < -100 || C1 > 100 ||
        A2 < -100 || A2 > 100 ||
        B2 < -100 || B2 > 100 ||
        C2 < -100 || C2 > 100) {
        cout << "All values must be within [-100; 100]." << endl;
        return;
    }

    SortDec3(A1, B1, C1);
    SortDec3(A2, B2, C2);

    cout << "First triple (descending):  "
         << A1 << "  " << B1 << "  " << C1 << endl;
    cout << "Second triple (descending): "
         << A2 << "  " << B2 << "  " << C2 << endl;
}

// ----------------------------------------------------------
//  Proc44: функція TriangleAreaByPoints(x1,y1,x2,y2,x3,y3)
//  обчислює площу трикутника за формулою:
//  S = 1/2 * |(x2-x1)(y3-y1) - (x3-x1)(y2-y1)|.
// ----------------------------------------------------------

double TriangleAreaByPoints(double x1, double y1,
                            double x2, double y2,
                            double x3, double y3)
{
    double s = 0.5 * fabs((x2 - x1) * (y3 - y1)
                        - (x3 - x1) * (y2 - y1));
    return s;
}

void task_Proc44()
{
    double x1, y1, x2, y2, x3, y3;

    cout << "\nProc44. Triangle 1 (x1 y1 x2 y2 x3 y3): ";
    if (!(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)) {
        cout << "Input error." << endl;
        return;
    }

    cout << "Triangle 2 (x1 y1 x2 y2 x3 y3): ";
    double x1b, y1b, x2b, y2b, x3b, y3b;
    if (!(cin >> x1b >> y1b >> x2b >> y2b >> x3b >> y3b)) {
        cout << "Input error." << endl;
        return;
    }

    cout << "Triangle 3 (x1 y1 x2 y2 x3 y3): ";
    double x1c, y1c, x2c, y2c, x3c, y3c;
    if (!(cin >> x1c >> y1c >> x2c >> y2c >> x3c >> y3c)) {
        cout << "Input error." << endl;
        return;
    }

    bool bad =
        x1  < -100 || x1  > 100 || y1  < -100 || y1  > 100 ||
        x2  < -100 || x2  > 100 || y2  < -100 || y2  > 100 ||
        x3  < -100 || x3  > 100 || y3  < -100 || y3  > 100 ||
        x1b < -100 || x1b > 100 || y1b < -100 || y1b > 100 ||
        x2b < -100 || x2b > 100 || y2b < -100 || y2b > 100 ||
        x3b < -100 || x3b > 100 || y3b < -100 || y3b > 100 ||
        x1c < -100 || x1c > 100 || y1c < -100 || y1c > 100 ||
        x2c < -100 || x2c > 100 || y2c < -100 || y2c > 100 ||
        x3c < -100 || x3c > 100 || y3c < -100 || y3c > 100;

    if (bad) {
        cout << "All coordinates must be within [-100; 100]." << endl;
        return;
    }

    double S1 = TriangleAreaByPoints(x1,  y1,  x2,  y2,  x3,  y3);
    double S2 = TriangleAreaByPoints(x1b, y1b, x2b, y2b, x3b, y3b);
    double S3 = TriangleAreaByPoints(x1c, y1c, x2c, y2c, x3c, y3c);

    cout << "S1 = " << S1 << endl;
    cout << "S2 = " << S2 << endl;
    cout << "S3 = " << S3 << endl;
}
