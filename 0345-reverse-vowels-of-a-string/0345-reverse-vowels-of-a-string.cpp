class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> set = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int l = 0;
        int r = s.length() - 1;
        
        while (l < r)
        {
            bool lb = set.find(s[l]) != set.end();
            bool rb = set.find(s[r]) != set.end();
            
            if (lb && rb)
            {
                swap(s[l++], s[r--]);
            }
            else if (lb)
            {
                --r;
            }
            else if (rb)
            {
                ++l;
            }
            else
            {
                ++l;
                --r;
            }
        }
        return s;
    }
};