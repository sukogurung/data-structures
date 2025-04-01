#include "StackQueue.h"
// Author: Suko Gurung (suko@pdx.edu)
// Course: Data Structures
// This is the main file that helps end-users to interact with the program 
using namespace std;

void display_menu() {
    cout << "\n--- Pop-Up Store Management ---\n";
    cout << "1. Add a new product to display (Push to Stack)\n";
    cout << "2. Sell a product (Pop from Stack and Enqueue to Queue)\n";
    cout << "3. Display all products on display (Stack)\n";
    cout << "4. Display all sold products (Queue)\n";
    cout << "5. Peek at the next product to be sold (Queue)\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Stack my_stack;
    Queue my_queue;
    int choice;

    do {
        display_menu();
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1: {
                // Add a new product to display (Push to Stack)
                Product new_product;
                new_product.name = new char[50];
                new_product.desc = new char[100];
                new_product.category = new char[50];

                cout << "Enter product name: ";
                cin.getline(new_product.name, 50);
                cout << "Enter product description: ";
                cin.getline(new_product.desc, 100);
                cout << "Enter product category: ";
                cin.getline(new_product.category, 50);
                cout << "Enter product expiry date (YYYYMMDD) Numerical value only: ";
                cin >> new_product.expiry_date;
                cout << "Enter product price($): ";
                cin >> new_product.price;
                cin.ignore(); 

                my_stack.push(new_product);
                break;
            }
            case 2: {
                // Sell a product (Pop from Stack and Enqueue to Queue)
                Product sold_product;
                if (my_stack.pop(sold_product)) {
                    SoldProduct sold;
                    sold.name = sold_product.name;
                    sold.desc = sold_product.desc;
                    sold.category = sold_product.category;
                    sold.expiry_date = sold_product.expiry_date;
                    sold.price = sold_product.price;

                    sold.purchaser = new char[50];
                    sold.date_sold = new char[10];
                    cout << "Enter purchaser name: ";
                    cin.getline(sold.purchaser, 50);
                    cout << "Enter date sold (YYYYMMDD): ";
                    cin.getline(sold.date_sold, 10);
                    cout << "Enter product rating: ";
                    cin >> sold.rating;
                    cin.ignore(); 

                    my_queue.enqueue(sold);
                } else {
                    cout << "No products available to sell.\n";
                }
                break;
            }
            case 3: {
                // Display all products on display (Stack)
                if (!my_stack.display_all()) {
                    cout << "No products on display.\n";
                }
                break;
            }
            case 4: {
                // Display all sold products (Queue)
                if (!my_queue.display_all_queue()) {
                    cout << "No products sold yet.\n";
                }
                break;
            }
            case 5: {
                // Peek at the next product to be sold (Queue)
                SoldProduct next_product;
                if (my_queue.peek(next_product)) {
                    cout << "Next product to be sold:\n";
                    cout << "Product Name: " << next_product.name << endl;
                    cout << "Product Description: " << next_product.desc << endl;
                    cout << "Product Category: " << next_product.category << endl;
                    cout << "Product Expiry Date: " << next_product.expiry_date << endl;
                    cout << "Product Price: " << next_product.price << endl;
                    cout << "Purchaser: " << next_product.purchaser << endl;
                    cout << "Date Sold: " << next_product.date_sold << endl;
                    cout << "Rating: " << next_product.rating << endl;
                } else {
                    cout << "No products sold yet.\n";
                }
                break;
            }
            case 6:
                cout << "Exiting the program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}
