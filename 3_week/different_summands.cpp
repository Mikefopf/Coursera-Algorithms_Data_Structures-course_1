#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
    vector<int> summands;
    int sum = 1, i = 1;
    while (sum <= n) {
        summands.push_back(i);
        i++;
        sum += i;
    }
    summands.pop_back();
    sum -= i;
    summands.push_back(n - sum + i - 1);
    //write your code here
    return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
