class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();

        // min-heap: (value, list_index, element_index)
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;

        int current_max = INT_MIN;

        // initialize heap
        for (int i = 0; i < k; i++) {
            pq.emplace(nums[i][0], i, 0);
            current_max = max(current_max, nums[i][0]);
        }

        int best_start = 0, best_end = INT_MAX;

        while (true) {
            auto [val, list_id, idx] = pq.top();
            pq.pop();

            // update best range
            if (current_max - val < best_end - best_start) {
                best_start = val;
                best_end = current_max;
            }

            // move forward in the same list
            if (idx + 1 == nums[list_id].size())
                break;  

            int next_val = nums[list_id][idx + 1];
            pq.emplace(next_val, list_id, idx + 1);

            current_max = max(current_max, next_val);
        }

        return {best_start, best_end};
    }
};
