class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        map<int,int> cnt;
        for (int x : hand) cnt[x]++;

        for (auto& p : cnt) {
            int start = p.first;
            int amount = p.second;

            if (amount > 0) {
                for (int i = 0; i < groupSize; i++) {
                    if (cnt[start + i] < amount) {
                        return false;
                    }
                    cnt[start + i] -= amount;
                }
            }
        }

        return true;
    }
};