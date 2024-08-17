public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        var numWithIndex = nums.Select((n, i) => (n, i)).OrderBy(p => p.n).ToArray();
        var i = 0;
        var j = nums.Length - 1;
        while (i < j)
        {
            var p1 = numWithIndex[i];
            var p2 = numWithIndex[j];
            if (p1.n + p2.n == target)
            {
                return new[] {p1.i, p2.i};
            }
            
            if (p1.n + p2.n > target)
                --j;
            if (p1.n + p2.n < target)
                ++i;
        }
        return new[] {-1, -1};
    }
}
