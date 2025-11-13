#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;

    cout << "Введите первый катет: ";
    cin >> a;
    cout << "Введите второй катет: ";
    cin >> b;

    c = sqrt(a * a + b * b);

    cout << "Гипотенуза = " << c << endl;

    return 0;
}