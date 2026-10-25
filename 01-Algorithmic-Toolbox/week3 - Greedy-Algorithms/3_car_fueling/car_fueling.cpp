
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int compute_min_refills(int dist, int tank, vector<int>& stops) {
    vector<int> allStops;
    allStops.push_back(0);

    for (int stop : stops) {
        allStops.push_back(stop);
    }

    allStops.push_back(dist);

    int numRefills = 0;
    int currentRefill = 0;
    int n = allStops.size();

    while (currentRefill < n - 1) {
        int lastRefill = currentRefill;

        // Go as far as possible with the current tank
        while (currentRefill < n - 1 &&
               allStops[currentRefill + 1] - allStops[lastRefill] <= tank) {
            currentRefill++;
        }

        // If we cannot reach the next stop, return -1
        if (currentRefill == lastRefill) {
            return -1;
        }

        // Count a refill if we haven't reached the destination
        if (currentRefill < n - 1) {
            numRefills++;
        }
    }

    return numRefills;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
