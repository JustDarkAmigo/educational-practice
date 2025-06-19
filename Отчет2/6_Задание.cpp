#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "введите количество запросов:";
    cin >> n;
    vector<int> results;

    for (int i = 0; i < n; ++i) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        int pairs1 = min(a, x);
        int availableA = a - pairs1;
        int availableB = b;
        int pairs2 = min(availableA + availableB, y); 
        int totalPairs = pairs1 + pairs2;
        results.push_back(totalPairs);
    }
    for (int i = 0; i < n; ++i) {
        cout << results[i] << " ";
    }
    cout << endl;
    return 0;
}
