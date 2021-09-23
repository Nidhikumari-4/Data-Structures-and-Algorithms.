## [509. Fibonacci Number](https://leetcode.com/problems/fibonacci-number/)

## Print Fibonacci Number Series upto N
```cpp
class Solution {
public:
    int fib(int n) {
        if (n <= 1)
        return n;
    int a = fib(n - 1);
    int b = fib(n - 2);
    return a + b;
    }
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Fibonacii series upto " << n << " is " << fib(n);
    return 0;
}
};
```

