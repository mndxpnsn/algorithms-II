//
//  main.cpp
//  unique-paths
//
//  Created by Derek Harrison on 21/08/2022.
//

#include <iostream>

const int MAX = 101;

int dp[MAX][MAX];

void init_dp() {
    for(int i = 0; i < MAX; ++i) {
        for(int j = 0; j < MAX; ++j) {
            dp[i][j] = 0;
        }
    }
}

int unique_paths_rec(int m, int n) {
    int num_paths = 0;
    
    if(dp[m][n] != 0) {
        return dp[m][n];
    }
    
    if(m == 1 || n == 1) {
        return 1;
    }
    
    num_paths = unique_paths_rec(m - 1, n) + unique_paths_rec(m, n - 1);
    
    dp[m][n] = num_paths;
    
    return num_paths;
}

int unique_paths(int m, int n) {
    
    init_dp();
    
    return unique_paths_rec(m, n);
}

int main(int argc, const char * argv[]) {

    // Dimensions of the grid
    int m = 3;
    int n = 7;
    
    // Compute number of unique paths
    int num_unique = unique_paths(m, n);
    
    // Print results
    std::cout << "number of unique paths: " << num_unique << std::endl;
    
    return 0;
}
