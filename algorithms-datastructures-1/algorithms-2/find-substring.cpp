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


