//
//  solution.cpp
//  673-number-LIS
//
//  Created by Derek Harrison on 10/09/2022.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {

    int ** dp;
    int ** dp2;
    
    int len_max;
    
    void init_dp(int n) {
        dp = new int * [n];
        for(int i = 0; i < n; ++i) {
            dp[i] = new int[n];
            for(int j = 0; j < n; ++j) {
                dp[i][j] = -1;
            }
        }
    }
    
    void init_dp2(int n) {
        dp2 = new int * [n];
        for(int i = 0; i < n; ++i) {
            dp2[i] = new int[n];
            for(int j = 0; j < n; ++j) {
                dp2[i][j] = -1;
            }
        }
    }
    
    int max(int a, int b) {
        int res = 0;
        
        if(a > b) res = a;
        else res = b;
        
        return res;
    }
    
    int len_rec_ref(vector<int> & nums, int d, int prev_d) {
        int n = (int) nums.size();
        
        int len = 0;
        
        if(dp[d][prev_d + 1] != -1) {
            return dp[d][prev_d + 1];
        }
        
        if(d < n) {
            int sum1 = 0;
            if(prev_d == -1 || nums[d] > nums[prev_d]) {
                sum1 = 1 + len_rec_ref(nums, d + 1, d);
            }
            int sum2 = len_rec_ref(nums, d + 1, prev_d);
            
            len = max(sum1, sum2);
        }
        
        if(d > n - 1) {
            return 0;
        }
        
        dp[d][prev_d + 1] = len;
        
        return len;
    }
    
    int lengthOfLIS(vector<int> & nums) {

        init_dp((int) nums.size() + 1);
        
        return len_rec_ref(nums, 0, -1);
    }
    
    int numOfLIS(vector<int> & nums, int lenSeq, int i, int prev_i, int count) {
        
        int res = 0;
        
        int n = (int) nums.size();
        
        if(count == lenSeq) {
            return 1;
        }
        
        if(count > lenSeq || i > n - 1) {
            return 0;
        }
        
        if(prev_i == -1 || nums[i] > nums[prev_i]) {
            res = numOfLIS(nums, lenSeq, i + 1, i, count + 1);
        }
        
        res = res + numOfLIS(nums, lenSeq, i + 1, prev_i, count);
        
        return res;
    }
    
    int numOfLIS2(vector<int> & nums, int lenSeq, int i, int prev_i, int count) {
        
        int res = 0;
        
        int n = (int) nums.size();
        
        if(count == lenSeq) {
            return 1;
        }
        
        if(count > lenSeq || i > n - 1) {
            return 0;
        }
        
        if(dp2[prev_i + 1][count] != -1) {
            return dp2[prev_i + 1][count];
        }
        
        if(prev_i == -1 || nums[i] > nums[prev_i]) {
            res = numOfLIS2(nums, lenSeq, i + 1, i, count + 1);
        }
        
        res = res + numOfLIS2(nums, lenSeq, i + 1, prev_i, count);
        
        dp2[prev_i + 1][count] = res;
        
        return res;
    }
    
    bool allStrict(vector<int> & nums) {
        
        int n = (int) nums.size();
        
        for(int i = 1; i < n; ++i) {
            if(nums[i] <= nums[i - 1]) {
                return false;
            }
        }
        
        return true;
    }
    
    bool allSame(vector<int> & nums) {
        
        int n = (int) nums.size();
        
        int val = nums[0];
        
        for(int i = 0; i < n; ++i) {
            if(val != nums[i]) {
                return false;
            }
        }
        
        return true;
    }
    
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int len = lengthOfLIS(nums);
        
        init_dp2((int) nums.size() + 1);
        
        if(allStrict(nums)) {
            return 1;
        }
        
        if(allSame(nums)) {
            return (int) nums.size();
        }
        
        return numOfLIS2(nums, len, 0, -1, 0);
    }
};
