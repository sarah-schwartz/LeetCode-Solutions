class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
            # Handle overflow case
        if dividend == -2**31 and divisor == -1:
            return 2**31 - 1  # INT_MAX

        # Determine sign of the result
        is_negative = (dividend < 0) ^ (divisor < 0)

        # Work with negative values to avoid overflow issues
        if dividend > 0:
            dividend = -dividend
        if divisor > 0:
            divisor = -divisor

        result = 0
        # Repeat until dividend is larger than divisor (both negative)
        while dividend <= divisor:
            temp_divisor = divisor
            multiple = 1
            # Double temp_divisor until it's too large or would overflow
            while temp_divisor >= (-2**31) // 2 and dividend <= temp_divisor + temp_divisor:
                temp_divisor += temp_divisor
                multiple += multiple
            # Subtract from dividend and add multiples to result
            dividend -= temp_divisor
            result += multiple

        return -result if is_negative else result