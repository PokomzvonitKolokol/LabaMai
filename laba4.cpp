#include <iostream>
#include <string>
#include <cstring>  // для strstr (работает с c_str())
#include <vector>   // НЕ используем, но <string> иногда требует его — оставим "на всякий"

// Простое перечисление (не enum class — новичку проще)
enum Priority {
    LOW,     // 0
    MEDIUM,  // 1
    HIGH     // 2
};

// Структура заметки
struct Note {
    int id;
    std::string text;
    int length;      // можно не хранить, но по условию — есть, и так быстрее
    Priority priority;
};

// Вспомогательная функция: приоритет → строка
const char* prioStr(Priority p) {
    switch (p) {
        case LOW:    return "Низкий";
        case MEDIUM: return "Средний";
        case HIGH:   return "Высокий";
        default:     return "???";
    }
}

// 1. Средняя длина по приоритету
double averageLength(Note notes[], int n, Priority prio) {
    int sum = 0, count = 0;
    for (int i = 0; i < n; ++i) {
        if (notes[i].priority == prio) {
            sum += notes[i].length;
            ++count;
        }
    }
    return count == 0 ? 0.0 : static_cast<double>(sum) / count;
}

// 2. Фильтр: приоритет ≥ minPrio, длина ∈ [minLen, maxLen]
void filterNotes(Note notes[], int n, Priority minPrio, int minLen, int maxLen) {
    std::cout << "🔹 Фильтр: приоритет ≥ " << prioStr(minPrio)
              << ", длина от " << minLen << " до " << maxLen << "\n";

    bool found = false;
    for (int i = 0; i < n; ++i) {
        Note& note = notes[i];
        if (note.priority >= minPrio && note.length >= minLen && note.length <= maxLen) {
            std::cout << "  ID=" << note.id
                      << " | " << prioStr(note.priority)
                      << " | len=" << note.length
                      << " | \"" << note.text << "\"\n";
            found = true;
        }
    }
    if (!found) std::cout << "  (ничего не найдено)\n";
    std::cout << "---\n";
}

// 3. Поиск подстроки (в std::string можно искать через .find(), но strstr тоже работает)
void searchSubstring(Note notes[], int n, const std::string& substr) {
    std::cout << "🔹 Поиск подстроки: \"" << substr << "\"\n";
    bool found = false;
    for (int i = 0; i < n; ++i) {
        // Используем .find() — более современно и для std::string
        if (notes[i].text.find(substr) != std::string::npos) {
            std::cout << "  ID=" << notes[i].id << ": \"" << notes[i].text << "\"\n";
            found = true;
        }
    }
    if (!found) std::cout << "  (не найдено)\n";
    std::cout << "---\n";
}

// 4. Сортировка: сначала по приоритету (HIGH → MEDIUM → LOW), затем по длине (↑)
void sortNotes(Note notes[], int n) {
    // Пузырьковая сортировка — просто и понятно
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            Note& a = notes[j];
            Note& b = notes[j + 1];

            // 1. Сначала по приоритету (больше — важнее)
            if (a.priority < b.priority) {
                Note tmp = a; a = b; b = tmp;
            }
            // 2. Если приоритеты равны — по длине (меньше — раньше)
            else if (a.priority == b.priority && a.length > b.length) {
                Note tmp = a; a = b; b = tmp;
            }
        }
    }
    std::cout << "🔹 Сортировка: приоритет (↓), затем длина (↑)\n---\n";
}

// —————————————————————————————————————
// Основная программа
// —————————————————————————————————————
int main() {
    const int N = 10;

    // Инициализируем 10 заметок
    Note notes[N] = {
        {1, "Купить молоко",               0, LOW},
        {2, "Прочитать главу",             0, MEDIUM},
        {3, "Срочно: сдать лабу!",         0, HIGH},
        {4, "Погладить кота",              0, LOW},
        {5, "Написать отчёт",              0, MEDIUM},
        {6, "Сдать зачёт по C++",          0, HIGH},
        {7, "Заправить машину",            0, LOW},
        {8, "Подготовить презентацию",     0, MEDIUM},
        {9, "Оплатить ЖКХ",                0, LOW},
        {10, "Исправить баг в программе", 0, HIGH}
    };

    // Заполним длину (или можно вычислять на лету, но по условию — поле есть)
    for (int i = 0; i < N; ++i) {
        notes[i].length = static_cast<int>(notes[i].text.length());
    }

    // ——— Выполняем задания: ———

    // 1. Средняя длина по приоритетам
    std::cout << " Средняя длина заметок:\n";
    std::cout << "Низкий:    " << averageLength(notes, N, LOW) << "\n";
    std::cout << "Средний:   " << averageLength(notes, N, MEDIUM) << "\n";
    std::cout << "Высокий:   " << averageLength(notes, N, HIGH) << "\n";
    std::cout << "---\n";

    // 2. Фильтр: приоритет ≥ MEDIUM, длина от 15 до 25
    filterNotes(notes, N, MEDIUM, 15, 25);

    // 3. Поиск подстроки
    searchSubstring(notes, N, "Сдать");

    // 4. Сортировка и вывод результата (чтобы проверить)
    sortNotes(notes, N);

    std::cout << " Результат сортировки:\n";
    for (int i = 0; i < N; ++i) {
        std::cout << "[" << i+1 << "] ID=" << notes[i].id
                  << " | " << prioStr(notes[i].priority)
                  << " | len=" << notes[i].length
                  << " | \"" << notes[i].text << "\"\n";
    }

    return 0;
}
