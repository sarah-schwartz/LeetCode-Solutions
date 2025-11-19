class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;  // special case
        
        long long upper = pow(10, n) - 1;
        
        for (long long half = upper; half >= 0; half--) {

            // Build palindrome from left half
            string s = to_string(half);
            string r = string(s.rbegin(), s.rend());
            long long p = stoll(s + r);

            // Try dividing it by n-digit numbers
            for (long long x = upper; x * x >= p; x--) {
                if (p % x == 0)
                    return p % 1337;
            }
        }
        return -1;
    }
};
