#include <iostream>
#include <string>
using namespace std;
bool isValidCarNumber(const string& number) {
    if (number.length() != 6) return false;

    if (!isupper(number[0])) return false;

    for (int i = 1; i <= 3; i++) {
        if (!isdigit(number[i])) return false;
    }

    for (int i = 4; i < 6; i++) {
        if (!isupper(number[i])) return false;
    }
    return true;
}
int main() {
    string carNumber;
    cout << "Введите номер машины: ";
    cin >> carNumber;
    if (isValidCarNumber(carNumber)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}
