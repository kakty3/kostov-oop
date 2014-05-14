#include "xlist.h"
#include "shapes.h"

int Shape::n_of_shapes = 0;

int main(){
    XList<Shape*> shapes;
    Point * point1 = new Point(0., 2., "point_1");
    shapes.push_back(point1);
    Point * point2 = new Point(4., 2., "point_2");
    shapes.push_back(point2);
    Point * point3 = new Point(4., 0., "point_3");
    shapes.push_back(point3);
    Point * point4 = new Point(0., 0., "point_4");
    shapes.push_back(point4);
    // printf("Number of shapes = %d\n", Shape::GetCount());

    Circle * circle = new Circle(point4, 10., "circle_1");
    shapes.push_back(circle);
    // printf("Number of shapes = %d\n", Shape::GetCount());

    Rect * rect = new Rect(point1, point2, point3, point4, "rectangle");
    shapes.push_back(rect);
    // printf("Number of shapes = %d\n", Shape::GetCount());

    Square * square = new Square(point4, 4, "square");
    shapes.push_back(square);
    // printf("Number of shapes = %d\n", Shape::GetCount());

    Polyline * polyline = new Polyline("polyline");
    polyline->AddPoint(point1);
    polyline->AddPoint(point2);
    polyline->AddPoint(point3);
    polyline->AddPoint(point4);
    shapes.push_back(polyline);

    for (XList<Shape*>::iterator it = shapes.begin(); it != NULL; ++it) {
        std::cout << *it;
    }
    printf("Number of shapes = %d\n", Shape::GetCount());
    for (XList<Shape*>::iterator it = shapes.begin(); it != NULL; ++it) {
        delete *it;
        std::cout << '\n';
    }
    printf("Number of shapes = %d\n", Shape::GetCount());
    return 0;
}

