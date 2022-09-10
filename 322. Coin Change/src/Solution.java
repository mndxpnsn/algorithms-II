import java.util.HashMap;
import java.util.Map;

class Solution {

    int LARGE_NUM = Integer.MAX_VALUE / 10;

    int min(int a, int b) {
        int res = 0;

        if(a == 0 && b > 0) {
            return b;
        }

        if(a > 0 && b == 0) {
            return a;
        }

        if(a < b) res = a;
        else res = b;

        return res;
    }

    int minCoin(int[] coins, int amount, Map<Integer, Integer> dp) {

        int n = coins.length;

        int res = LARGE_NUM;

        // Get results from memo table if available
        Integer elem = (Integer) dp.get(amount);
        if(elem != null) {
            return elem;
        }

        // Amount can be made from coins
        if(amount == 0) {
            return 0;
        }

        // Amount exceeded
        if(amount < 0) {
            return LARGE_NUM;
        }

        // Compute minimum number of coins to make amount
        for(int i = 0; i < n; ++i) {
            int resLoc = 1 + minCoin(coins, amount - coins[i], dp);
            res = min(res, resLoc);
        }

        // Store results in memo table
        dp.put(amount, res);

        return res;
    }

    public int coinChange(int[] coins, int amount) {

        // Memo table
        Map<Integer, Integer> dp = new HashMap<>();

        // Compute minimum number of coins to make amount
        int minCoins = minCoin(coins, amount, dp);

        return minCoins >= LARGE_NUM ? -1 : minCoins;
    }
}