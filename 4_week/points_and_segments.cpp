#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;


enum vertex_type {
    BEGIN = 1,
    POINT = 2,
    END = 3
};

class Vertex {
public:
    Vertex() {}
    Vertex(const int & a, const vertex_type & t, const int & i) : coordinate(a), type(t), index(i) {}
    int coordinate;
    vertex_type type;
    int index;
};


bool operator<(const Vertex & lhs, const Vertex & rhs) {
    return (lhs.coordinate < rhs.coordinate || (lhs.coordinate == rhs.coordinate && lhs.type < rhs.type));
}

bool operator==(const Vertex & lhs, const Vertex & rhs) {
    return (lhs.coordinate == rhs.coordinate && lhs.type == rhs.type);
}


vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
    vector<int> cnt(points.size(), 0);
    vector<Vertex> all_vertexes(starts.size() + ends.size() + points.size());
    for (int i = 0; i < starts.size(); ++i) {
        all_vertexes[i] = {starts[i], BEGIN, i};
        all_vertexes[i + starts.size()] = {ends[i], END, i};
    }
    for (int i = 0; i < points.size(); ++i) {
        all_vertexes[starts.size() + ends.size() + i] = {points[i], POINT, i};
    }
    int key = 0;
    sort(all_vertexes.begin(), all_vertexes.end());
    vector<int> intersections_num(points.size(), 0);
    for (int i = 0; i < all_vertexes.size(); ++i) {
        if (all_vertexes[i].type == BEGIN) {
            key++;
        } else if (all_vertexes[i].type == END){
            key--;
        } else {
            intersections_num[all_vertexes[i].index] = key;
        }
    }
    for (int i = 0; i < points.size(); ++i) {
        cnt[i] = intersections_num[i];
    }
    //write your code here
    
    return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
    vector<int> cnt(points.size());
    for (size_t i = 0; i < points.size(); i++) {
        for (size_t j = 0; j < starts.size(); j++) {
            cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
        }
    }
    return cnt;
}

void test_solution() {
    vector<int> answer(50000);
    vector<int> points(50000);
    vector<int> starts(50000);
    vector<int> ends(50000);
    for (int i = 0; i < 50000; ++i) {
        starts.push_back(50000 - i);
        ends.push_back(50010 - i);
        points.push_back(i);
    }
    answer = fast_count_segments(starts, ends, points);
    for (int i = 0; i < 50000; ++i) {
        cout << answer[i] << " ";
    }
    cout << endl;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
  return 0;
}
