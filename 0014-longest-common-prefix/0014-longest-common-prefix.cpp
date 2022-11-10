class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common = strs[0];
        for (int i=1;i<strs.size();++i)
        {
            string str = strs[i];
            for (int j=0;j<str.length()&&j<common.length();++j)
            {
                if (common[j] != str[j])
                {
                    common = common.substr(0, j);
                    break;
                }
            }
            if (common.find(str) != string::npos)
                common = str;
        }
        return common;
    }
};