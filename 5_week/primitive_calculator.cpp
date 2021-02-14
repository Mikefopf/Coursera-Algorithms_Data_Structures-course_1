#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> optimal_sequence(int n) {
    std::vector<int> sequence = vector<int>(n + 1, 0), backtrack = vector<int>(max(4, n + 1)), res;
    sequence[0] = 0;
    backtrack[0] = 0;
    sequence[1] = 0;
    backtrack[1] = 1;
    for (int i = 2; i < n + 1; ++i) {
        if (i % 3 == 0 && sequence[i / 3] <= sequence[i - 1] && (sequence[i / 3] <= sequence[i / 2] && i % 2 == 0 || i % 2 != 0)) {
            sequence[i] = sequence[i / 3] + 1;
            backtrack[i] = i / 3;
        } else if (i % 2 == 0 && sequence[i / 2] <= sequence[i - 1] && (sequence[i / 2] <= sequence[i / 3] && i % 3 == 0 || i % 3 != 0)) {
            sequence[i] = sequence[i / 2] + 1;
            backtrack[i] = i / 2;

        } else {
            sequence[i] = sequence[i - 1] + 1;
            backtrack[i] = i - 1;
        }
    }
    int value = n;
    res.push_back(value);
    while (value > 1) {
        value = backtrack[value];
        res.push_back(value);
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
