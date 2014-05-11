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

    Circle circle(0., 0., 10., "circle_1");
    circle.print();

    Rect rect(point1, point2, point3, point4, "rectangle");
    rect.print();

    Square square(point4, 4, "square");
    square.print();

    Polyline polyline("polyline");
    polyline.AddPoint(point1);
    polyline.AddPoint(point2);
    polyline.AddPoint(point3);
    polyline.AddPoint(point4);
    polyline.print();

    printf("Number of shapes = %d", Shape::GetCount());
    return 0;
}
