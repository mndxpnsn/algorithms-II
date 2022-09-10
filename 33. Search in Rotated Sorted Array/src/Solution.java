class Solution {


    public int search(int[] nums, int target) {

        int n = nums.length;

        if(n == 0) {
            return -1;
        }

        int index = 0;
        while(index < n - 1 && nums[index] != target) {
            index++;
        }

        return nums[index] == target ? index : -1;
    }
}