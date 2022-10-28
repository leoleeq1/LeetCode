class Solution {
public:
    int getLength(int x)
    {
        int length = 0;
        do
        {
            ++length;
            x /= 10;
        } while (x > 0);
        return length;
    }
    
    int getNumberAt(int x, int len)
    {
        for (int i=0;i<len-1;++i)
        {
            x /= 10;
        }
        return x % 10;
    }
    
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        
        int length = getLength(x);
        int half = length/2;
        for (int i=0;i<half;++i)
        {
            if (getNumberAt(x, i + 1) != getNumberAt(x, length - i))
                return false;
        }
        return true;
    }
};