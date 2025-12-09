class Solution {
public:
    int maxDistinct(string s) {
        std::vector<bool> counter(26, 0);
        int count = 0;
        for(int i = 0; i < s.length(); i++){
            if(counter[s[i] - 'a'] == false){
                count++;
                counter[s[i] - 'a'] = true;
            }
        }
        return count;
    }
};