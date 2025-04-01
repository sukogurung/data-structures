#include <iostream>
#include <cstring>
#include "list.h"
// Author: Suko Gurung (suko@pdx.edu)
// Course: CS163-001
// This is the main program as known as client program where user gets to interect.
using namespace std;
void display_menu() {
    cout << "\n--- Gift Tracker App ---\n";
    cout << "\n--- Menu ---\n";
    cout << "1. Add a new Recipient\n";
    cout << "2. Add a gift to a specific recipient\n";
    cout << "3. Display all recipients\n";
    cout << "4. Display all gifts for a particular recipient\n";
    cout << "5. Display all gifts given on a particular day\n";
    cout << "6. Remove all gifts for a recipient\n";
    cout << "7. Quit\n";
    cout << "\nEnter your choice: ";
}

int main() {
    CS_Gifts_list my_giftList;

    int choice;
    char name[MAX_CHAR];
    char giftDesc[MAX_CHAR];
    int date;
    float weight;

    do {
        display_menu();
        cin >> choice;
        cin.ignore(); // Ignore the newline character

        switch (choice) {
            case 1: {
                Recipient newRec;
                cout << "Enter recipient name: ";
                cin.getline(newRec.person_name, MAX_CHAR);
                cout << "Enter recipient age: ";
                cin >> newRec.age;
                cin.ignore(); 
                my_giftList.add_recipient(newRec);
                break;
            }
            case 2: {
                Gift newGift;
                cout << "Enter recipient name: ";
                cin.getline(name, MAX_CHAR);
                cout << "Enter gift name: ";
                cin.getline(newGift.gift_name, MAX_CHAR);
                cout << "Enter gift description: ";
                cin.getline(newGift.desc, MAX_CHAR);
                cout << "Enter gift date: ";
                cin >> newGift.date;
                cout << "Enter gift weight: ";
                cin >> newGift.weight;
                cin.ignore(); 
                my_giftList.add_gift(name, newGift);
                break;
            }
            case 3:
                cout << "All Recipients:\n";
                my_giftList.display_all_recipients();
                break;
            case 4:
                cout << "Enter recipient name: ";
                cin.getline(name, MAX_CHAR);
                my_giftList.display_gifts_by_recipient(name);
                break;
            case 5:
                cout << "Enter gift date: ";
                cin >> date;
                cin.ignore(); 
                my_giftList.display_gifts_by_date(date);
                break;
            case 6:
                cout << "Enter recipient name: ";
                cin.getline(name, MAX_CHAR);
                my_giftList.remove_gifts_by_recipient(name);
                break;
            case 7:
                cout << "Exiting the program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 7);
    return 0;
}
