#pragma once
#include <vector>
using namespace std;

class Curve
{
public:
    virtual ~Curve() = default;
    virtual vector<double> getPoint(double t) const = 0;
    virtual vector<double> getDerivative(double t) const = 0;
};