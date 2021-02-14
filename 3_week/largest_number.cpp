#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

bool IsGreaterOrEqual(int a, int b) {
    std::stringstream num1, num2;
    int number1, number2;
    num1 << a << b;
    num2 << b << a;
    num1 >> number1;
    num2 >> number2;
    return number1 > number2;
}

string largest_number(vector<int> a) {
  //write your code here
    std::stringstream ret;
    vector<int> all_nums;
    for (size_t i = 0; i < a.size(); i++) {
        all_nums.push_back(a[i]);
    }
    sort(all_nums.begin(), all_nums.end(), [](int a, int b) {return IsGreaterOrEqual(a, b);});
    for (auto it = all_nums.begin(); it != all_nums.end(); it++) {
        ret << std::to_string(*it);
    }
    string result;
    ret >> result;
    return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
