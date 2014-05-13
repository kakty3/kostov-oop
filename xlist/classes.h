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
    };
    std::string GetName() const { return _name; }
protected:
    std::string _name;
};


class Printable : public Named {
public:
    Printable(std::string name) : Named(name) {}
    virtual void print() = 0;
};

class Shape : public Printable {
public:
    Shape(std::string name) : Printable (name) {
        n_of_shapes++;
    };
    virtual ~Shape() {
        n_of_shapes--;
    }
    static int GetCount() { return n_of_shapes; }
    static int n_of_shapes;
private:
};

class Point : public Shape {
public:
    Point(double x, double y, std::string name) : Shape(name), _x(x), _y(y) {}
    virtual void print() {
        printf("name=%s\n\tx=%f\n\ty=%f\n", _name.c_str(), _x, _y);
    }
    void ToStream(std::ostream & out){
        out << "name=" << _name << std::endl
            << "\tx=" << _x << std::endl
            << "\ty=" << _y << std::endl;
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

class Circle : public Shape {
public:
    Circle(const Point& center, double radius, std::string name) : Shape(name), _center(center) {
        _radius = radius;
    }
    float GetSquare() const {  return (M_PI * sqr(_radius)); }
    virtual void print() {
        printf("name=%s\n"
               "\tcenter_x=%f\n"
               "\tcenter_y=%f\n"
               "\tradius=%f\n"
               "\tsquare=%f\n", \
            _name.c_str(), _center.GetX(), _center.GetY(), _radius, GetSquare());
    }
    void ToStream(std::ostream & out){
        out << "name=" << _name << std::endl <<
               "\tcenter_x=" << _center.GetX() << std::endl <<
               "\tcenter_y=" << _center.GetY() << std::endl <<
               "\tradius=" << _radius << std::endl <<
               "\tsquare=" << GetSquare() << std::endl;
    }
private:
    Point _center;
    double _radius;    
};

class Rect : public Shape {
public:
    // we need only two points
    Rect(const Point& top_left, const Point& top_right, const Point& bottom_right, const Point& bottom_left, std::string name) :
        Shape(name),
        _top_left(top_left), 
        _top_right(top_right),
        _bottom_right(bottom_right),
        _bottom_left(bottom_left) {
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
    void ToStream(std::ostream & out){
        out << "name=" << _name << std::endl <<
               "\ttop_left_point: x=" << _top_left.GetX() << ", y=" << _top_left.GetY() << std::endl <<
               "\ttop_right_point: x=" << _top_right.GetX() << ", y=" << _top_right.GetY() << std::endl <<
               "\tbottom_right_point: x=" << _bottom_right.GetX() << ", y=" << _bottom_right.GetY() << std::endl <<
               "\tbottom_left_point: x=" << _bottom_left.GetX() << ", y=" <<  _bottom_left.GetY() << std::endl <<
               "\tsquare=" << this->GetSquare() << std::endl;
    }
private:
    Point _top_left;
    Point _top_right;
    Point _bottom_right;
    Point _bottom_left;
};

class Square : public Rect {
public:
    Square(const Point& bottom_left, double side_size, std::string name) :
        Rect(Point(bottom_left.GetX(), bottom_left.GetY() + side_size, ""),
             Point(bottom_left.GetX() + side_size, bottom_left.GetY() + side_size, ""),
             Point(bottom_left.GetX() + side_size, bottom_left.GetY(), ""),
             bottom_left,
             name) {}    
};

class Polyline : public Shape {
public:
    Polyline(std::string name) : Shape(name){} 

    void AddPoint(const Point& point) {
        _points.push_back(point);
    }

    double GetLength(){
        double length = 0;
        for (XList<Point>::iterator it = _points.begin()->GetNext(); it != NULL; ++it) {
            Point prev_point = *(it->GetPrev());
            length += (*it).GetDistanceToPoint(prev_point);
        }
        return length;
    }

    virtual void print() {
        printf("name=%s\n", _name.c_str());
        for (XList<Point>::iterator it = _points.begin(); it != NULL; ++it) {
            // std::cout << it->GetValue() << ' ';
            printf("-");
            (*it).print();
        }
        printf("-length=%f\n", GetLength());
    }

    void ToStream(std::ostream & out){
        out << "name=" << _name << std::endl;
        for (XList<Point>::iterator it = _points.begin(); it != NULL; ++it) {
            out << "-";
            // out << *it;
            out << "name=" << (*it).GetName() << std::endl
                << "\tx=" << (*it).GetX() << std::endl
                << "\ty=" << (*it).GetY() << std::endl;
        }
        out << "-lenght=" << GetLength() << std::endl;
        // printf("-length=%f\n", GetLength());
    }
private:
    XList<Point> _points;
};

template <typename T>
std::ostream& operator<< (std::ostream& _stream, T& _shape) {
    _shape.ToStream(_stream);
    return _stream;
}

#endif /* CLASSES_H */
