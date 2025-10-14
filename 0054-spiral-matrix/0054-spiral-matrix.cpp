class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int height = matrix.size();
        if (height == 0) return res;
        int width = matrix[0].size();

        int top = 0, bottom = height - 1;
        int left = 0, right = width - 1;

        while (top <= bottom && left <= right) {
            // Move right
            for (int i = left; i <= right; ++i)
                res.push_back(matrix[top][i]);
            top++;

            // Move down
            for (int i = top; i <= bottom; ++i)
                res.push_back(matrix[i][right]);
            right--;

            // Move left, only if there is a new bottom row
            if (top <= bottom) {
                for (int i = right; i >= left; --i)
                    res.push_back(matrix[bottom][i]);
                bottom--;
            }

            // Move up, only if there is a new left column
            if (left <= right) {
                for (int i = bottom; i >= top; --i)
                    res.push_back(matrix[i][left]);
                left++;
            }
        }

        return res;
    }
};
