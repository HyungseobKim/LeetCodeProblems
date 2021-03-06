class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return std::string();
        
        std::string* shortest = &strs[0];
        
        std::for_each(strs.begin() + 1, strs.end(), [&](auto& word){
            if (word.length() < shortest->length())
                shortest = &word;
        });
        
        std::string result;
        const int length = static_cast<int>(shortest->length());
        const int size = static_cast<int>(strs.size());
        
        auto& word = *shortest;
        
        for (int i = 0; i < length; ++i)
        {
            const char curr = word[i];
            
            for (int j = 0; j < size; ++j)
            {
                if (strs[j][i] != curr)
                    return result;
            }
            
            result += curr;
        }
        
        return result;
    }
};