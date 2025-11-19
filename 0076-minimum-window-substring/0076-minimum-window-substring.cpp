#include <unordered_map>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) return "";

        unordered_map<char, int> t_count, window_count;
        for (char c : t) t_count[c]++;  // Count required characters in t

        int left = 0, min_start = 0, min_len = INT_MAX;
        int matched = 0;

        for (int right = 0; right < s.length(); right++) {
            char c = s[right];
            window_count[c]++;

            if (t_count.count(c) && window_count[c] <= t_count[c])
                matched++;

            // Shrink the window as much as possible without losing required chars
            while (matched == t.length()) {
                char left_char = s[left];
                if (!t_count.count(left_char) || window_count[left_char] > t_count[left_char]) {
                    window_count[left_char]--;
                    left++;
                } else {
                    break; // Cannot shrink more without losing a required char
                }
            }

            // Update minimum window AFTER shrinking
            if (matched == t.length()) {
                int window_len = right - left + 1;
                if (window_len < min_len) {
                    min_len = window_len;
                    min_start = left;
                }
            }
        }

        return (min_len == INT_MAX) ? "" : s.substr(min_start, min_len);
    }
};
