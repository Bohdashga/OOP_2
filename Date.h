#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Date
{
private:
    int day, month, year;
    int hours, minutes;
public:
    Date();

    Date(int day, int month, int year, int hours, int minutes);

    Date(const Date& date);

    int getDay();
    int getMonth();
    int getYear();
    int getHours();
    int getMinutes();

    void setDay(int day);

    void setMonth(int month);

    void setYear(int year);

    void setHours(int hours);

    void setMinutes(int minutes);

    string toString();

    void inputFromKeyboard();

    friend bool operator <(Date date1, Date date2);
    friend bool operator >(Date date1, Date date2);
    friend bool operator >=(Date date1, Date date2);
    friend bool operator <=(Date date1, Date date2);

    friend ostream& operator<<(ostream& out, Date& date);
    friend istream& operator>>(istream& in, Date& date);
    friend ofstream& operator<<(ofstream& out, Date& date);
    friend ifstream& operator>>(ifstream& in, Date& date);
};
bool operator <(Date date1, Date date2);
bool operator >(Date date1, Date date2);
bool operator >=(Date date1, Date date2);
bool operator <=(Date date1, Date date2);

ostream& operator<<(ostream& out, Date& date);
istream& operator>>(istream& in, Date& date);
ofstream& operator<<(ofstream& out, Date& date);
ifstream& operator>>(ifstream& in, Date& date);