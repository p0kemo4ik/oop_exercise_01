#ifndef TIMEPOINT_HPP
#define TIMEPOINT_HPP

#include <iostream>
#include <cmath>

class TimePoint{
private:
    int hour;
    int minute;
    int second;
public:
    TimePoint();

    void Read(std::istream &is); //ввод
    void Write(std::ostream &os); //вывод

    TimePoint Plus(TimePoint &a);//сумма моментов временни
    TimePoint Minus(TimePoint &a); //разница моментов временни
    TimePoint AddSec(int &sec);//добавь заданное количество секунд
    TimePoint SubtractSec(int &sec);//отнеми заданное количество секунд
    TimePoint ToTpFromSec(int &sec);//Перевод в Timepoint из секунд
    TimePoint ToTpFromMin(int &min);//Первод в Timepoint из минут

    short Compare(TimePoint &a);//сравнение моментов временни
    int HowManyTimesBigger(TimePoint &a);//Во сколько раз больше(меньше)
    bool IsCorrect();//проверка правильности ввода данных
    int ToSec();//Перевод из TimePoint в секунды
    int ToMinute();//Перевод из TimePoint в минуты
};
#endif //LAB1_TIMEPOINT_HPP
