class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        for (int i=stones.size()-1;i>0;)
        {
            int y = stones[i];
            int x = stones[i-1];
            if (x == y)
            {
                stones.pop_back();
                stones.pop_back();
                i -= 2;
            }
            else
            {
                int w = y - x;
                stones.pop_back();
                int k = upper_bound(stones.begin(), stones.end(), w) - stones.begin();
                stones[i-1] = w;
                for (int j=i-1;j>k;--j)
                {
                    swap(stones[j], stones[j-1]);
                }
                --i;
            }
        }
        
        if (stones.size() == 1)
            return stones[0];
        return 0;
    }
};