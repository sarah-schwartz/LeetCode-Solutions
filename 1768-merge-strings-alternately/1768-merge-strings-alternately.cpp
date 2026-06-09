class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        result.reserve(word1.size() + word2.size());
        int i = 0;
        for(; i < word1.length() && i < word2.length(); i++){
            result.push_back(word1[i]);
            result.push_back(word2[i]);
        }
        while(i < word1.length()){
            result.push_back(word1[i++]);
        }
        while(i < word2.length()){
            result.push_back(word2[i++]);
        }
        return result;
    }
};