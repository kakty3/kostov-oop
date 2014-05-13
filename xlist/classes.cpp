// Point – точка,
// Circle – окружность,
// Rect – прямоугольник со сторонами, параллельными OX и OY,
// Square – квадрат со сторонами, параллельными OX и OY, – как частный случай прямоугольника,
// Polyline – ломаная; должна быть реализована с помощью списка точек: XList< Point >, наполняться с помощью метода AddPoint( Point const & _point ).

#include "classes.h"

int Shape::n_of_shapes = 0;

int main(){    
    Point point1(0., 2., "point_1");
    Point point2(4., 2., "point_2");
    Point point3(4., 0., "point_3");
    Point point4(0., 0., "point_4");
    point1.print();
    printf("Number of shapes = %d\n", Shape::GetCount());

    Circle circle(point4, 10., "circle_1");
    circle.print();
    printf("Number of shapes = %d\n", Shape::GetCount());

    Rect rect(point1, point2, point3, point4, "rectangle");
    rect.print();
    printf("Number of shapes = %d\n", Shape::GetCount());

    Square square(point4, 4, "square");
    square.print();
    printf("Number of shapes = %d\n", Shape::GetCount());

    Polyline polyline("polyline");
    printf("Number of shapes = %d\n", Shape::GetCount());
    polyline.AddPoint(point1);
    printf("Number of shapes = %d\n", Shape::GetCount());
    polyline.AddPoint(point2);
    polyline.AddPoint(point3);
    polyline.AddPoint(point4);
    polyline.print();

    printf("Number of shapes = %d\n", Shape::GetCount());

    return 0;
}
