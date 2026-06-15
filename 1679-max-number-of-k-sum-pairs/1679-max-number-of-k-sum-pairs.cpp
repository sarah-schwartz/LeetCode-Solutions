class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int operations = 0;
        for (int num : nums) {

            int need = k - num;

            if (mp[need] > 0) {
                mp[need]--;
                operations++;
            }
            else {
                mp[num]++;
            }
        }
        return operations;
    }
};