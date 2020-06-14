#include "hotel.h"
using namespace std;

Hotel::Hotel()
{
    for (auto i : rooms)
    {
        i = Room();
    }
}

void Hotel::add(Room room)
{
    rooms.push_back(room);
}


void Hotel::checkin(int number, Date from, Date to, string note)
{
    for (auto i : rooms)
    {
        if(i.GetRoom() == number && i.is_free(i) && !(i.is_important(i)))
        {
            i.setFrom(from);
            i.setTo(to);
            i.setGuests(i.GetBeds());
            i.setNote(note);
            i.setFlag(false);
            cout<<i;
        } else cout<<"You can't check in this room!"<<endl;
    }
}
void Hotel::checkin(int number, Date from, Date to, string note, int guests)
{
    for (auto i : rooms)
    {
        if(i.GetRoom() == number && i.GetBeds() >= guests &&i.is_free(i) && !(i.is_important(i)))
        {
            i.setFrom(from);
            i.setTo(to);
            i.setGuests(guests);
            i.setNote(note);
            i.setFlag(false);
            cout<<i;
        } else cout<<"You can't check in this room!"<<endl;
    }
}

vector<Room> Hotel::availability(Date date)
{
    vector<Room> available;
    if (date == Date())
    {
        date.today_date();
    }

    for(auto i : rooms)
    {
        if ((i.getTo() >= date) && (date >= i.getFrom()))
        {
            if(i.is_free(i) && !(i.is_important(i)))
            {
                available.push_back(i);
            }
        }
    }
    for(auto i : available)
    {
        cout<<i<<endl;
    }
    return available;
}

void Hotel::checkout(int number)
{
    for (auto i : rooms)
    {
        if(i.GetRoom() == number)
        {
            i.setFlag(true);
        } else cout << "There is no such number"<<endl;
    }
}

vector<Room> Hotel::report(Date from, Date to)
{
    // for(auto i : rooms)
    // {
    //     if(((i.getFrom() >= from) && (to <= i.getTo())) || ((i.getFrom() <= from && to <=)
    // }
    return rooms;
}

Room Hotel::find (int bed, Date from, Date to)
{
    for(auto i : rooms)
    {

    }
}

bool Hotel::isFree(int number)
{
    for(auto i : rooms)
    {
        if(number == i.GetRoom())
        {
            return i.is_free(i);
        } 
        else
        {
            cout<<"There isn't such room"<<endl;
            return false;
        }   
    }
    return false;
}

//Room find!()

Room Hotel::unavailable(int number, Date from, Date to, string note)
{
    for(auto i : rooms)
    {
        if(number == i.GetRoom())
        {
            i.setFrom(from);
            i.setTo(to);
            i.setFlag(false);
            i.setNote(note);
            i.setImportant(true);
        }

    }
}
