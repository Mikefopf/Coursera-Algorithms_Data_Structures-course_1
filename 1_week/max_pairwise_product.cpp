#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                (long long)numbers[first] * numbers[second]);
        }
    }

    return max_product;
}

long long FastMaxPairwiseProduct(const std::vector<int>& numbers) {
    int n = numbers.size();
    int max1 = 0;
    int max_index = 0;
    for (int i = 0; i < n; ++i) {
        if (numbers[i] > max1) {
            max_index = i;
            max1 = numbers[i];
        }
    }
    int max2 = 0;
    for (int i = 0; i < n; ++i) {
        if (numbers[i] > max2 && i != max_index) {
            max2 = numbers[i];
        }
    }
    return (long long)max1 * max2;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << FastMaxPairwiseProduct(numbers) << "\n";
    return 0;
}
