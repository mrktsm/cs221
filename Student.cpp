#include <iostream>
using namespace std;

class Student
{
private:
    unsigned short data; // 2 bytes
public:
    Student() : data(0) // Will automatically put the value
    {
    }

    Student(unsigned short year) : data(0)
    {
        setYear(year);
    }

    int getYear()
    {
        unsigned short mask = 0b11; // 0x3

        unsigned short year = data & mask;
        year++; // Year is off by one

        return year;
    }

    int getCredits()
    {
        unsigned short mask = 0x1F; // 0b111111;
        mask <<= 2;

        unsigned short credits = data & mask;
        credits >>= 2;
        ++credits;

        return credits;
    }

    void setYear(unsigned short year)
    {
        year--;

        unsigned short mask = 0b11;

        data &= ~mask;

        data |= year;
    }

    void setCredits(unsigned short credits)
    {
        credits--;
        unsigned short mask = 0x1F; // 000...011111
        mask <<= 2;
        data = data & mask;

        data |= credits;
    }
};

int main()
{
    Student s1;    // Would use the default constructor
    Student s2(2); // Would use the other constructor
    cout << s2.getYear() << endl;

    return 0;
}