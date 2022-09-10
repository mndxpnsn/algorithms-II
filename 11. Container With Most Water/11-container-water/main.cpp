//
//  main.cpp
//  11-container-water
//
//  Created by Derek Harrison on 10/09/2022.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int min_height(int h1, int h2) {

        int min_height;

        if(h1 < h2) { min_height = h1; }
        else { min_height = h2; }

        return min_height;
    }
    
    int min_index(std::vector<int>& height, int i, int j) {

        int result = 0;

        if(height[i] < height[j]) {
            result = i;
        }
        else {
            result = j;
        }

        return result;
    }
    
    int maxArea2(vector<int>& height) {
           int result = 0;
        int size_vec = (int) height.size();

        for(int i = 0; i < size_vec; ++i) {
            for(int j = i + 1; j < size_vec; ++j) {
                int min_size = min_height(height[i], height[j]);
                int del_x = (j - i);
                int area = min_size * del_x;
                if(area > result) {
                    result = area;
                }
            }
        }

        return result;
    }
    
    int maxArea(vector<int>& height) {
        int result = 0;
        int size_vec = (int) height.size();

        int left_index = 0;
        int right_index = size_vec - 1;

        int i = left_index;
        int j = right_index;

        while(i != j) {
            int height_container = min_height(height[i], height[j]);
            int area = height_container * (j - i);
            if(area > result) { result = area; }
            int min_height_index = min_index(height, i, j);
            if(min_height_index == j) { --j; }
            else { ++i; }
        }

        return result;
    }
    
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
