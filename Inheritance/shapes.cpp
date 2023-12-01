#include <iostream>
#include <cmath>

using namespace std;

class Shape {
public:
    void whoAmI() {
        cout << "I am a generic shape." << endl;
    }
};
class TwoDimensionalShape : public Shape {
public:
    void whoAmI() {
        cout << "I am a two-dimensional shape." << endl;
    }
};

class ThreeDimensionalShape : public Shape {
public:
    void whoAmI() {
        cout << "I am a three-dimensional shape." << endl;
    }
};

// Derived classes for two-dimensional shapes
class Square : public TwoDimensionalShape {
private:
    double side_length;

public:
    Square(double side_length) : side_length(side_length) {}

    void whoAmI() {
        cout << "I am a square." << endl;
    }
    double calculateArea() {
        return side_length * side_length;
    }

    double calculatePerimeter() {
        return 4 * side_length;
    }
};

class Circle : public TwoDimensionalShape {
private:
    double radius;

public:
    Circle(double radius) : radius(radius) {}
void whoAmI() {
        cout << "I am a circle." << endl;
    }
    double calculateArea() {
        return M_PI * radius * radius;
    }

    double calculatePerimeter() {
        return 2 * M_PI * radius;
    }
};

class Triangle : public TwoDimensionalShape {
private:
    double side_a, side_b, side_c;

public:
    
    Triangle(double a, double b, double c) : side_a(a), side_b(b), side_c(c) {}
    void whoAmI() {
        cout << "I am a triangle." << endl;
    }
    double calculateArea() {
        double s = (side_a + side_b + side_c) / 2;
        return sqrt(s * (s - side_a) * (s - side_b) * (s - side_c));
    }

    double calculatePerimeter() {
        return side_a + side_b + side_c;
    }
};

class Rectangle : public TwoDimensionalShape {
private:
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}
    void whoAmI() {
        cout << "I am a rectangle." << endl;
    }
    double calculateArea() {
        return length * width;
    }

    double calculatePerimeter() {
        return 2 * (length + width);
    }
};

// Derived classes for three-dimensional shapes
class Cube : public ThreeDimensionalShape {
private:
    double side_length;

public:
    Cube(double side_length) : side_length(side_length) {}
    void whoAmI() {
        cout << "I am a Cube." << endl;
    }
    double calculateSurfaceArea() {
        return 6 * pow(side_length, 2);
    }

    double calculateVolume() {
        return pow(side_length, 3);
    }
};

class Sphere : public ThreeDimensionalShape {
private:
    double radius;

public:
    Sphere(double radius) : radius(radius) {}
    void whoAmI() {
        cout << "I am a Sphere." << endl;
    }
    double calculateSurfaceArea() {
        return 4 * M_PI * pow(radius, 2);
    }

    double calculateVolume() {
        return (4.0 / 3) * M_PI * pow(radius, 3);
    }
};

class Cylinder : public ThreeDimensionalShape {
private:
    double radius, height;

public:
    Cylinder(double r, double h) : radius(r), height(h) {}
    void whoAmI() {
        cout << "I am a cylinder." << endl;
    }
    double calculateSurfaceArea() {
        return 2 * M_PI * radius * (radius + height);
    }

    double calculateVolume() {
        return M_PI * pow(radius, 2) * height;
    }
};

class Cone : public ThreeDimensionalShape {
private:
    double radius, height;

public:
    Cone(double r, double h) : radius(r), height(h) {}
    void whoAmI() {
        cout << "I am a cone." << endl;
    }
    double calculateSurfaceArea() {
        return M_PI * radius * (radius + sqrt(pow(height, 2) + pow(radius, 2)));
    }

    double calculateVolume() {
        return (1.0 / 3) * M_PI * pow(radius, 2) * height;
    }
};

int main() {
  
    Square square(5);
    Circle circle(3);
    Triangle triangle(3, 4, 5);
    Rectangle rectangle(6, 8);
    Cube cube(4);
    Sphere sphere(2);
    Cylinder cylinder(3, 7);
    Cone cone(4, 6);
    cout << "Square:" << endl;
    cout << "Area: " << square.calculateArea() << endl;
    cout << "Perimeter: " << square.calculatePerimeter() << endl;
    square.whoAmI();

    cout << "\nCircle:" << endl;
    cout << "Area: " << circle.calculateArea() << endl;
    cout << "Perimeter: " << circle.calculatePerimeter() << endl;
    circle.whoAmI();

    cout << "\nTriangle:" << endl;
    cout << "Area: " << triangle.calculateArea() << endl;
    cout << "Perimeter: " << triangle.calculatePerimeter() << endl;
    triangle.whoAmI();

    cout << "\nRectangle:" << endl;
    cout << "Area: " << rectangle.calculateArea() << endl;
    cout << "Perimeter: " << rectangle.calculatePerimeter() << endl;
    rectangle.whoAmI();

    cout << "\nCube:" << endl;
    cout << "Surface Area: " << cube.calculateSurfaceArea() << endl;
    cout << "Volume: " << cube.calculateVolume() << endl;
    cube.whoAmI();

    cout << "\nSphere:" << endl;
    cout << "Surface Area: " << sphere.calculateSurfaceArea() << endl;
    cout << "Volume: " << sphere.calculateVolume() << endl;
    sphere.whoAmI();

    cout << "\nCylinder:" << endl;
    cout << "Surface Area: " << cylinder.calculateSurfaceArea() << endl;
    cout << "Volume: " << cylinder.calculateVolume() << endl;
    cylinder.whoAmI();

    cout << "\nCone:" << endl;
    cout << "Surface Area: " << cone.calculateSurfaceArea() << endl;
    cout << "Volume: " << cone.calculateVolume() << endl;
    cone.whoAmI();

    return 0;
}
