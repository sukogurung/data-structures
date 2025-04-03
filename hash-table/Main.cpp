// Author: Suko Gurung (suko@pdx.edu)
// Course: Data-Structures
// This is a client program for the end user.
#include "HashTable.h"
#include <fstream>
#include <cstring>

using namespace std;

int open_and_load_file(HashTable &ht) {
    cout << "Loading File" << endl;
    ifstream inputfile_in;
    inputfile_in.open("Survey-2024.txt");
    if (inputfile_in) 
    {
        int i = 0;
        JobEntry entry;
        char buffer[256];
        string line;
        
        // Skip header line
        getline(inputfile_in, line);
        
        // Read each data line
        while (getline(inputfile_in, line) && i < 143) {
            int response_id = 0, age = 0, years = 0;
            char job[256], mode[256], education[256], learnt_where[256];
            char dev_type[256], country[256], languages[256];
            char platform[256], personal_OS[256], work_OS[256];
            
            // Manual parsing of pipe-delimited data
            size_t pos = 0;
            size_t prev_pos = 0;
            int field_count = 0;
            
            while ((pos = line.find('|', prev_pos)) != string::npos) {
                string field = line.substr(prev_pos, pos - prev_pos);
                
                // Process each field based on its position
                switch (field_count) {
                    case 0: // ResponseID
                        response_id = atoi(field.c_str());
                        break;
                    case 1: // Current Job
                        strncpy(job, field.c_str(), 255);
                        job[255] = '\0';
                        break;
                    case 2: // Age
                        // Simplified age conversion - you might need more logic
                        if (field.find("Under 18") != string::npos) age = 17;
                        else if (field.find("18-24") != string::npos) age = 21;
                        else if (field.find("25-34") != string::npos) age = 30;
                        else if (field.find("35-44") != string::npos) age = 40;
                        else if (field.find("45-54") != string::npos) age = 50;
                        else age = 0;
                        break;
                    case 3: // Mode
                        strncpy(mode, field.c_str(), 255);
                        mode[255] = '\0';
                        break;
                    case 4: // Education
                        strncpy(education, field.c_str(), 255);
                        education[255] = '\0';
                        break;
                    case 5: // LearnCode
                        strncpy(learnt_where, field.c_str(), 255);
                        learnt_where[255] = '\0';
                        break;
                    case 6: // YearsCode
                        if (field != "NA") years = atoi(field.c_str());
                        break;
                    case 7: // DevType
                        strncpy(dev_type, field.c_str(), 255);
                        dev_type[255] = '\0';
                        break;
                    case 8: // Country
                        strncpy(country, field.c_str(), 255);
                        country[255] = '\0';
                        break;
                    case 9: // Languages
                        strncpy(languages, field.c_str(), 255);
                        languages[255] = '\0';
                        break;
                    case 10: // Platform
                        strncpy(platform, field.c_str(), 255);
                        platform[255] = '\0';
                        break;
                    case 11: // Personal OS
                        strncpy(personal_OS, field.c_str(), 255);
                        personal_OS[255] = '\0';
                        break;
                }
                prev_pos = pos + 1;
                field_count++;
            }
            
            // Last field (Work OS)
            string field = line.substr(prev_pos);
            strncpy(work_OS, field.c_str(), 255);
            work_OS[255] = '\0';
            
            // Create and insert entry
            entry.create_entry(response_id, job, age, mode, education, 
                              learnt_where, years, dev_type, country, 
                              languages, platform, personal_OS, work_OS);
            
            sprintf(buffer, "%d", response_id);
            ht.insert(buffer, entry, 1);
            
            i++;
        }
        cout << "Successfully loaded " << i << " entries." << endl;
        return 1;
    }
    cout << "Failed to open file." << endl;
    return 0;
}

int display_menu() {
    cout << "\n===== Devlopers Survey Data Menu =====\n";
    cout << "1. Insert an entry.\n";
    cout << "2. Display all Entries.\n";
    cout << "3. Display by specific id.\n";
    cout << "4. Retrieve by specific id.\n";
    cout << "5. Remove entry by id.\n";
    cout << "6. Display entries by programming languages.\n";
    cout << "7. Load data into the Table.\n";
    cout << "8. Exit.\n";
    return 1;
}

void insert_entry(HashTable &ht) {
    JobEntry entry;
    char key_value[256];
    int choice;
    
    // Get required data for a new entry
    int response_id, age, years;
    char job[256], mode[256], education[256], learnt_where[256];
    char dev_type[256], country[256], languages[256];
    char platform[256], personal_OS[256], work_OS[256];
    
    cout << "Enter ResponseID: ";
    cin >> response_id;
    
    cout << "Enter current job: ";
    cin.ignore();
    cin.getline(job, 256);
    
    cout << "Enter age: ";
    cin >> age;
    
    cout << "Enter mode (Remote/Hybrid/In-office): ";
    cin.ignore();
    cin.getline(mode, 256);
    
    cout << "Enter education level: ";
    cin.getline(education, 256);
    
    cout << "Enter where you learned programming: ";
    cin.getline(learnt_where, 256);
    
    cout << "Enter years of experience: ";
    cin >> years;
    
    cout << "Enter type of developer: ";
    cin.ignore();
    cin.getline(dev_type, 256);
    
    cout << "Enter country: ";
    cin.getline(country, 256);
    
    cout << "Enter programming languages (comma separated): ";
    cin.getline(languages, 256);
    
    cout << "Enter platform: ";
    cin.getline(platform, 256);
    
    cout << "Enter personal OS: ";
    cin.getline(personal_OS, 256);
    
    cout << "Enter work OS: ";
    cin.getline(work_OS, 256);
    
    // Create the entry
    entry.create_entry(response_id, job, age, mode, education, 
                      learnt_where, years, dev_type, country, 
                      languages, platform, personal_OS, work_OS);
    
    cout << "Enter choice (1 for key_id, 2 for job title as key): ";
    cin >> choice;
    
    if (choice == 1) {
        sprintf(key_value, "%d", response_id);
    } else {
        strcpy(key_value, job);
    }
    
    if (ht.insert(key_value, entry, choice)) {
        cout << "Entry inserted successfully." << endl;
    } else {
        cout << "Failed to insert entry." << endl;
    }
}

int main() {
    int size = 100;
    HashTable my_ht(size);
    int choice;

    do {
        display_menu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insert_entry(my_ht);
                break;
            case 2:
                my_ht.display_all();
                break;
            case 3: {
                int id;
                cout << "Enter id: ";
                cin >> id;
                my_ht.display_by_id(id);
                break;
            }
            case 4: {
                char title[256];
                JobEntry found;
                cout << "Enter job title: ";
                cin.ignore();
                cin.getline(title, 256);
                if (my_ht.retrieve(title, found)) {
                    cout << "Entry found:" << endl;
                    found.display();
                } else {
                    cout << "Entry not found.\n";
                }
                break;
            }
            case 5: {
                int id;
                cout << "Enter id: ";
                cin >> id;
                if (my_ht.remove_by_id(id)) {
                    cout << "Entry removed.\n";
                } else {
                    cout << "Entry not found.\n";
                }
                break;
            }
            case 6: {
                char languages[256];
                cout << "Enter programming languages to search for: ";
                cin.ignore();
                cin.getline(languages, 256);
                my_ht.display_by_languages(languages);
                break;
            }

            case 7: {
                open_and_load_file(my_ht);
                break;
            }

            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 8);

    return 0;
}
