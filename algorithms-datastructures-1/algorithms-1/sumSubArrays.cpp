//
//  subArrSum.cpp
//  test
//
//  Created by Vlad Shostak on 10/30/17.
//  Copyright © 2017 Vlad Shostak. All rights reserved.
//

//
//  find-substring.cpp
//  test
//
//  Created by Vlad Shostak on 10/30/17.
//  Copyright © 2017 Vlad Shostak. All rights reserved.
//

#include <stdio.h>

#include <iostream>
#include <vector>
#include <string>
using namespace std;


/*
 * Complete the function below.
 */
long subarraySum(vector <int> arr) {
    
    // first elem is size
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << endl;
    }
    
    // sample arr: 1 1 1
    // {1}, {1}, {1}
    // {1, 1}, {1,1}
    
    // {1, 1, 1}
    
    // start  from index 0 to 0, 0 to 1, 0 to 2, ...
    // 1 to 1, ...
    // 2 to 2
    
    // sum of all subarrays
    long int totalSumOfSubArrays = 0;
    
    
    // Choose start index, end index
    // for those indecies, accumulate
    for(int startIndx = 0; startIndx < arr.size(); startIndx++) {
        
        // compute from indecies: 0to0, 0to1, 0to2,
        // 1to1, 1to2 ...
        
        for(int endIndx = startIndx; endIndx < arr.size(); endIndx++) {
            
            
            // accumulate
            for (int i = startIndx; i <= endIndx; i++) {
                totalSumOfSubArrays += arr[i];
            }
            
        }
        
    }
    cout << totalSumOfSubArrays;
    return totalSumOfSubArrays;
    
    
    
    
}



int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));
    
    vector<int> mVect = {1,1,1};
    subarraySum(mVect);
    
    //    res = subarraySum(arr);
    //    fout << res;
    //
    //    fout.close();
    return 0;
}

