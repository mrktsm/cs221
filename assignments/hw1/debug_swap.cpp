#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    unsigned short data = 0xABCD;
    const unsigned short ZERO = 0;
    
    cout << "Original: 0x" << hex << data << endl;
    
    // Your swapLo logic
    unsigned short highMask = ~ZERO << 8;       
    unsigned short lowByte = data & (~highMask);
    unsigned short highByte = data & highMask;   

    cout << "highMask: 0x" << hex << highMask << endl;
    cout << "lowByte: 0x" << hex << lowByte << endl;
    cout << "highByte: 0x" << hex << highByte << endl;
    
    unsigned short result = highByte | ((lowByte >> 4) | (lowByte << 4));
    cout << "Result: 0x" << hex << result << endl;
    cout << "Expected: 0xABDC" << endl;
    
    return 0;
}
