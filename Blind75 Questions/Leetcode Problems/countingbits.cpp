#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
 * 
 */

/**
 * @brief Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

 

Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
 * 
 */

class Solution {
public:
    int hammingWeight(int val){
        int counter = 0;

        while (val > 0)
        {
            val = val&(val-1); //unset right most bit
            counter++;
        }
        

        return counter;
    }

    vector<int> countBits(int n) {
        vector<int> soln;

        for(int i = 0; i < n+1; i++){
            soln.push_back(hammingWeight(i));
        }

        return soln;
    }
};