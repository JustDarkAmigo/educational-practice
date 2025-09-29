#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cout << "Введите колличество запросов: ";
    cin >> n;
    vector<int> results;
    for (int i = 0; i < n; i++) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        int pairs_A = min(a, x + y);
        int pairs_B = min(b, x);
        int total_pairs = pairs_A + pairs_B;
        results.push_back(total_pairs);
    }
    for (int i = 0; i < n; i++) {
        cout << results[i] << " ";
    }
    cout << endl;
    return 0;
}
