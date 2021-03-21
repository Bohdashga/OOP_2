#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Date.h"

using namespace std;
class Ticket
{
private:
    int static ID;
    int number;
protected:
    bool control;
private:
    Date* arriveDate;
    Date* departDate;
    string departStation;
    string arriveStation;
    int raceNumber;

    bool sold;
public:
    string passanger;

    Ticket();

    Ticket(Date departDate, Date arriveDate, string departStation,
        string arriveStation, int raceNumber);
   

    Ticket(const Ticket& obj);
   

    ~Ticket();
    

    int getCount();

    bool sell();
    

    bool sell(Date departDate, Date arriveDate, string departStation,
        string arriveStation, int raceNumber);
    

    bool sell(string departStation, string arriveStation, int raceNumber);
   

    void cancelTicket();
     

    int getNumber();
    bool isControled();
    Date getArriveDate();
    Date getDepartDate();
    string getDepartStation();
    string getArriveStatiob();
    int getRaceNumber();
    void setDepartStation(string departStation);
    void setArriveStation(string arriveStation);
    void setRaceNumber(int raceNumber);

    string toString();
    

    void writeInFile(string fileName);
   

    friend ostream& operator<<(ostream& out, Ticket& ticket);
    friend istream& operator>>(istream& in, Ticket& ticket);

    friend ofstream& operator<<(ofstream& out, Ticket& ticket);
    friend ifstream& operator>>(ifstream& in, Ticket& ticket);


    

};
void sortByDate(Ticket** tickets, int size);

void printList(Ticket** tickets, int size);
ostream& operator<<(ostream& out, Ticket& ticket);
istream& operator>>(istream& in, Ticket& ticket);
ofstream& operator<<(ofstream& out, Ticket& ticket);
ifstream& operator>>(ifstream& in, Ticket& ticket);