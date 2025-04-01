## Project Overview
The Pop-Up Store Management System is a C++ application that helps manage inventory and sales for a temporary retail operation. The system tracks products available for display and maintains records of sold items using efficient data structures.

## Data Structures Used

### Stack Implementation
The project uses a **stack** to manage products on display:
- Implemented as a linked list of arrays
- Each node contains an array of products (efficient memory usage)
- LIFO (Last-In-First-Out) principle - newest products sell first

### Queue Implementation
A **circular queue** tracks products that have been sold:
- Implemented as a circular linked list
- Maintains sale history in order of purchase
- FIFO (First-In-First-Out) principle for sales records

```
Stack:                 Queue (Circular):
[Product Arrays]        
    ↓                    [Sold3] → [Sold1]
[Product Arrays]             ↑        ↓
    ↓                    [Sold2] ← [...]
   null
```

## Key Features

1. **Product Management**
   - Add new products to display (Push to Stack)
   - Products include name, description, category, expiration date, and price

2. **Sales Processing**
   - Sell products (Pop from Stack, Enqueue to Queue)
   - Record purchaser information and customer ratings

3. **Inventory Display**
   - View all products currently on display (Stack)
   - View complete sales history (Queue)

4. **Sales Analysis**
   - Preview next item in sales history

## Implementation Details

The project is organized into three main files:

1. **StackQueue.h**: Defines the data structures and class interfaces
   - Structs for Product, SoldProduct, StackNode, and QueueNode
   - Stack and Queue class declarations

2. **StackQueue.cpp**: Implements the Stack and Queue class methods
   - Memory management for dynamic allocation
   - Stack operations: push, pop, peek, display
   - Queue operations: enqueue, dequeue, peek, display

3. **Main.cpp**: Client program for user interaction
   - Menu-driven interface
   - Input handling and validation

## Usage

The application provides a menu where users can:
1. Add a new product to display (Push to Stack)
2. Sell a product (Pop from Stack and Enqueue to Queue)
3. Display all products on display (Stack)
4. Display all sold products (Queue)
5. Peek at the next product in the sales history (Queue)
6. Exit the application