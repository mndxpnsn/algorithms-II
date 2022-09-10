//
//  solution.hpp
//  15-3Sum
//
//  Created by mndx on 10/09/2022.
//

#ifndef solution_hpp
#define solution_hpp

#include <map>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    
    const int inf = 3e+8;

    void merge(std::vector<int>& arr, int i, int k, int j) {

        int n1 = k - i + 1;
        int n2 = j - k;
        int* arr1 = new int[n1 + 1];
        int* arr2 = new int[n2 + 1];
        int arr_index = i;
        for(int arr1_index = 0; arr1_index < n1; ++arr1_index) {
            arr1[arr1_index] = arr[arr_index];
            arr_index++;
        }

        for(int arr2_index = 0; arr2_index < n2; ++arr2_index) {
            arr2[arr2_index] = arr[arr_index];
            arr_index++;
        }

        arr1[n1] = inf;
        arr2[n2] = inf;

        int arr1_index = 0;
        int arr2_index = 0;
        for(int arr_index = i; arr_index <= j; ++arr_index) {
            if(arr1[arr1_index] >= arr2[arr2_index]) {
                arr[arr_index] = arr2[arr2_index];
                arr2_index++;
            }
            else {
                arr[arr_index] = arr1[arr1_index];
                arr1_index++;
            }
        }

        //Free data
        delete [] arr1;
        delete [] arr2;
    }

    void merge_sort(std::vector<int>& arr, int i, int j) {

        if(j - i > 0) {
            int k = (i + j) / 2;
            merge_sort(arr, i, k);
            merge_sort(arr, k + 1, j);
            merge(arr, i, k, j);
        }
    }

    void merge_sort_wrap(std::vector<int>& input_arr) {

        int n = (int) input_arr.size();

        //Perform sort
        merge_sort(input_arr, 0, n - 1);
    }

    bool bin_search(std::vector<int>& nums, int p, int m, int i, int j, int targ) {
        bool result = false;

        if(p == m) {
            if(nums[p] == targ && p != i && p != j) {
                return true;
            }
        }

        if(m - p > 0) {
            int k = (p + m) / 2;
            bool targ_left = targ <= nums[k];
            if(targ_left) {
                result = bin_search(nums, p, k, i, j, targ);
                if(result == true) { return true; }
            }
            else {
                result = bin_search(nums, k + 1, m, i, j, targ);
                if(result == true) { return true; }
            }
        }

        return result;
    }

    std::vector< std::vector<int> > threeSum(std::vector<int>& nums) {
        std::vector< std::vector<int> > all_triplets;
        std::map<std::string, bool> dup_check;
        vector<int> arr;
        
        int n = (int) nums.size();
        
        if(n > 0) {
            //Contract array
            std::map<std::string, bool> mult_check;
            std::map<std::string, int> num_elem_map;
            for(int i = 0; i < n; ++i) {
                std::string num_str = std::to_string(nums[i]);
                if(mult_check[num_str] == false) {
                    num_elem_map[num_str] = 1;
                    mult_check[num_str] = true;
                }
                if(mult_check[num_str] == true) {
                    num_elem_map[num_str] = num_elem_map[num_str] + 1;
                    mult_check[num_str] = true;
                }
                if(num_elem_map[num_str] < 5) {
                    arr.push_back(nums[i]);
                }
            }
            
            //Update array to contracted array
            nums = arr;
        }

        //Sort array
        merge_sort_wrap(nums);

        //Check for triplets satisfying requirements
        n = (int) nums.size();
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                int sum_loc = nums[i] + nums[j];
                bool targ_match = bin_search(nums, 0, n - 1, i, j, -sum_loc);
                if(targ_match) {
                    std::vector<int> res_elem;
                    res_elem.push_back(nums[i]);
                    res_elem.push_back(nums[j]);
                    res_elem.push_back(-sum_loc);
                    
                    //Sort array
                    merge_sort_wrap(res_elem);
                    std::string str1 = std::to_string(res_elem[0]);
                    std::string str2 = std::to_string(res_elem[1]);
                    std::string str3 = std::to_string(res_elem[2]);
                    std::string str = str1 + str2 + str3;
                    if(!dup_check[str]) {
                        all_triplets.push_back(res_elem);
                        dup_check[str] = true;
                    }
                }
            }
        }

        return all_triplets;
    }
};

#endif /* solution_hpp */
