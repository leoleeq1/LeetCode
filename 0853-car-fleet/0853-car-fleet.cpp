class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> ps;
        transform(position.begin(), position.end(), speed.begin(), back_inserter(ps), [](int p, int s) { return make_pair(p, s); });
        sort(ps.begin(), ps.end(), [](auto l, auto r) { return get<0>(l) < get<0>(r); });

        int cnt = 1;
        for (int i=ps.size()-1;i>0;--i)
        {
            auto& l = ps[i-1];
            auto& r = ps[i];
            double meet = solve(l, r);
            if (meet <= target)
            {
                l = r;
            }
            else
            {
                ++cnt;
            }
        }
        return cnt;
    }
    
    double solve(pair<int, int> ps1, pair<int, int> ps2)
    {
        if (get<1>(ps1) <= get<1>(ps2))
            return 1000001;
        auto x = (double)(get<0>(ps2) - get<0>(ps1)) / (get<1>(ps1) - get<1>(ps2));
        return get<1>(ps1) * x + get<0>(ps1);
    }
};