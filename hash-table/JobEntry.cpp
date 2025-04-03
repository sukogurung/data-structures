#include "JobEntry.h"
#include <iostream>
#include <cstring>
// Author: Suko Gurung (suko@pdx.edu)
// Course: Data-Strcuture
// This is a implementation file that will be providing Job Entry for the Table ADT for a array of linkedlist as data structure.

using namespace std;

JobEntry::JobEntry()
{
    response_id = 0;
    current_job = nullptr;
    age = 0;
    mode = nullptr;
    education = nullptr;
    learnt_where = nullptr;
    num_of_years = 0;
    type_of_dev = nullptr;
    country = nullptr;
    list_of_languages = nullptr;
    platform = nullptr;
    personal_OS = nullptr;
    work_OS = nullptr;
}

JobEntry::~JobEntry()
{
    if (current_job)
        delete [] current_job;
    if (mode)
        delete [] mode;
    if (education)
        delete [] education;
    if (learnt_where)
        delete [] learnt_where;
    if (type_of_dev)
        delete [] type_of_dev;
    if (country)
        delete [] country;
    if (list_of_languages)
        delete [] list_of_languages;
    if (platform)
        delete [] platform;
    if (personal_OS)
        delete [] personal_OS;
    if (work_OS)
        delete [] work_OS;
}

int JobEntry::create_entry(const int resp_id, char * job, int a, char * m, 
                     char * edu, char * learned, int years, 
                     char * dev_type, char * ctry, char * languages, 
                     char * platf, char * pers_OS, char * work_os)
{
    // Clean up any existing data
    if (current_job)
        delete [] current_job;
    if (mode)
        delete [] mode;
    if (education)
        delete [] education;
    if (learnt_where)
        delete [] learnt_where;
    if (type_of_dev)
        delete [] type_of_dev;
    if (country)
        delete [] country;
    if (list_of_languages)
        delete [] list_of_languages;
    if (platform)
        delete [] platform;
    if (personal_OS)
        delete [] personal_OS;
    if (work_OS)
        delete [] work_OS;
    
    // Set integer values
    response_id = resp_id;
    age = a;
    num_of_years = years;
    
    // Allocate and copy string values
    if (job && strlen(job) > 0) {
        current_job = new char[strlen(job) + 1];
        strcpy(current_job, job);
    } else {
        current_job = nullptr;
    }
    
    if (m && strlen(m) > 0) {
        mode = new char[strlen(m) + 1];
        strcpy(mode, m);
    } else {
        mode = nullptr;
    }
    
    if (edu && strlen(edu) > 0) {
        education = new char[strlen(edu) + 1];
        strcpy(education, edu);
    } else {
        education = nullptr;
    }
    
    if (learned && strlen(learned) > 0) {
        learnt_where = new char[strlen(learned) + 1];
        strcpy(learnt_where, learned);
    } else {
        learnt_where = nullptr;
    }
    
    if (dev_type && strlen(dev_type) > 0) {
        type_of_dev = new char[strlen(dev_type) + 1];
        strcpy(type_of_dev, dev_type);
    } else {
        type_of_dev = nullptr;
    }
    
    if (ctry && strlen(ctry) > 0) {
        country = new char[strlen(ctry) + 1];
        strcpy(country, ctry);
    } else {
        country = nullptr;
    }
    
    if (languages && strlen(languages) > 0) {
        list_of_languages = new char[strlen(languages) + 1];
        strcpy(list_of_languages, languages);
    } else {
        list_of_languages = nullptr;
    }
    
    if (platf && strlen(platf) > 0) {
        platform = new char[strlen(platf) + 1];
        strcpy(platform, platf);
    } else {
        platform = nullptr;
    }
    
    if (pers_OS && strlen(pers_OS) > 0) {
        personal_OS = new char[strlen(pers_OS) + 1];
        strcpy(personal_OS, pers_OS);
    } else {
        personal_OS = nullptr;
    }
    
    if (work_os && strlen(work_os) > 0) {
        work_OS = new char[strlen(work_os) + 1];
        strcpy(work_OS, work_os);
    } else {
        work_OS = nullptr;
    }
    
    return 1; // Success
}

