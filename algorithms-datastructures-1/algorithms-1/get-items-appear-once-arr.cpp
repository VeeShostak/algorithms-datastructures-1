//
//  element-appears-once-arr.cpp


//One solution is to check every element if it appears once or not. Once an an element with single occurrence is found, return it. Time complexity of this solution is O(n2).
//
//    A better solution is to use hashing.
        // number -> occurences
//    1) Traverse all elements and put them in a hash table. Element is used as key and count of occurrences is use value in hash table.
//    2) Traverse the array again and print the element with count 1 in hash table.
//    This solution works in O(n) time, but requires extra space.

//    The best solution is to use XOR. XOR of all array elements gives us the number with single occurrence. The idea is based on following two facts.
//    a) XOR of a number with itself is 0.
//    b) XOR of a number with 0 is number itself.

#include <stdio.h>
// C++ program to find the array element that appears only once
#include <iostream>
using namespace std;

int findSingle(int ar[], int ar_size)
{
    // Do XOR of all elements and return
    int res = ar[0];
    for (int i=1; i < ar_size; i++)
        res = res ^ ar[i];
    
    return res;
}

/* Diver function to test above function */
int main()
{
    int ar[] = {2, 3, 5, 4, 5, 3, 4};
    int n = sizeof(ar)/sizeof(ar[0]);
    cout << "Element occurring once is " << findSingle(ar, n);
    return 0;
}
