class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char, int> mp1, mp2;

        for (char c : word1) mp1[c]++;
        for (char c : word2) mp2[c]++;

        if (mp1.size() != mp2.size())
            return false;

        for (auto [ch, cnt] : mp1)
            if (!mp2.count(ch))
                return false;

        vector<int> f1, f2;

        for (auto [ch, cnt] : mp1)
            f1.push_back(cnt);

        for (auto [ch, cnt] : mp2)
            f2.push_back(cnt);

        sort(f1.begin(), f1.end());
        sort(f2.begin(), f2.end());

        return f1 == f2;

    }
};