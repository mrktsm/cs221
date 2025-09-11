#include <string>
#include <map>

using namespace std;

map<char, int> ROMAN_MAP = {
    {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
    {'C', 100}, {'D', 500}, {'M', 1000}
};

string to_string( const string& str ) {
	return str;
}

template<typename E1, typename E2>
void assertEquals(E1 a, E2 b) {
	string strA = to_string(a);
	string strB = to_string(b);

	if ( strA != strB ) {
	    cout << "failed: " << a << " != " << b << endl;
	}
}

long from10(long number, int base) {
    long result = 0;
    long position = 1;

    while (number > 0) {
        long remainder = number % base;
        result += position * remainder;
        position *= 10; // Shift position left
        number /= base;
    }

    return result;
}

char getSymbol(long digit) {
    if (digit >= 0 && digit <= 9) {
        return '0' + digit;
    } else {
        return 'A' + (digit - 10);
    }
}

string from10(long number) {
    if (number == 0) return "0";

    string result = "";

    while (number > 0) {
        long remainder = number % 16;
        result = getSymbol(remainder) + result;
        number /= 16;
    }

    return result;
}

long to10(long number, int base) {
    long result = 0;
    long position = 1;

    while (number > 0) {
        long lastDigit = number % 10;
        result += lastDigit * position;
        position *= base;
        number /= 10;
    }

    return result;
}

long getValue(char symbol) {
    if (symbol >= '0' && symbol <= '9') {
        return symbol - '0';
    } else {
        return (symbol - 'A') + 10;
    }
}

long to10(string number) {
    long result = 0;

    int weight = 1;
    for (int i = number.length() - 1; i >= 0; i--) {
        long lastDigit = getValue(number[i]);
        result += lastDigit * weight;
        weight *= 16;
    }

    return result;
}

int fromRoman(string number) {
    int result = 0;

    for (int i = 0; i < number.length() - 1; i++) {
        int curr = ROMAN_MAP[number[i]];
        int next = ROMAN_MAP[number[i + 1]];

        result += (curr < next) ? -curr : curr;
    }
    result += ROMAN_MAP[number[number.length() - 1]];

    return result;
}

int main() {
    // Test from10(long, int) 
    assertEquals(from10(9, 2), 1001L);
    assertEquals(from10(9, 7), 12L);
    assertEquals(from10(15, 8), 17L);
    assertEquals(from10(100, 3), 10201L);
    assertEquals(from10(123, 10), 123L);
    assertEquals(from10(0, 2), 0L);
    
    // Test from10(long) hex 
    assertEquals(from10(13), string("D"));
    assertEquals(from10(20), string("14"));
    assertEquals(from10(255), string("FF"));
    assertEquals(from10(2748), string("ABC"));
    assertEquals(from10(43981), string("ABCD"));
    assertEquals(from10(171), string("AB"));
    
    // Test to10 
    assertEquals(to10(1001, 2), 9L);
    assertEquals(to10(12, 7), 9L);
    assertEquals(to10(17, 8), 15L);
    
    assertEquals(to10("D"), 13L);
    assertEquals(to10("14"), 20L);
    assertEquals(to10("FF"), 255L);
    
    // Test fromRoman 
    assertEquals(fromRoman("V"), 5);
    assertEquals(fromRoman("IV"), 4);
    assertEquals(fromRoman("IX"), 9);
    assertEquals(fromRoman("XIV"), 14);
    assertEquals(fromRoman("XL"), 40);
    assertEquals(fromRoman("CD"), 400);
    assertEquals(fromRoman("CM"), 900);
    
    return 0;
}