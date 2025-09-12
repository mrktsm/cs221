#include <cassert>
#include <iostream>

using namespace std;

class Bitset {
private:
    const unsigned short ZERO = 0;
    unsigned short data;

public:
    explicit Bitset(unsigned short theBits) : data(theBits) {}

    unsigned short getValue() {
        return data;
    }

    // prints the value of the bitset as hex number    
    // note: oct would print the octal version
    //       dec would print the decimal version
    //       there is no specifier for binary
    void print() {
        cout << hex << data << endl;

        cout << dec;   // should always be the last line in this method to reset to decimal
    }

    bool none() {
        return data == ZERO;
    }

    bool any() {
        return !none();
    }

    bool all() {
        return data == ~ZERO;
    }

    bool flip() {
        return data ^ ~ZERO;
    }

    bool get(int index) {
        unsigned short mask = 1;

        mask <<= index;

        return bool(data & mask); // type-cast to boolean: 1 == true, 0 == false
    }

    void set() {
        data = ~ZERO;
    }

    void set(int index) {
        unsigned short mask = 1;

        mask <<= index;

        data |= mask;
    }

    void clear() {
        data = ZERO;
    }

    void clear(int index) {
        unsigned short mask = 1;

        mask <<= index;

        data &= ~mask;
    }

    void swap() {
        unsigned short shift = 8;

        unsigned short left = data << shift;
        unsigned short right = data >> shift;

        data = left | right;
    }

    void swapHi() {
        unsigned short highMask = ~ZERO << 8;       
        unsigned short lowByte = data & (~highMask);
        unsigned short highByte = data & highMask;   
        
        // Swap nibbles in high byte
        data = ((highByte >> 4) | (highByte << 4)) & highMask | lowByte;
    }

    void swapLo() {
        unsigned short highMask = ~ZERO << 8;       
        unsigned short lowByte = data & (~highMask);
        unsigned short highByte = data & highMask;   

        data = highByte | ((lowByte >> 4) | (lowByte << 4));
    }

    bool isPow2() {
       return (data != ZERO) && // Zero is not a power of 2
              ((data & (data - 1)) == ZERO); 
    }

    void clearLast1() {
        data &= (data - 1);
    }
};