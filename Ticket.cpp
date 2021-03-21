#include "Ticket.h"

int Ticket::ID = 0;


Ticket::Ticket()
    {
        number = ++ID * 100 + rand() % 100;
        cancelTicket();
    }

Ticket::Ticket(Date departDate, Date arriveDate, string departStation,
        string arriveStation, int raceNumber)
    {
        number = ++ID * 100 + rand() % 100;
        sell(departDate, arriveDate, departStation, arriveStation, raceNumber);
    }

Ticket::Ticket(const Ticket& obj)
    {
        ID++;
        number = obj.number;
        control = obj.control;
        arriveDate = new Date(*obj.arriveDate);
        departDate = new Date(*obj.departDate);
        departStation = obj.departStation;
        arriveStation = obj.arriveStation;
        raceNumber = obj.raceNumber;
    }

Ticket:: ~Ticket()
    {
        if (arriveDate != NULL)
            delete arriveDate;
        if (departDate != NULL)
            delete departDate;

        ID--;
    }

    int Ticket::getCount() { return ID; }

    bool Ticket::sell()
    {
        return sold;
    }

    bool Ticket::sell(Date departDate, Date arriveDate, string departStation,
        string arriveStation, int raceNumber)
    {
        if (!sold)
        {
            this->departDate = new Date(departDate);
            this->arriveDate = new Date(arriveDate);
            this->departStation = departStation;
            this->arriveStation = arriveStation;
            this->raceNumber = raceNumber;

            sold = true;
        }
        return sold;
    }

    bool Ticket::sell(string departStation, string arriveStation, int raceNumber)
    {
        if (!sold)
        {
            this->departStation = departStation;
            this->arriveStation = arriveStation;
            this->raceNumber = raceNumber;

            sold = true;
        }
        return sold;
    }

    void Ticket::cancelTicket()
    {
        if (arriveDate != NULL)
            delete arriveDate;
        if (departDate != NULL)
            delete departDate;

        control = false;
        arriveDate = new Date();
        departDate = new Date();
        departStation = "";
        arriveStation = "";
        raceNumber = 0;
        passanger = "";

        sold = false;
    }

    int Ticket::getNumber() { return number; }
    bool Ticket::isControled() { return control; }
    Date Ticket::getArriveDate() { return *arriveDate; }
    Date Ticket::getDepartDate() { return *departDate; }
    string Ticket::getDepartStation() { return departStation; }
    string Ticket::getArriveStatiob() { return arriveStation; }
    int Ticket::getRaceNumber() { return raceNumber; }

    void Ticket::setDepartStation(string departStation) { this->departStation = departStation; }
    void Ticket::setArriveStation(string arriveStation) { this->arriveStation = arriveStation; }
    void Ticket::setRaceNumber(int raceNumber) { this->raceNumber = raceNumber; }

    string Ticket::toString()
    {
        string res = "Number: " + to_string(number) +
            "\nControlled: " + (control ? "+" : "-") +
            "\nDepart station: " + departStation +
            "\nDepart date: " + departDate->toString() +
            "\nArrive station: " + arriveStation +
            "\nArrive date: " + arriveDate->toString() +
            "\nRace number: " + to_string(raceNumber) + "\n";
        return res;
    }

    void Ticket::writeInFile(string fileName)
    {
        ofstream file(fileName);

        if (file.is_open())
        {
            file << toString();
            file.close();
        }
    }


ostream& operator<<(ostream& out, Ticket& ticket)
{
    out << ticket.toString();
    return out;
}

ofstream& operator<<(ofstream& out, Ticket& ticket)
{
    out << ticket.toString();
    return out;
}

istream& operator>>(istream& in, Ticket& ticket)
{
    cout << "Depart station > ";
    in >> ticket.departStation;

    cout << "Depart date:\n ";
    in >> *ticket.departDate;

    cout << "Arrive station > ";
    in >> ticket.arriveStation;

    cout << "Arrive date:\n";
    in >> *ticket.arriveDate;

    cout << "Race number:";
    in >> ticket.raceNumber;

    ticket.sold = true;

    return in;
}

ifstream& operator>>(ifstream& in, Ticket& ticket)
{
    in >> ticket.departStation >> *ticket.departDate >> ticket.arriveStation >> *ticket.arriveDate >> ticket.raceNumber;
    return in;
}

void sortByDate(Ticket** tickets, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (tickets[i]->getDepartDate() > tickets[j]->getDepartDate())
            {
                Ticket* buffer = tickets[i];
                tickets[i] = tickets[j];
                tickets[j] = buffer;
            }
        }
    }
}

void  printList(Ticket** tickets, int size)
{
    cout << "Tickets:\n";
    for (int i = 0; i < size; i++)
    {
        cout << i << ". " << *tickets[i] << endl;
    }
}
