#include "list.h"
#include <iostream>
// Author: Suko Gurung
// Course: Data Structures
// Program #1
// This is an implementation file that will be providing an ADT for a linked list. 

CS_Gifts_list::CS_Gifts_list() : head(nullptr), tail(nullptr) {}

CS_Gifts_list::~CS_Gifts_list() {
    Recipient_Node* current = head;
    while (current) {
        Recipient_Node* next = current->next;
        Gift_Node* gift_current = current->gift_head;
        while (gift_current) {
            Gift_Node* gift_next = gift_current->next;
            delete gift_current;
            gift_current = gift_next;
        }
        delete current;
        current = next;
    }
}

int CS_Gifts_list::add_recipient(const Recipient& to_add) {
    Recipient_Node* new_node = new Recipient_Node;
    strncpy(new_node->data.person_name, to_add.person_name, MAX_CHAR);
    new_node->data.age = to_add.age;
    new_node->next = nullptr;
    new_node->gift_head = nullptr;
    if (!head) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
    return 1;
}

int CS_Gifts_list::display_all_recipients() const {
    Recipient_Node* current = head;
    while (current) {
        std::cout << "Recipient: " << current->data.person_name << ", Age: " << current->data.age << std::endl;
        current = current->next;
    }
    return 1;
}

int CS_Gifts_list::add_gift(const char* recipient_name, const Gift& to_add) {
    Recipient_Node* current = head;
    while (current) {
        if (strcmp(current->data.person_name, recipient_name) == 0) {
            Gift_Node* new_gift = new Gift_Node;
            strncpy(new_gift->data.gift_name, to_add.gift_name, MAX_CHAR);
            strncpy(new_gift->data.desc, to_add.desc, MAX_CHAR);
            new_gift->data.date = to_add.date;
            new_gift->data.weight = to_add.weight;
            new_gift->next = current->gift_head;
            current->gift_head = new_gift;
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int CS_Gifts_list::display_gifts_by_recipient(const char* recipient_name) const {
    Recipient_Node* current = head;
    while (current) {
        if (strcmp(current->data.person_name, recipient_name) == 0) {
            Gift_Node* gift_current = current->gift_head;
            while (gift_current) {
                std::cout << "Gift: " << gift_current->data.gift_name << ", Description: " << gift_current->data.desc << ", Date: " << gift_current->data.date << ", Weight: " << gift_current->data.weight << std::endl;
                gift_current = gift_current->next;
            }
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int CS_Gifts_list::display_gifts_by_date(int matching_date) const {
    Recipient_Node* current = head;
    while (current) {
        Gift_Node* gift_current = current->gift_head;
        while (gift_current) {
            if (gift_current->data.date == matching_date) {
                std::cout << "Gift: " << gift_current->data.gift_name <<
                ", Description: " << gift_current->data.desc <<
                " Date: " << gift_current->data.date << 
                " Weight: " << gift_current->data.weight << std::endl;
            }
            gift_current = gift_current->next;
        }
        current = current->next;
    }
    return 1;
}

int CS_Gifts_list::remove_gifts_by_recipient(const char* recipient_name) {
    Recipient_Node* current = head;
    while (current) {
        if (strcmp(current->data.person_name, recipient_name) == 0) {
            Gift_Node* gift_current = current->gift_head;
            while (gift_current) {
                Gift_Node* gift_next = gift_current->next;
                delete gift_current;
                gift_current = gift_next;
            }
            current->gift_head = nullptr;
            return 1;
        }
        current = current->next;
    }
    return 0;
}
