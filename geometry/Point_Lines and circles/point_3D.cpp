#include <bits/stdc++.h>
using namespace std;

typedef double ftype;

struct point3d
{
    ftype x, y, z;
    point3d() {}
    point3d(ftype x, ftype y, ftype z) : x(x), y(y), z(z) {}
    point3d &operator+=(const point3d &t)
    {
        x += t.x;
        y += t.y;
        z += t.z;
        return *this;
    }
    point3d &operator-=(const point3d &t)
    {
        x -= t.x;
        y -= t.y;
        z -= t.z;
        return *this;
    }
    point3d &operator*=(ftype t)
    {
        x *= t;
        y *= t;
        z *= t;
        return *this;
    }
    point3d &operator/=(ftype t)
    {
        x /= t;
        y /= t;
        z /= t;
        return *this;
    }
    point3d operator+(const point3d &t) const
    {
        return point3d(*this) += t;
    }
    point3d operator-(const point3d &t) const
    {
        return point3d(*this) -= t;
    }
    point3d operator*(ftype t) const
    {
        return point3d(*this) *= t;
    }
    point3d operator/(ftype t) const
    {
        return point3d(*this) /= t;
    }
};
point3d operator*(ftype a, point3d b)
{
    return b * a;
}

ftype dot(point3d a, point3d b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

ftype norm(point3d a)
{
    return dot(a, a);
}
double abs(point3d a)
{
    return sqrt(norm(a));
}
double proj(point3d a, point3d b)
{
    return dot(a, b) / abs(b);
}
double angle(point3d a, point3d b)
{
    return acos(dot(a, b) / abs(a) / abs(b));
}

point3d cross(point3d a, point3d b)
{
    return point3d(a.y * b.z - a.z * b.y,
                   a.z * b.x - a.x * b.z,
                   a.x * b.y - a.y * b.x);
}
ftype triple(point3d a, point3d b, point3d c)
{
    return dot(a, cross(b, c));
}

point3d intersect(point3d a1, point3d n1, point3d a2, point3d n2, point3d a3, point3d n3)
{
    point3d x(n1.x, n2.x, n3.x);
    point3d y(n1.y, n2.y, n3.y);
    point3d z(n1.z, n2.z, n3.z);
    point3d d(dot(a1, n1), dot(a2, n2), dot(a3, n3));
    return point3d(triple(d, y, z),
                   triple(x, d, z),
                   triple(x, y, d)) /
           triple(n1, n2, n3);
}

int main()
{

    return 0;
}