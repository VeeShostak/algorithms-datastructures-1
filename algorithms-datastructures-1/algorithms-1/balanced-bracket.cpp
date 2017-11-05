Brackets

//
//  main.cpp
//  test
//
//  Created by Vlad Shostak on 10/20/17.
//  Copyright © 2017 Vlad Shostak. All rights reserved.
//

// TODO: use trie to solve?
/*
 Algorithm:
 1) Declare a character stack S.
 2) Now traverse the expression string exp.
 a) If the current character is a starting bracket (‘(‘ or ‘{‘ or ‘[‘) then push it to stack.
 b) If the current character is a closing bracket (‘)’ or ‘}’ or ‘]’) then pop from stack and if the popped character is the matching starting bracket then fine else parenthesis are not balanced.
 3) After complete traversal, if there is some starting bracket left in stack then “not balanced”
 
 */

#include <stack>
#include <iostream>
using namespace std;

// function to check if paranthesis are balanced
bool areParanthesisBalanced(string expression)
{
    stack<char> s;
    char a, b, c;
    string temp = "";
    
    // Traversing the Expression
    for (int i=0; i<expression.length(); i++)
    {
        if (expression[i]=='('||expression[i]=='['||expression[i]=='{')
        {
            // Push the element in the stack
            s.push(expression[i]);
        }
        else
        {
            switch (expression[i])
            {
                case ')':
                    // encountered right bracket
                    //should have matching left bracket at top of the stacl
                    
                    // Store the top element in a
                    
                    // get the top element in the stack
                    a = s.top();
                    s.pop(); // pop top
                    if (a=='{'||a=='[')
                        cout<<"Not Balancedn";
                    break;
                case '}':
                    
                    // Store the top element in b
                    b = s.top();
                    s.pop();
                    if (b=='('||b=='[')
                        cout<<"Not Balancedn";
                    break;
                case ']':
                    
                    // Store the top element in c
                    c=s.top();
                    s.pop();
                    if (c=='('||c=='{')
                        cout<<"Not Balancedn";
                    break;
            }
        }
    }
    
    // Check Empty Stack
    if (s.empty())
        return true;
    else
        return false;
}

// Driver program to test above function
int main(int argc, const char * argv[]) {
    
    //char expr[]="{()}[]";
    string expr = "(5+5)";
    
    if(areParanthesisBalanced(expr))
        cout<<"Balanced";
    else
        cout<<"Not Balanced";
    return 0;
}




