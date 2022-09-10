//
//  main.cpp
//  longest-common-subsequence
//
//  Created by Derek Harrison on 21/08/2022.
//

#include <iostream>

typedef struct memo_table {
    bool is_set;
    int size;
} m_table;


int lcs(std::string & x, std::string & y, int jx, int jy, m_table ** memo_table) {

    int result = 0;

    //Compute longest common subsequence of substring
    if(jx > 0 && jy > 0) {

        //Get results from memo table if available
        if(memo_table[jx - 1][jy - 1].is_set) {
            return memo_table[jx - 1][jy - 1].size;
        }

        if(x[jx - 1] != y[jy - 1]) {
            int size1 = lcs(x, y, jx - 1, jy, memo_table);
            int size2 = lcs(x, y, jx, jy - 1, memo_table);

            if(size1 > size2) {
                result = result + size1;
            }
            else {
                result = result + size2;
            }
        }

        if(x[jx - 1] == y[jy - 1]) {
            result = result + 1;
            result = result + lcs(x, y, jx - 1, jy - 1, memo_table);
        }

        //Add results to memo table
        memo_table[jx - 1][jy - 1].is_set = true;
        memo_table[jx - 1][jy - 1].size = result;
    }

    return result;
}

int longest_common_subs(std::string & x, std::string & y) {
    int max_size = 0;
    int len1 = (int) x.length();
    int len2 = (int) y.length();

    //Compute max length input strings
    if(len1 < len2) {
        max_size = len2;
    }
    else {
        max_size = len1;
    }

    //Initialize memo table
    m_table** memo_table = new m_table*[max_size];
    for(int i = 0; i < max_size; ++i) {
        memo_table[i] = new m_table[max_size];
    }

    for(int i = 0; i < max_size; ++i) {
        for(int j = 0; j < max_size; ++j) {
            memo_table[i][j].is_set = false;
        }
    }

    //Compute longest common subsequence
    int longest_cs = lcs(x, y, len1, len2, memo_table);

    return longest_cs;
}

int longest_common_subsequence(std::string & text1, std::string & text2) {
    
    return longest_common_subs(text1, text2);
}

int main(int argc, const char * argv[]) {

    
    // Input strings
    std::string text1 = "abcde";
    std::string text2 = "ace";
    
    // Compute longest common subsequence length
    int len_lcs = longest_common_subsequence(text1, text2);
    
    // Print results
    std::cout << "length of longest common subsequence: " << len_lcs << std::endl;
    
    return 0;
}
