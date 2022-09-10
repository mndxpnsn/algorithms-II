import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {

    void makeList(int[] ints, int i, String str, Map<Integer, String> hash, List<String> res) {

        int n = ints.length;

        if(str.length() > n) {
            return;
        }

        if(str.length() == n) {
            res.add(str);
            return;
        }

        String letters = hash.get(ints[i]);

        char[] chars = letters.toCharArray();

        int numLetters = chars.length;

        for(int j = 0; j < numLetters; ++j) {
            String strLoc = str + chars[j];
            makeList(ints, i + 1, strLoc, hash, res);
        }
    }

    public List<String> letterCombinations(String digits) {

        // Make mapping from digit to letters
        Map<Integer, String> hash = new HashMap<>();

        hash.put(2, "abc");
        hash.put(3, "def");
        hash.put(4, "ghi");
        hash.put(5, "jkl");
        hash.put(6, "mno");
        hash.put(7, "pqrs");
        hash.put(8, "tuv");
        hash.put(9, "wxyz");

        // Convert input string to chars
        char[] chars = digits.toCharArray();

        int n = chars.length;

        // Convert chars array to int array
        int[] ints = new int[n];

        for(int i = 0; i < n; ++i) {
            ints[i] = Character.getNumericValue(chars[i]);
        }

        List<String> res = new ArrayList<>();

        if(digits.equals("")) {
            return res;
        }

        makeList(ints, 0, "", hash, res);

        return res;
    }
}