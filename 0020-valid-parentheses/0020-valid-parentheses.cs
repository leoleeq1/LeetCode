public class Solution {
    public bool IsValid(string s)
    {
        var stk = new Stack<char>();
        var open = "({[";

        foreach (var c in s)
        {
            if (open.Any(l => l == c))
            {
                stk.Push(c);
            }
            else
            {
                if (stk.Count == 0)
                    return false;

                var oc = stk.Pop();
                var expected = c switch
                {
                    ')' => '(',
                    '}' => '{',
                    ']' => '[',
                };

                if (oc != expected)
                    return false;
            }
        }

        return stk.Count == 0;
    }
}