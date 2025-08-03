from typing import List

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        # Store final result combinations
        result = []

        # Sort to help with pruning (skip candidates that are too large)
        candidates.sort()

        # Backtracking function to build combinations
        def backtrack(remaining, current_combination, start_index):
            # If we've reached the target, add a copy of the current combination
            if remaining == 0:
                result.append(list(current_combination))
                return
            # Try each candidate starting from current index (can reuse same index)
            for i in range(start_index, len(candidates)):
                candidate = candidates[i]
                # If candidate is larger than remaining, we can prune
                if candidate > remaining:
                    break
                # Choose the candidate
                current_combination.append(candidate)
                # Recurse with updated remaining and same index (can reuse)
                backtrack(remaining - candidate, current_combination, i)
                # Undo the choice (backtrack)
                current_combination.pop()

        # Start backtracking with empty combination
        backtrack(target, [], 0)
        return result
