#ifndef MYFINANCE_DATE_H
#define MYFINANCE_DATE_H

#include <string>

using namespace std;

class Date {
private:
    int _year;
    int _month;
    int _day;

public:
    Date(int year, int month, int day) {
        _year = year;
        _month = month;
        _day = day;
    }

    string ToString() {
        return to_string(_year) + "." + to_string(_month) + "." + to_string(_day);
    }
};


#endif //MYFINANCE_DATE_H
