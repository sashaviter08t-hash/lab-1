#include <iostream>
#include <cmath>
using namespace std;

// ================= STRUCTURES =================

struct TPoint {
    double x;
    double y;
};

struct TTriangle {
    TPoint A;
    TPoint B;
    TPoint C;
    double P;
};

struct Begin36Data {
    double V1;
    double V2;
    double S;
    double T;
    double distance;
};

struct Boolean5Data {
    int A;
    int B;
    bool result;
};

// ================= FUNCTIONS =================

double Dist(TPoint p1, TPoint p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

void Perim(TTriangle* tr) {
    double AB = Dist(tr->A, tr->B);
    double BC = Dist(tr->B, tr->C);
    double AC = Dist(tr->A, tr->C);

    tr->P = AB + BC + AC;
}

void CalcBegin36(Begin36Data* d) {
    d->distance = d->S + d->T * (d->V1 + d->V2);
}

void CalcBoolean5(Boolean5Data* d) {
    d->result = (d->A >= 0 || d->B < -2);
}

// ================= TASKS =================

void task_Param65() {
    TPoint A, B, C, D;

    cout << "Enter point A (x y): ";
    cin >> A.x >> A.y;

    cout << "Enter point B (x y): ";
    cin >> B.x >> B.y;

    cout << "Enter point C (x y): ";
    cin >> C.x >> C.y;

    cout << "Enter point D (x y): ";
    cin >> D.x >> D.y;

    TTriangle ABC = { A, B, C, 0 };
    TTriangle ABD = { A, B, D, 0 };
    TTriangle ACD = { A, C, D, 0 };

    Perim(&ABC);
    Perim(&ABD);
    Perim(&ACD);

    cout << "Perimeter ABC = " << ABC.P << endl;
    cout << "Perimeter ABD = " << ABD.P << endl;
    cout << "Perimeter ACD = " << ACD.P << endl;
}

void task_Begin36() {
    Begin36Data d;

    cout << "Enter V1: ";
    cin >> d.V1;

    cout << "Enter V2: ";
    cin >> d.V2;

    cout << "Enter S: ";
    cin >> d.S;

    cout << "Enter T: ";
    cin >> d.T;

    CalcBegin36(&d);

    cout << "Distance after T hours = " << d.distance << endl;
}

void task_Boolean5() {
    Boolean5Data d;

    cout << "Enter A: ";
    cin >> d.A;

    cout << "Enter B: ";
    cin >> d.B;

    CalcBoolean5(&d);

    cout << boolalpha;
    cout << "Expression A >= 0 or B < -2 is " << d.result << endl;
}

// ================= MENU =================

int main() {
    int choice;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1 - Param65\n";
        cout << "2 - Begin36\n";
        cout << "3 - Boolean5\n";
        cout << "0 - Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            task_Param65();
            break;

        case 2:
            task_Begin36();
            break;

        case 3:
            task_Boolean5();
            break;

        case 0:
            cout << "Exit..." << endl;
            break;

        default:
            cout << "Wrong choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}