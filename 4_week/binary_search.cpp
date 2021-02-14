#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int binary_search(const vector<int> &a, int x) {
    int left = 0, right = (int)a.size(), current = 0; 
    //write your code here
    if (a[left] > x || a[right - 1] < x) {
        return -1;
    }
    while (left != right) {
        current = (left + right) / 2;
        if (a[current] == x) {
            return current;
        } else if (a[current] > x) {
            right = current;
        } else {
            left = current + 1;
        }
    }
    if (a[left] == x) {
        return left;
    }
    return -1;
}

int linear_search(const vector<int> &a, int x) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] == x) return i;
    }
    return -1;
}

void test_solution() {
    vector<int> a(10000);
    for (size_t i = 0; i < 10000; i++) {
        a[i] = 1;
    }
    std::cout << binary_search(a, 0) << '\n';
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  //test_solution();
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
}
