//предназначен для проверки, является ли заданная строка корректным оператором сравнения в языке с++
//bool iscomparisonoperator(const std::string& s) { - проверяет явл. ли строка s корректным оператором сравнения
//true — если s совпадает в точности с одним из следующих операторов:
//"==", "!=", "<=", ">=", "<", ">".
//false — во всех остальных случаях + пустые строки
//  State - определяет все возможные состояния
//распознаёт только точные совпадения — без пробелов, без лишних символов
// Примеры :
//"=="  true (оператор)
//"!="  true
//"<="  true
//">="  true (оператор)
//"<"  true (оператор)
//">" true (оператор)
//"="  false
//"!"  false (не оператор)
//"=>"  false (не оператор)
//"=<"  false (не оператор)

#include <iostream>
#include <string>

// Перечисление всех состояний конечного автомата
enum State {
    START,      // начальное состояние
    LT,         // '<' 
    GT,         //  '>' 
    EQ,         //  '=' (ожидаем второй '=')
    EXCL,       //  '!' (ожидаем '=')
    EQ_EQ,      // "=="
    EXCL_EQ,    //  "!="
    LT_EQ,      //  "<="
    GT_EQ,      //  ">="
    REJECT      // ошибка
};

                                                                // проверка того , что строка - это оператор сравнения 
bool iscomparisonoperator(const std::string& s) {                // https://education.yandex.ru/handbook/cpp/article/references-pointers-const - про константные ссылки
    if (s.empty()) 
        return false;

    State state = START;

    for (char c : s) {
        if (state == START) {
            if (c == '<') state = LT;
            else if (c == '>') state = GT;
            else if (c == '=') state = EQ;
            else if (c == '!') state = EXCL;
            else state = REJECT;    // REJECT - означает ошибку 
        }
        else if (state == LT) {                                                   //Это последовательная проверка: как только одно условие true - (1)
            if (c == '=') state = LT_EQ;                                         // выполняется его блок, остальные else if пропускаютс (2)
            else state = REJECT;
        }
        else if (state == GT) {
            if (c == '=') state = GT_EQ;
            else state = REJECT;
        }
        else if (state == EQ) {
            if (c == '=') state = EQ_EQ;
            else state = REJECT;
        }
        else if (state == EXCL) {
            if (c == '=') state = EXCL_EQ;
            else state = REJECT;
        }
                                                           // если распознали двусимвольный оператор , но строка продолжается - ошибка
        else if (state == EQ_EQ || state == EXCL_EQ || 
                 state == LT_EQ || state == GT_EQ) {
            state = REJECT;
        }


        if (state == REJECT)
            return false;
    }

                                                 // конечные состояния состояния:
    if (state == LT ||        // "<"
        state == GT ||        // ">"
        state == EQ_EQ ||     // "=="
        state == EXCL_EQ ||   // "!="
        state == LT_EQ ||     // "<="
        state == GT_EQ)       // ">="
        return true;

    return false;
}

int main() {
    std::string tests[] = {         //массив тестов , который охватывает все возможные ситуации , для понимания того , как работают  "автоматы"
        "==", "!=", "<=", ">=", "<", ">",
        "=", "!", "=>", "=<", "<>", "a", "", "===",
        "===", "!=", ">=", "x"
    };

    for (const auto& t : tests) {        // auto& - позволяет автоматически выводить тип переменной (https://learn.microsoft.com/ru-ru/cpp/cpp/auto-cpp?view=msvc-170)
        std::cout << "\"" << t << "\" -> "
                  << (iscomparisonoperator(t) ? "оператор" : "не оператор")
                  << "\n";
    }
    return 0;
}