#include <iostream>
#include <string>
using namespace std;

string decimalToBinary(int num) {
    if (num == 0) {
        return "0";
    }
    else if (num == 1) {
        return "1";
    }
    else {
        return decimalToBinary(num / 2) + to_string(num % 2);
    }
}

int main() {
    system("chcp 1251");
    int decimalNumber = 31;
    string binaryNumber = decimalToBinary(decimalNumber);
    cout << "Десятичное число " << decimalNumber << " в двоичной системе: " << binaryNumber << endl;
    return 0;
}
