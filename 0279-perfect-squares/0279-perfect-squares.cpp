class Solution {
public:
    int cache[10001];
    int dp(int n)
    {
        if (cache[n] != -1)
            return cache[n];
        
        int nn = sqrt(n);
        int nnn = sqrt(nn);
        int mnm = 10001;
        for (int i=nn;i>nnn;--i)
        {
            int sqr = i * i;
            if (n % sqr == 0)
            {
                mnm = min(mnm, n / sqr);
                break;
            }
            else
                mnm = min(mnm, n / sqr + dp(n % sqr));
        }
        return cache[n] = mnm;
    }
    int numSquares(int n) {
        memset(cache, -1, sizeof(cache));
        for (int i=1;i<=100;++i)
            cache[i * i] = 1;
        cache[2] = 2;
        cache[3] = 3;
        return dp(n);
    }
};