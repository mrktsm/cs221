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
    const T ALL_ONES = ~ZERO;

    T data;

public:
    explicit Bitset(T theBits) : data(theBits) {}

    T getValue() const
    {
        return data;
    }

    bool none() const
    {
        return data == ZERO;
    }

    bool any() const
    {
        return !none();
    }

    bool all() const
    {
        return data == ALL_ONES;
    }

    void flip()
    {
        data ^= ALL_ONES;
    }

    bool get(int index) const
    {
        T mask = ONE;

        mask <<= index;

        return bool(data & mask); // type-cast to boolean: 1 == true, 0 == false
    }

    void set()
    {
        data = ALL_ONES;
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
        T highMask = ALL_ONES << SIZE / 2;
        T lowByte = data & (~highMask);
        T highByte = data & highMask;

        // Swap nibbles
        data = ((highByte >> 4) | (highByte << 4)) & highMask | lowByte;
    }

    void swapLo()
    {
        T highMask = ALL_ONES << SIZE / 2;
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

        for (int i = 0; i < SIZE; i++)
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
        T value = ~data;
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
    T result = (~((~a.getValue()) & (~b.getValue())));
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
//     T value = (~bitset.getValue());
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


int main()
{
    // Test with 1-byte bitset
    Bitset<unsigned char> byte_bitset(0xAB);
    assert(byte_bitset.any());
    assert(!byte_bitset.none());
    assert(!byte_bitset.all());
    
    // Test with 8-byte bitset  
    Bitset<unsigned long long> large_bitset(0xABCDEF0123456789ULL);
    assert(large_bitset.any());
    assert(!large_bitset.none());
    assert(!large_bitset.all());
    
    // Test basic Assignment 2 methods
    Bitset<unsigned short> bitset1(0xF0F0);
    assert(bitset1.count() == 8);
    assert(bitset1.get(4));
    assert(!bitset1.get(0));
    
    bitset1.flip();
    assert(bitset1 == Bitset<unsigned short>(0x0F0F));
    
    // Test == and != operators
    Bitset<unsigned short> a(0x1234);
    Bitset<unsigned short> b(0x1234);
    Bitset<unsigned short> c(0x5678);
    
    assert(a == b);
    assert(!(a == c));
    assert(a != c);
    assert(!(a != b));
    
    // Test bitwise operators & | ^ ~
    Bitset<unsigned short> x(0xF0F0);
    Bitset<unsigned short> y(0xFF00);
    
    assert((x & y) == Bitset<unsigned short>(0xF000));
    assert((x | y) == Bitset<unsigned short>(0xFFF0));
    assert((x ^ y) == Bitset<unsigned short>(0x0FF0));
    assert(~x == Bitset<unsigned short>(0x0F0F));
    
    // Test shift operators << >>
    Bitset<unsigned short> shift_test(0x000F);
    
    assert((shift_test << 4) == Bitset<unsigned short>(0x00F0));
    assert((shift_test >> 2) == Bitset<unsigned short>(0x0003));
    
    // Test comparison operators < >=
    Bitset<unsigned short> small(0x0010);
    Bitset<unsigned short> big(0x0020);
    
    assert(small < big);
    assert(!(big < small));
    assert(big >= small);
    assert(small >= small);
    
    // Test assignment operators ^= >>=
    Bitset<unsigned short> assign_test(0xAAAA);
    Bitset<unsigned short> mask(0x00FF);
    
    Bitset<unsigned short> result = assign_test ^= mask;
    assert(assign_test == Bitset<unsigned short>(0xAA55));
    assert(result == Bitset<unsigned short>(0xAA55));
    
    Bitset<unsigned short> assign_test2(0xFF00);
    Bitset<unsigned short> shift_result = assign_test2 >>= 4;
    assert(assign_test2 == Bitset<unsigned short>(0x0FF0));
    assert(shift_result == Bitset<unsigned short>(0x0FF0));
    
    // Test prefix increment operator ++
    Bitset<unsigned short> inc_test(25);
    ++inc_test;
    assert(inc_test == Bitset<unsigned short>(26));
    
    ++(++(++inc_test));
    assert(inc_test == Bitset<unsigned short>(29));
    
    // Test stream output operator <<
    Bitset<unsigned short> output_test(25);
    cout << "Output test: " << output_test << endl;
    
    return 0;
}