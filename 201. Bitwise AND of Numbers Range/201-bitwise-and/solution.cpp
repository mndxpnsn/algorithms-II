//
//  solution.cpp
//  201-bitwise-and
//
//  Created by Derek Harrison on 10/09/2022.
//

#include <stdio.h>

class Solution {

public:
    int rangeBitwiseAnd(int left, int right) {
        
        if(left == right) {
            return left;
        }
        
        int leadL = left / 2;
        int leadR = right / 2;
        
        if(leadL != 0 && leadR / leadL > 1) {
            return 0;
        }

        int res = left;
        
        for(long i = left; res != 0 && i <= right; ++i) {
            res = (int) (res & i);
        }
        
        return res;
    }
};
