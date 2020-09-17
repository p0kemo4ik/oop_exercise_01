#include <iostream>
#include "TimePoint.hpp"
int main() {
    TimePoint a;

    std::cout << "Введите время 1" << std::endl;

    a.Read(std::cin);
    if(a.IsCorrect()==false){
        std::cout << "Неверный формат ввода hh mm ss"<<std::endl;
        return 0;
    }
    std::cout << "В секундах" << std::endl;
    std::cout << a.ToSec() << std::endl;
    std::cout << "В минутах" << std::endl;
    std::cout << a.ToMinute()<< std::endl;

    TimePoint b;
    std::cout << "Введиет время 2" << std::endl;
    b.Read(std::cin);
    if(b.IsCorrect()==false){
        std::cout << "Неверный формат ввода hh mm ss"<<std::endl;
        return 0;
    }
    std::cout << "Сумма временни 1 и 2" << std::endl;
    a.Plus(b).Write(std::cout);
    std::cout << "Разница временни 1 и 2" << std::endl;
    a.Minus(b).Write(std::cout);
    int j = a.Compare(b);
    std::cout << "Сравнение временни 1 и 2" << std::endl;
    std::cout << j << std::endl;
    std::cout << "Во сколько раз время 1 больше временни 2" << std::endl;
    j =a.HowManyTimesBigger(b);
    std::cout << j << std::endl;

    int c;//кол-во сек добавленных/убраных сек

    std::cout << "Введите С секунд" << std::endl;
    std::cin >> c;
    std::cout << "Добавлено С секунд в время 1" << std::endl;
    a.AddSec(c).Write(std::cout);
    std::cout << "Убранно С секунд из временни 1" << std::endl;
    a.SubtractSec(c).Write(std::cout);

    int d;
    TimePoint e;
    std::cout << "Введите кол-во минут, которые хотите перевести" << std::endl;
    std::cin >> d;
    std::cout << "Минуты переведены в стандартное время" << std::endl;
    e.ToTpFromMin(d).Write(std::cout);
}