class Solution {

    int min(int a, int b) {
        int res = 0;

        if(a <= 0 && b > 0) {
            return b;
        }

        if(a > 0 && b <= 0) {
            return a;
        }

        if(a < b) res = a;
        else res = b;

        return res;
    }

    int minEdits(char[] chars1, char[] chars2, int j1, int j2, int[][] dp) {

        int n1 = chars1.length;
        int n2 = chars2.length;

        int numEdits = 0;

        if(j1 < 0 || j2 < 0) {
            return 0;
        }

        if(j1 == 0 && j2 > 0) {
            if(chars1[j1] == chars2[j2]) {
                return j2;
            }
            if(chars1[j1] != chars2[j2]) {
                int val = 1 + minEdits(chars1, chars2, j1, j2 - 1, dp);
                numEdits = min(numEdits, val);
                return numEdits;
            }
        }

        if(j1 > 0 && j2 == 0) {
            if(chars1[j1] == chars2[j2]) {
                return j1;
            }
            if(chars1[j1] != chars2[j2]) {
                int val = 1 + minEdits(chars1, chars2, j1 - 1, j2, dp);
                numEdits = min(numEdits, val);
                return numEdits;
            }
        }

        if(j1 == 0 && j2 == 0) {
            if(chars1[j1] != chars2[j2]) {
                return 2;
            }
            else {
                return 0;
            }
        }

        if(dp[j1][j2] != 0) {
            return dp[j1][j2];
        }

        if(chars1[j1] != chars2[j2]) {
            int val1 = 1 + minEdits(chars1, chars2, j1 - 1, j2, dp);
            int val2 = 1 + minEdits(chars1, chars2, j1, j2 - 1, dp);
            numEdits = min(numEdits, val1);
            numEdits = min(numEdits, val2);
        }
        if(chars1[j1] == chars2[j2]) {
            numEdits = min(numEdits, minEdits(chars1, chars2, j1 - 1, j2 - 1, dp));
        }

        dp[j1][j2] = numEdits;

        return numEdits;
    }

    public int minDistance(String word1, String word2) {

        char[] chars1 = word1.toCharArray();
        char[] chars2 = word2.toCharArray();

        int j1 = chars1.length;
        int j2 = chars2.length;

        int[][] dp = new int[j1 + 1][j2 + 1];

        return minEdits(chars1, chars2, j1 - 1, j2 - 1, dp);
    }
}