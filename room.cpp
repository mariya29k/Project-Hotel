#include "room.h"

using namespace std;

int Room::lastNumber = 0;

Room::Room()
{
    this->number = 1;
    this->from = Date();
    this->to = Date();
    this->guests = 0;
    this->beds = 1;
    this->note = "default";
    this->free = true;
    this->important = false;

}

Room::Room(int beds)
{
    this->number = Room::lastNumber++;
    this->from = Date();
    this->to = Date();
    this->guests = beds;
    this->beds = beds;
    this->note = "default";
    this->free = true;
    this->important = false;
}
Room::Room(const Room &other)
{
    this->number = other.number;
    this->from = other.from;
    this->to = other.to;
    //this->guests = other.guests; it is not zaduljitelno so idk
    this->beds = other.beds;
    this->note = other.note;
    this->free = other.free;
    this->important = other.important;
}
Room& Room::operator=(const Room &other)
{
    if (this != &other)
    {
        this->number = other.number;
        this->from = other.from;
        this->to = other.to;
        //this->guests = other.guests;
        this->beds = other.beds;
        this->note = other.note;
        this->free = other.free;
        this->important = other.important;
    }
    return *this;
}

int Room::GetRoom() const
{
    return number;
}
int Room::GetBeds() const
{
    return beds;
}

void Room::setFlag(const bool &flag)
{
    this->free = flag;
}

bool Room::is_free(const Room &room)
{
    if(free) return true;
    else return false;
}

void Room::setImportant(const bool &important)
{
    this->important = important;
}

bool Room::is_important(const Room &room)
{
    if(important) return false;
    else return true;
}




void Room::setFrom(const Date &other)
{
    this->from = other;
}

void Room::setTo(const Date &other)
{
    this->to = other;
}

void Room::setGuests(const int &guest)
{
    if(guest != 0)
    {
        this->guests = guest;
    } else this->guests = this->beds;
}

void Room::setNote(const string &other)
{
    this->note = other;
}

Date Room::getTo() const
{
    return to;
}

Date Room::getFrom() const
{
    return from;
}

string Room::getNote() const
{
    return note;
}

Room::~Room()
{

}

ostream& operator<< (ostream &out, const Room& room)
{
    out<<"Room's number: "<<room.GetRoom()<<endl;
    out<<"Date from: "<<room.getFrom()<<endl;
    out<<"Date to: "<<room.getTo()<<endl;
    out<<"Beds in room: "<<room.GetBeds()<<endl;
    out<<"Note: "<<room.getNote()<<endl;
    return out;
}