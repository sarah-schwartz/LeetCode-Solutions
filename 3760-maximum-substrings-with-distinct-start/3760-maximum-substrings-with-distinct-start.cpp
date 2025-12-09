class Solution {
public:
    int maxDistinct(const string& s) {
    std::vector<bool> seen(26, false);
    int count = 0;

    for (char c : s) {
        int idx = c - 'a';
        if (!seen[idx]) {
            seen[idx] = true;
            count++;
        }
    }
    return count;
}
};