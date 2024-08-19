public class Solution {
    public int[] TwoSum(int[] nums, int target)
    {
        int[] indices = Enumerable.Range(0, nums.Length).ToArray();
        Array.Sort(indices, (l, r) => { return nums[l].CompareTo(nums[r]); });

        var l = 0;
        var r = nums.Length - 1;

        while (l < r)
        {
            var sum = nums[indices[l]] + nums[indices[r]];
            if (sum == target) return new[] { indices[l], indices[r] };
            if (sum > target) --r;
            else ++l;
        }

        return new[] { -1, -1 };
    }
}