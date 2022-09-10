class Solution {

    int min_slice = 3;


    int num_slices_api(int[] nums) {

        int n = nums.length;

        int res = 0;

        for(int i = 0; i <= n - min_slice; ++i) {
            int diff = nums[i + 1] - nums[i];
            int slice = 1;
            for(int j = i + 1; j < n - 1 && diff == nums[j + 1] - nums[j]; ++j) {
                if(diff == nums[j + 1] - nums[j]) {
                    slice++;
                    if(slice >= 2) {
                        res++;
                    }
                }
            }
        }

        return res;
    }

    public int number_of_arithmetic_slices(int[] nums) {

        return num_slices_api(nums);
    }
}