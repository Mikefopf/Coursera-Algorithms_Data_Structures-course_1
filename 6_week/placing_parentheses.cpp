#include <iostream>
#include <cassert>
#include <string>
#include <sstream>
#include <vector>

using namespace std;


long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}



long long get_maximum_value(const string &exp) {
    //write your code here
    stringstream input;
    input << exp;
    vector<long long> nums;
    vector<char> ops;
    long long value;
    int j = 0;
    char operation;
    input >> value;
    nums.push_back(value);
    while (input >> operation) {
        ops.push_back(operation);
        input >> value;
        nums.push_back(value);
    }
    vector<vector<long long>> M = vector<vector<long long>>(nums.size(), vector<long long>(nums.size(), 0));
    vector<vector<long long>> m = vector<vector<long long>>(nums.size(), vector<long long>(nums.size(), 0));
    for (int i = 0; i < nums.size(); ++i) {
        M[i][i] = nums[i];
        m[i][i] = nums[i];
    }
    for (int s = 1; s < nums.size(); ++s) {
        for (int i = 0; i < nums.size() - s; ++i) {
            j = i + s;
            long long max_elem = eval(M[i][i], M[i + 1][j], ops[i]);
            long long min_elem = eval(M[i][i], M[i + 1][j], ops[i]);
            for (int k = i; k < j; ++k) {
                if (eval(M[i][k], M[k + 1][j], ops[k]) > max_elem) {
                    max_elem = eval(M[i][k], M[k + 1][j], ops[k]);
                }
                if (eval(M[i][k], m[k + 1][j], ops[k]) > max_elem) {
                    max_elem = eval(M[i][k], m[k + 1][j], ops[k]);
                }
                if (eval(m[i][k], m[k + 1][j], ops[k]) > max_elem) {
                    max_elem = eval(m[i][k], m[k + 1][j], ops[k]);
                }
                if (eval(m[i][k], M[k + 1][j], ops[k]) > max_elem) {
                    max_elem = eval(m[i][k], M[k + 1][j], ops[k]);
                }
                if (eval(M[i][k], M[k + 1][j], ops[k]) < min_elem) {
                    min_elem = eval(M[i][k], M[k + 1][j], ops[k]);
                }
                if (eval(M[i][k], m[k + 1][j], ops[k]) < min_elem) {
                    min_elem = eval(M[i][k], m[k + 1][j], ops[k]);
                }   
                if (eval(m[i][k], m[k + 1][j], ops[k]) < min_elem) {
                    min_elem = eval(m[i][k], m[k + 1][j], ops[k]);
                }
                if (eval(m[i][k], M[k + 1][j], ops[k]) < min_elem) {
                    min_elem = eval(m[i][k], M[k + 1][j], ops[k]);
                }
                M[i][j] = max_elem;
                m[i][j] = min_elem;
            }
        }
    }
   /* for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < nums.size(); ++j) {
            cout << M[i][j] << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < nums.size(); ++j) {
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }*/
    return M[0][nums.size() - 1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
