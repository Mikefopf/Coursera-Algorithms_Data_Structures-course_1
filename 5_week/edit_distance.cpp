#include <iostream>
#include <string>
#include <vector>

using namespace std;

int edit_distance(const string &str1, const string &str2) {
    //write your code here
    vector<vector<int>> dist = vector<vector<int>>(str1.size() + 1, vector<int>(str2.size() + 1, 0));
    for (int i = 0; i < str1.size() + 1; ++i) {
        dist[i][0] = i;
    }
    for (int i = 0; i < str2.size() + 1; ++i) {
        dist[0][i] = i;
    }
    for (int i = 1; i < str1.size() + 1; ++i) {
        for (int j = 1; j < str2.size() + 1; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dist[i][j] = min(min(dist[i - 1][j] + 1, dist[i][j - 1] + 1), dist[i - 1][j - 1]);
            } else {
                dist[i][j] = min(min(dist[i - 1][j] + 1, dist[i][j - 1] + 1), dist[i - 1][j - 1] + 1);
            }
        }
    }
    return dist[str1.size()][str2.size()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
