class Solution {

    int binSearchVert(int[][] mat, int j0, int j1, int target) {

        int row = 0;

        // Return row (or the row below row) which contains target
        if(j0 == j1) {
            return j0;
        }

        // Cut search space
        int k = (j0 + j1) / 2;
        int cut = mat[k][0];

        // Case target is below cut
        if(target <= cut) {
            row = binSearchVert(mat, j0, k, target);
        }
        // Case target is above cut
        else {
            row = binSearchVert(mat, k + 1, j1, target);
        }

        return row;
    }

    boolean binSearchHori(int[][] mat, int row, int i0, int i1, int target) {

        boolean res = false;

        // Row index out of bounds
        if(row < 0) {
            return false;
        }

        // Search space is closed
        if(i0 == i1) {
            return mat[row][i0] == target;
        }

        // Cut search space
        int k = (i0 + i1) / 2;
        int cut = mat[row][k];

        // Check if target can be made from input indices
        if(mat[row][i0] == target || mat[row][i1] == target || cut == target) {
            return true;
        }

        // Case target is to the left of cut
        if(target <= cut) {
            res = res || binSearchHori(mat, row, i0, k, target);
        }
        // Case target is to the right of cut
        else {
            res = res || binSearchHori(mat, row, k + 1, i1, target);
        }

        return res;
    }

    public boolean searchMatrix(int[][] matrix, int target) {

        int m = matrix.length;
        int n = matrix[0].length;

        // Compute row containing target or row above the row containing target
        int row = binSearchVert(matrix, 0, m - 1, target);

        // Check if row contains target
        boolean val1 = binSearchHori(matrix, row, 0, n - 1, target);

        // Check if row below row contains target
        boolean val2 = binSearchHori(matrix, row - 1, 0, n - 1, target);

        return val1 || val2;
    }
}