#pragma once
#include <iostream>

template <typename T>
class Vec3d {
private:
    T x, y, z;
public:
    Vec3d(T _x, T _y, T _z): x(_x), y(_y), z(_z) {};

    friend Vec3d<T> operator + (const Vec3d<T>& left, const Vec3d<T>& right) {
       return Vec3d(left.x + right.x, left.y + right.y, left.z + right.z);
    }

    friend std::ostream& operator <<(std::ostream& out, const Vec3d<T>& vec) {
        return out << vec.x << ", " << vec.y << ", " << vec.z << " ";
    }
};


