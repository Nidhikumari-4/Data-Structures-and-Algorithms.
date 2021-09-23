#include<iostream>
using namespace std;

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