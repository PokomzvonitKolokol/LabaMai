// double - юзаем для чисел с плавающей точкой (https://education.yandex.ru/handbook/cpp/article/data-types)
// cmath - предоставляет доступ к математическим функциям, таким как sqrt (квадратный корень)
// шаблон:
//
//#include <iostream>
//#include <cmath> // Подключаем, если нужны мат. функции (sqrt)  
//using namespace std;

//int main() {
    // Объявление переменных
//    double a, b, result; // Пример для |R чисел

    // Ввод данных
//    cout << "Введите значение a: ";
//    cin >> a;
//    cout << "Введите значение b: ";
//    cin >> b;

    //  Проверка ( отрицательные числа )
//    if (a < 0 || b < 0) {
//        cout << "Ошибка: значения не могут быть отрицательными." << endl;
//        return 1; // Возврат с ошибкой






#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;

    cout << "Введите первый катет: ";
    cin >> a;
    cout << "Введите второй катет: ";
    cin >> b;

     if (a < 0 || b < 0) {
       cout << " значения не могут быть отрицательными." << endl;
        return 1; // Возврат с ошибкой

    c = sqrt(a * a + b * b);

    cout << "Гипотенуза = " << c << endl;

    return 0;
}
