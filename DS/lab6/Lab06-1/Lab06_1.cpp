//
//  Lab06_1.cpp
//  Lab06
//
//  Modified by Jeman Park on 2024/11/12.
//

#include <iostream>
#include "DoubleSortedType.h"

using namespace std;

int main() {

    /* Feel free to edit codes below (test with more cases) */
    DoubleSortedType<int> sList;
    
    sList.insertItem(5);
    sList.insertItem(3);
    sList.insertItem(7);
    sList.insertItem(2);
    sList.insertItem(13);
    sList.insertItem(1);
    
    sList.printList();
    sList.printListRev();
    //    [    1    2    3    5    7    13    ]
    //    [    13    7    5    3    2    1    ]
    
    
    sList.removeItem(6);
    sList.removeItem(13);
    
    sList.printList();
    sList.printListRev();
    //    [    1    2    3    5    7    ]
    //    [    7    5    3    2    1    ]
    
    
    sList.clear();
    sList.printList();
    sList.printListRev();
    //    [    ]
    //    [    ]
    
    sList.insertItem(5);
    sList.printList();
    sList.printListRev();
    //    [    5    ]
    //    [    5    ]
    
    sList.removeItem(3);
    sList.printList();
    sList.printListRev();
    //    [    5    ]
    //    [    5    ]
    
    return 0;
}
