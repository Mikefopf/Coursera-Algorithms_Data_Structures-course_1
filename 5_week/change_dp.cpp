#include <iostream>
#include <vector>
using namespace std;

int get_change(int m) {
    //write your code here
    vector<int> change = vector<int>(max(m + 1, 5), 0);
    change[0] = 0;
    change[1] = 1;
    change[2] = 2;
    change[3] = 1;
    change[4] = 1;
    for (int i = 5; i <= m; ++i) {
        change[i] = min(change[i - 1], min(change[i - 3], change[i - 4])) + 1;
    }
    return change[m];
}

int main() {
    int m;
    std::cin >> m;
    std::cout << get_change(m) << '\n';
    return 0;
}
