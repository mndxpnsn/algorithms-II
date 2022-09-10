public class Main {
    public static void main(String[] args) {

        // Initialize point coordinates
        int[][] points = {{5151,5150},{0,0},{5152,5151}};

        // Compute max number of points on a line
        Solution solObj = new Solution();

        int numPoints = solObj.maxPoints(points);

        // Print results
        System.out.println("max number of points on a line: " + numPoints);
    }
}