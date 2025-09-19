#include <cassert>
#include <iostream>

using namespace std;

template <typename T>
class Bitset
{
private:
    const T ZERO = 0;
    const int SIZE = 8 * sizeof(T);
    const T ONE = 1;
    const T ALL_ONES = (T)(~ZERO);

    T data;

public:
    explicit Bitset(T theBits) : data(theBits) {}

    T getValue() const
    {
        return data;
    }

    bool none()
    {
        return data == ZERO;
    }

    bool any()
    {
        return !none();
    }

    bool all()
    {
        return data == ALL_ONES;
    }

    void flip()
    {
        data ^= ALL_ONES;
    }

    bool get(int index)
    {
        T mask = ONE;

        mask <<= index;

        return bool(data & mask); // type-cast to boolean: 1 == true, 0 == false
    }

    void set()
    {
        data = ~ALL_ONES;
    }

    void set(int index)
    {
        T mask = ONE;

        mask <<= index;

        data |= mask;
    }

    void clear()
    {
        data = ZERO;
    }

    void clear(int index)
    {
        T mask = ONE;

        mask <<= index;

        data &= ~mask;
    }

    void swap()
    {
        T shift = SIZE / 2;

        T lowToHigh = data << shift; // Move low byte to high position
        T highToLow = data >> shift; // Move high byte to low position

        data = lowToHigh | highToLow;
    }

    void swapHi()
    {
        T highMask = ~ALL_ONES << SIZE / 2;
        T lowByte = data & (~highMask);
        T highByte = data & highMask;

        // Swap nibbles
        data = ((highByte >> 4) | (highByte << 4)) & highMask | lowByte;
    }

    void swapLo()
    {
        T highMask = ~ALL_ONES << SIZE / 2;
        T lowByte = data & (~highMask);
        T highByte = data & highMask;

        data = highByte | ((lowByte >> 4) | (lowByte << 4)) & (~highMask);
    }

    bool isPow2()
    {
        return (data != ZERO) && // Zero is not a power of 2
               ((data & (data - 1)) == ZERO);
    }

    void clearLast1()
    {
        data &= (data - 1);
    }

    int count()
    {
        int counter = 0;
        T mask = ONE;

        for (int i = 0; i < SIZE - 1; i++)
        {
            if (data & mask)
            {
                counter++;
            }
            mask <<= 1; // Shift mask to next position
        }

        return counter;
    }

    void printBinary()
    {
        cout << "0b";
        for (int i = SIZE - 1; i >= 0; i--)
        {
            cout << ((data >> i) & 1);
        }
    }

    void print()
    {
        cout << "[" << dec << data << ", 0x" << hex << data << ", 0" << oct << data << ", ";
        printBinary();
        cout << "]" << endl;
        cout << dec;
    }

    bool operator==(const Bitset<T>& other) const {
        return data == other.getValue();
    }

    Bitset<T> operator&(const Bitset<T>& other) const {
        T value = data & other.getValue();
        return Bitset<T>(value);
    }

    Bitset<T> operator~() const {
        T value = (T)(~data);
        return Bitset<T>(value);
    }

    Bitset<T> operator<<(int shift) const {
        T value = data << shift;
        return Bitset<T>(value);
    }

    bool operator<(const Bitset<T>& other) const {
        return data < other.getValue();
    }

    Bitset<T>& operator^=(const Bitset<T>& other) {
        data ^= other.getValue();
        return *this;
    }

    Bitset<T>& operator>>=(int shift) {
        data >>= shift;
        return *this;
    }

    Bitset<T>& operator++() {
        data++;
        return *this;
    }
};

template <typename T>
bool operator!=(const Bitset<T>& a, const Bitset<T>& b) {
    return !(a == b);
}

template <typename T>
Bitset<T> operator|(const Bitset<T>& a, const Bitset<T>& b) {
    T result = (T)(~((~a.getValue()) & (~b.getValue())));
    return Bitset<T>(result);
}

template <typename T>
Bitset<T> operator^(const Bitset<T>& a, const Bitset<T>& b) {
    T value = a.getValue() ^ b.getValue();
    return Bitset<T>(value);
}

template <typename T>
ostream& operator<<(ostream& os, const Bitset<T>& bitset) {
    T data = bitset.getValue();
    os << '[' << dec << data 
       << ", 0x" << hex << data 
       << ", 0" << oct << data << ']';
    os << dec;  // restore dec
    return os;
}

// template <typename T>
// Bitset<T> operator~(const Bitset<T>& bitset) {
//     T value = (T)(~bitset.getValue());
//     return Bitset<T>(value);
// }

