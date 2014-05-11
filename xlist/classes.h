#ifndef CLASSES_H
#define CLASSES_H

#include <stdio.h>
#include <iostream>
#include <math.h>
#include "xlist.h"

double sqr(const double& x){
    return x * x;
}

class Named {
public:
    Named(std::string name) : _name(name){
         // std::cout << name << " Named constructor called.\n"; 
    };
protected:
    std::string _name;
};


class Printable : virtual public Named {
public:
    virtual void print() = 0;
};

class Shape : virtual public Named {
public:
    Shape(std::string name) : Named (name) {
        n_of_shapes++;
    };
    static int GetCount() { return n_of_shapes; }
    static int n_of_shapes;
    // static void ResetNumberOfShapes() { n_of_shapes = 0; }
private:
};

class Point : public Shape, public Printable {
public:
    Point(double x, double y, std::string name) : Shape(name), Named(name), _x(x), _y(y) {}
    virtual void print() { 
        printf("name=%s\n\tx=%f\n\ty=%f\n", _name.c_str(), _x, _y);
    }
    double GetX () const { return _x; }
    double GetY () const { return _y; }
    double GetDistanceToPoint(const Point& other_point) {
        return sqrt(sqr(other_point.GetX() - _x) + sqr(other_point.GetY() - _y));
    }
private:
    double _x;
    double _y;
};

class Circle : public Shape, public Printable {
public:
    Circle(double x, double y, double radius, std::string name) : Shape(name), Named(name), _center(Point(x, y, "")) {
        _radius = radius;
    }
    float GetSquare() const {  return (M_PI * _radius * _radius) / 2; }
    virtual void print() {
        printf("name=%s\n"
               "\tcenter_x=%f\n"
               "\tcenter_y=%f\n"
               "\tradius=%f\n"
               "\tsquare=%f\n", \
            _name.c_str(), _center.GetX(), _center.GetY(), _radius, GetSquare());
    }
private:
    Point _center;
    double _radius;    
};

class Rect : public Shape, public Printable {
public:
    Rect(Point top_left, Point top_right, Point bottom_right, Point bottom_left, std::string name) :
        Shape(name), Named(name),
        _top_left(top_left), 
        _top_right(top_right),
        _bottom_right(bottom_right),
        _bottom_left(bottom_left) {
            // this->square = GetSquare();
        }
    double GetSquare(){
        double top_line = _top_left.GetDistanceToPoint(_top_right);
        double side_line = _top_left.GetDistanceToPoint(_bottom_left);
        return top_line * side_line;
    };
    virtual void print() {
        printf("name=%s\n"
               "\ttop_left_point: x=%f, y=%f\n"
               "\ttop_right_point: x=%f, y=%f\n"
               "\tbottom_right_point: x=%f, y=%f\n"
               "\tbottom_left_point: x=%f, y=%f\n"
               "\tsquare=%f\n",
                _name.c_str(),
                _top_left.GetX(), _top_left.GetY(),
                _top_right.GetX(), _top_right.GetY(),
                _bottom_right.GetX(), _bottom_right.GetY(),
                _bottom_left.GetX(), _bottom_left.GetY(),
                this->GetSquare()
        );
    }
private:
    Point _top_left;
    Point _top_right;
    Point _bottom_right;
    Point _bottom_left;
    // double square;
};

class Square : public Rect {
public:
    Square(Point bottom_left, double side_size, std::string name) :
        Rect(Point(bottom_left.GetX(), bottom_left.GetY() + side_size, ""),
             Point(bottom_left.GetX() + side_size, bottom_left.GetY() + side_size, ""),
             Point(bottom_left.GetX() + side_size, bottom_left.GetY(), ""),
             bottom_left,
             name),
        Named(name) {}    
};

class Polyline : public Shape, public Printable {
public:
    Polyline(std::string name) : Shape(name), Named(name){} 

    void AddPoint(const Point& point) {
        _points.push_back(point);
    }

    double GetLength(){
        double length = 0;
        for (XList<Point>::iterator it = _points.begin()->GetNext(); it != NULL; ++it) {
            length += it->GetValue().GetDistanceToPoint(it->GetPrev()->GetValue());
        }
        return length;
    }

    virtual void print() {
        printf("name=%s\n", _name.c_str());
        for (XList<Point>::iterator it = _points.begin(); it != NULL; ++it) {
            // std::cout << it->GetValue() << ' ';
            printf("-");
            it->GetValue().print();
        }
        printf("-length=%f\n", GetLength());
    }
private:
    XList<Point> _points;
};

#endif /* CLASSES_H */
