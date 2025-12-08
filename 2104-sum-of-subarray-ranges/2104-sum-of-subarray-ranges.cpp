class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftMin(n), rightMin(n), leftMax(n), rightMax(n);
        stack<int> st;

        // ----- Count subarrays where nums[i] is the minimum -----

        // leftMin[i]: distance to previous smaller element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) st.pop();
            leftMin[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // rightMin[i]: distance to next smaller-or-equal element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            rightMin[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // ----- Count subarrays where nums[i] is the maximum -----

        // leftMax[i]: distance to previous larger element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) st.pop();
            leftMax[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // rightMax[i]: distance to next larger-or-equal element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            rightMax[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }

        // ----- Combine contributions -----
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long maxCount = 1LL * leftMax[i] * rightMax[i];
            long long minCount = 1LL * leftMin[i] * rightMin[i];
            ans += nums[i] * (maxCount - minCount);
        }

        return ans;
    }
};