template <typename T>
Bitset<T> operator>>(const Bitset<T>& bitset, int shift) {
    T value = bitset.getValue() >> shift;
    return Bitset<T>(value);
}

template <typename T>
bool operator>=(const Bitset<T>& a, const Bitset<T>& b) {
    return !(a < b);
}

unsigned short id(unsigned short value)
{
    return value;
}

int main()
{
    // Basic constructor tests
    Bitset b1(0xABCD);
    assert(b1.getValue() == id(0xABCD));

    Bitset empty(0x0000);
    assert(empty.getValue() == id(0x0000));

    Bitset full(0xFFFF);
    assert(full.getValue() == id(0xFFFF));
    // Testing none/any/all methods
    Bitset zeros(0x0000);
    assert(zeros.none());
    assert(!zeros.any());
    assert(!zeros.all());

    Bitset ones(0xFFFF);
    assert(!ones.none());
    assert(ones.any());
    assert(ones.all());

    Bitset partial(0x00F0);
    assert(!partial.none());
    assert(partial.any());
    assert(!partial.all());

    // Test get method
    Bitset getBits(0x0005);
    assert(getBits.get(0));
    assert(!getBits.get(1));
    assert(getBits.get(2));
    assert(!getBits.get(3));

    // Test set methods
    Bitset setAll(0x0000);
    setAll.set();
    assert(setAll.getValue() == id(0xFFFF));

    Bitset setBits(0x0000);
    setBits.set(3);
    assert(setBits.getValue() == id(0x0008));
    setBits.set(0);
    assert(setBits.getValue() == id(0x0009));

    // Test clear()
    Bitset testClearAll(0xFFFF);
    testClearAll.clear();
    assert(testClearAll.getValue() == id(0x0000));

    Bitset testClearIndex(0xFFFF);
    testClearIndex.clear(3);
    assert(testClearIndex.getValue() == id(0xFFF7));

    // Test flip()
    Bitset testFlip(0xAAAA);
    testFlip.flip();
    assert(testFlip.getValue() == id(0x5555));

    // Test swap()
    Bitset testSwap(0xABCD);
    testSwap.swap();
    assert(testSwap.getValue() == id(0xCDAB));

    // Test swapHi()
    Bitset testSwapHi(0xABCD);
    testSwapHi.swapHi();
    assert(testSwapHi.getValue() == id(0xBACD));

    // Test swapLo()
    Bitset testSwapLo(0xABCD);
    testSwapLo.swapLo();
    assert(testSwapLo.getValue() == id(0xABDC));

    // Test isPow2()
    Bitset pow2Test1(1);
    assert(pow2Test1.isPow2());

    Bitset pow2Test2(2);
    assert(pow2Test2.isPow2());

    Bitset pow2Test3(4);
    assert(pow2Test3.isPow2());

    Bitset pow2Test4(8);
    assert(pow2Test4.isPow2());

    Bitset pow2Test5(16);
    assert(pow2Test5.isPow2());

    Bitset notPow2Test1(0);
    assert(!notPow2Test1.isPow2());

    Bitset notPow2Test2(3);
    assert(!notPow2Test2.isPow2());

    Bitset notPow2Test3(5);
    assert(!notPow2Test3.isPow2());

    Bitset notPow2Test4(6);
    assert(!notPow2Test4.isPow2());

    // Test clearLast1()
    Bitset clearTest1(0x000C);
    clearTest1.clearLast1();
    assert(clearTest1.getValue() == id(0x0008));

    Bitset clearTest2(0x000A);
    clearTest2.clearLast1();
    assert(clearTest2.getValue() == id(0x0008));

    Bitset clearTest3(0x0007);
    clearTest3.clearLast1();
    assert(clearTest3.getValue() == id(0x0006));

    // Test count()
    Bitset countTest1(0x0007);
    assert(countTest1.count() == 3);

    Bitset countTest2(0xFFFF);
    assert(countTest2.count() == 16);

    Bitset countTest3(0x0000);
    assert(countTest3.count() == 0);

    Bitset countTest4(0x1010);
    assert(countTest4.count() == 2);

    // Print tests
    cout << "\n=== Testing output methods ===" << endl;

    Bitset test25(25);
    cout << "Value 25: ";
    test25.print();

    Bitset testHex(0xABCD);
    cout << "Value 0xABCD: ";
    testHex.print();

    cout << "\nBinary for 25: ";
    test25.printBinary();
    cout << endl;

    cout << "\nAll tests passed!" << endl;

    return 0;
}