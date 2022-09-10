//
//  solution.cpp
//  384-shuffle
//
//  Created by Derek Harrison on 10/09/2022.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
    
    vector<int> numsStore;
    
public:
    Solution(vector<int> & nums) {
        this->numsStore = nums;
    }
    
    vector<int> reset() {
        return numsStore;
    }
    
    vector<int> shuffle() {
        
        int n = (int) this->numsStore.size();
        vector<int> vec;
        while(vec.size() < n){
            int r = rand() % n + 1;
            bool hit = false;
            for(auto e : vec) {
                if(r == e) {
                    hit = true;
                }
            }
            if(!hit) {
                vec.push_back(r);
            }
        }
        
        vector<int> res;
        
        for(auto e : vec) {
            res.push_back(numsStore[e - 1]);
        }
        
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
