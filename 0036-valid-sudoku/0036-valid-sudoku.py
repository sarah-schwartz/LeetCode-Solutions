class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        # Initialize tracking arrays for rows, columns, and 3x3 sub-boxes
        rows = [[False] * 9 for _ in range(9)]
        cols = [[False] * 9 for _ in range(9)]
        boxes = [[False] * 9 for _ in range(9)]

        # Traverse every cell in the 9x9 board
        for i in range(9):
            for j in range(9):
                val = board[i][j]
                if val == '.':
                    continue  # Skip empty cells
                
                num = int(val) - 1  # Convert character '1'-'9' to index 0-8
                b = (i // 3) * 3 + (j // 3)  # Find sub-box index (0 through 8)

                # If number already seen in this row, column, or box → invalid
                if rows[i][num] or cols[j][num] or boxes[b][num]:
                    return False

                # Mark number as seen in row, column, and box
                rows[i][num] = cols[j][num] = boxes[b][num] = True

        # No conflicts found → valid Sudoku
        return True
