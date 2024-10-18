//
//  QueueType.h
//  Lab04
//
//  Modified by Jeman Park on 2024/10/13.
//


#ifndef QUEUETYPE_H
#define QUEUETYPE_H

#include <iostream>
using namespace std;

template <class ItemType>
struct NodeType{
    ItemType value;
    NodeType * next;
};

template <class ItemType>
class QueueType
{
    
private:
    NodeType<ItemType> * pFront;
    NodeType<ItemType> * pRear;
    
public:
    
    QueueType();
    ~QueueType();
    
    void clear();
    void enqueue(ItemType newItem);
    void dequeue(ItemType& value);

    int size() const;
    bool isFull() const;
    bool isEmpty() const;
    
    void Print();
    
};


template <class ItemType>
QueueType<ItemType>::QueueType()
{
    pFront = nullptr;
    pRear = nullptr;
}

template <class ItemType>
QueueType<ItemType>::~QueueType()
{
    /* Implement the function here */
    // This destructor function iteratively deletes all nodes in the queue.
    // All "NodeType" should be "deallocated" properly.
    // It returns nothing
    ItemType temp=-1;
    while (!isEmpty()) {
        dequeue(temp);
    }   
}

template <class ItemType>
void QueueType<ItemType>::clear()
{
    this -> ~QueueType();
}

template <class ItemType>
int QueueType<ItemType>::size() const
{
    /* Implement the function here */
    // This function counts the number of nodes in the queue and returns it.
    
    
    int len = 0;

    NodeType<ItemType>* tempPtr = pFront;

    while (tempPtr != nullptr) {
        len++;
        tempPtr = (*tempPtr).next;
    }

    
    return len;
}


template <class ItemType>
bool QueueType<ItemType>::isEmpty() const
{
    return (pFront == nullptr);
}

template <class ItemType>
bool QueueType<ItemType>::isFull() const
{
    NodeType<ItemType> * newNode;
    try {
        newNode = new NodeType<ItemType>;
        delete newNode;
        return false;
    }
    catch (std::bad_alloc exception){
        return true;
    }
}

template <class ItemType>
void QueueType<ItemType>::enqueue(ItemType newItem)
{
    /* Implement the function here */
    // This function enqueues "newItem" into the queue, and returns NOTHING.
    // If the queue is already full, do nothing.
    
    
    if (!isFull()) {

        NodeType<ItemType>* newnode = new NodeType<ItemType>;
        newnode->value = newItem;
        newnode->next = nullptr;


        if (isEmpty()) {
            pFront = newnode;
            pRear = newnode;
        }
        else {
            pRear->next = newnode;
            pRear = newnode;
        }
    }
}

template <class ItemType>
void QueueType<ItemType>::dequeue(ItemType& ret_value)
{
    
    /* Implement the function here */
    // This function dequeues the most front item in the queue, and returns it through "RETURN BY REFERENCE (ret_value).
    // You need to set "ret_value" as the dequeue item's value to return.
    // If the queue is empty, set "ret_value" as -1

    if (!(isEmpty())) {

        NodeType<ItemType>* tempPtr;
        tempPtr= pFront;
        ret_value = pFront->value;
        pFront = pFront->next;
        delete(tempPtr);

    }
    else {
        ret_value = -1;
    }
}

template <class ItemType>
void QueueType<ItemType>::Print(){
    if(isEmpty()){
        cout << "[EMPTY QUEUE]" << endl;
        return;
    }
    
    cout << "(front)\t[";
    NodeType<ItemType> * tempPtr = pFront;
    
    while(tempPtr != nullptr){
        cout << tempPtr -> value << "\t";
        tempPtr = tempPtr->next;
    }
    cout << "]\t(rear)" << endl;
}



#endif /* QUEUETYPE_H */
