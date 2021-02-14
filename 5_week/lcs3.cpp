#include <iostream>
#include <vector>

using std::vector;

int Max(int a1, int a2, int a3, int a4) {
    if (a4 >= a1 && a4 >= a2 && a4 >= a3) {
        return a4;
    } else if (a3 >= a1 && a3 >= a2) {
        return a3;
    } else if (a2 >= a1) {
        return a2;
    } else {
        return a1;
    }
}

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
    //write your code here
    vector<vector<vector<int>>> subs = vector<vector<vector<int>>>(a.size() + 1, vector<vector<int>>(b.size() + 1, vector<int>(c.size() + 1, 0)));
    for (int i = 1; i < a.size() + 1; ++i) {
        for (int j = 1; j < b.size() + 1; ++j) {
            for (int k = 1; k < c.size() + 1; ++k) {
                if (a[i - 1] == b[j - 1] && a[i - 1] == c[k - 1]) {
                    subs[i][j][k] = Max(subs[i - 1][j][k], subs[i][j - 1][k], subs[i][j][k - 1], subs[i - 1][j - 1][k - 1] + 1); 
                } else {
                    subs[i][j][k] = Max(subs[i - 1][j][k], subs[i][j - 1][k], subs[i][j][k - 1], subs[i - 1][j - 1][k - 1]);
                }
            }
        }
    }
    return subs[a.size()][b.size()][c.size()];
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
