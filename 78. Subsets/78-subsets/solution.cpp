//
//  solution.cpp
//  78-subsets
//
//  Created by Derek Harrison on 10/09/2022.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
    
    void makeSets(vector<int> & nums, int prev, vector<int> & grow, vector<vector<int>> & list) {
        
        int n = (int) nums.size();
        
        if(prev == n) {
            return;
        }
        
        for(int i = prev + 1; i <= n; ++i) {
            grow.push_back(i);
            list.push_back(grow);
            makeSets(nums, i, grow, list);
            grow.pop_back();
        }
    }
    
    void makeList(vector<int> & nums, vector<vector<int>> & list, vector<vector<int>> & listRes) {
        
        for(auto v : list) {
            vector<int> vecLoc;
            for(auto e : v) {
                vecLoc.push_back(nums[e - 1]);
            }
            listRes.push_back(vecLoc);
        }
    }
    
public:
    vector<vector<int>> subsets(vector<int> & nums) {
        
        // Make sets of unique indices
        vector<int> grow;
        
        vector<vector<int>> list;
        list.push_back(grow);
        
        makeSets(nums, 0, grow, list);
        
        // Convert list of indices to list of nums
        vector<vector<int>> res;
        
        makeList(nums, list, res);
        
        return res;
    }
};
