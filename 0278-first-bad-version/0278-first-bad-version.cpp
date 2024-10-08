// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 1, hi = n;
        int first = n;
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (isBadVersion(mid))
            {
                first = mid;
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return first;
    }
};