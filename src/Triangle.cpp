//
// Created by LEI XU on 4/11/19.
//

#include "Triangle.hpp"
#include <algorithm>
#include <array>

Triangle::Triangle()
{
    v[0] << 0.0f, 0.0f, 0.0f;
    v[1] << 0.0f, 0.0f, 0.0f;
    v[2] << 0.0f, 0.0f, 0.0f;

    color[0] << 0.0f, 0.0f, 0.0f;
    color[1] << 0.0f, 0.0f, 0.0f;
    color[2] << 0.0f, 0.0f, 0.0f;

    tex_coords[0] << 0.0f, 0.0f;
    tex_coords[1] << 0.0f, 0.0f;
    tex_coords[2] << 0.0f, 0.0f;
}

void Triangle::setVertex(int ind, Eigen::Vector3f ver)
{
    v[ind] = ver;
}

void Triangle::setNormal(int ind, Vector3f n)
{
    normal[ind] = n;
}

void Triangle::setColor(int ind, float r, float g, float b)
{
    if ((r < 0.0f) || (r > 255.0f) || (g < 0.0f) || (g > 255.0f) || (b < 0.0f) || (b > 255.0f))
    {
        throw std::runtime_error("Invalid color values");
    }

    color[ind] = Vector3f(r / 255.0f, g / 255.0f, b / 255.0f);
    return;
}

void Triangle::setTexCoord(int ind, float s, float t)
{
    tex_coords[ind] = Vector2f(s, t);
}

std::array<Vector4f, 3> Triangle::toVector4() const
{
    std::array<Vector4f, 3> res;
    std::transform(std::begin(v), std::end(v), res.begin(), [](auto& vec)
    {
        return Vector4f(vec.x(), vec.y(), vec.z(), 1.0f);
    });
    return res;
}
