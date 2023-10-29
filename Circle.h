//
// Created by Admin on 18.10.2023.
//

// ifndef, define, endif для защиты от повторного включения заголовочного файла
#ifndef CIRCLE_CIRCLE_H
#define CIRCLE_CIRCLE_H

#include <ostream>

class Circle {
private:
    // Приватный члены класса радиус, координаты (x, y), константа PI для
    // вычисления площади
    const double PI = 3.1415926;
    double r;
    double x;
    double y;
public:
    // Конструктор по умолчанию
    Circle();
    // Конструктор с параметрами
    Circle(double r, double x, double y);
    // Функция, показывающая, лежит ли точка внутри круга
    bool IsInCircle(double x, double y) const;
    // Перегрузка операторов сравнения <, >, == (сравнивают два круга по площади).
    // Помечены как const, так как они не изменяют приватные переменные.
    // Ссылка на объект в параметрах также константная, так как объект не меняется
    bool operator<(const Circle &other_circle) const;
    bool operator>(const Circle &other_circle) const;
    bool operator==(const Circle &other_circle) const;
    // Перегрузка оператора сложения круга. Увеличивает радиус круга.
    Circle& operator+(double r);
    // Операторы вставки в поток и получения из потока. Для вставки в поток используется
    // << и поток std::ostream os, для получения из потока >> и std::istream is. Вместо os и is
    // мы потом используем соответственно cout и cin в примерах использования. Ключевое слово
    // friend означает, что эти функции не принадлежат классу, но при этом имеют доступ к его
    // приватным членам данных. Ссылка в операторе << константная, так как мы просто выводим
    // данные и не меняем их.
    friend std::ostream& operator<<(std::ostream& os, const Circle& circle);
    friend std::istream& operator>>(std::istream& is, Circle& circle);
};


#endif //CIRCLE_CIRCLE_H
