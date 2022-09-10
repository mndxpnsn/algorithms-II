public class Main {
    public static void main(String[] args) {

        // Input array
        int[] nums = {1, 2, 3, 1};

        // Compute peak element index
        Solution solObj = new Solution();

        int index = solObj.findPeakElement(nums);

        // Print results
        System.out.println("index of peak element: " + index);
    }
}