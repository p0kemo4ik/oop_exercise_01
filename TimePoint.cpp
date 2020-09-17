#include "TimePoint.hpp"

TimePoint::TimePoint() {
    second = 0;
    minute = 0;
    hour = 0;
}

void TimePoint::Read(std::istream &is){
    is >> hour >> minute >> second;
}

void TimePoint::Write(std::ostream &os) {
    os << hour << ":" << minute << ":" << second << std::endl;
}

int TimePoint::ToSec() {
    int result;
    result = second + minute*60 + hour*3600;
    return result;
}

int TimePoint::ToMinute() {
    int result;
    result = ToSec() / 60;
    return result;
}

TimePoint TimePoint::ToTpFromSec(int &sec) {
    TimePoint result;
    result.hour = sec / 3600;
    result.minute = sec / 60 - result.hour*60;
    result.second= sec - (result.minute)*60 -(result.hour)*3600;
    return result;
}

TimePoint TimePoint::ToTpFromMin(int &min) {
    TimePoint result;
    result.hour = min / 60;
    result.minute= min - (result.hour)*60;
    return result;
}

TimePoint TimePoint::Plus(TimePoint &a){
    TimePoint result;
    int normal = (ToSec() + a.ToSec()) % 86400;
    return result.ToTpFromSec(normal);
}

TimePoint TimePoint::Minus(TimePoint &a) {
    TimePoint result;
    int normal = (ToSec() - a.ToSec());
    if(normal >= 0){
        return result.ToTpFromSec(normal);
    } else {
        normal+=86400;
        return result.ToTpFromSec(normal);
    }
}

TimePoint TimePoint::AddSec(int &sec) {
    TimePoint result;
    int normal = (ToSec() + sec) % 86400;
    return result.ToTpFromSec(normal);
}

TimePoint TimePoint::SubtractSec(int &sec) {
    TimePoint result;
    int normal = (ToSec() - sec);
    if(normal >= 0){
        return result.ToTpFromSec(normal);
    } else {
        normal+=86400;
        return result.ToTpFromSec(normal);
    };
}

int TimePoint::HowManyTimesBigger(TimePoint &a) {
    int result = ToSec()/a.ToSec();
    return result;
}

bool TimePoint::IsCorrect(){
    if(hour>24){
        return false;
    } else if(minute>60){
        return false;
    } else if(second>60){
        return false;
    } else {
        return true;
    }
}
short TimePoint::Compare(TimePoint &a) {
    if(ToSec()==a.ToSec()){
        return 0;
    } else if (ToSec() > a.ToSec()){
        return 1;
    } else {
        return -1;
    }
}