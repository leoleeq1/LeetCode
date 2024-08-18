class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> map;
        for (auto c : s)
        {
            if (map.find(c) == map.end())
                map[c] = 0;
            ++map[c];
        }
        
        int ans = 0;
        bool odd = false;
        for (auto p : map)
        {
            bool curOdd = p.second % 2 == 1;
            ans += p.second;
            if (curOdd)
            {
                if (!odd) odd = true;
                else --ans;
            }
        }
        return ans;
    }
};