//
//  DoubleSortedType.h
//  Lab06
//
//  Modified by Jeman Park on 2024/11/12.
//

#ifndef DOUBLESORTEDTYPE_H
#define DOUBLESORTEDTYPE_H

#include<iostream>
using namespace std;


template<class ItemType>
struct NodeType
{
    ItemType value;
    NodeType* next;
    NodeType* back;
};

template <class ItemType>
class DoubleSortedType
{
public:
    DoubleSortedType();
    ~DoubleSortedType();
    bool isFull();
    bool isEmpty();
    int  size();
    bool findItem(ItemType& item);
    void insertItem(ItemType item);
    void removeItem(ItemType item);

    void clear();
    ItemType getItem(int pos);
    void printList();
    void printListRev();
    
private:
    NodeType<ItemType>* listData;
    int length;
};





template <class ItemType>
DoubleSortedType<ItemType>::DoubleSortedType()
{
    length = 0;
    listData = nullptr;
}


template <class ItemType>
DoubleSortedType<ItemType>::~DoubleSortedType()
{
    
    NodeType<ItemType>* tempPtr;
    
    while (listData != nullptr)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    
}

template <class ItemType>
void DoubleSortedType<ItemType>::clear()
{
    this -> ~DoubleSortedType();
}


template<class ItemType>
bool DoubleSortedType<ItemType>::isFull()
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
bool DoubleSortedType<ItemType>::isEmpty()
{
    return (listData == nullptr);
}


template <class ItemType>
int DoubleSortedType<ItemType>::size()
{
    return length;
}


template <class ItemType>
bool DoubleSortedType<ItemType>::findItem(ItemType& item)
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
void DoubleSortedType<ItemType>::insertItem(ItemType item)
{
    
    /* Implement the function here */
    // Insert the new item into the double sorted linked list.
    // * Find the proper position
    // * Insert new item by creadting and linking a new node
    
    // Hint: Pay attention to the edge cases
    
    NodeType<ItemType>* newNode = new NodeType<ItemType>;
    newNode->value = item;
    newNode->next = nullptr;
    newNode->back = nullptr;

    if (listData == nullptr)
    {
        listData = newNode;
    }
    else
    {
        NodeType<ItemType>* current = listData;
        NodeType<ItemType>* previous = nullptr;

        while (current != nullptr && current->value < item)
        {
            previous = current;
            current = current->next;
        }

        if (previous == nullptr)
        {
            newNode->next = listData;
            listData->back = newNode;
            listData = newNode;
        }
        else if (current == nullptr)
        {
            previous->next = newNode;
            newNode->back = previous;
        }
        else
        {
            previous->next = newNode;
            newNode->back = previous;
            newNode->next = current;
            current->back = newNode;
        }
    }

    length++;
}


template <class ItemType>
void DoubleSortedType<ItemType>::removeItem(ItemType item)
{
    /* Implement the function here */
    // Delete the item from the doubly sorted linked list.
    // * Find the item
    // * If found, set "ret" to "item"
    // * If the item does not exist, return -1
    // * Delete the item from the list and maintain the list properly (both next and back)
    // * Deallocate the deleted node
    
    // Hint: Pay attention to the edge cases
    
    NodeType<ItemType>* current = listData;

    if (isEmpty())
        return;

    while (current != nullptr && current->value != item)
    {
        current = current->next;
    }

    if (current == nullptr)
        return;

    if (current->back == nullptr)
    {
        listData = current->next;
        if (listData != nullptr)
            listData->back = nullptr;
    }
    else if (current->next == nullptr)
    {
        current->back->next = nullptr;
    }    
    else
    {
        current->back->next = current->next;
        current->next->back = current->back;
    }

    delete current;

    length--;
}


template <class ItemType>
ItemType DoubleSortedType<ItemType>::getItem(int pos)
{
    NodeType<ItemType>* tempPtr = listData;
    for(int i=0; i < pos; i++){
        while(tempPtr != nullptr){
            tempPtr = tempPtr -> next;
        }
    }
    
    if(tempPtr != nullptr){
        return tempPtr -> value;
    }
    else{
        return -1;
    }
}



template <class ItemType>
void DoubleSortedType<ItemType>::printList(){
    NodeType<ItemType>* tempPtr = listData;
    
    cout << "[\t";
    while (tempPtr != NULL)
    {
        cout << tempPtr->value << "\t";
        tempPtr = tempPtr->next;
    }
    
    cout << "]" << std::endl;
    
}

template <class ItemType>
void DoubleSortedType<ItemType>::printListRev(){
    NodeType<ItemType>* tempPtr = listData;
    
    if(isEmpty()){
        cout << "[\t]" << endl;
        return;
    }
    
    while(tempPtr -> next != nullptr){
        tempPtr = tempPtr -> next;
    }
    
    
    cout << "[\t";
    while (tempPtr != nullptr)
    {
        cout << tempPtr -> value << "\t";
        tempPtr = tempPtr -> back;
    }
    
    cout << "]" << std::endl;
    
}

#endif
