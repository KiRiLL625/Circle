//
// Created by Admin on 18.10.2023.
//

#include <iostream>
#include "Circle.h"

// Значения в конструкторе по умолчанию инициализируем нулём
Circle::Circle(): r(0), x(0), y(0) {}

// Инициализируем приватные члены данных теми, которые вводим сами
Circle::Circle(double r, double x, double y): r(r), x(x), y(y) {}

// Основной комментарий в h-файле. Кстати, эту функцию тоже можно сделать константной
bool Circle::IsInCircle(double x, double y) const {
    return (x - this->x) * (x - this->x) + (y - this->y) * (y - this->y) <= r * r;
}

// Ну тут понятно, сравниваем два круга по площади
bool Circle::operator<(const Circle &other_circle) const {
    return PI * r * r < PI * other_circle.r * other_circle.r;
}

bool Circle::operator>(const Circle &other_circle) const {
    return PI * r * r > PI * other_circle.r * other_circle.r;
}

bool Circle::operator==(const Circle &other_circle) const {
    return (PI * r * r) == (PI * other_circle.r * other_circle.r);
}

// Добавляем к кругу радиус
Circle& Circle::operator+(const double r) {
    this->r += r;
    return *this;
}

// Просто выводим данные в поток (здесь friend писать не надо)
std::ostream& operator<<(std::ostream &os, const Circle &circle) {
    os << "r: " << circle.r << " x: " << circle.x << " y: " << circle.y;
    return os;
}

// Тут надо ввести данные из потока и реализация почти не должна отличаться от
// operator<<, но проблема в том, что данные из потока мы получаем в строковом виде
// (а когда наоборот вставляем данные в поток они неявно в строку преобразуются).
// Здесь же надо объявить временные строковые переменные, считать данные из потока,
// а затем преобразовать их в дробные с помощью функции stod().
std::istream& operator>>(std::istream &is, Circle &circle) {
    std::string tmp_r, tmp_x, tmp_y;
    is >> tmp_r >> tmp_x >> tmp_y;
    circle.r = std::stod(tmp_r);
    circle.x = std::stod(tmp_x);
    circle.y = std::stod(tmp_y);
    return is;
}

int main() {
    // Создаём круг радуса 4 и начальными точками (5, 9)
    Circle circle1(4, 5, 9);
    // Проверка оператора вывода в поток
    std::cout << circle1 << std::endl;
    // Проверка лежит ли точка (5, 9) в круге
    std::cout << circle1.IsInCircle(5, 9) << std::endl;
    // Проверка лежит ли точка (5, 10) в круге
    std::cout << circle1.IsInCircle(5, 10) << std::endl;
    // Увеличиваем радиус круга на 6 (не получится использовать +=, так как
    // его надо перегружать отдельно)
    circle1 + 6;
    // Снова выводим круг в поток вывода
    std::cout << circle1 << std::endl;
    // Создаём второй круг с помощью конструктора по умолчанию
    Circle circle2;
    // Проверка, что выведет 0 0 0
    std::cout << circle2 << std::endl;
    std::cout << "Enter radius, x, y of circle2:" << std::endl;
    // Проверка оператора получения данных из потока
    std::cin >> circle2;
    // Снова выводим данные, чтобы проверить, что всё корректно
    std::cout << circle2 << std::endl;
    // Проверка оператора сравнения по площади
    std::cout << (circle1 < circle2) << std::endl;
    return 0;
}