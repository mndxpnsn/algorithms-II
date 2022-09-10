import java.util.ArrayList;
import java.util.List;

class Solution {

    int max(int a, int b) {
        int res = 0;

        if(a > b) res = a;
        else res = b;

        return res;
    }

    int min(int a, int b) {
        int res = 0;

        if(a < b) res = a;
        else res = b;

        return res;
    }

    public int[][] intervalIntersection(int[][] firstList, int[][] secondList) {

        List<List<Integer>> list = new ArrayList<>();

        int n1 = firstList.length;
        int n2 = secondList.length;

        if(n1 == 0 || n2 == 0) {
            return new int[0][0];
        }

        for(var v : firstList) {
            int endV = v[1];
            int startS = 0;
            while(startS < secondList.length && secondList[startS][0] <= endV) {
                int minVal = max(v[0], secondList[startS][0]);
                int maxVal = min(v[1], secondList[startS][1]);
                if(maxVal - minVal >= 0) {
                    List<Integer> listLoc = new ArrayList<>();
                    listLoc.add(minVal);
                    listLoc.add(maxVal);
                    list.add(listLoc);
                }
                startS++;
            }
        }

        int n = list.size();

        int[][] res = new int[n][2];

        int index = 0;
        for(var e : list) {
            res[index][0] = e.get(0);
            res[index][1] = e.get(1);
            index++;
        }

        return res;
    }
}