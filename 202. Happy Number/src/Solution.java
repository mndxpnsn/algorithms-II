class Solution {

    boolean isHappyRec(int n) {
        String str = Integer.toString(n);

        char[] chars = str.toCharArray();

        int len = chars.length;

        int[] ints = new int[len];

        for(int i = 0; i < len; ++i) {
            ints[i] = Character.getNumericValue(chars[i]);
        }

        int sum = 0;

        for(var e : ints) {
            sum = sum + e * e;
        }

        if(sum == 4) {
            return false;
        }

        if(sum == 1) {
            return true;
        }

        return isHappyRec(sum);
    }

    public boolean isHappy(int n) {

        return isHappyRec(n);
    }
}