#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


string largest_number(vector<string>& a) {
    // Put a before b if concatenating ab gives a larger number than ba
    sort(a.begin(), a.end(),
      [](const string& x, const string& y) {
        return x + y > y + x;
      });

    // Handle the case where all numbers are zero
    if (a[0] == "0") {
      return "0";
    }
    
    stringstream ret;

    for (size_t i = 0; i < a.size(); i++) {
      ret << a[i];
    }

    return ret.str();
}


int main() {
  int n;
  cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    cin >> a[i];
  }
  cout << largest_number(a);
}
