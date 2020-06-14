#include <iostream>
#include <vector>
#include "hotel.h"
#include "room.h"
#include "commands.h"

using namespace std;

int main()
{
    Hotel hotel;
    Room first(4), second(3), third(3), fourth(4), fifth(5), sixth(2), seventh(1), eight(6), nine(4), ten(4);
    hotel.add(first);
    hotel.add(second);
    hotel.add(third);
    hotel.add(fourth);
    hotel.add(fifth);
    hotel.add(sixth);
    hotel.add(seventh);
    hotel.add(eight);
    hotel.add(nine);
    hotel.add(ten);
    cout<<hotel;
    
    

    int number;
    help();
    
    while (true)
    {
        cout << "Choose an option from the menu.. "<<endl;
        cin >> number;

        switch (number)
        {
            case 1:
                Open();
                break;
            case 2:
                Close();
                break;
            case 3:
                Save();
                break;
            case 4:
                SaveAs();
                break;
            case 5: 
                help();
                break;
            case 6:
            cout<<"Bye! ";
                exit();
                break;
            case 7:
                checkin();
                break;
            case 8:
                availability();
                break;
            case 9:
                checkout();
                break;
            case 10:
                //report();
                break;
            case 11:
                //find();
                break;
            case 12:
                unavailable();
                break;
            default: 
                cout << "Please enter a valid number"<<endl;
                break;
        }
    }

    return 0;
}