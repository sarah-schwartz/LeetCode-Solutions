class Solution {
public:
    // Main function to solve the N-Queens problem
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0)); // NxN board initialized to 0
        vector<vector<string>> solutions;                // Stores all valid solutions
        placeQueens(0, board, solutions);                // Start backtracking from row 0
        return solutions;
    }

    // Checks whether placing a queen at (row, col) is valid
    bool isValid(int row, int col, vector<vector<int>>& board, int n) {

        // Check the row
        for (int j = 0; j < n; j++) {
            if (board[row][j] == 1)
                return false;
        }

        // Check the column
        for (int i = 0; i < n; i++) {
            if (board[i][col] == 1)
                return false;
        }

        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1;
             i >= 0 && j >= 0; i--, j--) 
        {
            if (board[i][j] == 1)
                return false;
        }

        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1;
             i >= 0 && j < n; i--, j++) 
        {
            if (board[i][j] == 1)
                return false;
        }

        // Check lower-left diagonal
        for (int i = row + 1, j = col - 1;
             i < n && j >= 0; i++, j--) 
        {
            if (board[i][j] == 1)
                return false;
        }

        // Check lower-right diagonal
        for (int i = row + 1, j = col + 1;
             i < n && j < n; i++, j++) 
        {
            if (board[i][j] == 1)
                return false;
        }

        return true;
    }

    // Attempts to place queens row by row using backtracking
    void placeQueens(int row,
                     vector<vector<int>>& board,
                     vector<vector<string>>& solutions)
    {
        int n = board.size();

        // If we placed queens in all rows, record the solution
        if (row == n) {
            solutions.push_back(convertBoard(board));
            return;
        }

        // Try placing a queen in each column of the current row
        for (int col = 0; col < n; col++) {

            if (isValid(row, col, board, n)) {
                board[row][col] = 1;                // Place queen
                placeQueens(row + 1, board, solutions); // Recurse to next row
                board[row][col] = 0;                // Remove queen (backtrack)
            }
        }
    }

    // Converts 0/1 board into a board of '.' and 'Q'
    vector<string> convertBoard(vector<vector<int>>& board) {
        int n = board.size();
        vector<string> result(n, string(n, '.'));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (board[i][j] == 1)
                    result[i][j] = 'Q';

        return result;
    }
};
