# Gift Tracker Application

## Project Overview
Enough gifting the same gifts to your families and friends. The Gift Tracker Application is a C++ program that allows users to keep track of gifts given to various recipients. Users can add recipients, associate gifts with specific recipients, view all recipients, display gifts by recipient or date, and remove all gifts for a recipient.

## Data Structures Used

### Nested Linked Lists
This project implements a **nested linked list** structure:
- The primary linked list tracks **recipients**
- Each recipient node contains a secondary linked list of **gifts**

```
Recipient1 → Recipient2 → Recipient3 → null
   ↓            ↓            ↓
 Gift1        Gift1        Gift1
   ↓            ↓            ↓
 Gift2        Gift2        null
   ↓            ↓
 Gift3        null
   ↓
  null
```

## Key Features

1. **Recipient Management**
   - Add new recipients with name and age
   - Display all recipients in the system

2. **Gift Management**
   - Add gifts to specific recipients
   - Each gift includes name, description, date, and weight

3. **Search and Display**
   - View all gifts for a particular recipient
   - View all gifts given on a specific date

4. **Deletion**
   - Remove all gifts associated with a specific recipient

## Implementation Details

The project is organized into three main files:

1. **list.h**: Defines the data structures and class interfaces
   - Structs for Gift, Gift_Node, Recipient, and Recipient_Node
   - CS_Gifts_list class declaration with public and private members

2. **list.cpp**: Implements the CS_Gifts_list class methods
   - Constructor and destructor (with proper memory management)
   - Methods for adding, displaying, and removing data

3. **main.cpp**: Client program for user interaction
   - Menu-driven interface
   - Input handling and validation

## Usage

The application presents a menu-driven interface where users can:
1. Add a new recipient
2. Add a gift to a specific recipient
3. Display all recipients
4. Display all gifts for a particular recipient
5. Display all gifts given on a particular day
6. Remove all gifts for a recipient
7. Quit the application

