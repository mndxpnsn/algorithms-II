//
//  solution.cpp
//  90-subsets-II
//
//  Created by Derek Harrison on 10/09/2022.
//

#include <map>
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
    
    bool allSame(vector<int> & vec1, vector<int> & vec2) {
        
        int n1 = (int) vec1.size();
        int n2 = (int) vec2.size();
        
        if(n1 != n2) {
            return false;
        }
        
        map<int, int> hash1;
        map<int, int> hash2;
        
        for(auto e : vec1) {
            hash1[e]++;
        }
        
        for(auto e : vec2) {
            hash2[e]++;
        }
        
        for(auto e : vec1) {
            if(hash1[e] != hash2[e]) {
                return false;
            }
        }
        
        return true;
    }
    
    void removeDups(vector<vector<int>> & nums, vector<vector<int>> & set) {
        
        int n = (int) nums.size();
        
        map<int, int> hash;
        
        for(int i = 0; i < n; ++i) {
            hash[i] = 1;
        }
        
        for(int i = 0; i < n; ++i) {
            bool same = false;
            for(int j = i + 1; j < n; ++j) {
                same = allSame(nums[i], nums[j]);
                if(same) {
                    hash[j]++;
                }
            }
            
            if(hash[i] == 1) {
                set.push_back(nums[i]);
            }
        }
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int> & nums) {
        
        vector<vector<int>> res = subsets(nums);
        
        vector<vector<int>> set;
        
        removeDups(res, set);
        
        return set;
    }
};
