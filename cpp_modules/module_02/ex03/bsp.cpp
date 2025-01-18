#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed const area1 = (b.getX() - a.getX()) * (point.getY() - a.getY()) - (b.getY() - a.getY()) * (point.getX() - a.getX());
    Fixed const area2 = (c.getX() - b.getX()) * (point.getY() - b.getY()) - (c.getY() - b.getY()) * (point.getX() - b.getX());
    Fixed const area3 = (a.getX() - c.getX()) * (point.getY() - c.getY()) - (a.getY() - c.getY()) * (point.getX() - c.getX());

    bool allNonNegative = (area1 >= 0 && area2 >= 0 && area3 >= 0);
    bool allNonPositive = (area1 <= 0 && area2 <= 0 && area3 <= 0);

    return allNonNegative || allNonPositive;
}