#include <iostream>
using namespace std;

long long get_fibonacci_last_digit(long long n)
{
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;

    for (long long i = 2; i <= n; i++)
    {
        int next = (previous + current) % 10;
        previous = current;
        current = next;
    }

    return current;
}

int main()
{
    long long n;
    cin >> n;

    cout << get_fibonacci_last_digit(n) << '\n';
    return 0;
}
