//
//  Lab03_1.cpp
//  Lab03
//
//  Modified by Jeman Park on 2024/10/01.
//


#include <iostream>
#include "QueueType.h"
using namespace std;

int main(int argc, const char * argv[]) {
    QueueType<int> Que(5);
    
    
    Que.enqueue(1);
    Que.enqueue(2);
    Que.enqueue(3);
    Que.enqueue(4);
    Que.enqueue(5);
    Que.printQueue();
    // [ 1    2    3    4    5     ]
    
    Que.rotateFirstItem();
    Que.printQueue();
    // [ 2    3    4    5    1     ]
    

    return 0;
}

