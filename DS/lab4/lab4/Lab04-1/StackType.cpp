//
//  StackType.cpp
//  Lab04
//
//  Modified by Jeman Park on 2024/10/13.
//

#include "StackType.h"

StackType::StackType()
{
    topPtr = nullptr;
}

StackType::~StackType()
{
    /* Implement the function here */
    // This destructor function iteratively deletes all nodes in the stack.
    // All "NodeType" should be "deallocated" properly.
    // It returns nothing
    
    while (!isEmpty()) {
        pop();
    }

}


void StackType::clear(){
    this->~StackType();
}

bool StackType::isEmpty() const
{
    
    return (topPtr == nullptr);
    
}


bool StackType::isFull() const
{
    NodeType * newNode;
    try {
        newNode = new NodeType;
        delete newNode;
        return false;
    }
    catch (std::bad_alloc exception){
        return true;
    }
}

int StackType::size() const
{
    /* Implement the function here */
    // This function counts the number of nodes in the stack and returns it.
    
    
    int len = 0;
    
    NodeType* tempPtr = topPtr;

    while (tempPtr) {
        
        tempPtr = (*tempPtr).next;

        len++;
    }

   
    return len;
    
}

void StackType::push(ItemType newItem)
{
    /* Implement the function here */
    // This function pushes "newItem" into the stack, and returns NOTHING.
    // If the stack is already full, do nothing.
    
    if (!isFull()) {
        NodeType* newnode = new NodeType;

        (*newnode).value = newItem;

        (*newnode).next = topPtr;

        topPtr = newnode;
    }
    
}

ItemType StackType::pop()
{
    /* Implement the function here */
    // This function pops the item at the top of the stack, and returns it.
    // It should deallocate the popped node.
    // If the stack is EMPTY, it returns -1.
    
    
    if (!isEmpty()) {
        
        ItemType rv;
        NodeType* tempPtr = topPtr;
        
        topPtr = (*topPtr).next;
        rv = (*tempPtr).value;
        delete(tempPtr);
        return rv;
    }
}


void StackType::Print() {
    if(isEmpty()){
        cout << "[EMPTY STACK]" << endl;
        return;
    }
    
    cout << "(top)\t";
    NodeType * tempPtr = topPtr;

    while(tempPtr != nullptr){
        cout << tempPtr->value << "\t";
        tempPtr = tempPtr->next;
    }
    
    cout <<  " ] " << endl;
        
}
