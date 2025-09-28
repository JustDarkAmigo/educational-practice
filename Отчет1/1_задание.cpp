#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
std::vector<std::vector<int>> Generate_Moon(int n) {
    std::vector<std::vector<int>> pyr(n);
    for (int i = 0; i < n; ++i) {
        pyr[i].resize(i + 1);
        for (int j = 0; j <= i; ++j) {
            pyr[i][j] = std::rand() % 100 + 1;
        }
    }
    return pyr;
}
std::pair<int, std::vector<int>> min_path(const std::vector<std::vector<int>>& Moon) {
    int height = Moon.size();
    std::vector<std::vector<int>> Dp_Moon(height);
    for (int i = 0; i < height; i++) {
        Dp_Moon[i].resize(i + 3, 99999999);
    }
    Dp_Moon[0][0] = Moon[0][0];

    for (int i = 1; i < height; ++i) {
        for (int j = 0; j <= i; ++j) {
            int min_prev = 9999;
            if (j > 0) min_prev = std::min(min_prev, Dp_Moon[i-1][j-1]);
            if (j < i) min_prev = std::min(min_prev, Dp_Moon[i-1][j]);
            if (j < i-1) min_prev = std::min(min_prev, Dp_Moon[i-1][j+1]);
            Dp_Moon[i][j] = Moon[i][j] + min_prev;
        }
    }
    int current = std::min_element(Dp_Moon[height-1].begin(), Dp_Moon[height-1].end()) - Dp_Moon[height-1].begin();
    int time = Dp_Moon[height - 1][current];

    std::vector<int> Path;
    Path.push_back(Moon[height-1][current]);
    for (int i = height-2; i >= 0; --i) {
        if (current == 0) {
            current = std::min_element(Dp_Moon[i].begin(), Dp_Moon[i].begin() + 2) - Dp_Moon[i].begin();
        } else {
            current = std::min_element(Dp_Moon[i].begin() + current - 1, Dp_Moon[i].begin() + current + 1) - Dp_Moon[i].begin();
        }
        Path.push_back(Moon[i][current]);
    }
    std::reverse(Path.begin(), Path.end());
    return {time, Path};
}
int main() {
    std::cout << "Здравствуйте, Введите высоту пирамиды: ";
    int n;
    std::cin >> n;
    std::rand();
    auto pyr = Generate_Moon(n);
    std::cout << "Гора:" << std::endl;
    for (const auto& row : pyr) {
        for (size_t i = 0; i < row.size(); ++i) {
            std::cout << row[i] << (i < row.size() - 1 ? " " : "");
        }
        std::cout << "\n";
    }
    std::cout << "Результат:" << std::endl;
    auto result = min_path(pyr);
    std::cout << result.first << "\n";
    for (size_t i = 0; i < result.second.size(); ++i) {
        std::cout << result.second[i] << (i < result.second.size() - 1 ? " " : "");
    }
    std::cout << "\n";
    return 0;
}
