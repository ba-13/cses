#include "macro.hpp"

// sets and maps have ordered elements, so custom objects, if needed to be inserted, must be comparable
// all comparisons in STL is based on `<`
// so need to define only `<` for custom objects to make them comparable according to STL
const double epsilon = 1e-7;
struct point
{
    double x, y;
    // note that in struct or classes in cpp, you directly access the variables inside, no need for `this` keyword
    bool operator<(const point &p) const
    {
        if (x < p.x - epsilon)
            return true;
        if (x > p.x + epsilon)
            return false;
        if (y < p.y - epsilon)
            return true;
        if (y > p.y + epsilon)
            return false;
    }
};

int main()
{
    // now the struct can be used to create points, and if problem is given some intersecting line segments, we want to make a set of intersection points
    // the < overloaded operator makes it so that now we can directly insert point struct in sets.
    return 0;
}