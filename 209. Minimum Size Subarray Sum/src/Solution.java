class Solution {

    int LARGE = Integer.MAX_VALUE;

    int min(int a, int b) {
        int res = 0;

        if(a < b) res = a;
        else res = b;

        return res;
    }

    public int minSubArrayLen(int target, int[] nums) {

        int n = nums.length;

        int leftP = 0;
        int rightPS = 0;
        int minLen = n;

        int sum = 0;

        for(int rightP = 0; rightP < n; ++rightP) {
            sum = sum + nums[rightP];
            if(sum >= target) {
                rightPS = rightP;
                while(sum - nums[leftP] >= target) {
                    sum = sum - nums[leftP];
                    leftP++;
                }
                minLen = min(minLen, rightP - leftP + 1);
            }
        }

        if(sum < target && minLen == n) {
            minLen = 0;
        }

        return minLen;
    }
}