class Solution {

    int getIndex(int[] nums, int target, int i, int j) {

        int index = -1;

        int n = nums.length;

        // Nums is empty
        if(n == 0) {
            return -1;
        }

        // Search space closed
        if(i == j) {
            return nums[i] == target ? i : -1;
        }

        // Cut array in two
        int k = (i + j) / 2;
        int cut = nums[k];

        // Check if target is among input indices
        if(target == nums[i]) {
            return i;
        }
        if(target == nums[k]) {
            return k;
        }
        if(target == nums[j]) {
            return j;
        }

        // Compute index of target
        if(target <= cut) {
            index = getIndex(nums, target, i, k);
        }
        if(target > cut) {
            index = getIndex(nums, target, k + 1, j);
        }

        return index;
    }

    public int[] searchRange(int[] nums, int target) {

        int[] res = new int[2];

        int n = nums.length;

        // Get index of target. If not found index = -1
        int index = getIndex(nums, target, 0, n - 1);

        if(index == -1) {
            res[0] = -1;
            res[1] = -1;
            return res;
        }

        int leftIndex = index;
        int rightIndex = index;

        while(leftIndex >= 0 && nums[leftIndex] == target) {
            leftIndex--;
        }
        leftIndex++;

        while(rightIndex < n && nums[rightIndex] == target) {
            rightIndex++;
        }
        rightIndex--;

        res[0] = leftIndex;
        res[1] = rightIndex;

        return res;
    }
}