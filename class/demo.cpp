#include <iostream>
using namespace std;

int main()
{
    cout << 3.14 << " Hello world!" << endl;

    int a = 25;
    int b = 0b11001; // binary
    int c = 031;
    int d = 0x19; // hex

    cout << hex; // switch to hexadecimal
    cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
    cout << oct; // switch to octal
    cout << a << ' ' << b << ' ' << c << ' ' << d << endl;

    char ch = 'A';

    char ch1 = ch + 32; // lower a
    char ch2 = ch | 0b00100000;
    char ch3 = ch | 0x20;

    // x ^ x == 0
    // x ^ 1111..1 = ~x

    cout << ch << ch1 << ch2 << ch3 << endl;

    // lower to upper
    char upper = ch1 & 0xDF;

    cout << dec;
    cout << "Upper letters " << upper << endl;

    return 0;
}