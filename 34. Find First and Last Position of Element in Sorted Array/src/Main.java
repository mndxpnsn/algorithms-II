public class Main {
    public static void main(String[] args) {

        // Input
        int[] nums = {5,7,7,8,8,10};

        int target = 8;

        // Compute first and last index
        Solution solObj = new Solution();

        int[] pos = solObj.searchRange(nums, target);

        // Print results
        System.out.println("pos[0]: " + pos[0]);
        System.out.println("pos[1]: " + pos[1]);
    }
}