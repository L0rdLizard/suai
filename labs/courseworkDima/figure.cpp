// A Point about Polygons

#include <iostream>
#include <cmath>
using namespace std;

class Point {
public:
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    double getX() const { return x; }
    double getY() const { return y; }
    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }
    void print() const { cout << "(" << x << ", " << y << ")"; }
    double distance(const Point& p) const {
        return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
    }
private:
    double x, y;
};

class Polygon {
public:
    Polygon(int n = 0) : n(n) {
        points = new Point[n];
    }
    ~Polygon() { delete[] points; }
    void setPoint(int i, const Point& p) {
        points[i] = p;
    }
    Point getPoint(int i) const {
        return points[i];
    }
    void print() const {
        for (int i = 0; i < n; i++) {
            points[i].print();
            cout << " ";
        }
        cout << endl;
    }
    double perimeter() const {
        double p = 0;
        for (int i = 0; i < n; i++) {
            p += points[i].distance(points[(i + 1) % n]);
        }
        return p;
    }
private:
    int n;
    Point* points;
};

int main() {
    Polygon p(4);
    p.setPoint(0, Point(0, 0));
    p.setPoint(1, Point(0, 1));
    p.setPoint(2, Point(1, 1));
    p.setPoint(3, Point(1, 0));
    p.print();
    cout << "Perimeter: " << p.perimeter() << endl;
    return 0;
}

