//
//  find-substring.cpp
//  test
//
//  Created by Vlad Shostak on 10/30/17.
//  Copyright © 2017 Vlad Shostak. All rights reserved.
//

#include <stdio.h>

#include <iostream>
#include <string>


/*
 Given two strings, find if first string is a subsequence of second
 Input: str1 = "AXY", str2 = "ADXCPY"
 Output: True (str1 is a subsequence of str2)
 
 
 Input: str1 = "AXY", str2 = "YADXCP"
 Output: False (str1 is not a subsequence of str2)
 
 solution:
 we traverse both strings from one side to other side (say from rightmost
 character to leftmost). If we find a matching character,
 we move ahead in both strings. Otherwise we move ahead only in strToFindIn.
 
 
 ADXCPY
 AXY
 
 
 
 
 */

// Iterative C++ program to check if a string is subsequence of another string
#include<iostream>
#include<cstring>
using namespace std;

// Returns true if str1[] is a subsequence of str2[]. m is
// length of str1 and n is length of str2
bool isSubSequence(char str1[], char str2[], int m, int n)
{
    int j = 0; // For index of str1 (or subsequence
    
    // Traverse str2 and str1, and compare current character
    // of str2 with first unmatched char of str1, if matched
    // then move ahead in str1
    for (int i=0; i<n&&j<m; i++)
        if (str1[j] == str2[i])
            j++;
    
    // If all characters of str1 were found in str2
    return (j==m);
}

// Driver program to test methods of graph class
int main()
{
    char str1[] = "gksrek";
    char str2[] = "geeksforgeeks";
    int m = strlen(str1);
    int n = strlen(str2);
    isSubSequence(str1, str2, m, n)? cout << "Yes ":
    cout << "No";
    return 0;
}






/*
 
 
 
 
 // Recursive C++ program to check if a string is subsequence of another string
 #include<iostream>
 #include<cstring>
 using namespace std;
 
 // Returns true if str1[] is a subsequence of str2[]. m is
 // length of str1 and n is length of str2
 bool isSubSequence(char str1[], char str2[], int m, int n)
 {
 // Base Cases
 if (m == 0) return true;
 if (n == 0) return false;
 
 // If last characters of two strings are matching
 if (str1[m-1] == str2[n-1])
 return isSubSequence(str1, str2, m-1, n-1);
 
 // If last characters are not matching
 return isSubSequence(str1, str2, m, n-1);
 }
 
 // Driver program to test methods of graph class
 int main()
 {
 char str1[] = "gksrek";
 char str2[] = "geeksforgeeks";
 int m = strlen(str1);
 int n = strlen(str2);
 isSubSequence(str1, str2, m, n)? cout << "Yes ":
 cout << "No";
 return 0;
 }
 */



// find substring is simple
/*
 hello
 
 llo
 
 go throug first and second, see if first char of .... too easy
 
 */
/*
 bool CheckSubstring(std::string firstString, std::string secondString){
 if(secondString.size() > firstString.size())
 return false;
 // hello
 // ll  j = 01
 for (int i = 0; i < firstString.size(); i++){
 int j = 0;
 if(firstString[i] == secondString[j]){
 while (firstString[i] == secondString[j] && j < secondString.size()){
 j++;
 i++;
 }
 
 if (j == secondString.size())
 return true;
 }
 }
 return false;
 }
 
 int main(){
 std::string firstString, secondString;
 
 std::cout << "Enter first string:";
 std::getline(std::cin, firstString);
 
 std::cout << "Enter second string:";
 std::getline(std::cin, secondString);
 
 if(CheckSubstring(firstString, secondString))
 std::cout << "Second string is a substring of the frist string.\n";
 else
 std::cout << "Second string is not a substring of the first string.\n";
 
 return 0;
 }
 
 */
