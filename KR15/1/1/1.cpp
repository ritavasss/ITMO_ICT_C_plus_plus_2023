#include <iostream>
#include <map>
#include <string>

struct StudentGrade {
    std::string name;
    char grade;
};

int main() {
    system("chcp 1251");
    std::map<std::string, char> grades; // Контейнер map для хранения оценок

    // Функция для добавления оценки студента по его имени
    auto assignGrade = [](std::map<std::string, char>& grades, const std::string& name, char grade) {
        grades[name] = grade; // Присваиваем оценку студенту по его имени
    };

    // Пример использования
    assignGrade(grades, "Анна", 'A');
    assignGrade(grades, "Мария", 'B');
    assignGrade(grades, "Дмитрий", 'C');

    // Запрос оценок по имени студента
    std::string studentName;
    std::cout << "Введите имя студента для получения оценки: ";
    std::cin >> studentName;

    // Поиск оценки студента и вывод результата
    auto it = grades.find(studentName);
    if (it != grades.end()) {
        std::cout << "Оценка студента " << studentName << ": " << it->second << std::endl;
    }
    else {
        std::cout << "Оценка для студента " << studentName << " не найдена." << std::endl;
    }

    return 0;
}
