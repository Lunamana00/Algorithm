//
//  UnsortedType.h
//  Lab06
//
//  Modified by Jeman Park on 2024/11/12.
//

#include<iostream>

using namespace std;
  
template <class ItemType>
struct NodeType;

template <class ItemType>
class UnsortedType
{
public:
    UnsortedType();
    ~UnsortedType();
    
    bool isFull() const;
    bool isEmpty() const;
    void clear();
    bool findItem(ItemType& item);
    bool findItemRecursive(ItemType& item);
    void appendItem(ItemType item);
    void removeItem(ItemType item);
    void sortList();
    void sort(NodeType<ItemType>* location);
    void printList();
    ItemType getMinItem();
    
protected:
    NodeType<ItemType>* MinLoc(NodeType<ItemType>* location, NodeType<ItemType>* minPtr);
    bool findItemRecur(NodeType<ItemType>* location, ItemType & item);
    
private:
    NodeType<ItemType>* listData;
    int length;
};

template<class ItemType>
struct NodeType
{
    ItemType value;
    NodeType* next;
};

template <class ItemType>
UnsortedType<ItemType>::UnsortedType()
{
    length = 0;
    listData = nullptr;
}

template <class ItemType>
UnsortedType<ItemType>::~UnsortedType()
{
    clear();
}

template<class ItemType>
bool UnsortedType<ItemType>::isEmpty() const
{
    return listData == nullptr;
}

template<class ItemType>
bool UnsortedType<ItemType>::isFull() const
{
    NodeType<ItemType>* location;
    try
    {
        location = new NodeType<ItemType>;
        delete location;
        return false;
    }
    catch(bad_alloc exception)
    {
        return true;
    }
}

template <class ItemType>
void UnsortedType<ItemType>::clear()
{
    NodeType<ItemType>* tempPtr;
    
    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}

template <class ItemType>
bool UnsortedType<ItemType>::findItem(ItemType& item)
{
    NodeType<ItemType>* tempPtr;
    
    tempPtr = listData;
        
    while (tempPtr != nullptr)
    {
        if (item == tempPtr -> value)
        {
            item = tempPtr->value;
            return true;
        }
        tempPtr = tempPtr ->next;
    }
    return false;
}

template <class ItemType>
bool UnsortedType<ItemType>::findItemRecur(NodeType<ItemType>* location, ItemType& item){
    /* Implement the function here */
    // this function "Recursively" finds the "item" in the list.
    // If the "item" exists in the list, then return "true"
    // else, return "false"
    
    // Time Complexity: O (N)

    if (location == nullptr)
        return false;

    if (location->value == item)
        return true;

    return findItemRecur(location->next, item);
     
}

template <class ItemType>
bool UnsortedType<ItemType>::findItemRecursive(ItemType& item)
{
    /* Entry Function for Recursive Find Item */
    return findItemRecur(listData, item);
}

template <class ItemType>
void UnsortedType<ItemType>::appendItem(ItemType item)
{
    NodeType<ItemType>* tempPtr;
    
    tempPtr = new NodeType<ItemType>;
    tempPtr -> value = item;
    tempPtr -> next = listData;
    listData = tempPtr;
    length++;
}

template <class ItemType>
void UnsortedType<ItemType>::removeItem(ItemType item)
{
    if(isEmpty()){
        return;
    }
    
    NodeType<ItemType>* tempPtr = listData;
    NodeType<ItemType>* deallocPtr;
        
    if (tempPtr -> value == item) // if the "item" is the first element in the list
    {
        deallocPtr = tempPtr;
        listData = listData->next;
        delete deallocPtr;
        length --;
        return;
    }
    else if(tempPtr -> next == nullptr){
        cout << "[removeItem]: item NOT exists" << endl;
        return;
    }
    
    while (item != (tempPtr -> next) -> value){
        tempPtr = tempPtr -> next;
        if(tempPtr -> next == nullptr){
            cout << "[removeItem]: item NOT exists" << endl;
            return;
        }
    }
    
    deallocPtr = tempPtr->next;
    tempPtr -> next = (tempPtr -> next) -> next;
    delete deallocPtr;
    length--;
}

template <class ItemType>
void UnsortedType<ItemType>::sort(NodeType<ItemType>* location) {
    /* Implement the function here */
    // Sort() must use (1) recursion and (2) MinLoc()
    // It returns nothing (void), but after Sort() the list will be sorted (ascending order)
    // E.g., [11, 2, 5, 3] --> sortList( )/sort( ) --> [2, 3, 5, 11]
    
    // For example, suppose that the list is [43, 21, 14, 26, 17]
    // 1) First *location points to 43 (1st element)
    // 2) Finds the MIN value of the list using MinLoc. (14)
    // 3) Changes their positions -> [14, 21, 43, 26, 17]
    // 4) Recursively call "Sort()" for location->next [21, 43, 26, 17]
    // 5) Finds the MIN value of the list using MinLoc. (17)
    // 6) Changes their positions -> [17, 43, 26, 21]
    // Repeat....
    
    if (location == nullptr || location->next == nullptr)
        return;

    NodeType<ItemType>* minPtr = MinLoc(location, location);

    if (minPtr != location) {
        ItemType temp = location->value;
        location->value = minPtr->value;
        minPtr->value = temp;
    }

    sort(location->next);
    
    
}

template <class ItemType>
void UnsortedType<ItemType>::sortList(){
    /* Entry Function for sort( ) */
    sort(listData);
}

template <class ItemType>
NodeType<ItemType>* UnsortedType<ItemType>::MinLoc(NodeType<ItemType>* location, NodeType<ItemType>* minPtr) {
    /* Implement the function here */
    // MinLoc returns the "pointer" to the MIN value node.
    // MinLoc "recursively" finds the MIN value.
        
    if (location == nullptr)
        return minPtr;

    if (location->value < minPtr->value)
        minPtr = location;

    return MinLoc(location->next, minPtr);
    
    return minPtr;
}

template <class ItemType>
ItemType UnsortedType<ItemType>::getMinItem(){
    NodeType<ItemType>* tempPtr = listData;
    NodeType<ItemType>* ret = MinLoc(listData, tempPtr);

    return ret -> value;
}

template <class ItemType>
void UnsortedType<ItemType>::printList(){
    NodeType<ItemType>* tempPtr = listData;
    
    while (tempPtr != NULL){
        cout << tempPtr -> value << "\t";
        tempPtr = tempPtr -> next;
    }
    cout << endl;
}
