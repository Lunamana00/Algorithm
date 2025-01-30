//
//  Lab06_3.cpp
//  Lab06
//
//  Added by Jeman Park on 2024/11/12.
//

#include <iostream>
using namespace std;

static int recurFuncCount = 0;
static int recurFuncCountMemoization = 0;

// ASSUME that N is always < 20, where
#define MAX_SIZE 20
static int memoization[MAX_SIZE+1];


int NaiveFibonacci(int n) {
    recurFuncCount ++; // <- Do NOT edit nor move this instruction
    
	if (n == 0 || n == 1)
		return 1;
	else
		return NaiveFibonacci(n-1) + NaiveFibonacci(n-2);
}


int FibonacciMemoization(int n) {
    recurFuncCountMemoization ++; // <- Do NOT edit nor move this instruction
    
    /* Implement the function here */
    // FibonacciMemoization does the same thing as NaiveFibonacci, but in a better way.
    // It uses the matrix "memoization" to store the intermediate results.
    // When it calculates Fibo[n], it stores the value in memoization[n].
    
    // When the function is invoked:
    // 1) it first searches "memoization[n]" to check if it was previously stored
    // 2) if found, it returns the value
    // 3) otherwise, it recursively gets the result (Same as NaiveFibonacci)
    
    
    // Time Complexity: O( N )
    

    if (memoization[n] != -1) {
        return memoization[n];
    }

    if (n == 0 || n == 1) {
        memoization[n] = 1;
        return memoization[n];
    }

    memoization[n] = FibonacciMemoization(n - 1) + FibonacciMemoization(n - 2);
    return memoization[n];

}

int main() {
    for(int i=0; i < MAX_SIZE+1; i++){
        memoization[i] = -1;
    }
    
    NaiveFibonacci(15);
    cout << "NaiveFibonacci has been invoked " << recurFuncCount << " times" << endl;
    
    
    FibonacciMemoization(15);
    cout << "FibonacciMemoization has been invoked " << recurFuncCountMemoization << " times" << endl;
    
    //    NaiveFibonacci has been invoked 1973 times
    //    FibonacciMemoization has been invoked 29 times

	return 0;
}
