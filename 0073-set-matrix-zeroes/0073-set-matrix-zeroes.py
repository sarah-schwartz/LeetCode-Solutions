from typing import List

class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        rows, cols = len(matrix), len(matrix[0])
        row_zero = any(matrix[0][j] == 0 for j in range(cols))
        col_zero = any(matrix[i][0] == 0 for i in range(rows))

        # Use first row and column as markers
        for i in range(1, rows):
            for j in range(1, cols):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0  # mark row
                    matrix[0][j] = 0  # mark column

        # Zero out marked cells
        for i in range(1, rows):
            for j in range(1, cols):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0

        # Handle first row if needed
        if row_zero:
            for j in range(cols):
                matrix[0][j] = 0

        # Handle first column if needed
        if col_zero:
            for i in range(rows):
                matrix[i][0] = 0
