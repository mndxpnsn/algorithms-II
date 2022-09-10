//
//  main.cpp
//  jump-game-II
//
//  Created by mndx on 16/08/2022.
//

#include <iostream>
#include <vector>

using namespace std;

typedef struct memo_table {
    bool is_set;
    int val;
} m_table;

m_table * init_memo_table(int n) {
    m_table * table = new m_table[n + 1];
    for(int i = 0; i < n + 1; ++i) {
        table[i].is_set = false;
        table[i].val = 0;
    }
    
    return table;
}

void free_memo_table(m_table * dp) {
    delete [] dp;
}

int min(int a, int b) {
    int res = 0;
    if(a < b) { res = a; }
    else { res = b; }
    
    return res;
}

int min_jumps(int c, vector<int> & nums, m_table * dp) {
            
    int min_num_jumps = 3e8;
    int n = (int) nums.size();

    // End of array reached
    if(c > n - 2) {
        return 0;
    }
    
    // Get data from memo table if available
    if(dp[c].is_set) {
        return dp[c].val;
    }

    // Compute range
    int lim = nums[c];

    // Compute minimum number of jumps
    for(int i = 1; i <= lim; ++i) {
        min_num_jumps = min(min_num_jumps, 1 + min_jumps(i + c, nums, dp));
    }

    // Store data in memo table
    dp[c].is_set = true;
    dp[c].val = min_num_jumps;
    
    return min_num_jumps;
}

int jump(vector<int> & nums) {
    int res = 0;
    int n = (int) nums.size();
    
    // Initialize memo table
    m_table * dp = init_memo_table(n);
    
    // Compute minimum number of jumps
    res = min_jumps(0, nums, dp);
    
    // Free table
    free_memo_table(dp);
    
    return res;
}

int main(int argc, const char * argv[]) {

    // Input array
    vector<int> nums = {2, 3, 1, 1, 4};
    
    // Compute minimum number of jumps to reach the end
    int num_jumps = jump(nums);
    
    // Print results
    cout << "minimum number of jumps to reach the end: " << num_jumps << endl;
    
    return 0;
}
