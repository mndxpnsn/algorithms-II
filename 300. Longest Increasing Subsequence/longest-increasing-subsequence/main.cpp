//
//  main.cpp
//  longest-increasing-subsequence
//
//  Created by Derek Harrison on 21/08/2022.
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int MAX = 2502;

int dp[MAX][MAX];

int len_max;

void init_dp() {
    for(int i = 0; i < MAX; ++i) {
        for(int j = 0; j < MAX; ++j) {
            dp[i][j] = -1;
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

int length_of_LIS(vector<int> & nums) {

    init_dp();
    
    return len_rec_ref(nums, 0, -1);
}


int main(int argc, const char * argv[]) {

    // Input array
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    
    // Compute the length of the longest increasing subsequence
    int lis_len = length_of_LIS(nums);
    
    // Print results
    cout << "length of longest increasing subsequence: " << lis_len << endl;
    
    return 0;
}
