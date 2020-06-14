#pragma once
#include <iostream>
#include <vector>
#include "room.h"

using namespace std;

class Hotel
{

    private:
    vector <Room> rooms;

    public:
    Hotel();
    //Hotel(const Hotel &other);
    //Hotel& operator=;
    void add(Room room);
    
    void checkin(int number, Date from, Date to, string note);
    void checkin(int number, Date from, Date to, string note, int guests);
    
    vector<Room> availability(Date date);

    void checkout(int number);

    vector<Room> report(Date from, Date to);

    Room find (int bed, Date from, Date to);
    bool isFree(int number);
    //Room find!()

    Room unavailable(int number, Date from, Date to, string note);

    friend ostream& operator<< (ostream &out, const Hotel &hotel)
    {
        for (auto i : hotel.rooms)
        {
            out << i<< endl;
        }
        return out;
    }

};