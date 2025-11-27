class Solution {
public:

bool can_split(vector<int>& nums, int max_sum, int k) {
    int current_sum = 0;
    int subspaces_count = 1;

    for (int value : nums) {

        // If adding this value exceeds the limit,
        // start a new subarray
        if (value + current_sum > max_sum) {
            subspaces_count++;
            current_sum = value;

            // Too many subarrays - cannot split
            if (subspaces_count > k) {
                return false;
            }
        } 
        else {
            current_sum += value;
        }
    }

    return true;
}

int splitArray(vector<int>& nums, int k) {
    // The lower bound is the largest single element
    int left = *std::max_element(nums.begin(), nums.end());

    // The upper bound is the total sum
    int right = 0;
    for (int value : nums) {
        right += value;
    }

    int answer = right;

    // Binary search the minimal maximum subarray sum
    while (left <= right) {
        int mid = (left + right) / 2;

        // If we CAN split with this max sum, try a smaller one
        if (can_split(nums, mid, k)) {
            answer = mid;
            right = mid - 1;
        }
        // Otherwise, we need a larger allowed sum
        else {
            left = mid + 1;
        }
    }

    return answer;
}

};