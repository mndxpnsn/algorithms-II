//
//  main.cpp
//  jump-game
//
//  Created by Derek Harrison on 16/08/2022.
//

#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b) {
    int res = 0;
    
    if(a > b) res = a;
    else res = b;
    
    return res;
}

bool can_jump(vector<int> & nums) {
    
    int n = (int) nums.size();
    
    bool res = true;
    
    // Initial range
    int range = nums[0];
    
    // Case single element
    if(n == 1) {
        return true;
    }
    
    // Compute if end is within range
    for(int i = 0; i < n; ++i) {
        range = max(range, nums[i] + i);
        if(range == i && range < n - 1) {
            return false;
        }
    }

    return res;
}

int main(int argc, const char * argv[]) {
    
    // Input array
    vector<int> nums = {2, 3, 1, 1, 4};
    
    // Compute if end of array is reachable
    bool is_reachable = can_jump(nums);
    
    // Print results
    cout << "the end of array is reachable: " << is_reachable << endl;
    
    return 0;
}
