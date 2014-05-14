#include "xlist.h"
#include "shapes.h"

int Shape::n_of_shapes = 0;

int main(){
    XList<Shape*> shapes;
    Point * point1 = new Point(0., 2., "point_1");
    shapes.push_back(point1);
    Point * point2 = new Point(2., 2., "point_2");
    shapes.push_back(point2);
    Point * point3 = new Point(2., 0., "point_3");
    shapes.push_back(point3);
    Point * point4 = new Point(0., 0., "point_4");
    shapes.push_back(point4);

    Circle * circle = new Circle(point4, 10., "circle_1");
    shapes.push_back(circle);

    Rect * rect = new Rect(point1, point2, point3, point4, "rectangle");
    shapes.push_back(rect);

    try {
        Square * square = new Square(point1, point2, point3, point4, "square");
        shapes.push_back(square);
    } catch (const char* error){
        // std::cout << "EXCEPTION RAISED: " << error << std::endl;
    }


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
    }
    printf("Number of shapes = %d\n", Shape::GetCount());
    return 0;
}

