#include "circle.h"

Circle::Circle(double radius)
{
    m_radius = radius;
}

vector<double> Circle::getPoint(double t) const
{
    return {m_radius * cos(t), m_radius * sin(t), 0.0};
}

vector<double> Circle::getDerivative(double t) const
{
    return {-m_radius * sin(t), m_radius * cos(t), 0.0};
}

double Circle::getRadius()
{
    return m_radius;
}
