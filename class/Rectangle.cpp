#include <iostream>
using namespace std;

template <typename T>
class Rectangle
{
private:
    int width;
    int height;

public:
    Rectangle() : width(1), height(1)
    {
    }

    Rectangle(int w, int h) : width(w), height(h)
    {
    }

    int getWidth()
    {
        return width;
    }

    int getHeight()
    {
        return height;
    }

    // Rectangle add(Rectangle other)
    Rectangle add(Rectangle other)
    {
        int newWidth = this->width + other.getWidth();
        int newHeight = this->height + other.getHeight();

        Rectangle result(newWidth, newHeight);
        return result;
    }

    Rectangle operator+(Rectangle other)
    {
        int newWidth = this->width + other.getWidth();
        int newHeight = this->height + other.getHeight();

        Rectangle result(newWidth, newHeight);
        return result;
    }

    Rectangle operator+=(Rectangle other)
    {
        this->width += other.getWidth();
        this->height += other.getHeight();

        return *this;
    }

    // Java way
    Rectangle mul(int factor)
    {
        int newHeight = height * factor;
        int newWidth = width * factor;

        Rectangle result(newWidth, newHeight);
        return result;
    }

    // New C++ style
    // One parameter is implicit
    Rectangle operator*(int factor)
    {
        Rectangle result = factor * (*this);
        return result;
        // int newHeight = height * factor;
        // int newWidth = width * factor;

        // Rectangle result(newWidth, newHeight);
        // return result;
    }

    void print()
    {
        cout << "height: " << height << " width: " << width << endl;
    }
};

// Both parameters are explicit here
Rectangle operator*(int factor, Rectangle rectangle)
{
    int newWidth = factor * rectangle.getWidth();
    int newHeight = factor * rectangle.getHeight();

    Rectangle result(newWidth, newHeight);

    return result;
}

int main()
{
    Rectangle r1(3, 4);
    Rectangle r2(10, 2);

    // Rectangle r3 = r1.add(r2);
    Rectangle r3 = r1 + r2;
    Rectangle r4 = r1 * 5; // 5 * r1 throws error -> 5 is primitive type
    // Rectangle r4 = r1.mul(5);

    r3.print();
    r4.print();
}