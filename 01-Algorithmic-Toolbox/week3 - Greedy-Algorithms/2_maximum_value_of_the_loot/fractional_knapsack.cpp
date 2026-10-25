#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  int n = weights.size();
  
  // Calculate value per unit of weight for each item
  vector<double> ratios(n);

  for(int i = 0; i < n; i++) {
    ratios[i] = static_cast<double>(values[i]) / weights[i];
  }

  // Greedily select items with the highest value-to-weight ratio
  while(capacity > 0) {
    int best = -1;

    for(int i = 0; i < n; i++) {
      if (weights[i] > 0 &&
        (best == -1 || ratios[i] > ratios[best])) {
        best = i;
      }
    }

    if (best == -1) {
      break;
    }

    int amount = min(capacity, weights[best]);

    value += amount * ratios[best];
    capacity -= amount;

    // Mark this item as fully used
    weights[best] = 0;
  }

  return value;
}

int main() {
  int n;
  int capacity;
  cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  cout.precision(10);
  cout << optimal_value << endl;
  return 0;
}
