class Solution:
    def reverse(self, x: int) -> int:
        # Define 32-bit signed integer range limits
        INT_MIN, INT_MAX = -2**31, 2**31 - 1

        # Store the sign of the input number
        sign = -1 if x < 0 else 1
        
        # Work with the absolute value to simplify the reversal process
        num = abs(x)

        # Variable to accumulate the reversed number
        result = 0

        # Loop until there are no more digits left
        while num != 0:
            # Get the last digit
            digit = num % 10
            
            # Remove the last digit from the number
            num //= 10

            # Check for overflow before multiplying by 10 and adding the digit
            if (result > INT_MAX // 10 or
               (result == INT_MAX // 10 and digit > INT_MAX % 10)):
                return 0

            # Append the digit to the reversed number
            result = result * 10 + digit

        # Return the reversed number with the original sign
        return sign * result
