#include <iostream>
#include <cassert>

using namespace std;

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }
    if (n == 0) {
        return 0;
    }
    return current % 10;
}

int get_fibonacci_last_digit_fast(int N) {
    int n = N % 60;
    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
    }
    if (n == 0) {
        return 0;
    }
    return current;
}

void test_solution() {
    assert(get_fibonacci_last_digit_fast(3) == 2);
    assert(get_fibonacci_last_digit_fast(10) == 5);
    for (int n = 0; n < 100; ++n) {
        cout << n << "\n";
        assert(get_fibonacci_last_digit_fast(n) == get_fibonacci_last_digit_naive(n));
    }
}


int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
    return 0;
}
