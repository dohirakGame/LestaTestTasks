#include <iostream>
using namespace std;

class EvenNumber {
public:
    bool IsEven(int value) {
        return value % 2 == 0;
    }
    
    bool ByteEven(int value) {
        return value & 1;
    }
};

int main() {
    int check;
    EvenNumber evenNumber;

    cout << "Enter number - ";
    cin >> check;

    cout << "IsEven: ";
    evenNumber.IsEven(check) ? cout << check << " is even\n" : cout << check << " is not even\n";

    cout << "ByteEven: ";
    !evenNumber.ByteEven(check) ? cout << check << " is even\n" : cout << check << " is not even\n";
}