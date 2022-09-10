public class Main {
    public static void main(String[] args) {

        // Input array
        int[] nums = {1, 2, 3, 4};

        // Compute number of arithmetic slices
        Solution sol_obj = new Solution();

        int num_slices = sol_obj.number_of_arithmetic_slices(nums);

        // Print results
        System.out.println("number of arithmetic slices: " + num_slices);
    }
}