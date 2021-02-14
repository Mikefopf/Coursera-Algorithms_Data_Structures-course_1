#include <iostream>
#include <algorithm>

using namespace std;

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
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
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
