class Solution {
public:
    string reverseWords(string s) {
        int write = 0;
        int read = 0;
        int n = s.size();

        while (read < n) {
            while (read < n && s[read] == ' ')
                read++;

            while (read < n && s[read] != ' ')
                s[write++] = s[read++];

            while (read < n && s[read] == ' ')
                read++;

            if (read < n)
                s[write++] = ' ';
        }

        s.resize(write);

        reverse(s.begin(), s.end());

        int start = 0;

        for (int end = 0; end <= s.size(); end++) {
            if (end == s.size() || s[end] == ' ') {
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        }

        return s;
    }
};