class Solution {

    int findPoint(int[] nums, int i, int j) {

        int point = -1;

        if(i == j - 1) {
            return nums[j] < nums[i] ? nums[j] : nums[i];
        }

        int k = (i + j) / 2;
        boolean inRightHalf = nums[j] < nums[k];

        if(inRightHalf) {
            point = findPoint(nums, k, j);
        }

        if(!inRightHalf) {
            point = findPoint(nums, i, k);
        }

        return point;
    }

    public int findMin(int[] nums) {

        int n = nums.length;

        if(n == 1) {
            return nums[0];
        }

        return findPoint(nums, 0, n - 1);
    }
}