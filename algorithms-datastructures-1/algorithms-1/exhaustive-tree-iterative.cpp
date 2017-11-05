#include <iostream>
#include <vector>
using namespace std;


// func prototypes
void allCombinations( vector<vector<string> > vectOfVectOfwords);
void printVectOfVect(vector<vector<string> > vectOfVectOfwords);

// exhaustive enumeration:

// START Algorithm:

//020 for list 3 am I at max? no add1
// 021
//for ...
// yes so reset and carry, cant carry, reset and carry to next..., not carried? all at max
// END Algorithm

//000 quick brown fox
//001 quick brown dog
//010 quick black fox
//011 quick black dog
//020 quick grey fox
//021 quick grey dog
//
//100 lazy brown fox
//110 lazy black fox
//111 lazy black dog
//120 lazy grey fox
//121 lazy grey dog
//
//
//for list 3 am I at max? no so add.
//yes so reset and carry
//
//for list 3 am I at max? no add1
//yes so reset and carry
//
//for ...
//yes so reset and carry, cant carry, reset and carry to next..., not carried? all at max <= Algorithm
//
//for list 3 am i at max? add1
//yes reset and carry ...

// =============================
// START MAIN
// =============================

int main() {
    
    // auto words = { "Hello, ", "World!", "\n" };
    // for (const string& word : words) {
    //   cout << word;
    // }
    
    // sample input
    vector<vector<string> > sampleVect = {{"quick", "lazy"}, {"brown", "black", "grey"}, {"fox", "dog"}};
    
    
    allCombinations(sampleVect);
    
    return 0;
}

// =============================
// END MAIN
// =============================

// =============================
// START FUNCTION DEFINITIONS
// =============================


void allCombinations( vector<vector<string> > vectOfVectOfwords) {
    
    // rename to indeciesMax. from example mVect will be: 121
    vector<int> mVect; //
    // get size of each vector
    for (int i = 0; i < vectOfVectOfwords.size(); i++) {
        mVect.push_back(vectOfVectOfwords[i].size() - 1);
    }
    
    
    int numCombinations = vectOfVectOfwords.size(); // ex. for vectofVect of size 3 we have 3 combinations
    
    
    // rename: (where we are currVector)
    vector<int> tempVect(numCombinations, 0); // index vector. 0 0 0
    
    string tempStr;
    
    // used to retireve index from indicies vector
    int indexFromVect;
    // keep track of indicies
    vector<int> indicesVect;
    
    
    for(int i = numCombinations - 1; i >= 0; i--) {
        
        // =======
        // START display
        
        // accumulate indices to display
        for(int j = 0; j < tempVect.size(); j++) {
            cout << tempVect[j];
            indicesVect.push_back(tempVect[j]);
        }
        
        // display
        // accumulate full combination of indices (done before this step), then for each vect display according index
        for(int indexV = 0; indexV < vectOfVectOfwords.size(); indexV++) {
            
            indexFromVect = indicesVect[indexV];
            
            if (indexV+1 != vectOfVectOfwords.size()) {
                // if not last element, add a space
                tempStr = vectOfVectOfwords[indexV][indexFromVect] + " ";
                cout << tempStr;
            } else {
                tempStr = vectOfVectOfwords[indexV][indexFromVect];
                cout << tempStr;
            }
        }
        cout << "\n";
        
        // END display
        // =======
        
        
        // this index is not at max, increment it
        if(tempVect[i] < mVect[i]) {
            
            // (where we are curr)tempVect: 000    (max)mVect: 121
            
            // not at max, increment it
            tempVect[i]+=1;
            i++; // keep on same index until carry
            
            // reset for display
            indicesVect.clear();
            
        }
        else { // this index is at max
            
            // START: reset, and if can carry then carry and then iterate again
            
            
            //ex. (021) index 2 at max - reset, carry to index 1, but index 1 at max - reset, carry to index 0
            
            bool carried = false;
            // all after i is at max, so start at k = i
            for (int k = i; k >= 0 && !carried; k--) {
                
                if(tempVect[k] < mVect[k]) {
                    // found where we are not at max. carry this one
                    tempVect[k] += 1;
                    carried = true;
                    
                } else {
                    // at max, reset. incrment k to see if we can to carry next, (if not we see if we can carry to next of that ...and so on)
                    tempVect[k] = 0;
                }
                
            }
            
            if (!carried) {
                // did not carry b/c all at max. Hence, displayed all combinations
                return;
            }
            
            i++; // stay on same
            
            // END: reset, and if can carry then carry and then iterate again
            
            // reset
            indicesVect.clear();
        }
        
    }
    
    return;
    
}


