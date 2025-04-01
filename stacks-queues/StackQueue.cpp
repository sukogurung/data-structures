#include <iostream>
#include <cstring>
#include <cctype>
#include "StackQueue.h"
// Author: Suko Gurung (suko@pdx.edu)
// Course: Data Structures
// This is the header file that contains the design of the whole program.
// This file contains classes, ADT, and function prototypes for Stacks and Queues.

using namespace std;

Stack::Stack(void): head(nullptr), top_index(0) {}

Stack::~Stack() {
    StackNode *curr = head;
    while (curr) {
        StackNode *to_delete = curr;
        curr = curr->next;
        delete[] to_delete->products;
        delete to_delete;
    }
}

int Stack::display_all() const {
    StackNode *curr = head;
    while (curr) {
        for (int i = 0; i < MAX; ++i) {
            if (curr->products[i].name) {
                cout << "Product Name: " << curr->products[i].name << endl;
                cout << "Product Description: " << curr->products[i].desc << endl;
                cout << "Product Category: " << curr->products[i].category << endl;
                cout << "Product Expiry Date: " << curr->products[i].expiry_date << endl;
                cout << "Product Price: " << curr->products[i].price << endl;
            }
        }
        curr = curr->next;
    }
    return 1;
}

int Stack::push(const Product &to_add) {
    if (!head || top_index >= MAX) {
        StackNode *new_node = new StackNode();
        new_node->products = new Product[MAX];
        new_node->next = head;
        head = new_node;
        top_index = 0;
    }

    head->products[top_index].name = new char[strlen(to_add.name) + 1];
    strcpy(head->products[top_index].name, to_add.name);

    head->products[top_index].desc = new char[strlen(to_add.desc) + 1];
    strcpy(head->products[top_index].desc, to_add.desc);

    head->products[top_index].category = new char[strlen(to_add.category) + 1];
    strcpy(head->products[top_index].category, to_add.category);

    head->products[top_index].expiry_date = to_add.expiry_date;
    head->products[top_index].price = to_add.price;

    ++top_index; 

    return 1; 
}

int Stack::pop(Product &removed_item) {
    if (!head) {
        return 0;
    }

    --top_index;

    // Allocate memory for removed_item fields
    removed_item.name = new char[strlen(head->products[top_index].name) + 1];
    strcpy(removed_item.name, head->products[top_index].name);

    removed_item.desc = new char[strlen(head->products[top_index].desc) + 1];
    strcpy(removed_item.desc, head->products[top_index].desc);

    removed_item.category = new char[strlen(head->products[top_index].category) + 1];
    strcpy(removed_item.category, head->products[top_index].category);

    removed_item.expiry_date = head->products[top_index].expiry_date;
    removed_item.price = head->products[top_index].price;

    // Set the pointers in the stack to nullptr to avoid dangling pointers
    delete[] head->products[top_index].name;
    delete[] head->products[top_index].desc;
    delete[] head->products[top_index].category;

    // If the current node is empty, delete it and move to the next node
    if (top_index == 0) {
        StackNode *to_delete = head;
        head = head->next;
        delete[] to_delete->products;
        delete to_delete;
        top_index = MAX;
    }

    return 1;
}

int Stack::peek(Product &found_at_top) const {
    if (!head) {
        return 0;
    }

    // Allocate memory for found_at_top fields
    found_at_top.name = new char[strlen(head->products[top_index - 1].name) + 1];
    strcpy(found_at_top.name, head->products[top_index - 1].name);

    found_at_top.desc = new char[strlen(head->products[top_index - 1].desc) + 1];
    strcpy(found_at_top.desc, head->products[top_index - 1].desc);

    found_at_top.category = new char[strlen(head->products[top_index - 1].category) + 1];
    strcpy(found_at_top.category, head->products[top_index - 1].category);

    found_at_top.expiry_date = head->products[top_index - 1].expiry_date;
    found_at_top.price = head->products[top_index - 1].price;

    return 1;
}

