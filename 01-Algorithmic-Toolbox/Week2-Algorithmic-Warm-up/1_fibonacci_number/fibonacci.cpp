#include <iostream>
using namespace std;

long long fibonacci_fast(int n)
{
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;

    for (int i = 2; i <= n; i++)
    {
        long long next = previous + current;

        previous = current;
        current = next;
    }

    return current;
}

int main()
{
    int n;
    cin >> n;

    cout << fibonacci_fast(n) << '\n';
    return 0;
}