void printVectOfVect(vector<vector<string>> vectOfVectOfwords) {
    
    for (int i = 0; i < vectOfVectOfwords.size(); i++) {
        for (int j = 0; j < vectOfVectOfwords[i].size(); j++) {
            cout << vectOfVectOfwords[i][j];
        }
    }
    return;
    
}

// =============================
// END FUNCTION DEFINITIONS
// =============================

// PROBLEM:
/*
 You're given a vector of vectors of words, e.g.:
 [['quick', 'lazy'], ['brown', 'black', 'grey'], ['fox', 'dog']].
 
 Write a generalized function that prints all combinations of one word from the first vector, one word from the second vector, etc.
 The solution may not use recursion.
 NOTE: the number of vectors and number of elements within each vector may vary.
 
 For the input above, it should print (in any order):
 quick brown fox
 quick brown dog
 quick black fox
 quick black dog
 ...
 lazy grey dog
 */

//quick
//lazy
//brown
//black
//fox
//dog


// NON WORKING: acess index that is out of bounds:

/*

// func prototypes
void allCombinations( vector<vector<string> > vectOfVectOfwords);




// =============================
// START MAIN
// =============================
// To execute C++, please define "int main()"
int main() {
    
    // auto words = { "Hello, ", "World!", "\n" };
    // for (const string& word : words) {
    //   cout << word;
    // }
    
    // sample input
    vector<vector<string> > sampleVect = {{"quick", "lazy"}, {"brown", "black", "grey"}, {"fox", "dog"}};

    
    allCombinations(sampleVect);
    
    return 0;
}

// =============================
// END MAIN
// =============================

// =============================
// START FUNCTION DEFINITIONS
// =============================


void allCombinations( vector<vector<string> > vectOfVectOfwords) {
    
    // vector<vector<string> > resultVect;
    
    vector<int> mVect;
    
    // get size of each vector
    for (int i = 0; i < vectOfVectOfwords.size(); i++) {
        mVect.push_back(vectOfVectOfwords[i].size() - 1);
    }
    
    // from example. TODO: dynamically we get sizes of each vector
    //vector<int> mVect = {1,1,1};
    
    int numCombinations = vectOfVectOfwords.size(); // ex. for vectofVect of size 3 we have 3 combinations
    
    
    // take one value from each vector. on exhaust of all combinations, reset. until exhausted all
    
    // display root
    for(int i = 0; i < vectOfVectOfwords.size(); i++) {
        // for each vect display first value
        
        if (i+1 != vectOfVectOfwords.size()) {
            // if not last element, add a space
            cout << vectOfVectOfwords[i][0] + " ";
        } else {
            cout << vectOfVectOfwords[i][0];
        }
        
    }
    cout << "\n";
    
    vector<int> tempVect(numCombinations, 0);
    
    string tempStr;

    // used to retireve index from indicies vector
    int indexFromVect;
    // keep track of indicies
    vector<int> indicesVect;
    
    for(int i = numCombinations - 1; i >= 0; i--) {
        
        if(tempVect[i] < mVect[i]) {
            tempVect[i]+=1;
            i++; // keep on same index until carry
            
            // accumulate indices
            for(int j = 0; j < tempVect.size(); j++) {
                //cout << tempVect[j];
                indicesVect.push_back(tempVect[j]);
            }
            
            // display
            // accumulate full combination of indices, then for each vect display according index
            for(int indexV = 0; indexV < vectOfVectOfwords.size(); indexV++) {
                
                indexFromVect = indicesVect[indexV];

                if (indexV+1 != vectOfVectOfwords.size()) {
                    // if not last element, add a space
                    tempStr = vectOfVectOfwords[indexV][indexFromVect] + " ";
                    cout << tempStr;
                } else {
                    tempStr = vectOfVectOfwords[indexV][indexFromVect];
                    cout << tempStr;
                }
            }

            // reset
            indicesVect.clear();
            
            cout << "\n";
            i++;
            
        }
        else {
            // reset, since we will now cary over the addition
            // (i will be decremented (moving to the next index))
            
            tempVect[i] = 0;
            // reset
            indicesVect.clear();
        }
        
    }
    
    return;
    
}





 
 
 */





