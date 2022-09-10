import java.util.ArrayList;
import java.util.List;

class Solution {

    void makeCombos(int[] candidates, int target, int prev, List<Integer> combo, List<List<Integer>> list) {

        int n = candidates.length;

        if(target < 0) {
            return;
        }

        if(target == 0) {
            list.add(combo);
            return;
        }

        for(int i = 0; i < n; ++i) {
            if(candidates[i] >= prev) {
                int targetLoc = target - candidates[i];
                List<Integer> comboLoc = new ArrayList<>(combo);
                comboLoc.add(candidates[i]);
                makeCombos(candidates, targetLoc, candidates[i], comboLoc, list);
            }
        }
    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {

        List<List<Integer>> combos = new ArrayList<>();
        List<Integer> combo = new ArrayList<>();

        makeCombos(candidates, target, 0, combo, combos);

        return combos;
    }
}