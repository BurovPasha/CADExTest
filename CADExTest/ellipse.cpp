#include "ellipse.h"

Ellipse::Ellipse(double radiusX, double radiusY)
{
    m_radiusX = radiusX;
    m_radiusY = radiusY;
}

vector<double> Ellipse::getPoint(double t) const
{
    return {m_radiusX * cos(t), m_radiusY * sin(t), 0.0};
}

vector<double> Ellipse::getDerivative(double t) const
{
    return {-m_radiusX * sin(t), m_radiusY * cos(t), 0.0};
}