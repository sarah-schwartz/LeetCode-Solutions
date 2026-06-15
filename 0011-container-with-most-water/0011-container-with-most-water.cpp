class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int answer = 0;

        while (left < right) {
            int area =
                (right - left) *
                min(height[left], height[right]);

            answer = max(answer, area);

            if (height[left] < height[right])
                left++;
            else
                right--;
        }

        return answer;
    }
};