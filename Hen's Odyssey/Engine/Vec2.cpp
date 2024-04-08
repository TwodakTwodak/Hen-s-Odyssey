#include "Vec2.h"

bool Math::vec2::operator==(const vec2& v) {
    return (x == v.x && y == v.y && z == v.z);
}

bool Math::vec2::operator!=(const vec2& v) {
    return (x != v.x || y != v.y || z != v.z);
}

Math::vec2 Math::vec2::operator+(const vec2& v) {
    return { x + v.x, y + v.y, z + v.z };
}

Math::vec2& Math::vec2::operator+=(const vec2& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

Math::vec2 Math::vec2::operator-(const vec2& v) {
    return { x - v.x, y - v.y, z - v.z };
}

Math::vec2& Math::vec2::operator-=(const vec2& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

Math::vec2 Math::vec2::operator*(double scale) {
    return { x * scale, y * scale, z * scale };
}

Math::vec2& Math::vec2::operator*=(double scale) {
    x *= scale;
    y *= scale;
    z *= scale;
    return *this;
}

Math::vec2 Math::vec2::operator/(double divisor) {
    return { x * divisor, y * divisor, z * divisor };
}

Math::vec2& Math::vec2::operator/=(double divisor) {
    x /= divisor;
    y /= divisor;
    z /= divisor;
    return *this;
}

Math::vec2 Math::operator*(double scale, const Math::vec2& v) {
    return Math::vec2(scale * v.x, scale * v.y, scale * v.z);
}



bool Math::ivec2::operator==(const ivec2& v) {
    return (x == v.x && y == v.y && z == v.z);
}

bool Math::ivec2::operator!=(const ivec2& v) {
    return (x != v.x || y != v.y || z != v.z);
}

Math::ivec2 Math::ivec2::operator+(const ivec2& v) {
    return { x + v.x, y + v.y, z + v.z };
}

Math::ivec2& Math::ivec2::operator+=(const ivec2& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

Math::ivec2 Math::ivec2::operator-(const ivec2& v) {
    return { x - v.x, y - v.y, z - v.z };
}

Math::ivec2& Math::ivec2::operator-=(const ivec2& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

Math::ivec2 Math::ivec2::operator*(int scale) {
    return { x * scale, y * scale, z * scale };
}

Math::ivec2& Math::ivec2::operator*=(int scale) {
    x *= scale;
    y *= scale;
    z *= scale;
    return *this;
}

Math::ivec2 Math::ivec2::operator/(int divisor) {
    return { x / divisor, y / divisor, z / divisor };
}

Math::ivec2& Math::ivec2::operator/=(int divisor) {
    x /= divisor;
    y /= divisor;
    z /= divisor;
    return *this;
}

Math::vec2 Math::ivec2::operator* (double scale) {
    return { x * scale, y * scale, z * scale };
}

Math::vec2 Math::ivec2::operator/ (double divisor) {
    return { x / divisor, y / divisor, z / divisor };
}