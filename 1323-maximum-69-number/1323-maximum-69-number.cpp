#include <stdlib.h>
class Solution {
public:
    int maximum69Number (int num) {
        int sum = 0;
        int i = 1000;
        bool changed = false;
        while (i > 0)
        {
            int n = num / i;
            switch (n)
            {
                case 6:
                    sum += (changed ? 6 : 9) * i;
                    changed = true;
                    break;
                case 9:
                   sum += 9 * i; 
            }
            num %= i;
            i /= 10;
        }
        return sum;
    }
};