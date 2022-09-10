public class Main {
    public static void main(String[] args) {

        // Integer number input. Max input size is 58
        int n = 58;

        // Comput maximum sum product
        Solution sol_obj = new Solution();

        int max_sum_prod = sol_obj.integer_break(n);

        // Print results
        System.out.println("maximum sum product: " + max_sum_prod);
    }
}