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
    
    bool none() {
        return data == ZERO;
    }

    bool any() {
        return !none();
    }

    bool all() {
        return data == (unsigned short)(~ZERO);
    }

    void flip() {
        data ^= (~ZERO);
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
        
        // Swap nibbles
        data = ((highByte >> 4) | (highByte << 4)) & highMask | lowByte;
    }

    void swapLo() {
        unsigned short highMask = ~ZERO << 8;       
        unsigned short lowByte = data & (~highMask);
        unsigned short highByte = data & highMask;   

        data = highByte | ((lowByte >> 4) | (lowByte << 4)) & (~highMask);
    }

    bool isPow2() {
       return (data != ZERO) && // Zero is not a power of 2
              ((data & (data - 1)) == ZERO); 
    }

    void clearLast1() {
        data &= (data - 1);
    }

    int count() {
        int counter = 0;
        unsigned short mask = 1;
        
        for (int i = 0; i < sizeof(data) * 8; i++) {
            if (data & mask) {
                counter++;
            }
            mask <<= 1;  // Shift mask to next position
        }
        
        return counter;
    }

    void printBinary() {
        cout << "0b";
        for (int i = sizeof(data) * 8 - 1; i >= 0; i--) {
            cout << ((data >> i) & 1);
        }
    }

    void print() {
        cout << "[" << dec << data << ", 0x" << hex << data << ", 0" << oct << data << ", ";
        printBinary();
        cout << "]" << endl;
        cout << dec;  
    }
};

unsigned short id(unsigned short value) {
    return value;
}

int main() {
    // Test constructor and getValue
    Bitset bits1(0xABCD);
    assert(bits1.getValue() == id(0xABCD));
    
    Bitset bits2(0x0000);
    assert(bits2.getValue() == id(0x0000));
    
    Bitset bits3(0xFFFF);
    assert(bits3.getValue() == id(0xFFFF));
    
    // Test none(), any(), all()
    Bitset allZeros(0x0000);
    assert(allZeros.none());
    assert(!allZeros.any());
    assert(!allZeros.all());
    
    Bitset allOnes(0xFFFF);
    assert(!allOnes.none());
    assert(allOnes.any());
    assert(allOnes.all());
    
    Bitset someOnes(0x00F0);
    assert(!someOnes.none());
    assert(someOnes.any());
    assert(!someOnes.all());
    
    // Test get()
    Bitset testGet(0x0005);  // Binary: 0000000000000101
    assert(testGet.get(0));   // Bit 0 is 1
    assert(!testGet.get(1));  // Bit 1 is 0
    assert(testGet.get(2));   // Bit 2 is 1
    assert(!testGet.get(3));  // Bit 3 is 0
    
    // Test set()
    Bitset testSetAll(0x0000);
    testSetAll.set();
    assert(testSetAll.getValue() == id(0xFFFF));
    
    Bitset testSetIndex(0x0000);
    testSetIndex.set(3);
    assert(testSetIndex.getValue() == id(0x0008));  // Bit 3 set
    testSetIndex.set(0);
    assert(testSetIndex.getValue() == id(0x0009));  // Bits 0 and 3 set
    
    // Test clear()
    Bitset testClearAll(0xFFFF);
    testClearAll.clear();
    assert(testClearAll.getValue() == id(0x0000));
    
    Bitset testClearIndex(0xFFFF);
    testClearIndex.clear(3);
    assert(testClearIndex.getValue() == id(0xFFF7));  // All bits except bit 3
    
    // Test flip()
    Bitset testFlip(0xAAAA);  // 1010101010101010
    testFlip.flip();
    assert(testFlip.getValue() == id(0x5555));  // 0101010101010101
    
    // Test swap()
    Bitset testSwap(0xABCD);
    testSwap.swap();
    assert(testSwap.getValue() == id(0xCDAB));  // Bytes swapped
    
    // Test swapHi()
    Bitset testSwapHi(0xABCD);  // AB = 1010 1011, CD unchanged
    testSwapHi.swapHi();
    assert(testSwapHi.getValue() == id(0xBACD));  // BA = 1011 1010
    
    // Test swapLo()
    Bitset testSwapLo(0xABCD);  // AB unchanged, CD = 1100 1101
    testSwapLo.swapLo();
    assert(testSwapLo.getValue() == id(0xABDC));  // DC = 1101 1100
    
    // Test isPow2()
    Bitset pow2Test1(1);     // 2^0
    assert(pow2Test1.isPow2());
    
    Bitset pow2Test2(2);     // 2^1
    assert(pow2Test2.isPow2());
    
    Bitset pow2Test3(4);     // 2^2
    assert(pow2Test3.isPow2());
    
    Bitset pow2Test4(8);     // 2^3
    assert(pow2Test4.isPow2());
    
    Bitset pow2Test5(16);    // 2^4
    assert(pow2Test5.isPow2());
    
    Bitset notPow2Test1(0);  // 0 is not a power of 2
    assert(!notPow2Test1.isPow2());
    
    Bitset notPow2Test2(3);  // 3 is not a power of 2
    assert(!notPow2Test2.isPow2());
    
    Bitset notPow2Test3(5);  // 5 is not a power of 2
    assert(!notPow2Test3.isPow2());
    
    Bitset notPow2Test4(6);  // 6 is not a power of 2
    assert(!notPow2Test4.isPow2());
    
    // Test clearLast1()
    Bitset clearTest1(0x000C);  // Binary: 1100, should become 1000
    clearTest1.clearLast1();
    assert(clearTest1.getValue() == id(0x0008));
    
    Bitset clearTest2(0x000A);  // Binary: 1010, should become 1000
    clearTest2.clearLast1();
    assert(clearTest2.getValue() == id(0x0008));
    
    Bitset clearTest3(0x0007);  // Binary: 0111, should become 0110
    clearTest3.clearLast1();
    assert(clearTest3.getValue() == id(0x0006));
    
    // Test count()
    Bitset countTest1(0x0007);  // Binary: 0111, should count 3 bits
    assert(countTest1.count() == 3);
    
    Bitset countTest2(0xFFFF);  // All bits set, should count 16 bits
    assert(countTest2.count() == 16);
    
    Bitset countTest3(0x0000);  // No bits set, should count 0 bits
    assert(countTest3.count() == 0);
    
    Bitset countTest4(0x1010);  // Binary: 0001000000010000, should count 2 bits
    assert(countTest4.count() == 2);
    
    // Test enhanced print() and printBinary() - visual verification
    cout << "\n=== Testing print methods ===" << endl;
    
    Bitset printTest(25);  // Should print [25, 0x19, 031, 0b0000000000011001]
    cout << "Value 25: ";
    printTest.print();
    
    Bitset printTest2(0xABCD);
    cout << "Value 0xABCD: ";
    printTest2.print();
    
    cout << "\nBinary only for 25: ";
    printTest.printBinary();
    cout << endl;
    
    cout << "\nAll tests passed!" << endl;
    
    return 0;
}