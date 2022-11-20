class Solution {
public:
    int getNum(string& s, int& inoutIndex)
    {
        int num = 0;
        while (s[inoutIndex] == ' ')
            ++inoutIndex;
        while (s[inoutIndex] >= '0' && s[inoutIndex] <= '9' && inoutIndex < s.length())
        {
            num = num * 10 + (s[inoutIndex++] - '0');
        }
        --inoutIndex;
        return num;
    }
    int calculate(string s) {
        stack<char> ops;
        stack<int> nums;
        for (int i=0;i<s.length();++i)
        {
            if (s[i] == ' ') continue;
            if (s[i] == '+' || s[i] == '-')
            {
                ops.push(s[i]);
            }
            else if (s[i] == '(')
            {
                int si = i;
                stack<int> brackets;
                brackets.push(i++);
                while (!brackets.empty())
                {
                    if (s[i] == '(')
                        brackets.push(i);
                    else if (s[i] == ')')
                        brackets.pop();
                    ++i;
                }
                int ei = i-1;
                int num = calculate(s.substr(si+1, ei-1-si));
                if (ops.size() > 0)
                {
                    char op = ops.top();
                    ops.pop();
                    
                    int l = 0;
                    if (nums.size() > 0)
                    {
                        l = nums.top();
                        nums.pop();
                    }
                    int r = num;
                    
                    nums.push(op == '+' ? l+r : l-r);
                }
                else
                {
                    nums.push(num);
                }
                i = ei;
            }
            else
            {
                if (ops.size() > 0)
                {
                    char op = ops.top();
                    ops.pop();
                    
                    int l = 0;
                    if (nums.size() > 0)
                    {
                        l = nums.top();
                        nums.pop();
                    }
                    int r = getNum(s, i);
                    
                    nums.push(op == '+' ? l+r : l-r);
                }
                else
                {
                    nums.push(getNum(s, i));
                }
            }
        }
        
        return nums.size() > 0 ? nums.top() : 0;
    }
};