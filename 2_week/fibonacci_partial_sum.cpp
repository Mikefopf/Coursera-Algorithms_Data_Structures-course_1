#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

int get_fibonacci_huge_fast(long long N, int m) {
    int previous = 0;
    int current  = 1;
    int tmp_previous = 0;
    int counter = 0;
    do {
        tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % m;
        counter++;
    } while (previous != 0 or current != 1);
    int n = N % counter;
    if (n == 0) {
        return 0;
    }
    previous = 0;
    current = 1;
    for (long long i = 0; i < n - 1; ++i) {
        tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % m;
    }
    return current;
}

int get_fibonacci_sum_fast(long long n) {
    return ((9 + get_fibonacci_huge_fast(n + 2, 10)) % 10);
}

int get_fibonacci_partial_sum_fast(long long from, long long to) {
    return ((get_fibonacci_sum_fast(to) - get_fibonacci_sum_fast(from - 1) + 10) % 10);
}
int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
