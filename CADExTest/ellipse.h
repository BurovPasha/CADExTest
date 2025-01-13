#pragma once
#include "curve.h"

class Ellipse : public Curve 
{
private:
    double m_radiusX, m_radiusY;

public:
    Ellipse(double radiusX, double radiusY);
    vector<double> getPoint(double t) const override;
    vector<double> getDerivative(double t) const override;
};
