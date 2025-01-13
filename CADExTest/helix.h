#pragma once
#include "curve.h"

class Helix : public Curve 
{
private:
    double m_radius, m_step;

public:
    Helix(double radius, double step);
    vector<double> getPoint(double t) const override;
    vector<double> getDerivative(double t) const override;

};
