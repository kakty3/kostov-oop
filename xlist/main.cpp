#include "xlist.h"
#include "shapes.h"

int Shape::n_of_shapes = 0;

int main(){
    XList<Shape> shapes;
    Point point1(0., 2., "point_1");
    shapes.push_back(point1);
    Point point2(4., 2., "point_2");
    Point point3(4., 0., "point_3");
    Point point4(0., 0., "point_4");
    printf("Number of shapes = %d\n", Shape::GetCount());

    Circle circle(point4, 10., "circle_1");
    shapes.push_back(circle);
    circle.print();
    // std::cout << circle;
    printf("Number of shapes = %d\n", Shape::GetCount());

    Rect rect(point1, point2, point3, point4, "rectangle");
    shapes.push_back(rect);
    rect.print();
    // std::cout << rect;
    printf("Number of shapes = %d\n", Shape::GetCount());

    Square square(point4, 4, "square");
    shapes.push_back(square);
    square.print();
    // std::cout << square;
    printf("Number of shapes = %d\n", Shape::GetCount());

    Polyline polyline("polyline");
    printf("Number of shapes = %d\n", Shape::GetCount());
    polyline.AddPoint(point1);
    polyline.AddPoint(point2);
    polyline.AddPoint(point3);
    polyline.AddPoint(point4);
    printf("Number of shapes = %d\n", Shape::GetCount());
    shapes.push_back(polyline);
    printf("Number of shapes = %d\n", Shape::GetCount());
    polyline.print();

    printf("Number of shapes = %d\n", Shape::GetCount());
    return 0;
}

