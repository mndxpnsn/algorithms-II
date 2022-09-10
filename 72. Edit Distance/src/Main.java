public class Main {

    static int min(int a, int b, int c) {
        int res;

        if(a < b) res = a;
        else res = b;

        if(c < res) res = c;

        return res;
    }

    static int min_dist(String word1, String word2, int m1, int m2, int[][] dp) {

        int res = 0;

        if(word1.equals(word2)) {
            return 0;
        }

        if(m1 <= 0 && m2 > 0) {
            return m2;
        }

        if(m1 > 0 && m2 <= 0) {
            return m1;
        }

        if(dp[m1][m2] != -1) {
            return dp[m1][m2];
        }

        if(m1 > 0 && m2 > 0) {
            if(word1.charAt(m1 - 1) == word2.charAt(m2 - 1)) {
                res = min_dist(word1, word2, m1 - 1, m2 - 1, dp);
            }
            if(word1.charAt(m1 - 1) != word2.charAt(m2 - 1)) {
                int d = 1 + min_dist(word1, word2, m1 - 1, m2, dp);
                int r = 1 + min_dist(word1, word2, m1 - 1, m2 - 1, dp);
                int i = 1 + min_dist(word1, word2, m1, m2 - 1, dp);

                res = min(d, r, i);
            }
        }

        dp[m1][m2] = res;

        return res;
    }

    static void init_dp(int[][] dp, int m1, int m2) {

        for(int i = 0; i < m1; ++i) {
            for(int j = 0; j < m2; ++j) {
                dp[i][j] = -1;
            }
        }
    }

    static int min_distance(String word1, String word2) {

        int m1 = word1.length();
        int m2 = word2.length();

        int[][] dp = new int[m1 + 1][m2 + 1];

        init_dp(dp, m1 + 1, m2 + 1);

        return min_dist(word1, word2, m1, m2, dp);
    }

    public static void main(String[] args) {

        String word1 = "intention";
        String word2 = "execution";

        int min_d = min_distance(word1, word2);

        System.out.println("minimum edit distance: " + min_d);
    }
}