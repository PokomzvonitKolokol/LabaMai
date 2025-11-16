// #include <iostream> — подключает библиотеку для работы с вводом и выводом 
// include <string> — подключает библиотеку для работы со стрОками
// main - главная функция программы , с которой начинается ее выполнение
// string - тип данных для строк
// str - переменная , куда будет записан. строка , которая вводится
// undstr -  переменная ,  куда будет записана подстрока , которая вводится
// getline - функция , считывающая всю! строку (https://www.geeksforgeeks.org/cpp/getline-string-c/?ysclid=mi1vbnt9fs998425405)
// (https://www.geeksforgeeks.org/cpp/substring-in-cpp/?ysclid=mi1ve6p34w980674675) substr - используется для извлечения подстроки из заданной строки
// pos - ищет подстроку в строке
// Вход : подстрока и строка
// Выход : целое число 
// Строка : "aaaa", подстрока : "a" => 4 вхождений => примнер
// строка : "", подстрока : "nol" => 0 вхождений => пример того , что будет , если запросить подстроку от пустой строки
// Строка : "hello" , подстрока : "" => 0 вхождений => пустая подстрока от существенной строки
// Строка : "ab", подстрока: "abc" => 0 вхождений => подстрока > строки

//шаблон:

// #include <iostream>
//#include <string>

//int main() {
//    std::string str, undstr;
    
    // Ввод строк
//    std::cout << "Введите строку: ";
//    std::getline(std::cin, str);

//   std::cout << "Введите подстроку для поиска: ";
//    std::getline(std::cin, undstr);

    // Условие: если подстрока пуста
//    if (undstr.empty()) {
//        std::cout << "Пустая подстрока. Количество вхождений: 0" << std::endl;
//        return 0; // Возврат из main в случае пустой подстроки
    

//    int count = 0;
//    size_t pos = 0;

    // Цикл поиска с условием
//    while ((pos = str.find(undstr, pos)) != std::string::npos) {
//        ++count;
//        pos += 1; // сдвигаем позицию на 1, чтобы искать перекрывающиеся вхождения
    

//    std::cout << "Количество вхождений подстроки: " << count << std::endl;

    // Явный return 0; в конце main (по умолчанию, но для ясности)





#include <iostream>
#include <string>

int main() {
    std::string str, undstr;
    
    std::cout << "Введите строку: ";
    std::getline(std::cin, str);

    std::cout << "Введите подстроку для поиска: ";
    std::getline(std::cin, undstr);

    if (undstr.empty()) {
        std::cout << "Пустая подстрока. Количество вхождений: 0" << std::endl;
        return 0;
    }

    int count = 0;
    size_t pos = 0;

    while ((pos = str.find(undstr, pos)) != std::string::npos) {
        ++count;
        pos += 1; // сдвигаем позицию на 1, чтобы искать перекрывающиеся вхождения
    }

    std::cout << "Количество вхождений подстроки: " << count << std::endl;

    return 0;
}