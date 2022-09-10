class Solution {
    int max(int a, int b) {
        int res = 0;

        if(a > b) res = a;
        else res = b;

        return res;
    }

    int num_ways_rec(int[] nums, int k, int target, int[] dp) {

        int res = 0;

        int n = nums.length - 1;

        if(target < 0) {
            return 0;
        }

        if(target == 0 && k >= 2) {
            return 1;
        }

        if(target == 0 && k < 2) {
            return 0;
        }

        if(dp[target] != -1) {
            return dp[target];
        }

        for(int i = 1; i <= n; ++i) {
            int target_loc = target - nums[i];
            int prod = nums[i] * num_ways_rec(nums, k + 1, target_loc, dp);
            res = max(res, prod);
        }

        dp[target] = res;

        return res;
    }

    void init_dp(int[] dp, int target) {
        for(int i = 0; i < target; ++i) {
            dp[i] = -1;
        }
    }

    int num_ways(int[] nums, int target) {

        int n = nums.length - 1;

        int[] dp = new int[target + 1];

        init_dp(dp, target + 1);

        int k = 0;

        return num_ways_rec(nums, k, target, dp);
    }

    public int integer_break(int n) {
        int[] nums = new int[n + 1];

        for(int i = 1; i <= n; ++i) {
            nums[i] = i;
        }

        return num_ways(nums, n);
    }
}