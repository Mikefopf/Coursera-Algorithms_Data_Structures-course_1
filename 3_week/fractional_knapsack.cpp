#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class good {
public:
    double unit_value;
    int order_num;
};

bool operator<(good & lhs, good & rhs) {
    return lhs.unit_value > rhs.unit_value;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
    double value = 0.0;
    int n = weights.size(), a = 0;
    vector<good> unit_values = vector<good>(n, {0.0, 0});
    for (int i = 0; i < n; ++i) {
        unit_values[i].unit_value = (double)values[i] / (double)weights[i];
        unit_values[i].order_num = i;
    }
    sort(unit_values.begin(), unit_values.end());
    for (int i = 0; i < n; ++i) {
        a = min(capacity, weights[unit_values[i].order_num]);
        capacity -= a;
        value += values[unit_values[i].order_num] * ((double)a / (double)weights[unit_values[i].order_num]);
        if (capacity == 0) {
            return value;
        }
    }
    return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
