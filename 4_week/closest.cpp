#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class point {
public:
    point() {}
    point(const int & a, const int & b, const int & i) : x_coord(a), y_coord(b), index(i) {}
    ~point() {} 
    point & operator=(const point & a) {
        x_coord = a.Get_x();
        y_coord = a.Get_y();
        index = a.Get_index();
        return *this;
    }
    int Get_x() const {
        return x_coord;
    }
    int Get_y() const {
        return y_coord;
    }
    int Get_index() const {
        return index;
    }
private:
    int x_coord = 0;
    int y_coord = 0;
    int index = 0;
};


double distance(const point & p1, const point & p2) {
    return pow(pow(p2.Get_y() - p1.Get_y(), 2) + pow(p1.Get_x() - p2.Get_x(), 2), 0.5);
}

double step_of_recursion(vector<point> & sorted_by_x, vector<point> & sorted_by_y, int l, int r) {
    if (r - l == 2) {
        return distance(sorted_by_x[l], sorted_by_x[l + 1]);
    } else if (r - l == 3) {
        return min(distance(sorted_by_x[l], sorted_by_x[l + 1]), min(distance(sorted_by_x[l], sorted_by_x[l + 2]), distance(sorted_by_x[l + 1], sorted_by_x[l + 2])));
    } else {
        vector<point> close_to_edge, sorted_by_y_left, sorted_by_y_right;
        for (int i = 0; i < sorted_by_y.size(); ++i) {
            if (sorted_by_y[i].Get_index() < (r + l) / 2) {
                sorted_by_y_left.push_back(sorted_by_y[i]);
            } else {
                sorted_by_y_right.push_back(sorted_by_y[i]);
            }
        }
        double d1 = step_of_recursion(sorted_by_x, sorted_by_y_left, l, (r + l) / 2);
        double d2 = step_of_recursion(sorted_by_x, sorted_by_y_right, (r + l) / 2, r);
        double d = min(d1, d2);
        int key = 0;
        for (int i = 0; i < sorted_by_y.size(); ++i) {
            if ((double)abs(sorted_by_y[i].Get_x() - sorted_by_x[(r + l) / 2].Get_x()) <= d) {
                close_to_edge.push_back(sorted_by_y[i]);
            }
        }
        double res = d;
        for (int i = 0; i < close_to_edge.size(); ++i) {
            for (int j = max(0, i - 7); j < min((int)close_to_edge.size(), i + 8); ++j) {
                if (distance(close_to_edge[i], close_to_edge[j]) < res && i != j) {
                    res = distance(close_to_edge[i], close_to_edge[j]);
                }
            }
        }
        return res;
    }
}

double minimal_distance(vector<int> x, vector<int> y) {
    //write your code here
    double res = 0;
    vector<point> sorted_by_x(x.size());
    vector<point> sorted_by_y(y.size());
    for (int i = 0; i < x.size(); ++i) {
        sorted_by_x[i] = point(x[i], y[i], i);
    }
    sort(sorted_by_x.begin(), sorted_by_x.end(), [](point lhs, point rhs) {return lhs.Get_x() < rhs.Get_x();});
    for (int i = 0; i < x.size(); ++i) {
        sorted_by_y[i] = point(sorted_by_x[i].Get_x(), sorted_by_x[i].Get_y(), i);
    }
    sort(sorted_by_y.begin(), sorted_by_y.end(), [](point lhs, point rhs) {return lhs.Get_y() < rhs.Get_y();});
    
    return step_of_recursion(sorted_by_x, sorted_by_y, 0, x.size());
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(x, y) << "\n";
}
