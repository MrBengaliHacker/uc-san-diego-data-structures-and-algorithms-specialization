#include <iostream>
using namespace std;

int fibonacci_mod10(long long n) {
    n %= 60;

    if (n <= 1) {
        return n;
    }

    int previous = 0;
    int current = 1;

    for (int i = 2; i <= n; i++) {
        int next = (previous + current) % 10;
        previous = current;
        current = next;
    }

    return current;
}

int fibonacci_sum_squares(long long n) {
    int a = fibonacci_mod10(n);
    int b = fibonacci_mod10(n + 1);

    return (a * b) % 10;
}

int main() {
    long long n;
    cin >> n;

    cout << fibonacci_sum_squares(n) << '\n';
    return 0;
}