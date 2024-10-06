//
//  Lab03_3.cpp
//  Lab03
//
//  Modified by Jeman Park on 2024/10/01.
//

#include <iostream>
#include "QueueType.h"
using namespace std;



int main(int argc, const char * argv[]) {
    QueueType<task> PrioirityQue(5);
    task ret;
    
    PrioirityQue.enqueue(task(10, "A"));
    PrioirityQue.enqueue(task(17, "B"));
    PrioirityQue.enqueue(task(8, "C"));
    PrioirityQue.enqueue(task(20, "D"));
    PrioirityQue.enqueue(task(26, "E"));
    
    PrioirityQue.enqueue(task(100, "Z"));
    // [ERROR] Queue is Full. Enqueue Failed.
    
    PrioirityQue.printQueue();
    // (front) [ A: 10    B: 17    C: 8    D: 20    E: 26     ] (rear)
    
    if(PrioirityQue.priority_dequeue(ret)){
        cout << "[PRIORITY_DEQUEUED]: " << ret.description << endl;
    }
    PrioirityQue.printQueue();
    // [PRIORITY_DEQUEUED]: C
    // (front) [ A: 10    B: 17    D: 20    E: 26     ] (rear)
    
    PrioirityQue.enqueue(task(21, "F"));
    PrioirityQue.enqueue(task(13, "G"));
    // [ERROR] Queue is Full. Enqueue Failed.
    PrioirityQue.printQueue();
    // (front) [ A: 10    B: 17    D: 20    E: 26    F: 21     ] (rear)
    
    
    if(PrioirityQue.dequeue(ret)){
        cout << "[DEQUEUED]: " << ret.description << endl;
    }
    if(PrioirityQue.dequeue(ret)){
        cout << "[DEQUEUED]: " << ret.description << endl;
    }
    if(PrioirityQue.dequeue(ret)){
        cout << "[DEQUEUED]: " << ret.description << endl;
    }
    if(PrioirityQue.dequeue(ret)){
        cout << "[DEQUEUED]: " << ret.description << endl;
    }
    //    [DEQUEUED]: A
    //    [DEQUEUED]: B
    //    [DEQUEUED]: D
    //    [DEQUEUED]: E
    PrioirityQue.printQueue();
    //    (front) [ F: 21     ] (rear)
    
    PrioirityQue.enqueue(task(51, "H"));
    PrioirityQue.enqueue(task(12, "I"));;
    PrioirityQue.enqueue(task(7, "J"));
    PrioirityQue.printQueue();
    //     (front) [ F: 21    H: 51    I: 12    J: 7     ] (rear)
    
    if(PrioirityQue.priority_dequeue(ret)){
        cout << "[PRIORITY_DEQUEUED]: " << ret.description << endl;
    }
    //    [PRIORITY_DEQUEUED]: J
    PrioirityQue.printQueue();
    //    (front) [ F: 21    H: 51    I: 12     ] (rear)


    
    if(PrioirityQue.priority_dequeue(ret)){
        cout << "[PRIORITY_DEQUEUED]: " << ret.description << endl;
    }
    // [PRIORITY_DEQUEUED]: I
    if(PrioirityQue.priority_dequeue(ret)){
        cout << "[PRIORITY_DEQUEUED]: " << ret.description << endl;
    }
    // [PRIORITY_DEQUEUED]: F
    if(PrioirityQue.priority_dequeue(ret)){
        cout << "[PRIORITY_DEQUEUED]: " << ret.description << endl;
    }
    // [PRIORITY_DEQUEUED]: H
    if(PrioirityQue.priority_dequeue(ret)){
        cout << "[PRIORITY_DEQUEUED]: " << ret.description << endl;
    }
    // [ERROR] Queue is Empty. Dequeue Failed.
    
    PrioirityQue.printQueue();
    // [EMPTY QUEUE]

    return 0;
}
