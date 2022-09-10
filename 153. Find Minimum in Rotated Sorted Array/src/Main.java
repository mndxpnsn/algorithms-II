public class Main {
    public static void main(String[] args) {

        // Input array
        int[] nums = {3,4,5,1,2};

        // Compute minimum point
        Solution solObj = new Solution();

        int min = solObj.findMin(nums);

        // Print results
        System.out.println("minimum element: " + min);
    }
}