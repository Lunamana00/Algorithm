//
//  QueueType.h
//  Lab03
//
//  Modified by Jeman Park on 2024/10/01.
//


#ifndef QUEUETYPE_H
#define QUEUETYPE_H


#include <iostream>
using namespace std;


struct task{
    int priority;
    string description;
    
    task(){}
    task(int prio, string desc): priority(prio), description(desc){}
};


template<class ItemType>
class QueueType
{
private:
    ItemType *     data; // dynamic array implementation
    int         front; // the index of the front element
    int         rear; // the index of the rear element
    int         maxQueue; // the MAX size of the queue
    
public:
    QueueType(int maxQue);
    bool        enqueue(ItemType value);
    bool        dequeue(ItemType &ret);
    bool        priority_dequeue(ItemType &ret);
    
    
    void        clear( );
    bool        isFull( ) const;
    bool        isEmpty( ) const;
    void        printQueue( ) const;
};


template<class ItemType>
QueueType<ItemType>::QueueType(int maxQue){
    maxQueue = maxQue + 1;
    front = maxQueue - 1;
    rear= maxQueue - 1;
    data = new ItemType[maxQueue];
}

template<class ItemType>
bool QueueType<ItemType>::isFull( ) const {
    return ( (rear + 1) % maxQueue == front );
}


template<class ItemType>
bool QueueType<ItemType>::isEmpty( ) const {
    return ( rear == front );
}

template<class ItemType>
void QueueType<ItemType>::clear( ){
    front = maxQueue - 1;
    rear= maxQueue - 1;
}


template<class ItemType>
bool QueueType<ItemType>::enqueue(ItemType newItem){
    if(isFull()){
        cout << "[ERROR] Queue is Full. Enqueue Failed." << endl;
        return false;
    }
    rear = (rear + 1) % maxQueue ;
    data[rear] = newItem;
    return true;
}


template<class ItemType>
bool QueueType<ItemType>::dequeue(ItemType& ret) {
    if(isEmpty()){
        cout << "[ERROR] Queue is Empty. Dequeue Failed." << endl;
        return false;
    }
    front = (front + 1) % maxQueue ;
    ret = data[front];
    
    return true;
}

template<class ItemType>
bool QueueType<ItemType>::priority_dequeue(ItemType& ret) {
    if(isEmpty()){
        cout << "[ERROR] Queue is Empty. Dequeue Failed." << endl;
        return false;
    }
    
    
    /* Implement the function here (Lab 03-3) */
    // This function dequeues "task" that has the MINIMUM prioiroty value.
    // it returns false if the queue is empty (already implemented above)
    // Otherwise, it returns the dequeued "task" as "ret" (return by reference)
    //
    // For details, check the PDF slides!

    int pTemp = front;
    int min = 99999999999999;
    while (pTemp != rear) {
        if (min > data[pTemp]) {
            min = data[pTemp];
        }
        pTemp = (pTemp + 1) / maxQueue;
    }
    ret = min;

    return true;
}


template<class ItemType>
void QueueType<ItemType>::printQueue() const{
    if(isEmpty()){
        std::cout << "[EMPTY QUEUE] " << endl;
        return;
    }
    
    cout << "(front) [ ";
    
    int i = front;
    
    do{
        i = (i + 1) % maxQueue;
        cout << data[i].description << ": " << data[i].priority << "\t";
    } while(i != rear);
    
    
    cout << " ] (rear)";
    cout << endl;
}


#endif
