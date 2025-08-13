from collections import defaultdict
from typing import List

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = defaultdict(list)

        for s in strs:
            # Count frequency of each letter (26 lowercase letters)
            count = [0] * 26
            for char in s:
                count[ord(char) - ord('a')] += 1
            
            # Convert count list to a tuple so it can be used as a dict key
            anagrams[tuple(count)].append(s)

        return list(anagrams.values())
