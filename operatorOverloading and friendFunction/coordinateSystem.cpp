#include <bits/stdc++.h>
using namespace std;
class Coordinate
{
private:
    float abscissa;
    float ordinate;

public:
    Coordinate(float x = 0.0, float y = 0.0) : abscissa(x), ordinate(y) {}
    ~Coordinate() {}
    void display() const
    {
        cout << "(" << abscissa << ", " << ordinate << ")";
    }

    float getDistance(const Coordinate &c)
    {
        float dx = c.abscissa - abscissa;
        float dy = c.ordinate - ordinate;
        return sqrt(dx * dx + dy * dy);
    }
    float getDistance() const
    {
        return sqrt(abscissa * abscissa + ordinate * ordinate);
    }

    void moveX(float val)
    {
        abscissa += val;
    }
    void moveY(float val)
    {
        ordinate += val;
    }

    void move(float val)
    {
        moveX(val);
        moveY(val);
    }

    bool operator>(const Coordinate &c) const
    {
        return getDistance() > c.getDistance();
    }

    bool operator<(const Coordinate &c) const
    {
        return getDistance() < c.getDistance();
    }
    bool operator>=(const Coordinate &c) const
    {
        return getDistance() >= c.getDistance();
    }

    bool operator<=(const Coordinate &c) const
    {
        return getDistance() <= c.getDistance();
    }

    bool operator==(const Coordinate &c) const
    {
        return abscissa == c.abscissa && ordinate == c.ordinate;
    }

    bool operator!=(const Coordinate &c) const
    {
        return !(*this == c);
    }
    Coordinate &operator++()
    {
        move(1.0);
        return *this;
    }
    Coordinate operator++(int)
    {
        Coordinate temp(*this);
        move(1.0);
        return temp;
    }
    Coordinate &operator--()
    {
        move(-1.0);
        return *this;
    }
    Coordinate operator--(int)
    {
        Coordinate temp(*this);
        move(-1.0);
        return temp;
    }
};

int main()
{
    using namespace std;

    Coordinate c1(1, 1);
    Coordinate c2(-1, -1);
    Coordinate c3(2, 2);

    cout << "c1 > c2: " << (c1 > c2) << endl;
    cout << "c1 < c2: " << (c1 < c2) << endl;
    cout << "c1 >= c2: " << (c1 >= c2) << endl;
    cout << "c1 <= c2: " << (c1 <= c2) << endl;
    cout << "c1 == c2: " << (c1 == c2) << endl;
    cout << "c1 != c2: " << (c1 != c2) << endl;

    cout << "c1 before ++: ";
    c1.display();
    cout << endl;

    cout << "c1 after ++ (prefix): ";
    (++c1).display();
    cout << endl;

    cout << "c1 after ++ (postfix): ";
    (c1++).display();
    cout << endl;

    cout << "c1 before --: ";
    c1.display();
    cout << endl;

    cout << "c1 after -- (prefix): ";
    (--c1).display();
    cout << endl;

    cout << "c1 after -- (postfix): ";
    (c1--).display();
    cout << endl;

    return 0;
}
