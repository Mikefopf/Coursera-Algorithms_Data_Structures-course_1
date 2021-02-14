#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int res = 0, current = 0, i = 0, n = stops.size() + 1;
    stops.push_back(dist);
    stops.push_back(dist);
    while (current < dist) {
        while (i < n && stops[i] - current <= tank) {
            i++;
        }
        if (i == n) {
            i++;
        }
        if (i == 0 || stops[i - 1] == current) {
            return -1;
        } else {
            current = stops[i - 1];
            res++;
        }
    }
    return res - 1;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
