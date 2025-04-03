#include "JobEntry.h"
// Author: Suko Gurung (suko@pdx.edu)
// Course: Data-Structures
// This is a implementation file that will be providing a Table ADT for a array of linkedlist as data structure.
#ifndef HASHTABLE_H
#define HASHTABLE_H

struct Node {
    JobEntry entry;
    Node * next;
};

class HashTable {
public:
    HashTable(int size);
    ~HashTable();

    int insert(const char* key_value, const JobEntry& to_add, int choice);
    int retrieve(const char * title_to_find, JobEntry & found);
    int remove_by_id(int specific_id);
    int display_all();
    int display_by_id(int matching_id);
    int display_by_languages(const char * matching_programming_languages);
   
private:
    int hash_function_int(int key_id);
    int hash_function_char(const char *key_value);

    Node ** hash_table;
    int hash_table_size;
};

#endif //HASHTABLE_H