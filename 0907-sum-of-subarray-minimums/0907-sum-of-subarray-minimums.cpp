class Solution {
public:
    int modulo = 1000000007;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n);
        stack<int> s;
        
        int ret = 0;
        for (int i=0;i<n;++i)
        {
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            
            if (s.size())
            {
                dp[i] = dp[s.top()] + (i - s.top()) * arr[i];
            }
            else
            {
                dp[i] = (i+1) * arr[i];
            }
            
            s.push(i);
            ret = (ret + dp[i]) % modulo;
        }
        return ret;
    }
};