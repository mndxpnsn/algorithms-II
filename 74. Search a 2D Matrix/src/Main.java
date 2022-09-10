public class Main {
    public static void main(String[] args) {

        // Input
        int[][] matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};

        int target = 3;

        // Check whether target is in matrix
        Solution solObj = new Solution();

        boolean hitTarget = solObj.searchMatrix(matrix, target);

        // Print results
        System.out.println("Target found: " + hitTarget);
    }
}