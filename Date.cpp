#include "Date.h"

Date::Date()
{
    day = 0;
    month = 0;
    year = 0;
    hours = 0;
    minutes = 0;
}

Date::Date(int day, int month, int year, int hours, int minutes)
{
    this->day = day;
    this->month = month;
    this->year = year;
    this->hours = hours;
    this->minutes = minutes;
}

Date::Date(const Date& date)
{
    day = date.day;
    month = date.month;
    year = date.year;
    hours = date.hours;
    minutes = date.minutes;
}

int Date::getDay() { return day; }
int Date::getMonth() { return month; }
int Date::getYear() { return year; }
int Date::getHours() { return hours; }
int Date::getMinutes() { return minutes; }


void Date::setDay(int day) {
    if (day > 0 && day < 32)
        this->day = day;
}

void Date::setMonth(int month) {
    if (month > 0 && month < 13)
        this->month = month;
}

void Date::setYear(int year) {
    if (year > 0)
        this->year = year;
}

void Date::setHours(int hours) {
    if (hours >= 0 && hours < 24)
        this->hours = hours;
}

void Date::setMinutes(int minutes) {
    if (minutes >= 0 && minutes <= 60)
        this->minutes = minutes;
}

string Date::toString()
{
    return to_string(day) + "/" + to_string(month) + "/" + to_string(year) +
        "  " + to_string(hours) + ":" + to_string(minutes);
}

void Date::inputFromKeyboard()
{
    cout << "Year > ";
    cin >> year;

    cout << "Month > ";
    cin >> month;

    cout << "Day > ";
    cin >> day;

    cout << "Hours > ";
    cin >> hours;

    cout << "Minutes > ";
    cin >> minutes;
}
bool operator <(Date date1, Date date2)
{
    return (double)(date1.year * 366 + date1.month * 31 + date1.day) + (1.0 / (date1.hours * 60 + date1.minutes)) <
        (double)(date2.year * 366 + date2.month * 31 + date2.day) + (1.0 / (date2.hours * 60 + date2.minutes));
}

bool operator >(Date date1, Date date2)
{
    return (double)(date1.year * 366 + date1.month * 31 + date1.day) + (1.0 / (date1.hours * 60 + date1.minutes)) >
        (double)(date2.year * 366 + date2.month * 31 + date2.day) + (1.0 / (date2.hours * 60 + date2.minutes));
}

bool operator <=(Date date1, Date date2)
{
    return !(date1 > date2);
}

bool operator >=(Date date1, Date date2)
{
    return !(date1 < date2);
}

ostream& operator<<(ostream& out, Date& date)
{
    out << date.toString();
    return out;
}

istream& operator>>(istream& in, Date& date)
{
    cout << "Year > ";
    in >> date.year;

    cout << "Month > ";
    in >> date.month;

    cout << "Day > ";
    in >> date.day;

    cout << "Hours > ";
    in >> date.hours;

    cout << "Minutes > ";
    in >> date.minutes;

    return in;
}

ofstream& operator<<(ofstream& out, Date& date)
{
    out << date.toString();
    return out;
}

ifstream& operator>>(ifstream& in, Date& date)
{
    in >> date.year >> date.month >> date.day >> date.hours >> date.minutes;

    return in;
}