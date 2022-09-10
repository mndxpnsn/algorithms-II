//
//  main.cpp
//  decode-ways
//
//  Created by Derek Harrison on 16/08/2022.
//

#include <iostream>
#include <string>

using namespace std;

int num_ways(string s, int i, int * dp) {
    
    int res = 0;
    
    int n = (int) s.length();
    
    // If end of array reached return 1
    if(i == n) {
        return 1;
    }
    
    // Get data from memo table if available
    if(dp[i] != -1) {
        return dp[i];
    }
    
    // Compute number of ways to decode if substring of size 1 is chosen
    if(i < n) {
        string s_loc = s.substr(i, 1);
        int val = stoi(s_loc);
        if(1 <= val && val <= 26) {
            if(s[i] == '0') {
                res = 0;
            }
            if(s[i] != '0') {
                res = num_ways(s, i + 1, dp);
            }
        }
    }
    
    // Compute number of ways to decode if substring of size 2 is chosen
    if(i < n - 1) {
        string s_loc = s.substr(i, 2);
        int val = stoi(s_loc);
        if(1 <= val && val <= 26) {
            if(s[i] == '0') {
                res = 0;
            }
            if(s[i] != '0') {
                res = res + num_ways(s, i + 2, dp);
            }
        }
    }
    
    // Store results in memo table
    dp[i] = res;
    
    return res;
}

int * get_dp_table(int n) {
    int * dp = new int[n];
    for(int i = 0; i < n; ++i) {
        dp[i] = -1;
    }
    
    return dp;
}

void free_dp_table(int * dp) {
    delete [] dp;
}

int num_ways_api(string s) {
    
    int n = (int) s.length();
    
    // Initialize memot table
    int * dp = get_dp_table(n);
    
    // Compute number of decodings
    int num_dec = num_ways(s, 0, dp);
    
    // Free memo table
    free_dp_table(dp);
    
    return num_dec;
}

int num_decodings(string s) {
 
    return num_ways_api(s);
}

int main(int argc, const char * argv[]) {

    // Input string
    string s = "226";
    
    // Compute number of ways to decode string:
    int number_decodings = num_decodings(s);
    
    // Print results
    cout << "number of decodings: " << number_decodings << endl;
    
    return 0;
}
