#include <iostream>
#include <vector>

using namespace std;


vector<int> optimal_summands(int n) {
  vector<int> summands;

  int next = 1;

  while (n > 0) {
    // Take next if enough remains for a larger summand
    if (n - next > next) {
      summands.push_back(next);
      n -= next;
      next++;
    } else {
        // Use the remaining amount as the final summand
        summands.push_back(n);
        break;
    }
  }

    return summands;
}


int main() {
  int n;
  cin >> n;
  vector<int> summands = optimal_summands(n);
  cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    cout << summands[i] << ' ';
  }
}
