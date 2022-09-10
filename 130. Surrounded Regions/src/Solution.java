class Solution {

    void search(char[][] grid, boolean[][] visited, int i, int j) {

        int r = grid.length;
        int c = grid[0].length;

        // If obstacle or visited
        if(grid[i][j] == 'X' || visited[i][j]) {
            return;
        }

        visited[i][j] = true;

        int n = i > 0 ? i - 1 : 0;
        int s = i < r - 1 ? i + 1 : r - 1;
        int w = j > 0 ? j - 1 : 0;
        int e = j < c - 1 ? j + 1 : c - 1;

        search(grid, visited, n, j);
        search(grid, visited, i, w);
        search(grid, visited, s, j);
        search(grid, visited, i, e);
    }

    public void solve(char[][] board) {

        int m = board.length;
        int n = board[0].length;

        boolean[][] visited = new boolean[m][n];

        // DFS to explore all locations reachable from left and right boundary
        for(int i = 0; i < m; ++i) {
            if(board[i][0] == 'O') {
                search(board, visited, i, 0);
            }
            if(board[i][n - 1] == 'O') {
                search(board, visited, i, n - 1);
            }
        }

        // DFS to explore all locations reachable from upper and lower boundary
        for(int j = 0; j < n; ++j) {
            if(board[0][j] == 'O') {
                search(board, visited, 0, j);
            }
            if(board[m - 1][j] == 'O') {
                search(board, visited, m - 1, j);
            }
        }

        // Replace all inner Os with Xs
        for(int i = 1; i < m - 1; ++i) {
            for(int j = 1; j < n - 1; ++j) {
                if(board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
}