public class Solution {
    public int[][] Insert(int[][] intervals, int[] newInterval)
    {
        List<int[]> answer = new();
        var i = 0;

        for (; i < intervals.Length && intervals[i][1] < newInterval[0]; ++i)
        {
            answer.Add(intervals[i]);
        }

        for (; i < intervals.Length && intervals[i][0] <= newInterval[1]; ++i)
        {
            newInterval[0] = Math.Min(newInterval[0], intervals[i][0]);
            newInterval[1] = Math.Max(newInterval[1], intervals[i][1]);
        }
        answer.Add(newInterval);

        for (; i < intervals.Length; ++i)
        {
            answer.Add(intervals[i]);
        }

        return answer.ToArray();
    }
}