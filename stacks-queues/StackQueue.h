
#include <iostream>
#include <cstring>
#include <cctype>
// Author: Suko Gurung (suko@pdx.edu)
// Course: Data Structures
// This is the implementation file that contains the implemenation of structures, and classes for stacks and queues
// declared in you header/design file.

const int MAX = 5;

struct Product {
    char *name;
    char *desc;
    char *category;   // Product category (e.g., Home Goods)
    int expiry_date;  
    int price;
    int copy_products(const Product &to_copy);    
};

struct SoldProduct {
    char *name;
    char *desc;
    char *category;   // Product category (e.g., Home Goods)
    int expiry_date;  
    int price;
    char *purchaser;  // Name of the purchaser (for queue)
    char *date_sold;  // Date sold (for queue)
    int rating;
};

struct StackNode {
    Product * products;  // Array of products
    StackNode *next;
};

struct QueueNode {
    SoldProduct product;
    QueueNode *next; 
};

class Stack {
public:
    Stack(void);
    ~Stack(void);
    int display_all(void) const;
    int push(const Product &to_add);
    int pop(Product & removed_item);
    int peek(Product &found_at_top) const;

private:
    StackNode *head;  
    int top_index;      // Index of the top element in the array
};

class Queue {
public:
    Queue(void);
    ~Queue(void);
    int display_all_queue(void) const;
    int enqueue(const SoldProduct &to_add);
    int dequeue();
    int peek(SoldProduct &found_at_front) const;

private:
    QueueNode *rear;  // Pointer to the rear of the queue
};
