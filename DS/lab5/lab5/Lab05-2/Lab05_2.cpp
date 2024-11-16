//
//  Lab05_2.cpp
//  Lab05-2
//
//  Modified by Jeman Park on 2024/11/05.
//

#include <iostream>
#include "SortedType.h"

using namespace std;

int main() {

    /* Feel free to edit codes below (test with more cases) */
    SortedType<int> sList;
    
    sList.insertItem(5);
    sList.insertItem(3);
    sList.insertItem(7);
    sList.insertItem(2);
    sList.insertItem(13);
    sList.insertItem(1);
    
    sList.printList();
    
    
    sList.removeItem(6);
    sList.removeItem(13);
    
    
    sList.printList();
    
    sList.clear();
    sList.printList();
    
    sList.insertItem(5);
    sList.printList();
    sList.removeItem(3);
    sList.printList();
    
    return 0;
}
