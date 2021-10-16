#include "macro.hpp"

// sorting uses < operator
// redefining that operator enables us perform non-trivial sorting with STL
// else pass the comparison function to sort as third argument

struct fraction
{
    int n, d;
    bool operator<(const fraction &f) const
    {
        if (false)
        {
            return (double(n) / d) < (double(f.n) / f.d);
        }
        else
        {
            return f.d < f.n;
            // unsure what's here
        }
    }
};

typedef std::pair<double, double> dd;
const double epsilon = 1e-6;

struct sort_by_polar_angle
{
    dd center;
    template <typename T>
    sort_by_polar_angle(T b, T e)
    {
        int count = 0;
        center = dd(0, 0); // constructor for pair!
        while (b != e)
        {
            center.first += b->first;
            center.second += b->second;
            b++;
            count++;
        }
        double k = count ? (1.0 / count) : 0;
        center.first *= k;
        center.second *= k;
    }

    bool operator()(const dd &a, const dd &b) const
    {
        double p1 = atan2(a.second - center.second, a.first - center.first);
        double p2 = atan2(b.second - center.second, b.first - center.first);
        return p1 + epsilon < p2;
    }
};

int main()
{
    std::vector<fraction> v;
    std::sort(all(v));

    std::vector<dd> points;
    sort(all(points), sort_by_polar_angle(all(points)));
}