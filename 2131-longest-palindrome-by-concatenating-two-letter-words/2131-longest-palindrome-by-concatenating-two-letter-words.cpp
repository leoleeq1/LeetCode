class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> map;
        for (int i=0;i<words.size();++i)
        {
            if (map.find(words[i]) == map.end())
                map[words[i]] = 1;
            else
                map[words[i]] += 1;
        }
        
        bool center = false;
        int length = 0;
        
        for (auto& pair : map)
        {
            if (pair.first[0] == pair.first[1])
            {
                if ((pair.second & 1) == 1)
                {
                    if (center)
                    {
                        length += pair.second - 1;
                    }
                    else
                    {
                        length += pair.second;
                        center = true;
                    }
                }
                else
                {
                    length += pair.second;
                }
            }
            else
            {
                string inv(pair.first.crbegin(), pair.first.crend());
                if (map.find(inv) != map.end())
                {
                    length += (pair.second < map[inv] ? pair.second : map[inv]) * 2;
                    map[inv] = 0;
                }
            }
        }
        
        return length * 2;
    }
};