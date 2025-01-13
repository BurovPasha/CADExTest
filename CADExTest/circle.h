#pragma once
#include "curve.h"

class Circle : public Curve
{
private:
    double m_radius;

public:
    Circle(double radius);
    vector<double> getPoint(double t) const override;
    vector<double> getDerivative(double t) const override;
};

