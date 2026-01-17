#include "Point.hpp"

// A(x=5, y=7)
// B(x=1, y=2)
// C(x=7, y=2)
// P(x=4, y=4)

static Fixed cross_product(Point const start, Point const end, Point const point) {
    return ((end.getX() - start.getX()) * (point.getY() - start.getY()) -
            (end.getY() - start.getY()) * (point.getX() - start.getX()));
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed ab = cross_product(a, b, point);
    Fixed bc = cross_product(b, c, point);
    Fixed ca = cross_product(c, a, point);

    return ((ab > 0 && bc > 0 && ca > 0) || (ab < 0 && bc < 0 && ca < 0));
}