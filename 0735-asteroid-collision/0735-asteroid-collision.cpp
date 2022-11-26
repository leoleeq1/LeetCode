class Solution {
public:
    bool isSameDir(int a, int b)
    {
        return a > 0 && b > 0 || a < 0 && b < 0;
    }
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> s;
        
        for (int i=0;i<n;++i)
        {
            bool destroyed = false;
            int a = asteroids[i];
            while (s.size())
            {
                int b = s.back();
                if (isSameDir(a, b))
                    break;
                
                if (a > b)
                    break;
                if (abs(a) > abs(b))
                    s.pop_back();
                else
                {
                    destroyed = true;
                    if (abs(a) == abs(b))
                        s.pop_back();
                    break;
                }
            }
            
            if (!destroyed)
                s.push_back(a);
        }
        return s;
    }
};