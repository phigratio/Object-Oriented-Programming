#include <bits/stdc++.h>
using namespace std;
class Counter
{
private:
    int count;
    int incrementStep;

public:
    Counter(int initialCount = 0, int step = 1) : count(max(0, initialCount)), incrementStep(max(1, step)) {}

    void setIncrementStep(int stepVal)
    {
        if (stepVal > 0)
        {
            incrementStep = stepVal;
        }
    }

    int getCount() const
    {
        return count;
    }

    void increment()
    {
        count += incrementStep;
    }

    void resetCount()
    {
        count = 0;
    }

    friend Counter operator+(const Counter &c1, const Counter &c2);
    friend bool operator>(const Counter &c1, const Counter &c2);
    friend bool operator<(const Counter &c1, const Counter &c2);
    friend bool operator>=(const Counter &c1, const Counter &c2);
    friend bool operator<=(const Counter &c1, const Counter &c2);
    friend bool operator==(const Counter &c1, const Counter &c2);
    friend bool operator!=(const Counter &c1, const Counter &c2);
    friend Counter operator+=(Counter &c1, const Counter &c2);
    friend Counter operator++(Counter &c, int);
    friend Counter operator++(Counter &c);
    friend void testFunction(const Counter &c);
};

Counter operator+(const Counter &c1, const Counter &c2)
{
    Counter result(c1.count + c2.count, max(c1.incrementStep, c2.incrementStep));
    return result;
}

bool operator>(const Counter &c1, const Counter &c2)
{
    return c1.count > c2.count;
}

bool operator<(const Counter &c1, const Counter &c2)
{
    return c1.count < c2.count;
}

bool operator>=(const Counter &c1, const Counter &c2)
{
    return c1.count >= c2.count;
}

bool operator<=(const Counter &c1, const Counter &c2)
{
    return c1.count <= c2.count;
}

bool operator==(const Counter &c1, const Counter &c2)
{
    return c1.count == c2.count;
}

bool operator!=(const Counter &c1, const Counter &c2)
{
    return c1.count != c2.count;
}

Counter operator+=(Counter &c1, const Counter &c2)
{
    c1.count += c2.count;
    c1.incrementStep = max(c1.incrementStep, c2.incrementStep);
    return c1;
}

Counter operator++(Counter &c, int)
{
    Counter temp(c);
    c.increment();
    return temp;
}

Counter operator++(Counter &c)
{
    c.increment();
    return c;
}

void testFunction(const Counter &c)
{
    cout << c.getCount();
}

int main()
{
    Counter c1(3, 2);
    Counter c2(5, 4);

    Counter c3 = c1 + c2;
    cout << "c3 = c1 + c2: " << c3.getCount() << endl;

    cout << "c1 > c2: " << (c1 > c2) << endl;
    cout << "c1 < c2: " << (c1 < c2) << endl;
    cout << "c1 >= c2: " << (c1 >= c2) << endl;
    cout << "c1 <= c2: " << (c1 <= c2) << endl;
    cout << "c1 == c2: " << (c1 == c2) << endl;
    cout << "c1 != c2: " << (c1 != c2) << endl;

    c1 += c2;
    cout << "c1 += c2: " << c1.getCount() << endl;

    Counter c4 = c1++;
    cout << "c4 = c1++: " << c4.getCount() << endl;

    Counter c5 = ++c1;
    cout << "c5 = ++c1: " << c5.getCount() << endl;
    testFunction(c1);

    return 0;
}