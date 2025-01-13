#define _USE_MATH_DEFINES
#include "helix.h"
#include <cmath>

Helix::Helix(double radius, double step)
{
    m_radius = radius;
    m_step = step;
}

vector<double> Helix::getPoint(double t) const
{
    return {m_radius * cos(t), m_radius * sin(t), (m_step * t) / (2 * M_PI)};
}

vector<double> Helix::getDerivative(double t) const
{
    return {-m_radius * sin(t), m_radius * cos(t), m_step / (2 * M_PI)};
}