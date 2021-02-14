#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition3(vector<int> &A) {
    //write your code here
    int sum = 0;
    vector<int> to_maximise = vector<int>(4, 0);
    for (int i = 0; i < A.size(); ++i) {
        sum += A[i];
    }
    if (sum % 3 != 0) {
        return 0;
    }
    sum /= 3;
    vector<vector<vector<vector<int>>>> opt_sol = vector<vector<vector<vector<int>>>>(A.size() + 1, vector<vector<vector<int>>>(sum + 1, vector<vector<int>>(sum + 1, vector<int>(sum + 1, 0))));
    for (int j = 1; j < A.size() + 1; ++j) {
        for (int i1 = 0; i1 < sum + 1; ++i1) {
            for (int i2 = 0; i2 < sum + 1; ++i2) {
                for (int i3 = 0; i3 < sum + 1; ++i3) {
                    to_maximise[0] = opt_sol[j - 1][i1][i2][i3];    
                    to_maximise[1] = 0;    
                    to_maximise[2] = 0;   
                    to_maximise[3] = 0;
                    if (i1 >= A[j - 1]) {
                        to_maximise[1] = opt_sol[j - 1][i1 - A[j - 1]][i2][i3] + A[j - 1];
                    }
                    if (i2 >= A[j - 1]) {
                        to_maximise[2] = opt_sol[j - 1][i1][i2 - A[j - 1]][i3] + A[j - 1];
                    }
                    if (i3 >= A[j - 1]) {
                        to_maximise[3] = opt_sol[j - 1][i1][i2][i3 - A[j - 1]] + A[j - 1];
                    }
                    opt_sol[j][i1][i2][i3] = *max_element(to_maximise.begin(), to_maximise.end());
                }
            }
        }
    }
    if (opt_sol[A.size()][sum][sum][sum] == 3 * sum) {
        return 1;
    }
    return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
