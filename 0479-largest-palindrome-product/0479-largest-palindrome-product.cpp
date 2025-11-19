class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;  // Special case for 1-digit numbers
        
        long long maxNDigit = pow(10, n) - 1;  // Largest n-digit number
        
        // Loop over possible "left halves" of palindrome, from largest down
        for (long long leftHalf = maxNDigit; leftHalf >= 0; leftHalf--) {

            // Build palindrome by appending reversed left half
            string leftStr = to_string(leftHalf);
            string reversedStr(leftStr.rbegin(), leftStr.rend());
            long long palindrome = stoll(leftStr + reversedStr);

            // Check if palindrome can be written as product of two n-digit numbers
            for (long long divisor = maxNDigit; divisor * divisor >= palindrome; divisor--) {
                if (palindrome % divisor == 0)
                    return palindrome % 1337;
            }
        }

        return -1; // No palindrome found (should not happen)
    }
};
