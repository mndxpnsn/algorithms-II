class Solution {

    int getIndex(long[] nums, int i, int j) {

        int index = -1;

        int k = (i + j) / 2;

        if(nums[k - 1] < nums[k] && nums[k] > nums[k + 1]) {
            return k;
        }

        if(nums[k - 1] >= nums[k + 1]) {
            index = getIndex(nums, i, k);
        }

        if(nums[k - 1] < nums[k + 1]) {
            index = getIndex(nums, k + 1, j);
        }

        return index;
    }

    public int findPeakElement(int[] nums) {

        int n = nums.length;

        if(n == 1) {
            return 0;
        }

        long[] numsPadded = new long[n + 2];

        numsPadded[0] = Long.MIN_VALUE;
        numsPadded[n + 1] = Long.MIN_VALUE;

        for(int i = 1; i < n + 1; ++i) {
            numsPadded[i] = (long) nums[i - 1];
        }

        return getIndex(numsPadded, 1, n) - 1;
    }
}