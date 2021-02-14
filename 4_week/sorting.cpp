#include <iostream>
#include <vector>
#include <cstdlib>
#include <utility>

using namespace std;

pair<int, int> partition3(vector<int> & a, int l, int r) {
    int m1 = l;
    int m2 = l;
    int x = a[l];
  /*  for (int j = l; j <= r; ++j) {
        cout << a[j] << " ";
    }
    cout << endl;*/
    for (int i = l + 1; i <= r; ++i) {
        if (a[i] < x) {
            m1++;
            m2++;
            swap(a[m2], a[i]);
            swap(a[m2], a[m1]);
        } else if (a[i] == x) {
            m2++;
            swap(a[m2], a[i]);
        }
       /* cout << m1 << " " << m2 << " " << i << endl;
        for (int j = l; j <= r; ++j) {
            cout << a[j] << " ";
        }
        cout << endl;*/
    }
    swap(a[m1], a[l]);
    return make_pair(m1, m2);
}

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  pair<int, int> m = partition3(a, l, r);
  int m1 = m.first;
  int m2 = m.second;

  randomized_quick_sort(a, l, m1 - 1);
  randomized_quick_sort(a, m2 + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
