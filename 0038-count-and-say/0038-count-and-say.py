class Solution:
    def countAndSay(self, n: int) -> str:
        # Initial term of the sequence is "1"
        result = "1"

        # Generate terms from 2 to n
        for _ in range(1, n):
            current = ""
            i = 0

            # Parse through the current result to build the next term
            while i < len(result):
                count = 1
                # Count consecutive identical digits
                while i + 1 < len(result) and result[i] == result[i + 1]:
                    i += 1
                    count += 1
                # Append the count and the digit
                current += str(count) + result[i]
                i += 1
            
            # Update result to the newly generated term
            result = current

        return result
