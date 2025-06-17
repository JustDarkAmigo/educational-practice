#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

vector<vector<int>> hill(int n) {
    vector<vector<int>> pyr(n);
    for (int i = 0; i < n; ++i) {
        pyr[i].resize(i + 1);
        for (int j = 0; j <= i; ++j) {
            pyr[i][j] = rand() % 100 + 1;
        }
    }
    return pyr;
}
pair<int, vector<int>> minPath(const vector<vector<int>>& pyr) {
    int n = pyr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<int>> par(n, vector<int>(n, -1));
    dp[0][0] = pyr[0][0];
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][j] + pyr[i][j];
                par[i][j] = j;
            } else if (j == i) {
                dp[i][j] = dp[i - 1][j - 1] + pyr[i][j];
                par[i][j] = j - 1;
            } else {
                if (dp[i - 1][j - 1] < dp[i - 1][j]) {
                    dp[i][j] = dp[i - 1][j - 1] + pyr[i][j];
                    par[i][j] = j - 1;
                } else {
                    dp[i][j] = dp[i - 1][j] + pyr[i][j];
                    par[i][j] = j;
                }
            }
        }
    }
    int minSum = dp[n - 1][0], minIdx = 0;
    for (int j = 1; j < n; ++j) {
        if (dp[n - 1][j] < minSum) {
            minSum = dp[n - 1][j];
            minIdx = j;
        }
    }
    vector<int> path;
    for (int i = n - 1; i >= 0; --i) {
        path.push_back(pyr[i][minIdx]);
        minIdx = par[i][minIdx];
    }
    reverse(path.begin(), path.end());
    return {minSum, path};
}

int main() {
    cout << "Здравствуйте, введите высоту пирамиды: ";
    int n;
    cin >> n;
    rand();
    auto pyr = hill(n);
    cout << "Гора:" << endl;
    for (const auto& row : pyr) {
        for (size_t i = 0; i < row.size(); ++i) {
            cout << row[i] << (i < row.size() - 1 ? " " : "");
        }
        cout << "\n";
    }
    cout << "Результат:" << endl;
    auto result = minPath(pyr);
    cout << result.first << "\n";
    for (size_t i = 0; i < result.second.size(); ++i) {
        cout << result.second[i] << (i < result.second.size() - 1 ? " " : "");
    }
    cout << "\n";
    return 0;
}
