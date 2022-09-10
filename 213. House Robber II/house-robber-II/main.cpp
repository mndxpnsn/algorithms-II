//
//  main.cpp
//  house-robber-II
//
//  Created by Derek Harrison on 21/08/2022.
//

#include <iostream>
#include <vector>

using namespace std;

int * dp1;
int * dp2;

void init_dp_tables(int n) {
    dp1 = new int[n + 1];
    dp2 = new int[n + 1];
    for(int i = 0; i < n + 1; ++i) {
        dp1[i] = -1;
        dp2[i] = -1;
    }
}

void delete_dp_tables(int n) {
    
    delete [] dp1;
    delete [] dp2;
}

int max(int a, int b) {
    int res = 0;
    
    if(a > b) { res = a; }
    else { res = b; }
    
    return res;
}

int rob_calc(int n, vector<int> & nums, int c, int * dp) {
    int loot = 0;
    
    // Only one house on the street
    if(n == 1) {
        return nums[0];
    }
    
    // Index out of bounds
    if(c >= n) {
        return 0;
    }
    
    // Get results from memo table if available
    if(dp[c] != -1) {
        return dp[c];
    }
          
    // Compute max loot
    if(c < n) {
        // Loot current house and skip neighbor
        int val1 = nums[c] + rob_calc(n, nums, c + 2, dp);
        // Skip current house
        int val2 =  rob_calc(n, nums, c + 1, dp);
        
        // Get max of choices
        loot = max(loot, val1);
        loot = max(loot, val2);
    }
    
    // Store results in memo table
    dp[c] = loot;
    
    return loot;
}

int rob(vector<int> & nums) {
    
    int n = (int) nums.size();
    
    // Initialize memo tables
    init_dp_tables(n);
    
    // Compute max loot if first house is considered for looting
    int val1 = rob_calc(n - 1, nums, 0, dp1);
    
    // Compute max loot if first house is not considered for looting
    int val2 = rob_calc(n, nums, 1, dp2);
    
    // Compute max loot
    int res = max(val1, val2);
    
    // Delete memo tables
    delete_dp_tables(n);
    
    return res;
}

int main(int argc, const char * argv[]) {

    // Stash array
    vector<int> nums = {1, 2, 3, 1};
    
    // Compute max loot
    int loot = rob(nums);
    
    // Print results
    cout << "max loot: " << loot << endl;
    
    return 0;
}
