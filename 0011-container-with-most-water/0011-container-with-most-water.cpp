class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int lm = 0;
        int rm = 0;
        int ma = 0;
        
        while (l < r)
        {
            lm = max(lm, height[l]);
            rm = max(rm, height[r]);
            auto area = (r - l) * min(lm, rm);
            ma = max(ma, area);
            
            if (lm < rm)
            {
                do
                {                    
                    ++l;
                } while (l < r && height[l] <= lm);
            }
            else
            {
                do
                {
                    --r;
                } while (r > l && height[r] <= rm);
            }
        }
        
        return ma;
    }
};