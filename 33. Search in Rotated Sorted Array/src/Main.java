public class Main {
    public static void main(String[] args) {

        // Input
        int[] nums = {4,5,6,7,0,1,2};

        int target = 0;

        // Compute target index
        Solution solObj = new Solution();

        int index = solObj.search(nums, target);

        // Print results
        System.out.println("index: " + index);
    }
}