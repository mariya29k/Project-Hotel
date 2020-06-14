#include "commands.h"
#include <string>

using namespace std;

Hotel hotel;
ofstream HotelFile;
ofstream NewHotelFile;


void Open ()
{
    //first we check whether the file is already opened
    if(HotelFile.is_open())
    {
        cout<<"File is already opened! "<<endl;
    } 
    else 
    {   
        cout<<"File is now opened! "<<endl;
        HotelFile.open("hotel.txt", ios::out);
    }
    
    //then we check for errors
    if (HotelFile.fail())
    {
        cout<<"Error opening file! "<<endl;
        exit(1); //we close the program exit(0) - successfully executed, exit(1) - closed because of fail
    }
  
}

void Close()
{
    if(HotelFile.is_open())
    { 
        HotelFile.close();
        cout<<"File is closed"<<endl;
    }
    else if(NewHotelFile.is_open())
    {
        NewHotelFile.close();
        cout<<"File is closed"<<endl;
    }
    else cout<<"There are no opened files!"<<endl;

}

bool is_saved = false;

void Save ()
{
    
    if (HotelFile.is_open())
    {
        HotelFile.open("hotel.txt", ios::trunc);
    } else HotelFile.open("hotel.txt", ios::out);

    if (HotelFile.fail())
    {
        cout<< "Error opening file! ";
        exit(1);
    } 
    else
    {
        HotelFile << hotel;
        cout<<"Info is safed! "<<endl;
        is_saved = true;
    }
        

}

void SaveAs ()
{
    
    if (NewHotelFile.is_open())
    {
        cout << "File is already opened!"<<endl;
        cout << "Do you want to overwrite it? Y/N"<<endl;
        char answer;
        cin>>answer;
        if (answer == 'y' || answer == 'Y')
        {
            NewHotelFile.open("newfile.txt", ios::trunc);
        } else  NewHotelFile.close();
    } else  NewHotelFile.open("newfile.txt", ios::out);

    if(NewHotelFile.fail())
    {
        cout<<"Error opening file! ";
        exit(1);
    }
    
    is_saved = true;
    NewHotelFile << hotel;
    cout<<"Info is saved in new file! "<<endl;
    NewHotelFile.close();

}



void help ()
{
    cout <<"---------------------------------------------------------------------------\n";
    cout <<"| 1.  Open <file>           opens the file                                 |\n"
         <<"| 2.  Close                 closes currently opened file                   |\n"
         <<"| 3.  save                  saves the currently open file                  |\n"
         <<"| 4.  save as <file>        saves the currently open file in a <file>      |\n"
         <<"| 5.  help                  prints this information                        |\n"
         <<"| 6.  exit                  exists the program                             |\n"
         <<"| 7.  checkin               register in a room                             |\n"
         <<"| 8.  availability          shows all the available rooms                  |\n"
         <<"| 9.  checkout              checkout from a room                           |\n"
         <<"| 10. report <from> <to>    shares all checkins made to a certain room     |\n"
         <<"| 11. find                  find a free room                               |\n"
         <<"| 10. unavailable           declares a room temporarily unavailable        |\n";
    cout <<"---------------------------------------------------------------------------\n";
}

void exit()
{
    if(is_saved == 0)
    {
        cout<<"File isn't saved! Do you want to save it? Y/N"<<endl;
        char answer;
        cin>>answer;
        if(answer == 'Y' || answer == 'y')
        {
            Save();
            cout<<"File is saved!"<<endl;
            cout<<"Bye! "<<endl;
            exit(0);
        } else exit(0);
    } else exit(0);
}

void checkin()
{  
    int number, guests;
    Date from, to;
    string note;
    cout<<"Which room do you want to check in to?"<<endl;
    cin>>number;
    hotel.isFree(number);
    cout<<"Enter date from: "<<endl;
    do
    {
        cin>>from;
    } while (!from.isValid());
    cout<<"Enter date to: "<<endl;
    do
    {
        cin>>to;
    } while (!to.isValid());
    cout<<"Enter a comment: "<<endl;
    cin.get();
    getline(cin,note);
    cout<<"Do you want to enter number of guests?"<<endl;
    char answer;
    cin>>answer;
    if(answer == 'Y' || answer == 'y')
    {
        cout<<"How many guests? "<<endl;
        cin>>guests;
        hotel.checkin(number,from,to, note, guests);
    } else hotel.checkin(number, from, to, note);
}

void availability()
{
    Date available;
    cout<<"For which date you want to check?"<<endl;
    do
    {
        cin>>available;
    } while (!available.isValid());
    hotel.availability(available);
}

void checkout()
{
    int number;
    cout<<"Enter the number of the room: "<<endl;    
    cin>>number;
    hotel.checkout(number);
}

void unavailable()
{
    int number;
    Date from, to;
    string note;
    cout<<"You are making a room unavailable!"<<endl;
    cout<<"Which room do you need? "<<endl;
    cin>>number;
    cout<<"Enter date from: "<<endl;
    do
    {
        cin>>from;
    } while (!from.isValid());
    cout<<"Enter date to: "<<endl;
    do
    {
        cin>>to;
    } while (!to.isValid());
    cout<<"Add a reason why"<<endl;
    cin.get();
    getline(cin,note);
    hotel.unavailable(number, from, to, note);
    
}