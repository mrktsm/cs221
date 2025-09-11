#include <string>
#include <map>

using namespace std;

map<char, int> ROMAN_MAP = {
    {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
    {'C', 100}, {'D', 500}, {'M', 1000}
};

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