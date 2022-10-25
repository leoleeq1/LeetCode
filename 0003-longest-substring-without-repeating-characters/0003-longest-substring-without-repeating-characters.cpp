class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const unsigned short NOT_VISITED = 65535;
        unsigned short visited[256];
        int max = 0;
        int length = 0;
        
        memset(visited, 255, sizeof(visited));
        for (int i=0;i<s.length();++i)
        {
            if (visited[s[i]] < NOT_VISITED)
            {
                max = length > max ? length : max;
                
                int temp = length;
                length = i - (visited[s[i]] + 1);
                temp -= length;
                
                for (int j=temp-1;j>=0;--j)
                    visited[s[visited[s[i]] - j]] = NOT_VISITED;
            }
            
            visited[s[i]] = i;
            ++length;
        }
        
        return max > length ? max : length;
    }
};