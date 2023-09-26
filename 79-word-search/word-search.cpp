class Solution {
public:
    bool solver(vector<vector<char>>& board, string word, int row, int col, int idx) {
        if (idx == word.size()) {
            return true; // We've found the entire word.
        }
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[idx]) {
            return false; // Conditions for invalid cells or mismatched characters.
        }
        
        char original = board[row][col]; // Store the original character.
        board[row][col] = '0'; // Mark the cell as visited.
        
        // Try exploring in all four directions.
        bool found = solver(board, word, row - 1, col, idx + 1) ||
                     solver(board, word, row + 1, col, idx + 1) ||
                     solver(board, word, row, col - 1, idx + 1) ||
                     solver(board, word, row, col + 1, idx + 1);
        
        board[row][col] = original; // Restore the cell.
        
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        if (rows == 0) return false;
        int cols = board[0].size();
        
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (solver(board, word, row, col, 0)) {
                    return true; // If we find the word starting from (row, col), return true.
                }
            }
        }
        
        return false; // The word was not found.
    }
};
