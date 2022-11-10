class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        int l1 = num1.length();
        int l2 = num2.length();
        vector<int> v(l1 + l2 + 1, 0);
        for (int i=l1-1;i>=0;--i)
        {
            int vi1 = l1 - 1 - i;
            for (int j=l2-1;j>=0;--j)
            {
                int vi2 = l2 - 1 - j;
                int mul = (num1[i] - '0') * (num2[j] - '0');
                mul += v[vi1 + vi2];
                v[vi1 + vi2 + 1] += mul / 10;
                v[vi1 + vi2] = mul % 10;
            }
        }
        string result;
        for (int i=v.size()-1;i>=0;--i)
            result += v[i] + '0';
        result = result.erase(0, result.find_first_not_of('0'));
        return result;
    }
};