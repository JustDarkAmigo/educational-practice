#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> generateGraph(int n, int m) {
    vector<vector<int>> graph(n + 1);
    cout << "Введите " << m << " рёбер (формат: u v, где u и v <= "<< n <<"):" << endl;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    return graph;
}
void dfs(int v, vector<bool>& visited, const vector<vector<int>>& graph) {
    visited[v] = true;

    for (int neighbor : graph[v]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, graph);
        }
    }
}
int count_communication_lines(int n, const vector<vector<int>>& graph) {
    vector<bool> visited(n+1, false);
    int count = -1;

    for (int i = 1; i < n+1; ++i) {
        if (!visited[i]) {
            dfs(i, visited, graph);
            ++count;
        }
    }

    return count;
}
int main() {
  int n, m;
  cout << "Здравствуйте, введите число вершин графа (узлы сети, не более 1000)" << endl << 
  "и набор рёбер (сохранившиеся линии связи, не более 1000) через пробел и нажмите enter:";
  cin >> n;
  cin >> m;
  vector<vector<int>> graph = generateGraph(n,m);
  if (n <= 0 or m <= 0){
    cout << "неверные данные. Пожалуйста, введите количество вершин, превышающее 0!" << endl;
      return 0;
  }
  int count = count_communication_lines(n, graph);
  cout << "минимальное число линий связи: "<<count << endl;
  return 0;
}
