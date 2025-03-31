// Author: Suko Gurung (suko@pdx.edu)
// Course: CS163-001
// Date: 1/13/2025
 
// Program #1
// This is a header file that will be providing an ADT for a linked list 

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cstring>
#include <cctype>

#define MAX_CHAR 100
struct Gift {
    char gift_name[MAX_CHAR];
    char desc[MAX_CHAR];
    int date;
    float weight;
};

struct Gift_Node {
    Gift data;
    Gift_Node* next;
};

struct Recipient {
    char person_name[MAX_CHAR];
    int age;
};

struct Recipient_Node {
    Recipient data;
    Recipient_Node* next;
    Gift_Node* gift_head;
};

//List ADT
class CS_Gifts_list {
public:
    CS_Gifts_list();
    ~CS_Gifts_list();

    int add_recipient(const Recipient& to_add);
    int display_all_recipients() const;
    int add_gift(const char* recipient_name, const Gift& to_add);
    int display_gifts_by_recipient(const char* recipient_name) const;
    int display_gifts_by_date(int matching_date) const;
    int remove_gifts_by_recipient(const char* recipient_name);

private:
    Recipient_Node* head;
    Recipient_Node* tail;
};

#endif // LIST_H
