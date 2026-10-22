#include <iostream>
using namespace std;

int fibonacci_mod10(long long n)
{
    n %= 60;

    if (n <= 1)
        return n;

    int previous = 0;
    int current = 1;

    for (int i = 2; i <= n; i++)
    {
        int next = (previous + current) % 10;
        previous = current;
        current = next;
    }

    return current;
}

int fibonacci_sum_last_digit(long long n)
{
    return (fibonacci_mod10(n + 2) + 9) % 10;
}

int main()
{
    long long n = 0;
    cin >> n;
    cout << fibonacci_sum_last_digit(n) << '\n';
    return 0;
}
