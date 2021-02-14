#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
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


int fibonacci_sum_squares_fast(long long n) {
    return ((get_fibonacci_huge_fast(n, 10) * get_fibonacci_huge_fast(n + 1, 10)) % 10);
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_fast(n) << "\n";
}
