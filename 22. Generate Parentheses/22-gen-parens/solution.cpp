//
//  solution.cpp
//  22-gen-parens
//
//  Created by Derek Harrison on 10/09/2022.
//

#include <set>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
    
    void genParens(int n, int m, string so, set<string>& store) {
        if(m < 2 * n) {
            string so_loc = "";
            so_loc = so + "(";
            genParens(n, m + 1, so_loc, store);
            so_loc = so + ")";
            genParens(n, m + 1, so_loc, store);
        }
        
        if(m == 2 * n) {
            store.insert(so);
        }
    }
    
    bool admissable_str(string str, int n) {
        bool str_is_admissable = true;
        int count_l_parens = 0;
        int count_r_parens = 0;
        
        for(int i = 0; i < n; ++i) {
            if(str[i] == '(') {
                count_l_parens++;
            }
            if(str[i] == ')') {
                count_r_parens++;
            }
            if(count_r_parens > count_l_parens) {
                str_is_admissable = false;
            }
        }
        
        if(count_r_parens != count_l_parens) {
            str_is_admissable = false;
        }
        
        return str_is_admissable;
    }
    
    set<string> admissable_set(set<string>& store, int n) {
        set<string> res;
        
        for(auto elem : store) {
            bool str_is_adm = admissable_str(elem, 2 * n);
            if(str_is_adm) {
                res.insert(elem);
            }
        }
        
        return res;
    }
        
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        set<string> store;
        
        if(n < 1) {
            return res;
        }
        
        genParens(n, 0, "", store);
        
        store = admissable_set(store, n);
        
        for(auto elem : store) {
            res.push_back(elem);
        }
        
        return res;
    }
};
