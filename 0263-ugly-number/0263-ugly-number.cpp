class Solution {
public:
    int primes[3] = {2, 3, 5};
    bool isUgly(int n) {
        if (n < 1)
            return false;
        while (n > 1)
        {
            bool flag = false;
            for (int i=0;i<3;++i)
            {
                int t = n % primes[i];
                if (t == 0)
                {
                    n /= primes[i];
                    flag = true;
                    break;
                }
            }
            if (!flag)
                return false;
        }
        return true;
    }
};