public class Solution {
    public int MajorityElement(int[] nums)
    {
        int major = nums[0];
        int count = 1;

        for (int i = 1; i < nums.Length; i++)
        {
            if (count == 0)
            {
                major = nums[i];
                ++count;
            }
            else if (major == nums[i]) ++count;
            else --count;
        }

        return major;
    }
}