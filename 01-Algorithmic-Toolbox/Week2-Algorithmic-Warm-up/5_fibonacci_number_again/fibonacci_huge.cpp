#include <iostream>
using namespace std;

long long get_fibonacci_huge(long long n, long long m)
{
    if (m == 1)
    {
        return 0;
    }

    if (n <= 1)
    {
        return n;
    }

    long long previous = 0;
    long long current = 1;
    long long period = 0;

    while (true)
    {
        long long next = (previous + current) % m;
        previous = current;
        current = next;
        period++;

        if (previous == 0 && current == 1)
        {
            break;
        }
    }

    n %= period;

    if (n <= 1)
    {
        return n;
    }

    previous = 0;
    current = 1;

    for (long long i = 2; i <= n; i++)
    {
        long long next = (previous + current) % m;
        previous = current;
        current = next;
    }

    return current;
}

int main()
{
    long long n, m;
    cin >> n >> m;

    cout << get_fibonacci_huge(n, m) << '\n';
    return 0;
}
