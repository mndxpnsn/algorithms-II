class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {

        int n = nums.length;

        int count = 0;

        for(int i = 0; i < n; ++i) {
            int prod = 1;
            int j = i;
            while(prod < k && j < n) {
                prod = prod * nums[j];
                if(prod < k) {
                    count++;
                }
                j++;
            }
        }

        return count;
    }
}