int JobEntry::display(void)
{
    if (!current_job)
        return 0; 
    
    cout << "\n===== Job Entry Details =====" << endl;
    cout << "Response ID: " << response_id << endl;
    cout << "Current Job: " << (current_job ? current_job : "N/A") << endl;
    cout << "Age: " << age << endl;
    cout << "Mode: " << (mode ? mode : "N/A") << endl;
    cout << "Education: " << (education ? education : "N/A") << endl;
    cout << "Learned programming from: " << (learnt_where ? learnt_where : "N/A") << endl;
    cout << "Years of experience: " << num_of_years << endl;
    cout << "Type of developer: " << (type_of_dev ? type_of_dev : "N/A") << endl;
    cout << "Country: " << (country ? country : "N/A") << endl;
    cout << "Programming languages: " << (list_of_languages ? list_of_languages : "N/A") << endl;
    cout << "Platform: " << (platform ? platform : "N/A") << endl;
    cout << "Personal OS: " << (personal_OS ? personal_OS : "N/A") << endl;
    cout << "Work OS: " << (work_OS ? work_OS : "N/A") << endl;
    
    return 1;
}

int JobEntry::copy_entry(const JobEntry & copy_from)
{
    // Clean up existing data (just like in create_entry)
    if (current_job)
        delete [] current_job;
    if (mode)
        delete [] mode;
    if (education)
        delete [] education;
    if (learnt_where)
        delete [] learnt_where;
    if (type_of_dev)
        delete [] type_of_dev;
    if (country)
        delete [] country;
    if (list_of_languages)
        delete [] list_of_languages;
    if (platform)
        delete [] platform;
    if (personal_OS)
        delete [] personal_OS;
    if (work_OS)
        delete [] work_OS;
    
    response_id = copy_from.response_id;
    age = copy_from.age;
    num_of_years = copy_from.num_of_years;
    
    // Copy string values (with proper memory allocation)
    if (copy_from.current_job) {
        current_job = new char[strlen(copy_from.current_job) + 1];
        strcpy(current_job, copy_from.current_job);
    } else {
        current_job = nullptr;
    }
    
    if (copy_from.mode) {
        mode = new char[strlen(copy_from.mode) + 1];
        strcpy(mode, copy_from.mode);
    } else {
        mode = nullptr;
    }
    
    if (copy_from.education) {
        education = new char[strlen(copy_from.education) + 1];
        strcpy(education, copy_from.education);
    } else {
        education = nullptr;
    }
    
    if (copy_from.learnt_where) {
        learnt_where = new char[strlen(copy_from.learnt_where) + 1];
        strcpy(learnt_where, copy_from.learnt_where);
    } else {
        learnt_where = nullptr;
    }
    
    if (copy_from.type_of_dev) {
        type_of_dev = new char[strlen(copy_from.type_of_dev) + 1];
        strcpy(type_of_dev, copy_from.type_of_dev);
    } else {
        type_of_dev = nullptr;
    }
    
    if (copy_from.country) {
        country = new char[strlen(copy_from.country) + 1];
        strcpy(country, copy_from.country);
    } else {
        country = nullptr;
    }
    
    if (copy_from.list_of_languages) {
        list_of_languages = new char[strlen(copy_from.list_of_languages) + 1];
        strcpy(list_of_languages, copy_from.list_of_languages);
    } else {
        list_of_languages = nullptr;
    }
    
    if (copy_from.platform) {
        platform = new char[strlen(copy_from.platform) + 1];
        strcpy(platform, copy_from.platform);
    } else {
        platform = nullptr;
    }
    
    if (copy_from.personal_OS) {
        personal_OS = new char[strlen(copy_from.personal_OS) + 1];
        strcpy(personal_OS, copy_from.personal_OS);
    } else {
        personal_OS = nullptr;
    }
    
    if (copy_from.work_OS) {
        work_OS = new char[strlen(copy_from.work_OS) + 1];
        strcpy(work_OS, copy_from.work_OS);
    } else {
        work_OS = nullptr;
    }
    
    return 1; 
}


int JobEntry::retrieve(char * matching_title, JobEntry & found)
{
    
    if (!current_job || !matching_title)
        return 0;
    
   
    if (strcmp(current_job, matching_title) == 0) {
        found.copy_entry(*this);
        return 1; 
    }
    
    // Also check if the response_id (as a string) matches
    char id_str[32];
    sprintf(id_str, "%d", response_id);
    if (strcmp(id_str, matching_title) == 0) {
        found.copy_entry(*this);
        return 1; 
    }
    
    return 0; 
}


int JobEntry::match_languages(const char* languages_to_match)
{
    if (!list_of_languages || !languages_to_match) 
        return 0;
    
    return (strstr(list_of_languages, languages_to_match) != nullptr);
}