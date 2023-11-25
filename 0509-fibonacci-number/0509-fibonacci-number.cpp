class Solution {
public:
    vector<int> v = vector<int>(31, -1);
    int fib(int n) {
        if (n == 0) return 0;
        if (n <= 2) return 1;
        if (v[n] != -1)
            return v[n];
        return v[n] = fib(n-1) + fib(n-2);
    }
};