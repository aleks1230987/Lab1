
#include <iostream>
using namespace std;

class Date {
public:
    int year, month, day, hour, minute, second;
    bool isOurEra;

    Date() {
        this->isOurEra = true;
        this->year = 1960;
        this->month = 1;
        this->day = 1;
        this->hour = 0;
        this->minute = 0;
        this->second = 0;
        
    }

    Date(bool isOurEra, int year, int month, int day, int hour, int minute, int second) {
        this->isOurEra = isOurEra;
        this->year = year;
        this->month = month;
        this->day = day;
        this->hour = hour;
        this->minute = minute;
        this->second = second;
        CheckDate();
    }

    bool CheckYear(int y) {
        if (((y % 4 == 0) and (y % 100 != 0)) or (y % 400 == 0)) return true;
        else return false;
    }

    int DaysInMonth(int month, int year) {
        switch (month) {
        case 1: return 31;
        case 2: if (CheckYear(year)) return 29; else return 28;
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
        }
    }

    void CheckDate() {

        while (second > 60) { minute++; second -= 60; }
        while (second < 0) { minute--; second += 60; }

        while (minute > 60) { hour++; minute -= 60; }
        while (minute < 0) { hour--; minute += 60; }

        while (hour > 24) { day++; hour -= 24; }
        while (hour < 0) { day--; hour += 24; }

        while (month > 12) { year++; month -= 12; }
        while (month < 0) { year--; month += 12; }

        while (day > DaysInMonth(month,year))
        {
            month++;
            day -= DaysInMonth(month, year);
            if (month > 12) { year++; month = 1; }
        }
        while (day <= 0)
        {
            month--;
            day += DaysInMonth(month, year);
            if (month < 0) { year--; month = 1; }
        }

        if (year < 0 && isOurEra == 1) {
            year = -1 * year;
            isOurEra = 0;
        }
        else if (year < 0 && isOurEra == 0) {
            year = -1 * year; 
            isOurEra = 1;
        }
        else if (year == 0) {
            year += 1;
            isOurEra = 1;
        }
    }

    Date add(int y, int m, int d, int h, int min, int s) const
    {
        Date NewDate = *this;

        NewDate.year += y;
        NewDate.month += m;
        NewDate.day += d;
        NewDate.hour += h;
        NewDate.minute += min;
        NewDate.second += s;

        NewDate.CheckDate();

        return NewDate;
    }

    Date subtract(int y, int m, int d, int h, int min, int s) const
    {
        Date NewDate = *this;

        NewDate.year -= y;
        NewDate.month -= m;
        NewDate.day -= d;
        NewDate.hour -= h;
        NewDate.minute -= min;
        NewDate.second -= s;

        NewDate.CheckDate();

        return NewDate;
    }

    Date operator+(const Date& other) const {
        Date res = *this;

        if ((other.isOurEra)&&(res.isOurEra)) {
            res.year += other.year;
        }
        else if ((other.isOurEra == 0) && (res.isOurEra)) {
            res.year -= other.year;
        }
        else if ((other.isOurEra) && (res.isOurEra == 0)) {
            res.year -= other.year;
        }
        else {
            res.year += other.year;
        }
        res.month += other.month;
        res.day += other.day;
        res.hour += other.hour;
        res.minute += other.minute;
        res.second += other.second;
        res.CheckDate();

        return res;
    }

    Date& operator+=(const Date& other) {

       
        if ((other.isOurEra) && (isOurEra)) {
            year += other.year;
        }
        else if ((other.isOurEra == 0) && (isOurEra)) {
            year -= other.year;
        }
        else if ((other.isOurEra) && (isOurEra == 0)) {
            year -= other.year;
        }
        else {
            year += other.year;
        }
        month += other.month;
        day += other.day;
        hour += other.hour;
        minute += other.minute;
        second += other.second;
        CheckDate();

        return *this;
    }

    Date operator-(const Date& other) const {
        Date res = *this;

        if ((other.isOurEra) && (res.isOurEra)) {
            res.year -= other.year;
        }
        else if ((other.isOurEra == 0) && (res.isOurEra)) {
            res.year += other.year;
        }
        else if ((other.isOurEra) && (res.isOurEra == 0)) {
            res.year += other.year;
        }
        else {
            res.year -= other.year;
        }
        res.month -= other.month;
        res.day -= other.day;
        res.hour -= other.hour;
        res.minute -= other.minute;
        res.second -= other.second;
        res.CheckDate();

        return res;
    }

    Date& operator-=(const Date& other) {

        if ((other.isOurEra) && (isOurEra)) {
            year -= other.year;
        }
        else if ((other.isOurEra == 0) && (isOurEra)) {
            year += other.year;
        }
        else if ((other.isOurEra) && (isOurEra == 0)) {
            year += other.year;
        }
        else {
            year -= other.year;
        }
        month -= other.month;
        day -= other.day;
        hour -= other.hour;
        minute -= other.minute;
        second -= other.second;
        CheckDate();

        return *this;
    }

    bool operator<(const Date& other) const {
        if (isOurEra != other.isOurEra)
        {
            return isOurEra < other.isOurEra;
        }
        if (year != other.year)
        {
            return year < other.year;
        }
        if (month != other.month)
        {
            return month < other.month;
        }
        if (day != other.day)
        {
            return day < other.day;
        }
        if (hour != other.hour)
        {
            return hour < other.hour;
        }
        if (minute != other.minute)
        {
            return minute < other.minute;
        }
        if (second != other.second)
        {
            return second < other.second;
        }
        return false;
    }

    bool operator>(const Date& other) const {
        if (isOurEra != other.isOurEra)
        {
            return isOurEra > other.isOurEra;
        }
        if (year != other.year)
        {
            return year > other.year;
        }
        if (month != other.month)
        {
            return month > other.month;
        }
        if (day != other.day)
        {
            return day > other.day;
        }
        if (hour != other.hour)
        {
            return hour > other.hour;
        }
        if (minute != other.minute)
        {
            return minute > other.minute;
        }
        if (second != other.second)
        {
            return second > other.second;
        }
        return false;
    }

    bool operator==(const Date& other) const {
        if ((isOurEra == other.isOurEra) && (year == other.year) && (month == other.month) && (day == other.day) && (hour == other.hour) && (minute == other.minute) && (second == other.second)) {
            return true;
        }
        return false;
    }

    friend ostream& operator<<(ostream& os, const Date& other) {
        if (other.isOurEra == 1)
        {
            os << "Дата: " << other.year << "/" << other.month << "/" << other.day << "/" << other.hour << "/" << other.minute << "/" << other.second << "  Нашей эры";
        }
        else {
            os << "Дата: " << other.year << "/" << other.month << "/" << other.day << "/" << other.hour << "/" << other.minute << "/" << other.second << "  До нашей эры";
        }
        return os;
    }

    Date& operator=(const Date& other) {
        isOurEra = other.isOurEra;
        year = other.year;
        month = other.month;
        day = other.day;
        hour = other.hour;
        minute = other.minute;
        second = other.second;

        return *this;
    }

};


int main()
{
    setlocale(LC_ALL, "Russian");
    Date date1;
    Date date2(true, 312, 6, 20, 7, 23, 43);
    Date date3(false, 4012, 642, 230, 17, 223, 443);
    Date date4;
    cout << date1 << endl;
    cout << date3 << endl;
    date1 += date3;
    cout << date1 << endl;
    date1 += date3;
    cout << date1 << endl;
    cout << (date1 - date3) << endl;
}

