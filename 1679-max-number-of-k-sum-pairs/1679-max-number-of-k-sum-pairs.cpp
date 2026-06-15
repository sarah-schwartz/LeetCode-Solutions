class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int operations = 0;
        for (int num : nums) {

            int need = k - num;

            auto it = mp.find(need);

            if (it != mp.end() && it->second > 0) {
                it->second--;
                operations++;
            }
            else {
                mp[num]++;
            }
        }
        return operations;
    }
};