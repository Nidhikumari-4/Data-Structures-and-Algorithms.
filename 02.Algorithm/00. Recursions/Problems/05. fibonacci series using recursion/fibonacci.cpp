//1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ……..

#include <iostream>
using namespace std;

int fibo(int n)
{
    if (n <= 1)
        return n;
    int a = fibo(n - 1);
    int b = fibo(n - 2);
    return a + b;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Fibonacii series upto " << n << " is " << fibo(n);
    return 0;
}