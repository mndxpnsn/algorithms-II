//
//  solution.cpp
//  40-combo-sum-II
//
//  Created by Derek Harrison on 10/09/2022.
//

#include <set>
#include <stdio.h>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
           
    void makeCombos(unordered_map<int, int> & hash, int target, int elem, vector<int> & perm, vector<int> & listElems, set<vector<int>> & list) {
        
        int n = (int) listElems.size();
        
        // Target missed or element out of range
        if(target < 0 || elem > n - 1) {
            return;
        }
        
        unordered_map<int, int> map;
        
        // Target hit
        if(target == 0) {
            list.insert(perm);
            return;
        }
        
        // Generate combinations
        for(int i = 0; i < n; ++i) {
            int sum = listElems[i];
            if(hash[listElems[i]] <= 0) {
                continue;
            }
            perm.push_back(listElems[i]);
            hash[listElems[i]]--;
            makeCombos(hash, target - sum, i, perm, listElems, list);
            hash[listElems[i]]++;
            perm.pop_back();
        }
    }
    
    bool theSame(vector<int> & v1, vector<int> & v2) {
        
        int n1 = (int) v1.size();
        int n2 = (int) v2.size();
        
        if(n1 != n2) {
            return false;
        }
        
        unordered_map<int, int> map1;
        unordered_map<int, int> map2;
        
        for(auto e : v1) {
            map1[e]++;
        }
        
        for(auto e : v2) {
            map2[e]++;
        }
        
        for(auto e : v1) {
            if(map1[e] != map2[e]) {
                return false;
            }
        }
        
        return true;
    }
    
    void makeSet(set<vector<int>> & list, vector<vector<int>> & res) {
        
        vector<vector<int>> vecLoc;
        for(auto li : list) {
            vecLoc.push_back(li);
        }
        
        // Remove duplicates
        int n = (int) vecLoc.size();
        
        unordered_map<int, int> hash;
        
        for(int i = 0; i < n; ++i) {
            hash[i]++;
            for(int j = i + 1; j < n; ++j) {
                if(theSame(vecLoc[i], vecLoc[j])) {
                    hash[j]++;
                }
            }
            if(hash[i] == 1) {
                res.push_back(vecLoc[i]);
            }
        }
    }
    
public:
    
    vector<vector<int>> combinationSum2(vector<int> & candidates, int target) {

        int n = (int) candidates.size();
        
        unordered_map<int, int> hash;
        set<int> hashSet;
        
        for(int i = 0; i < n; ++i) {
            hash[candidates[i]]++;
            hashSet.insert(candidates[i]);
        }
        
        vector<int> perm;
        set<vector<int>> list;
        vector<int> listElems;
        
        // Make list of unique elements
        for(auto e : hashSet) {
            listElems.push_back(e);
        }
          
        // Generate valid combinations
        makeCombos(hash, target, 0, perm, listElems, list);
        
        // Remove duplicates
        vector<vector<int>> res;
        
        makeSet(list, res);
        
        return res;
    }
};
