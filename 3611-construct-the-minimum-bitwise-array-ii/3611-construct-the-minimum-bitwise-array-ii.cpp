class Solution {
public:
      unsigned int clearHighestBitInTrailingOnes(unsigned int value) {
        // Step 1: find 2^k where k = length of trailing-ones run
        unsigned int firstZeroAboveRun = (~value) & (value + 1u);

        // Special case: all bits from LSB up to MSB are 1
        if (firstZeroAboveRun == 0u) {
            unsigned int temp = value;
            unsigned int highestBit = 1u;

            // Shift right until only the top '1' remains,
            // while shifting 'highestBit' left in parallel.
            while (temp >>= 1) {
                highestBit <<= 1;
            }

            // Clear that highest bit in the trailing-ones run
            return value ^ highestBit;
        }

        // Step 2: firstZeroAboveRun = 1u << k  => run length is k
        // The highest bit in the trailing run is then:
        unsigned int highestBitInRun = firstZeroAboveRun >> 1;

        // Clear that bit in the original value
        return value ^ highestBitInRun;
    }

    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        for(int i = 0; i < n; i++){
            if(nums[i] == 2)
                ans[i] = -1;
            else{
                if ((nums[i] & 3u) == 3u)
                    ans[i] = clearHighestBitInTrailingOnes(nums[i]);
                else{
                    int temp = nums[i] >> 1;
                    temp <<= 1;
                    ans[i] = ((temp | (temp - 1)) == nums[i]) ? (temp - 1) : temp;
                }
            }
        }
        return ans;
    }
};