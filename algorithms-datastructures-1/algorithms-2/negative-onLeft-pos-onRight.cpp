#include <iostream>
#include <vector>
using namespace std;


// func prototypes
void allCombinations( vector<vector<string> > vectOfVectOfwords);
void segregateElements(int arr[], int n);
void RearrangePosNeg(vector<int> &theVector);
void printArray(vector<int> theVector);


//Given array of integers, change the order so that negative on left,
//positives on right, while preserving order . Give Time and space complexity.
//(With additional data structure but no lists, then without additional data structures)

// NOTE:
//One approach that does not use any data structure is to use use partition process of
//QuickSort. The idea is to consider 0 as pivot and divide the array around it. The
//problem with this approach is that it changes relative order of elements.


//do not use any other data structure and also preserves relative order of elements.
// insertion sort

// =============================
// START MAIN
// =============================

int main() {
    
    
    //    int arr[] = {1 ,-1 ,-3 , -2, 7, 5, 11, 6 };
    //    int n = sizeof(arr)/sizeof(arr[0]);
    //
    //    segregateElements(arr, n);
    //
    //    for (int i = 0; i < n; i++)
    //        cout << arr[i] << " ";
    
    
    // int arr[] = { -12, 11, -13, -5, 6, -7, 5, -3, -6 };
    //    int arr[] = { -12, 11, 6, -2, 1 };
    //    int n = sizeof(arr) / sizeof(arr[0]);
    
    vector<int> mVect = { -12, 11, 6, -2, 1 };
    //    int n = sizeof(arr) / sizeof(arr[0]);
    
    RearrangePosNeg(mVect);
    printArray(mVect);
    
    return 0;
}

// =============================
// END MAIN
// =============================

// =============================
// START FUNCTION DEFINITIONS
// =============================


// Loop from i = 1 to n - 1.
//   a) If the current element is positive, do nothing.
//   b) If the current element arr[i] is negative, we
//      insert it into sequence arr[0..i-1] such that
//      all positive elements in arr[0..i-1] are shifted
//      one position to their right and arr[i] is inserted
//      at index of first positive element.


// modified insertion sort
//negative on left, posititve on right

//Time complexity of above solution is O(n2) and a
//uxiliary space is O(1).
//We have maintained the order of appearance and have not used any other data structure.
// Function to Rearrange positive and negative
// numbers in a array
void RearrangePosNeg(vector<int> &theVector)
{
    int key, j;
    for(int i = 1; i < theVector.size(); i++)
    {
        key = theVector[i];
        
        // if current element is positive
        // do nothing
        if (key > 0)
            continue;
        
        /* if current element is negative,
         shift positive elements of arr[0..i-1],
         to one position to their right */
        
        // j = 3-1
        // j = 2
        j = i - 1; // prev element
        // shift to right until if see negative, stop, if not shift all to right and place first negative
        while (j >= 0 && theVector[j] > 0)
        {
            // -2 = 6
            theVector[j + 1] = theVector[j];
            j = j - 1; // j = 1
        }
        
        // Put negative element at its right position
        theVector[j + 1] = key;
    }
}

// A utility function to print an array of size n
void printArray(vector<int> theVector)
{
    for (int i = 0; i < theVector.size(); i++)
        cout << theVector[i] << " ";
    
    cout << endl;
    
}



//Time Complexity : O(n)
//Auxiliary space : O(n)
// Moves all -ve element to end of array in
// same order.
void segregateElements(int arr[], int n)
{
    // Create an empty array to store result
    int temp[n];
    
    // Traversal array and store +ve element in
    // temp array
    int j = 0; // index of temp
    for (int i = 0; i < n ; i++)
        if (arr[i] >= 0 )
            temp[j++] = arr[i];
    
    // If array contains all positive or all negative.
    if (j == n || j == 0)
        return;
    
    // Store -ve element in temp array
    for (int i = 0 ; i < n ; i++)
        if (arr[i] < 0)
            temp[j++] = arr[i];
    
    // Copy contents of temp[] to arr[]
    memcpy(arr, temp, sizeof(temp));
}


// =============================
// END FUNCTION DEFINITIONS
// =============================

