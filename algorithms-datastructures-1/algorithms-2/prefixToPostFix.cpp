

#include <stdio.h>
#include <stack>

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// TODO MAKE WORK
// TODO USE TRIE



// https://fahadshaon.wordpress.com/2008/01/18/prefix-to-postfix-stack-emplementation/


vector <string> prefixToPostfix(vector <string> prefixes) {
    
    stack<string> mStack;
    vector<string> allPostFix;
    string postFix;
    string tempChar;
    
    // detect if operation or integer
    // stacks, regex
    
    // for each prefix expression string
    for (int i = 0; i < prefixes.size(); i++) {
        // for each char in prefixExpr
        for (int k = 0; k < prefixes.size(); k++) {
            
            tempChar = prefixes[i].at(k);
            
            
            
        }
        allPostFix.push_back(postFix);
        postFix = ""; // reset
        
        
    }
    
    for (int i= 0;i< allPostFix.size();i++) {
        cout << allPostFix[i];
        //        for (int k= 0;k< allPostFix[i].size();k++) {
        //            cout <<
        //        }
    }
    
    return allPostFix;
}



void prefix_to_postfix(string& prefix, string& postfix)
{
    //Convert the input prefix expression to postfix format
    
    postfix = prefix;   //initialize the postfix string to the same length of the         prefix string
    
    stack<stackItem> S;
    stackItem x;
    int k = 0;  //index for accessing char of the postfix string
    
    for (int i = 0; i < prefix.length(); i++)  //process each char in the prefix string from left to right
    {
        char c = prefix[i];
        
        if(prefix.length() == 1)
            break;
        
        //Implement the body of the for-loop
        if(isOperator(c))
        {
            x.symb = c;
            x.count = 0;
            S.push(x);
        }
        else
        {
            S.top().count++;
            postfix[k++] = c;
            
            if(S.top().count == 2)
            {
                postfix[k++] = S.top().symb;
                S.pop();
                S.top().count++;
            }
        }
        if(i == (prefix.length() - 1))
        {
            postfix[k++] = S.top().symb;
            S.pop();
        }
        
    }
}





int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));
    
    vector<string> mVect = {"+1*23"};
    prefixToPostfix(mVect);
    
    //    res = subarraySum(arr);
    //    fout << res;
    //
    //    fout.close();
    return 0;
}


