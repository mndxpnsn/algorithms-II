import java.util.HashMap;
import java.util.Map;
import java.util.Random;

public class Main {

    static void initArray(int[] arr) {

        int n = arr.length;

        for(int i = 0; i < n; ++i) {
            Random r = new Random();
            int min = 1;
            int max = 300;

            int rand_val = min + r.nextInt(max);
            arr[i] = rand_val;
        }
    }

    public static void main(String[] args) {

        // Number of coins
        int n = 10;

        // Declare and initialize coins array
        int[] coins = new int[n];

        initArray(coins);

        // Target amount
        int amount = 3000;

        // Compute minimum number of coins required
        Solution solObj = new Solution();

        int numCoins = solObj.coinChange(coins, amount);

        // Print results
        System.out.println("number of coins: " + numCoins);
    }
}
