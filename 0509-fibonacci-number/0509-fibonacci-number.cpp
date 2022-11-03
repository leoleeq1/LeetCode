class Solution {
public:
    int arr[31] = {0,1,};
    int fib(int n) {
        if (n == 0)
            return arr[0];
        else if (n == 1)
            return arr[1];
        
        if (arr[n] == 0)
            arr[n] = fib(n - 1) + fib(n - 2);
        return arr[n];
    }
};