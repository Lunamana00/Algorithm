//
//  Lab02_1.cpp
//  Lab02
//
//  Modified by Jeman Park on 2023/09/24.
//


#include <iostream>
#include "SortedType.h"
using namespace std;


int main() {
    
    SortedType<int> sList;

    /* Feel free to edit codes below (test with more cases) */

    sList.insertItem(27);
    sList.insertItem(15);
    sList.insertItem(5);
    sList.insertItem(12);
    sList.insertItem(20);
    sList.insertItem(21);
    sList.insertItem(4);
    sList.insertItem(2);
    sList.insertItem(7);
    

    sList.PrintList();
    // Correct Output: [1 3 6 7 11 15 16 23 ]
    
    sList.removeItem(4);
    sList.removeItem(15);
    sList.PrintList();
    // Correct Output: [ 3 6 11 15 16 23 ]
    
    
   
    cout << "[BinarySearch]: the result of input '5' is " << sList.BinarySearch(5) << endl;
    // Correct Output: [BinarySearch]: the result of input '5' is 1
    cout << "[BinarySearch]: the result of input '20' is " << sList.BinarySearch(20) << endl;
    // Correct Output: [BinarySearch]: the result of input '20' is 4
    cout << "[BinarySearch]: the result of input '4' is " << sList.BinarySearch(4) << endl;
    // Correct Output: [BinarySearch]: the result of input '4' is -1
    cout << "[BinarySearch]: the result of input '15' is " << sList.BinarySearch(15) << endl;
    // Correct Output: [BinarySearch]: the result of input '15' is -1
    

    cout << "[BinarySearchNearestSmaller]: the result of input '5' is " << sList.BinarySearchNearestSmaller(5) << endl;
    // Correct Output: [BinarySearchNearest]: the result of input '5' is 1
    cout << "[BinarySearchNearestSmaller]: the result of input '20' is " << sList.BinarySearchNearestSmaller(20) << endl;
    // Correct Output: [BinarySearchNearest]: the result of input '20' is 4
    cout << "[BinarySearchNearestSmaller]: the result of input '24' is " << sList.BinarySearchNearestSmaller(24) << endl;
    // Correct Output: [BinarySearchNearest]: the result of input '24' is 5
    cout << "[BinarySearchNearestSmaller]: the result of input '30' is " << sList.BinarySearchNearestSmaller(30) << endl;
    // Correct Output: [BinarySearchNearest]: the result of input '30' is 6
    cout << "[BinarySearchNearestSmaller]: the result of input '1' is " << sList.BinarySearchNearestSmaller(1) << endl;
    // Correct Output: [BinarySearchNearest]: the result of input '1' is -1


    return 0;
}
