#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

vector<int> optimal_points(vector<Segment> & segments) {
    vector<int> points;
    sort(segments.begin(), segments.end(), [](Segment lhs, Segment rhs) {return lhs.start > rhs.start;});
    for (auto it = segments.begin(); it != segments.end(); it++) {
        if (points.empty() || points.back() > it->end) {
            points.push_back(it->start);
        }
    }
    return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
