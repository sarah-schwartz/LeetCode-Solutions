#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string originalDigits(string s) {

        // Count occurrences of each letter
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        vector<int> count(10, 0);

        // Digits identified by unique letters
        count[0] = freq['z' - 'a']; // zero
        count[2] = freq['w' - 'a']; // two
        count[4] = freq['u' - 'a']; // four
        count[6] = freq['x' - 'a']; // six
        count[8] = freq['g' - 'a']; // eight

        // Remaining digits after removing known contributions
        count[3] = freq['h' - 'a'] - count[8];                 // three
        count[5] = freq['f' - 'a'] - count[4];                 // five
        count[7] = freq['s' - 'a'] - count[6];                 // seven
        count[1] = freq['o' - 'a'] - count[0] - count[2] - count[4]; // one
        count[9] = freq['i' - 'a'] - count[5] - count[6] - count[8]; // nine

        // Build result in ascending order
        string result;
        for (int d = 0; d <= 9; ++d) {
            result.append(count[d], char('0' + d));
        }

        return result;
    }
};
