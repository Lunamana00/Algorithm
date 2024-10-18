//
//  Lab04_2.cpp
//  Lab04
//
//  Modified by Jeman Park on 2024/10/13.
//

#include <iostream>
#include <string>
#include "QueueType.h"

using namespace std;

int main() {

    /* Feel free to edit codes below (test with more cases) */
    QueueType<int> tempQue;
    
    tempQue.enqueue(5);
    tempQue.enqueue(3);
    tempQue.enqueue(7);
    
    tempQue.Print();
    // (front)    [5    3    7    ]    (rear)
    cout << "[SIZE]: " << tempQue.size() << endl;
    // [SIZE]: 3
    
    tempQue.clear();
    tempQue.Print();
    // [EMPTY QUEUE]
    
    tempQue.enqueue(21);
    tempQue.enqueue(13);
    tempQue.enqueue(37);
    tempQue.Print();
    // (front)    [21    13    37    ]    (rear)
    
    cout << "[SIZE]: " << tempQue.size() << endl;
    // [SIZE]: 3
    
    int ret = 0;
    tempQue.dequeue(ret);
    cout << "[DEQUEUE]: " << ret << endl;
    tempQue.dequeue(ret);
    cout << "[DEQUEUE]: " << ret << endl;
    tempQue.dequeue(ret);
    cout << "[DEQUEUE]: " << ret << endl;
    tempQue.dequeue(ret);
    cout << "[DEQUEUE]: " << ret << endl;
    //    [DEQUEUE]: 21
    //    [DEQUEUE]: 13
    //    [DEQUEUE]: 37
    //    [DEQUEUE]: -1
    
    tempQue.Print();
    // [EMPTY QUEUE]
    
    cout << "[SIZE]: " << tempQue.size() << endl;
    // [SIZE]: 0
    
    return 0;
}
