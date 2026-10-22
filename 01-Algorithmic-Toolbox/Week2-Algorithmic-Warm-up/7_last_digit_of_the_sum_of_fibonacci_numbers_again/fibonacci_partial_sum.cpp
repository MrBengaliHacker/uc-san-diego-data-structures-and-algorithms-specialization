#include <iostream>
#include <vector>
using namespace std;
using std::vector;

int fibonacci_mod10(long long n)
{
    n %= 60;

    if (n <= 1)
    {
        return n;
    }

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

int get_fibonacci_partial_sum(long long from, long long to)
{
    int end_sum = fibonacci_mod10(to + 2);
    int start_sum = fibonacci_mod10(from + 1);

    return (end_sum - start_sum + 10) % 10;
}

int main()
{
    long long from, to;
    cin >> from >> to;

    cout << get_fibonacci_partial_sum(from, to) << '\n';
    return 0;
}