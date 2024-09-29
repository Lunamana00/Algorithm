//
//  Lab02_2.cpp
//  Lab02
//
//  Modified by Jeman Park on 2023/09/24.
//

#include <iostream>
#include <string>
#include "CheckMatching.h"
using namespace std;

int main() {

    /* Feel free to edit codes below (test with more cases) */
    
    char someString1[] = "((()))";
    if(checkMatching(someString1, int(strlen(someString1)))){
        cout << "[MATCHED]" << endl;
    }
    else{
        cout << "[UNMATCHED]" << endl;
    }
    // "[MATCHED]"
    
    char someString2[] = "((())";
    if(checkMatching(someString2, int(strlen(someString2)))){
        cout << "[MATCHED]" << endl;
    }
    else{
        cout << "[UNMATCHED]" << endl;
    }
    // "[UNMATCHED]"
    
    char someString3[] = "(qwer)[{asdf}]";
    if(checkMatching(someString3, int(strlen(someString3)))){
        cout << "[MATCHED]" << endl;
    }
    else{
        cout << "[UNMATCHED]" << endl;
    }
    // "[MATCHED]"
    
    
    char someString4[] = "(qwer[){asdf}]";
    if(checkMatching(someString4, int(strlen(someString4)))){
        cout << "[MATCHED]" << endl;
    }
    else{
        cout << "[UNMATCHED]" << endl;
    }
    // "[UNMATCHED]"
    
    return 0;
}