Queue::Queue(void): rear(nullptr) {}

Queue::~Queue() {
    if (!rear) return;
    QueueNode *curr = rear->next;
    while (curr != rear) {
        QueueNode *to_delete = curr;
        curr = curr->next;
        delete[] to_delete->product.name;
        delete[] to_delete->product.desc;
        delete[] to_delete->product.category;
        delete[] to_delete->product.purchaser;
        delete[] to_delete->product.date_sold;
        delete to_delete;
    }
    delete[] rear->product.name;
    delete[] rear->product.desc;
    delete[] rear->product.category;
    delete[] rear->product.purchaser;
    delete[] rear->product.date_sold;
    delete rear;
}

int Queue::display_all_queue() const {
    if (!rear) {
        return 0;
    }

    QueueNode *curr = rear->next;
    do {
        cout << "Product Name: " << curr->product.name << endl;
        cout << "Product Description: " << curr->product.desc << endl;
        cout << "Product Category: " << curr->product.category << endl;
        cout << "Product Expiry Date: " << curr->product.expiry_date << endl;
        cout << "Product Price: " << curr->product.price << endl;
        cout << "Purchaser: " << curr->product.purchaser << endl;
        cout << "Date Sold: " << curr->product.date_sold << endl;
        cout << "Rating: " << curr->product.rating << endl;
        curr = curr->next;
    } while (curr != rear->next);

    return 1;
}

int Queue::enqueue(const SoldProduct &to_add) {
    QueueNode *new_node = new QueueNode();
    new_node->product.name = new char[strlen(to_add.name) + 1];
    strcpy(new_node->product.name, to_add.name);

    new_node->product.desc = new char[strlen(to_add.desc) + 1];
    strcpy(new_node->product.desc, to_add.desc);

    new_node->product.category = new char[strlen(to_add.category) + 1];
    strcpy(new_node->product.category, to_add.category);

    new_node->product.expiry_date = to_add.expiry_date;
    new_node->product.price = to_add.price;

    new_node->product.purchaser = new char[strlen(to_add.purchaser) + 1];
    strcpy(new_node->product.purchaser, to_add.purchaser);

    new_node->product.date_sold = new char[strlen(to_add.date_sold) + 1];
    strcpy(new_node->product.date_sold, to_add.date_sold);

    new_node->product.rating = to_add.rating;

    if (!rear) {
        rear = new_node;
        rear->next = rear;
    } else {
        new_node->next = rear->next;
        rear->next = new_node;
        rear = new_node;
    }

    return 1;
}

int Queue::dequeue() {
    if (!rear) {
        return 0;
    }

    QueueNode *front = rear->next;
    if (rear == front) {
        rear = nullptr;
    } else {
        rear->next = front->next;
    }

    delete[] front->product.name;
    delete[] front->product.desc;
    delete[] front->product.category;
    delete[] front->product.purchaser;
    delete[] front->product.date_sold;
    delete front;

    return 1;
}

int Queue::peek(SoldProduct &found_at_front) const {
    if (!rear) {
        return 0;
    }

    QueueNode *front = rear->next;
    found_at_front.name = new char[strlen(front->product.name) + 1];
    strcpy(found_at_front.name, front->product.name);

    found_at_front.desc = new char[strlen(front->product.desc) + 1];
    strcpy(found_at_front.desc, front->product.desc);

    found_at_front.category = new char[strlen(front->product.category) + 1];
    strcpy(found_at_front.category, front->product.category);

    found_at_front.expiry_date = front->product.expiry_date;
    found_at_front.price = front->product.price;

    found_at_front.purchaser = new char[strlen(front->product.purchaser) + 1];
    strcpy(found_at_front.purchaser, front->product.purchaser);

    found_at_front.date_sold = new char[strlen(front->product.date_sold) + 1];
    strcpy(found_at_front.date_sold, front->product.date_sold);

    found_at_front.rating = front->product.rating;

    return 1;
}
