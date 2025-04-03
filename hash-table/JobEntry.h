#include <iostream>
#include <cstring>
// Author: Suko Gurung (suko@pdx.edu)
// Course: Data-Structure
// This is a header file that will be providing Job Entry for theTable ADT for a array of linkedlist as data structure.

#ifndef JOBENTRY_H
#define JOBENTRY_H

class JobEntry {

    private:
        int response_id;
        char * current_job;
        int age;
        char * mode;
        char * education;
        char * learnt_where;
        int num_of_years;
        char * type_of_dev;
        char * country;
        char * list_of_languages;
        char * platform;
        char * personal_OS;
        char * work_OS;

    public:
        JobEntry();
        ~JobEntry();
        
        int create_entry(const int response_id, char * current_job, int age, char * mode, 
                         char * education, char * learnt_where, int num_of_years, 
                         char * type_of_dev, char * country, char * list_of_languages, 
                         char * platform, char * personal_OS, char * work_OS);
        int display();
        int copy_entry(const JobEntry & copy_from);
        int retrieve(char * matching_title, JobEntry & found);
        int match_languages(const char* languages_to_match);
};

#endif //JOBENTRY_H