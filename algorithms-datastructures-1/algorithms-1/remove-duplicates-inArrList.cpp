// Simple C++ program to remove duplicates
#include<iostream>
using namespace std;


// TODO: use hashtable
// Create a hashtable with O(1) access. 
// Traverse the original list. If it is not in the hashtable already, 
// add it to the result array and add it to the hash table. If it is in the hash table, ignore it.

// linked list variation:
// We traverse the link list from head to end. For every 
// newly encountered element, we check whether it is in the hash table: 
// if yes, we remove it; otherwise we put it in the hash table.


// time On (sorting nlogn if not sorted)
// space: O1

// C++ program to remove duplicates in-place
#include<iostream>
using namespace std;
 
// Function to remove duplicate elements
// This function returns new size of modified
// array.
int removeDuplicates(int arr[], int n)
{
    if (n==0 || n==1)
        return n;
 
    // To store index of next unique element
    int j = 0;
 
    // Doing same as done in Method 1
    // Just maintaining another updated index i.e. j
    for (int i=0; i < n-1; i++)
        if (arr[i] != arr[i+1])
            arr[j++] = arr[i];
 
    arr[j++] = arr[n-1];
 
    return j;
}
 
// Driver code
int main()
{
    int arr[] = {1, 2, 2, 3, 4, 4, 4, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    // removeDuplicates() returns new size of
    // array.
    n = removeDuplicates(arr, n);
 
    // Print updated array
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
 
    return 0;
}


/*

// Time Complexity : O(n)
// Auxiliary Space : O(n)


// Function to remove duplicate elements
// This function returns new size of modified
// array.
int removeDuplicates(int arr[], int n)
{
    // Return, if array is empty
    // or contains a single element
    if (n==0 || n==1)
        return n;
 
    int temp[n];
 
    // Start traversing elements
    int j = 0;
    for (int i=0; i<n-1; i++)
 
        // If current element is not equal
        // to next element then store that
        // current element
        if (arr[i] != arr[i+1])
            temp[j++] = arr[i];
 
    // Store the last element as whether
    // it is unique or repeated, it hasn't
    // stored previously
    temp[j++] = arr[n-1];
 
    // Modify original array
    for (int i=0; i<j; i++)
        arr[i] = temp[i];
 
    return j;
}
 
// Driver code
int main()
{
    int arr[] = {1, 2, 2, 3, 4, 4, 4, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    // removeDuplicates() returns new size of
    // array.
    n = removeDuplicates(arr, n);
 
    // Print updated array
    for (int i=0; i<n; i++)
       cout << arr[i] << " ";
 
    return 0;
}

*/