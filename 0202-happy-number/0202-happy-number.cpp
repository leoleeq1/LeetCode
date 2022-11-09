class Solution {
public:
    bool isHappy(int n) {
        int sum;
        while (n != 4 && n != 1)
        {
            sum = 0;
            while (n > 0)
            {
                int num = n % 10;
                sum += num * num;
                n /= 10;
            }
            n = sum;
        }
        
        return n == 1;
    }
};