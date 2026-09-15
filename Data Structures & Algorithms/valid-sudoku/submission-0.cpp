class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        // We use a hash set for checking duplicates
        std::vector<std::unordered_set<char>> rows(9);
        std::vector<std::unordered_set<char>> cols(9);
        std::vector<std::unordered_set<char>> boxes(9);

        for (size_t r = 0; r < board.size(); ++r)
        {
            for (size_t c = 0; c < board[r].size(); ++c)
            {
                if (board[r][c] == '.')
                    continue;
                // Check if the row already has the number
                if (rows[r].find(board[r][c]) != rows[r].end())
                    return false;
                // Check if the col already has the number
                if (cols[c].find(board[r][c]) != cols[c].end())
                    return false;
                // Check if the box already has the number (r/3*3 for row and c/3 for col in the 3x3)
                int position = r / 3 * 3 + c / 3;
                if (boxes[position].find(board[r][c]) != boxes[position].end())
                    return false;
                
                rows[r].insert(board[r][c]);
                cols[c].insert(board[r][c]);
                boxes[position].insert(board[r][c]);
            }
        }
        return true;
    }
};
