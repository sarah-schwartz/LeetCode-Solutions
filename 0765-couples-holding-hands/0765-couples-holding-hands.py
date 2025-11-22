class Solution:

    def minSwapsCouples(self, row: List[int]) -> int:
         n = len(row)
    
        # Map each person to their current seat index
         positions = {person: i for i, person in enumerate(row)}
        
         swaps = 0
        
        # Iterate by couples (indices 0,2,4,...)
         for i in range(0, n, 2):
            first_person = row[i]
            
            # The partner is always first_person XOR 1 (0↔1, 2↔3, 4↔5, ...)
            second_person = first_person ^ 1
            
            # If the partner is not sitting next to them, fix it
            if row[i + 1] != second_person:
                
                # Find where the partner is currently sitting
                pos_to_swap = positions[second_person]
                
                # Swap the wrong person with the correct partner
                row[i + 1], row[pos_to_swap] = row[pos_to_swap], row[i + 1]
                
                # Update position records after the swap
                positions[row[pos_to_swap]] = pos_to_swap
                positions[row[i + 1]] = i + 1
                
                swaps += 1
        
         return swaps
            