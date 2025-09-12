#include <iostream>
using namespace std;

int main() {
    const unsigned short ZERO = 0;
    cout << "ZERO = " << ZERO << endl;
    cout << "~ZERO = " << ~ZERO << endl;
    cout << "0xFFFF = " << 0xFFFF << endl;
    cout << "~ZERO == 0xFFFF? " << (~ZERO == 0xFFFF) << endl;
    return 0;
}
