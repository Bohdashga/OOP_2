#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "Date.h"
#include "Ticket.h"

using namespace std;

int main()
{
    srand(time(NULL));

    Ticket** tickets;
    int size;

    cout << "List size > ";
    cin >> size;

    tickets = new Ticket * [size];
    for (int i = 0; i < size; i++)
    {
        tickets[i] = new Ticket();
    }

    cout << "Filling:\n";
    for (int i = 0; i < size; i++)
    {
        cout << endl << i << ". ";
        cin >> *tickets[i];
    }

    cout << endl << endl;

    printList(tickets, size);

    sortByDate(tickets, size);

    cout << endl << endl << "Sorted list:\n\n";
    printList(tickets, size);

    cout << endl << endl;

    string fileName;

    cout << "File name > ";
    cin >> fileName;

    ofstream file(fileName);
    file << "Tickets:\n";
    for (int i = 0; i < size; i++)
    {
        file << i << ". " << *tickets[i] << endl;
    }

    return 0;
}

