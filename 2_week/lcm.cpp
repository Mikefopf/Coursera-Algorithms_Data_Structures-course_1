#include <iostream>
#include <algorithm>

using namespace std;

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

int gcd_fast(int a, int b) {
    int previous = max(a, b);
    int current = min(a, b);
    int tmp_previous = previous;
    while (current != 0) {
         tmp_previous = previous;
         previous = current;
         current = tmp_previous % previous;
    }
    return previous;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << (long long)a * b / gcd_fast(a, b) << std::endl;
  return 0;
}
