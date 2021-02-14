#include <iostream>
#include <vector>

using namespace std;

int optimal_weight(int W, const vector<int> &w) {
    //write your code here
    vector<vector<int>> opt_sol = vector<vector<int>>(w.size() + 1, vector<int>(W + 1, 0));
    for (int i = 1; i < w.size() + 1; ++i) {
        for (int j = 1; j <= W; ++j) {
            if (j >= w[i - 1]) {
                opt_sol[i][j] = max(opt_sol[i - 1][j], w[i - 1] + opt_sol[i - 1][j - w[i - 1]]);
            } else {
                opt_sol[i][j] = opt_sol[i - 1][j];
            }
        }
    }
    return opt_sol[w.size()][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
