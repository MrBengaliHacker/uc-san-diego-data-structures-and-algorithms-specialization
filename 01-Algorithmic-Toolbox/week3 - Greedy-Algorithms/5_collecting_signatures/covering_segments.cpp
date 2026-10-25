#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Segment {
  int start, end;
};


vector<int> optimal_points(vector<Segment>& segments) {
  vector<int> points;

  // Sort segments by their ending positions
  sort(segments.begin(), segments.end(),
    [](const Segment& a, const Segment& b) {
      return a.end < b.end;
    });

  for (size_t i = 0; i < segments.size(); ++i) {
    // Choose a point at the end of the current segment
    int point = segments[i].end;

    // Add it only if the last chosen point doesn't cover this segment
    if (points.empty() || points.back() < segments[i].start) {
      points.push_back(point);
    }
  }

    return points;
}


int main() {
  int n;
  cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    cout << points[i] << " ";
  }
}
