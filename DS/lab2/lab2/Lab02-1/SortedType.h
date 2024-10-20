//
//  SortedType.h
//  Lab02
//
//  Modified by Jeman Park on 2023/09/24.
//

#ifndef SORTEDTYPE_H
#define SORTEDTYPE_H

#define MAX_ITEMS 30

using namespace std;

template <class ItemType>
class SortedType
{
private:
    ItemType data[MAX_ITEMS];
    int length;
    
public:
    SortedType();
    void        insertItem(ItemType value);
    void        removeItem(ItemType value);
    void        clear( );
    
    int         size( );
    bool        isFull( );
    bool        isEmpty( );
    ItemType    getItem(int pos);
    bool        findItem(ItemType & item);
    int         BinarySearch(ItemType item);
    int         BinarySearchNearestSmaller(ItemType item);

    void PrintList();
};


template <class ItemType>
SortedType<ItemType>::SortedType()
{
    length = 0;
}

template <class ItemType>
int SortedType<ItemType>::size()
{
    return length;
}

template <class ItemType>
bool SortedType<ItemType>::isFull()
{
    return (length == MAX_ITEMS);
}

template <class ItemType>
bool SortedType<ItemType>::isEmpty()
{
    return (length == 0);
}


template <class ItemType>
void SortedType<ItemType>::insertItem(ItemType value){
    if (isFull( )){
        cout << "[ERROR] List is FULL" << endl;
        return;
    }
    int location = 0;
    while (location < length){
        if(value > data[location]){
            location ++;
        }
        else{
            break;
        }
    }
    
    for ( int i = length; i > location; i-- ){
        data[ i ] = data[i-1];
    }
    data[location] = value;
    length ++;
}

template <class ItemType>
void SortedType<ItemType>::removeItem(ItemType value){
    if (isEmpty( )){
        cout << "[ERROR] List is EMPTY" << endl;
        return;
    }
    int location = 0;
    while (location < length){
        if(value > data[location]){
            location ++;
        }
        else{
            break;
        }
    }
    for ( int i = location + 1; i < length; i++ ){
        data[i-1] = data[i];
    }
    length --;
}

template <class ItemType>
void SortedType<ItemType>::clear( ){
    length = 0;
}

template <class ItemType>
ItemType SortedType<ItemType>::getItem(int pos){
    if (pos >= length){
        cout << "[ERROR] Invalid Position (pos >= length)" << endl;
        return -1;
    }
    
    return data[pos];
}

template <class ItemType>
bool SortedType<ItemType>::findItem(ItemType & item){
    int location = 0;
    
    while(location < length){
        if(data[location] == item){
            item = data[location];
            return true;
        }
        location ++;
    }
    return false;
}

template <class ItemType>
int SortedType<ItemType>::BinarySearch(ItemType item){
   
    int ret = -1;
    /* Implement the function here (Lab 02-1 (1)) */
    // This function performs "binary search" on the sorted list
    // It returns the "index" if "value" exists
    // Otherwise, it returns -1
    // For example, suppose that test_sorted_list = [ 1, 3, 4, 10, 12, 14]
    // BinarySearch(4) will return (2)  -- (the index of "4" is [2])
    // BinarySearch(5) will return (-1) -- ("5" does not exist)
    
    int pBegin = 0;
    int pMid;
    int pEnd = length - 1;

    while (pBegin <= pEnd) {
        cout << pBegin << " " << pEnd << "\n";
        pMid = (pBegin + pEnd )/ 2;
        if (data[pMid] == item) {
            ret = pMid;
            break;
        }
        else if (data[pMid] < item) {
            pBegin = pMid + 1;
        }
        else if (data[pMid] > item) {
            pEnd = pMid - 1;
        }

    }
    return ret;
}

template <class ItemType>
int SortedType<ItemType>::BinarySearchNearestSmaller(ItemType item) {
    int nearest = -10;

    /* Implement the function here (Lab 02-1 (2)) */
    // This function is very similar to "BinarySearch" above
    // it also performs "binary search" on the sorted list
    // It returns the "index" if "value" exists (same as the above)
    // But BinarySearchNearest will return the index of the element nearest to "item" and smaller than "item"
    // Refer to the example in the slide
    int p_begin = 0;
    int p_end = length - 1;
    int p_mid;

    if (data[p_begin] > item) {
        return -1;
    }

    while (p_begin <= p_end) {

        p_mid = (p_begin + p_end) / 2;

        if (data[p_mid] == item) {
            nearest = p_mid;
            break;
        }
        else if (data[p_mid] < item) {
            nearest = p_mid;
            p_begin = p_mid + 1;
        }
        else if(data[p_mid] > item) {

            p_end = p_mid - 1;

        }
    }
    return nearest;
}

template <class ItemType>
void SortedType<ItemType>::PrintList()
{
    if(length == 0){
        cout << "[EMPTY LIST]" << endl;;
        return;
    }
    cout << "[";
    for(int i=0; i < length; i++){
        cout << data[i] << " ";
    }
    cout << "]" << endl;
}


#endif
