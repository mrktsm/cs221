#include <iostream>
#include <iomanip>
#include <typeinfo>
using namespace std;

int main() {
    const unsigned short ZERO = 0;
    
    cout << "=== What ~ZERO actually returns ===" << endl;
    cout << "ZERO = " << ZERO << " (decimal)" << endl;
    cout << "ZERO = 0x" << hex << ZERO << " (hex)" << endl;
    
    auto result = ~ZERO;
    cout << "\n~ZERO returns:" << endl;
    cout << "Type: " << typeid(result).name() << " (i = int)" << endl;
    cout << "Value (decimal): " << dec << result << endl;
    cout << "Value (hex): 0x" << hex << result << endl;
    cout << "Value (unsigned hex): 0x" << hex << (unsigned int)result << endl;
    
    cout << "\n=== When cast back to unsigned short ===" << endl;
    unsigned short casted = (unsigned short)(~ZERO);
    cout << "Casted value (decimal): " << dec << casted << endl;
    cout << "Casted value (hex): 0x" << hex << casted << endl;
    
    return 0;
}
