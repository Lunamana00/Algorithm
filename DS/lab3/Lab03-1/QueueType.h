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
    void        enqueue(ItemType value);
    ItemType    dequeue( );
    
    void        rotateFirstItem();
    
    
    void        clear( );
    bool        isFull( ) const;
    bool        isEmpty( ) const;
    void        printQueue( ) const;
};


template<class ItemType>
QueueType<ItemType>::QueueType(int maxQue){
    // Constructor -- No return type
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
void QueueType<ItemType>::rotateFirstItem()
{
    /* Implement the function here (Exercise 3-1) */
    // This "rotates" the first item of the queue and returns NOTHING.
    // "rotate" means to move the first item to the last place.
    // For example:
    //   Que: [ 1    2    3    4    5     ]
    //       rotateFirstItem()
    //   Que: [ 2    3    4    5    1     ]
    
    // HINT: You can call "other member functions" of QueType here.
    
    if(isEmpty()){
        return;
    }

    enqueue(dequeue());
    return;

}

template<class ItemType>
void QueueType<ItemType>::enqueue(ItemType newItem){
    if(isFull()){
        cout << "[ERROR] Queue is Full. Enqueue Failed." << endl;
        return;
    }
    rear = (rear + 1) % maxQueue ;
    data[rear] = newItem;
}


template<class ItemType>
ItemType QueueType<ItemType>::dequeue( ) {
    ItemType ret;
    if(isEmpty()){
        cout << "[ERROR] Queue is Empty. Dequeue Failed." << endl;
        return -1;
    }
    front = (front + 1) % maxQueue ;
    ret = data[front];
    return ret;
}


template<class ItemType>
void QueueType<ItemType>::printQueue() const{
    if(isEmpty()){
        std::cout << "[EMPTY QUEUE] " << endl;
        return;
    }
    
    cout << "[ ";
    
    int i = front;
    
    do{
        i = (i + 1) % maxQueue;
        cout << data[i] << "\t";
    } while(i != rear);
    
    
    cout << " ]";
    cout << endl;
}


#endif /* QUEUETYPE_H */
