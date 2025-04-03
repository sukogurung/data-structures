
#include "HashTable.h"
#include <cstdlib> 
#include <cstring> 
#include <cstdio>  
// Author: Suko Gurung (suko@pdx.edu)
// Course: Data-Structures 
// This is an implementation file that will be providing a Table ADT for an array of linked lists as a data structure.

using namespace std;

HashTable::HashTable(int size) 
    : hash_table(new Node*[size]), hash_table_size(size) {
    for (int i = 0; i < size; ++i) {
        hash_table[i] = nullptr;
    }
}

HashTable::~HashTable() {
    for (int i = 0; i < hash_table_size; ++i) {
        Node* current = hash_table[i];
        while (current) {
            Node* to_delete = current;
            current = current->next;
            delete to_delete;
        }
    }
    delete[] hash_table;
}

int HashTable::hash_function_int(int key_id) {
    return key_id % hash_table_size;
}

int HashTable::hash_function_char(const char *key_value) {
    if (!key_value) return 0;
    
    int hash = 0;
    for (int i = 0; key_value[i] != '\0'; i++) {
        hash += key_value[i];
    }
    return hash % hash_table_size;
}

int HashTable::insert(const char* key_value, const JobEntry& to_add, int choice) {
    if (!key_value) return 0;
    int index;
    if (choice == 1) {
        index = hash_function_int(atoi(key_value));
    } else {
        index = hash_function_char(key_value);
    }
    
    Node* new_node = new Node;
    if (!new_node) return 0;
    new_node->next = nullptr;
    if (!new_node->entry.copy_entry(to_add)) {
        delete new_node;
        return 0;
    }
    
    new_node->next = hash_table[index];
    hash_table[index] = new_node;
    
    return 1;
}

int HashTable::retrieve(const char* title_to_find, JobEntry& found) {
    if (!title_to_find) return 0;
    
    int index = hash_function_char(title_to_find);
    Node* current = hash_table[index];
    
    while (current) {
        if (current->entry.retrieve(const_cast<char*>(title_to_find), found)) {
            return 1; 
        }
        current = current->next;
    }
    
    for (int i = 0; i < hash_table_size; ++i) {
        if (i == index) continue; 
        
        current = hash_table[i];
        while (current) {
            if (current->entry.retrieve(const_cast<char*>(title_to_find), found)) {
                return 1; 
            }
            current = current->next;
        }
    }
    return 0; 
}

int HashTable::remove_by_id(int specific_id) {
    char id_str[32];
    sprintf(id_str, "%d", specific_id);
    
    int index = hash_function_int(specific_id); 
    Node* current = hash_table[index];
    Node* previous = nullptr;
    
    while (current) {
        JobEntry temp;
        
        if (current->entry.retrieve(id_str, temp)) {
            
            if (previous) {
                previous->next = current->next;
            } else {
                hash_table[index] = current->next;
            }
            delete current;
            return 1; 
        }
        
        previous = current;
        current = current->next;
    }
    return 0;
}

int HashTable::display_all() {
    int entries_found = 0;
    
    for (int i = 0; i < hash_table_size; ++i) {
        Node* current = hash_table[i];
        if (current != nullptr) {
            cout << "\n----- Index " << i << " -----" << endl;
            while (current) {
                if (current->entry.display()) {
                    entries_found++;
                } else {
                    cout << "Error displaying entry at index " << i << endl;
                }
                current = current->next;
            }
        }
    }
    
    if (entries_found == 0) {
        cout << "No entries found in the hash table." << endl;
        return 0;
    }
    
    cout << "\nTotal entries displayed: " << entries_found << endl;
    return 1;
}

int HashTable::display_by_id(int matching_id) {
    // Convert ID to string for comparison
    char id_str[32];
    sprintf(id_str, "%d", matching_id);
    
    int entries_found = 0;
    
    // Optimization: only search the specific bucket for this ID
    int index = hash_function_int(matching_id);
    Node* current = hash_table[index];
    
    while (current) {
        // Create temp entry for comparison
        JobEntry temp;
        
        // Use retrieve to see if this entry matches
        if (current->entry.retrieve(id_str, temp)) {
            cout << "\nFound matching entry at index " << index << ":" << endl;
            if (current->entry.display()) {
                entries_found++;
            } else {
                cout << "Error displaying entry with ID: " << matching_id << endl;
            }
        }
        
        current = current->next;
    }
    
    if (entries_found == 0) {
        cout << "No entries found with ID: " << matching_id << endl;
        return 0;
    }
    
    cout << "\nTotal entries found: " << entries_found << endl;
    return 1;
}

int HashTable::display_by_languages(const char* matching_programming_languages) {
    if (!matching_programming_languages) {
        cout << "Invalid search term (null pointer)." << endl;
        return 0;
    }
    
    int entries_found = 0;
    
    cout << "\nSearching for entries containing language: " << matching_programming_languages << endl;
    
    // We need to search all buckets
    for (int i = 0; i < hash_table_size; ++i) {
        Node* current = hash_table[i];
        while (current) {
            // Use JobEntry's match_languages method to check for matches
            if (current->entry.match_languages(matching_programming_languages)) {
                cout << "\nFound matching entry at index " << i << ":" << endl;
                if (current->entry.display()) {
                    entries_found++;
                } else {
                    cout << "Error displaying entry" << endl;
                }
            }
            
            current = current->next;
        }
    }
    
    if (entries_found == 0) {
        cout << "No entries found with programming language: " << matching_programming_languages << endl;
        return 0;
    }
    
    cout << "\nTotal entries found: " << entries_found << endl;
    return 1;
}