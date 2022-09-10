//
//  main.cpp
//  word-break
//
//  Created by Derek Harrison on 15/08/2022.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct memo_table {
    bool is_set = false;
    bool val;
} m_table;

m_table * get_dp_table(int n) {
    
    m_table * dp = new m_table[n + 1];
    
    for(int i = 0; i < n + 1; ++i) {
        dp[i].is_set = false;
        dp[i].val = false;
    }
    
    return dp;
}

void delete_dp_table(m_table * dp) {
    delete [] dp;
}

bool word_in_dict(string s, vector<string> & dict) {
    bool res = false;
    
    for(auto e : dict) {
        if(e == s) {
            res = true;
        }
    }
    
    return res;
}

bool word_break_rec(string & s, vector<string> & w, int cut, int n, m_table * dp) {

    bool res = false;
    
    // Get data from memo table if available
    if(dp[cut].is_set) {
        return dp[cut].val;
    }
    
    // Check if string can be split into words in w
    for(int i = cut + 1; i <= n; ++i) {
        string s_loc = s.substr(cut, i - cut);
        bool in_dict = word_in_dict(s_loc, w);
        if(in_dict) {
            // If at the end of the string return true
            if(i == n) {
                return true;
            }
            // Check if remaining substring can be split
            res = word_break_rec(s, w, i, n, dp);
            // If string can be split, stop computation
            if(res) {
                return true;
            }
        }
    }
    
    // Store data in memo table
    dp[cut].is_set = true;
    dp[cut].val = res;
    
    return res;
}

bool word_break(string & s, vector<string> & word_dict) {
    
    int n = (int) s.length();
    
    // Get memo table
    m_table * dp = get_dp_table(n);
    
    bool can_split = word_break_rec(s, word_dict, 0, n, dp);
    
    delete_dp_table(dp);
    
    return can_split;
}

bool word_break_api(string s, vector<string> & word_dict) {
    
    return word_break(s, word_dict);
}

int main(int argc, const char * argv[]) {

    // Word
    string word = "leetcode";
    
    // Word dictionary
    vector<string> word_dict = {"leet", "code"};
    
    // Compute if word can be split into words in word_dict
    bool can_split = word_break_api(word, word_dict);
    
    // Print results
    cout << "String can be split: " << can_split << endl;
    
    return 0;
}
