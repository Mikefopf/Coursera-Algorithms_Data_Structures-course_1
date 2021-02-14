#include <iostream>
#include <vector>

using namespace std;

int lcs2(vector<int> &a, vector<int> &b) {
    //write your code here
    vector<vector<int>> subs = vector<vector<int>>(a.size() + 1, vector<int>(b.size() + 1, 0));
    for (int i = 1; i < a.size() + 1; ++i) {
        for (int j = 1; j < b.size() + 1; ++j) {
            if (a[i - 1] == b[j - 1]) {
                subs[i][j] = max(max(subs[i - 1][j], subs[i][j - 1]), subs[i - 1][j - 1] + 1);
            } else {
                subs[i][j] = max(max(subs[i - 1][j], subs[i][j - 1]), subs[i - 1][j - 1]);
            }
        }
    }
    return subs[a.size()][b.size()];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
