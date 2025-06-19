#include <iostream>
#include <vector>
#include <string>
using namespace std;

string decrypt(const string& encrypted, const vector<int>& permutation, int k) {
    int n = encrypted.size();
    string original = encrypted;
    vector<int> inversePermutation(n);
    for (int i = 0; i < n; ++i) {
        inversePermutation[permutation[i] - 1] = i;
    }
    for (int i = 0; i < k; ++i) {
        string temp = original;
        for (int j = 0; j < n; ++j) {
            original[j] = temp[inversePermutation[j]];
        }
    }
    return original;
}
int main() {
    int n, k;
    cout << "Введите данные:";
    cin >> n >> k;
    vector<int> permutation(n);
    for (int i = 0; i < n; ++i) {
        cin >> permutation[i];
    }
    string encrypted;
    cin >> encrypted;
    string original = decrypt(encrypted, permutation, k);
    cout << original << endl;
    return 0;
}
