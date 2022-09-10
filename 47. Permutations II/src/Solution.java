import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Solution {

    void makePerm(int[] nums, boolean[] visited, ArrayList<Integer> perm, Set<ArrayList<Integer>> list) {

        int n = nums.length;

        if(perm.size() == n) {
            ArrayList<Integer> listLoc = new ArrayList<>();
            for(var e : perm) {
                listLoc.add(nums[e]);
            }
            list.add(listLoc);
            return;
        }

        for(int e = 0; e < n; ++e) {
            if(!visited[e]) {
                visited[e] = true;
                perm.add(e);
                makePerm(nums, visited, perm, list);
                visited[e] = false;
                perm.remove(Integer.valueOf(e));
            }
        }
    }

    public List<List<Integer>> permuteUnique(int[] nums) {

        int n = nums.length;

        boolean[] visited = new boolean[n];

        ArrayList<Integer> perm = new ArrayList<>();
        Set<ArrayList<Integer>> list = new HashSet<>();

        makePerm(nums, visited, perm, list);

        List<List<Integer>> set = new ArrayList<>(list);

        return set;
    }
}