#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
    if (left == right) {
        return -1;
    }
    if (left + 1 == right) {
        return a[left];
    }
    //write your code here
    int m1 = get_majority_element(a, left, (left + right) / 2), n1 = 0;
    int m2 = get_majority_element(a, (left + right) / 2, right), n2 = 0;
    if (m1 != -1) {
        for (int i = left; i < right; ++i) {
            n1 += (int)(a[i] == m1);
        }
    }
    if (n1 > (right - left) / 2) {
        return m1;
    }
    if (m2 != -1) {
        for (int i = left; i < right; ++i) {
            n2 += (int)(a[i] == m2);
        }
    }
    if (n2 > (right - left) / 2) {
        return m2;
    }
    return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
