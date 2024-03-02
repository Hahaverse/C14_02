#include <iostream>
#define PI 3.141592
using namespace std;

class Shape {
protected:
    int width;
    int height;
public:
    Shape() { width = 0; height = 0; }
    Shape(int w, int h) { width = w; height = h; }
    void setWidth(int w) { width = w; }
    void setHeight(int h) { height = h; }
    int getWidth() { return width; }
    int getHeight() { return height; }
    virtual void display() = 0;
};

class TwoDimShape : public Shape {
protected:
    double area;
public:
    // 여기에 TwoDimShape 클래스의 생성자와 멤버함수들 정의
    TwoDimShape() :Shape() { area = 0.0; }
    TwoDimShape(int w, int h) :Shape(w, h) { area = 0.0; }
};

class ThreeDimShape : public Shape {
protected:
    double volume;
public:
    // 여기에 ThreeDimShape 클래스의 생성자와 멤버함수들 정의
    ThreeDimShape() :Shape() { volume = 0.0; }
    ThreeDimShape(int w, int h) :Shape(w, h) { volume = 0.0; }
};

class Rectangle : public TwoDimShape {
    // 사각형 클래스에 추가 멤버변수 없음!
public:
    Rectangle():TwoDimShape(){}
    Rectangle(int w, int h) :TwoDimShape(w, h) {}
    double getArea() {
        area = width * height;
        return area;
    }
    void display() { cout << "Rectangle\n" << "면적 : " << getArea() << endl; }
};

class Ellipse : public TwoDimShape {
    // 타원 클래스에 추가 멤버변수 없음!
public:
    Ellipse() :TwoDimShape() {}
    Ellipse(int w, int h) :TwoDimShape(w, h) {}
    double getArea() {
        area = width * height * PI / 4;
        return area;
    }
    void display() { cout << "Ellipse\n" << "면적 : " << getArea() << endl; }
};

class Triangle : public TwoDimShape {
    // 삼각형 클래스에 추가 멤버변수 없음!
public:
    Triangle():TwoDimShape(){}
    Triangle(int w, int h) :TwoDimShape(w, h) {}
    double getArea() {
        area = width * height / 2;
        return area;
    }
    void display() { cout << "Triangle\n" << "면적 : " << getArea() << endl; }
};

class Sphere : public ThreeDimShape {
private:
    int radius;
public:
    Sphere() :ThreeDimShape() { radius = 0; }
    Sphere(int w, int h, int r) :ThreeDimShape(w, h) { radius = r; }
    double getVolume() {
        volume = ((double)4 / 3) * radius * radius * radius * PI;
        return volume;
    }
    void display() { cout << "Sphere\n" << "체적 : " << getVolume() << endl; }
};

class Cube : public ThreeDimShape {
private:
    int base;
public:
    Cube() :ThreeDimShape() { base = 0; }
    Cube(int w, int h, int b) :ThreeDimShape(w, h) { base = b; }
    double getVolume() {
        volume = width * height * base;
        return volume;
    }
    void display() { cout << "Cube\n" << "체적 : " << getVolume() << endl; }
};

class Cylinder : public ThreeDimShape {
private:
    int radius;
public:
    Cylinder() :ThreeDimShape() { radius = 0; }
    Cylinder(int w, int h, int r) :ThreeDimShape(w, h) { radius = r; }
    double getVolume() {
        volume = radius * radius * PI * height;
        return volume;
    }
    void display() { cout << "Cylinder\n" << "체적 : " << getVolume() << endl; }
};

void printShape(Shape* p) {
    p->display();
}

int main(void) {
    TwoDimShape* arrayOfTwo[3];
    arrayOfTwo[0] = new Ellipse(1, 2);
    arrayOfTwo[1] = new Rectangle(3, 4);
    arrayOfTwo[2] = new Triangle(5, 6);

    ThreeDimShape* arrayOfThree[3];
    arrayOfThree[0] = new Sphere(7, 8, 9);
    arrayOfThree[1] = new Cube(10, 11, 12);
    arrayOfThree[2] = new Cylinder(13, 14, 15);

    for (int i = 0; i < 3; i++) {
        printShape(arrayOfTwo[i]);
        printShape(arrayOfThree[i]);
    }

    return 0;
}