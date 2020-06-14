#pragma once
#include <iostream>
#include "date.h"
#include <cstring>

using namespace std;

class Room
{
    private:
    static int lastNumber;
    int number;
    Date from;
    Date to;
    int guests;
    int beds;
    string note;
    bool free;
    bool important;

    public:
    Room();
    Room(int);
    Room(const Room &other);
    Room& operator=(const Room &other);

    int GetRoom() const;
    int GetBeds() const;
    void setFlag(const bool &flag);
    bool is_free(const Room &room);
    void setImportant(const bool &important);
    bool is_important(const Room &room);

    void setFrom(const Date &other);
    void setTo(const Date &other);
    void setGuests(const int &guests);
    void setNote(const string &other);
    

    Date getTo() const;
    Date getFrom() const;
    string getNote () const;

    ~Room();

    friend ostream& operator<< (ostream &out, const Room& room);
};