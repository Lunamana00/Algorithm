//
//  SortedType.h
//  Lab05-2
//
//  Modified by Jeman Park on 2024/11/05.
//

#ifndef SORTEDTYPE_H
#define SORTEDTYPE_H

#include<iostream>
using namespace std;


template<class ItemType>
struct NodeType
{
    ItemType value;
    NodeType* next;
};

template <class ItemType>
class SortedType
{
public:
    SortedType();
    ~SortedType();
    bool isFull();
    bool isEmpty();
    int  size();
    bool findItem(ItemType& item);
    void insertItem(ItemType item);
    void removeItem(ItemType item);

    void clear();
    ItemType getItem(int pos);
    void printList();
    
private:
    NodeType<ItemType>* listData;
    int length;
};





template <class ItemType>
SortedType<ItemType>::SortedType()
{
    length = 0;
    listData = nullptr;
}


template <class ItemType>
SortedType<ItemType>::~SortedType()
{
    
    /* Implement the function here */
    // Deallocate all nodes in the queue.
    // Set the pointer (listData) and length properly.
    
    NodeType<ItemType>* tempPtr;
    while (listData != nullptr) {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
    
}

template <class ItemType>
void SortedType<ItemType>::clear()
{
    this -> ~SortedType();
}


template<class ItemType>
bool SortedType<ItemType>::isFull()
{
    NodeType<ItemType>* tempPtr;
    try
    {
        tempPtr = new NodeType<ItemType>;
        delete tempPtr;
        return false;
    }
    catch(std::bad_alloc exception)
    {
        return true;
    }
}

template<class ItemType>
bool SortedType<ItemType>::isEmpty()
{
    return (listData == nullptr);
}


template <class ItemType>
int SortedType<ItemType>::size()
{
    return length;
}


template <class ItemType>
bool SortedType<ItemType>::findItem(ItemType& item)
{
    NodeType<ItemType>* tempPtr;
    tempPtr = listData;
    
    
    while(tempPtr != nullptr){
        if((tempPtr->value) == item ){
            item = tempPtr -> value;
            return true;
        }
        else{
            tempPtr = tempPtr -> next;
        }
    }
    return false;
}


template <class ItemType>
void SortedType<ItemType>::insertItem(ItemType item)
{
    
    /* Implement the function here */
    // Insert the new item into the sorted list.
    // * Find the proper position
    // * Insert new item by creadting and linking a new node
    
    // Time Complexity: O( N )
    
    NodeType<ItemType>* newNode = new NodeType<ItemType>;
    newNode->value = item;
    newNode->next = nullptr;

    if (listData == nullptr || listData->value >= item) {
        newNode->next = listData;
        listData = newNode;
    }
    else {
        NodeType<ItemType>* tempPtr = listData;
        while (tempPtr->next != nullptr && tempPtr->next->value < item) {
            tempPtr = tempPtr->next;
        }
        newNode->next = tempPtr->next;
        tempPtr->next = newNode;
    }
    length++;

}


template <class ItemType>
void SortedType<ItemType>::removeItem(ItemType item)
{
    /* Implement the function here */
    // Delete the item from the sorted list.
    // * Find the item
    // * If "item" NOT exists in the list, do not anything (return)
    // * Delete the item from the list and maintain the list (linked structures) and "length" properly
    // * Deallocate the deleted node
    // * Handle edge cases properly
        
    
    // Time Complexity: O(  N  )
    if (listData == nullptr) {
        return;
    }

    if (listData->value == item) {
        NodeType<ItemType>* tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
        length--;
        return;
    }

    NodeType<ItemType>* prevPtr = listData;
    NodeType<ItemType>* tempPtr = listData->next;

    while (tempPtr != nullptr) {
        if (tempPtr->value == item) {
            prevPtr->next = tempPtr->next;
            delete tempPtr;
            length--;
            return;
        }
        prevPtr = tempPtr;
        tempPtr = tempPtr->next;
    }
    
}


template <class ItemType>
ItemType SortedType<ItemType>::getItem(int pos)
{
    
    /* Implement the function here */
    // Return the "pos"-th item in the list (array-like).
    // if "pos" is out of list, return -1
    // For example, if the list is [1, 3, 5, 7]
    // getItem(0) returns 1
    // getItem(2) returns 5
    // getItem(3) returns 7
    // getItem(4) returns -1 (length of list is 4 (0 ~ 3)
    
    if (pos < 0 || pos >= length) {
        return -1;
    }

    NodeType<ItemType>* tempPtr = listData;
    for (int i = 0; i < pos; i++) {
        tempPtr = tempPtr->next;
    }
    return tempPtr->value;
    
    
}



template <class ItemType>
void SortedType<ItemType>::printList(){
    NodeType<ItemType>* tempPtr = listData;
    
    std::cout << "[\t";
    while (tempPtr != NULL)
    {
        std::cout << tempPtr->value << "\t";
        tempPtr = tempPtr->next;
    }
    
    std::cout << "]" << std::endl;
    
}

#endif
