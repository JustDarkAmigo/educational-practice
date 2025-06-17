#include <iostream>
#include <vector>
using namespace std;

void snow_center(int n, int k){
  vector<int> snow_level(n,0);
  int count_k = 0;
  int command, a, b;
  while (count_k != k)
  {
    cin >> command >> a >> b;
    if (command == 1){
      snow_level[a-1] += b;
    } else if (command == 2){
      int snow_count = 0;
      for (int i = a-1; i <= b-1; i++){
        snow_count += snow_level[i];
      }
      cout << snow_count << endl;
    } else {
      cout << "Неправильные входные данные. они должны начинаться либо с 1, либо с 2." << endl;
      continue;
    }
    ++count_k;
  }
}

int main() {
  int n,k;
  cout << "введите количество улиц и число запросов через пробел: ";
  cin >> n >> k;
  snow_center(n,k);
  return 0;
}
