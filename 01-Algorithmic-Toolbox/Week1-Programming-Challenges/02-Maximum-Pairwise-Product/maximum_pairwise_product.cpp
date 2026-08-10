#include <iostream>
#include <vector>
using namespace std;

long long Maximum_Pairwise_Product(int n, vector<long long> &a)
{
  long long largest = 0;
  long long second_largest = 0;

  for (int i = 0; i < n; i++)
  {
    if (a[i] > largest)
    {
      second_largest = largest;
      largest = a[i];
    }
    else if (a[i] > second_largest)
    {
      second_largest = a[i];
    }
  }
  return largest * second_largest;
}

int main()
{
  int n;
  cin >> n;

  vector<long long> a(n);

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  cout << Maximum_Pairwise_Product(n, a) << endl;
  
  return 0;
}