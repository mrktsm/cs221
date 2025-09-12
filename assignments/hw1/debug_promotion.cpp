#include <iostream>
#include <typeinfo>
using namespace std;

int main() {
    const unsigned short ZERO = 0;
    unsigned short data = 0xFFFF;
    
    cout << "ZERO type: " << typeid(ZERO).name() << endl;
    cout << "~ZERO type: " << typeid(~ZERO).name() << endl;
    cout << "data type: " << typeid(data).name() << endl;
    
    cout << "ZERO = " << ZERO << endl;
    cout << "~ZERO = " << ~ZERO << endl;
    cout << "data = " << data << endl;
    
    cout << "data == ~ZERO? " << (data == ~ZERO) << endl;
    cout << "data == (unsigned short)(~ZERO)? " << (data == (unsigned short)(~ZERO)) << endl;
    
    return 0;
}
