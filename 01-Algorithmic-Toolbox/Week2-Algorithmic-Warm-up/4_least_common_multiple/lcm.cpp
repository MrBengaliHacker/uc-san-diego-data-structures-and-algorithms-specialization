#include <iostream>
using namespace std;

long long gcd(int a, int b)
{
  while (b != 0)
  {
    long long remainder = a % b;
    a = b;
    b = remainder;
  }

  return a;
}

long long lcm(long long a, long long b)
{
  if (a == 0 || b == 0)
  {
    return 0;
  }

  return (a / gcd(a, b)) * b;
}

int main()
{
  int a, b;
  cin >> a >> b;
  cout << lcm(a, b) << endl;
  return 0;
}
