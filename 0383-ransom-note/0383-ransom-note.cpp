class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) return false;
        
        int letters[26] = {0,};        
        for (auto c : magazine)
        {
            ++letters[c-'a'];
        }
        
        for (auto c : ransomNote)
        {
            if (--letters[c-'a'] < 0)
                return false;
        }
        
        return true;
    }
};