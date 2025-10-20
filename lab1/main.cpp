#include <iostream>
using namespace std;

int main() {
    // Задача Begin11
    cout << "=== Задача 1: Begin11 ===" << endl;
    // Дана довжина L окружності. Знайти її радіус R і площу S круга.
    // L = 2 * pi * R, S = pi * R^2, pi = 3.14
    double L, R, S;
    const double pi = 3.14;

    // Введення L
    cout << "Введiть довжину L окружностi: ";
    cin >> L;

    // Обчислення R та S
    R = L / (2 * pi);
    S = pi * R * R;

    // Виведення результатів
    cout << "Радiус R = " << R << endl;
    cout << "Площа круга S = " << S << endl;


    // Задача Begin21
    cout << "\n=== Задача 2: Begin21 ===" << endl;
    // Дано кут в радіанах. Знайти значення цього ж кута в градусах.
    // 180° = pi радіан
    double alpha_rad, alpha_deg;

    // Введення alpha
    cout << "Введiть кут alpha в радiанах (0 <= alpha < 2*pi): ";
    cin >> alpha_rad;

    // Обчислення градусів
    alpha_deg = alpha_rad * 180 / pi;

    // Виведення результату
    cout << "Значення кута в градусах = " << alpha_deg << endl;


    // Задача Begin48
    cout << "\n=== Задача 3: Begin48 ===" << endl;
    // Дано два ненульових числа. Знайти квадрат їх середнього геометричного.
    // G^2 = a * b
    double a, b, G2;

    // Введення a і b
    cout << "Введiть перше ненульове число a: ";
    cin >> a;
    cout << "Введiть друге ненульове число b: ";
    cin >> b;

    // Обчислення G^2
    G2 = a * b;

    // Виведення результату
    cout << "Квадрат середнього геометричного = " << G2 << endl;

    return 0;
}
