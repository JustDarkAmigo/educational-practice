#include <iostream>
#include <vector>

using namespace std;

int main() {
    int h, w;
    cout << "Введите высоту матрицы и её ширину через," << endl;
    cout << "а потом саму матрицу:";
    cin >> h >> w;

    vector<vector<int>> matrix(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> matrix[i][j];
        }
    }

    int minRow = h, maxRow = -1, minCol = w, maxCol = -1;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (matrix[i][j] == 1) {
                minRow = min(minRow, i);
                maxRow = max(maxRow, i);
                minCol = min(minCol, j);
                maxCol = max(maxCol, j);
            }
        }
    }

    cout << minRow - 1 << " " << minCol - 1 << " " << maxRow + 1 << " " << maxCol + 1 << endl;

    return 0;
}
