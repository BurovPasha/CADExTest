#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <omp.h>
#include "circle.h"
#include "ellipse.h"
#include "helix.h"

using namespace std;

int main()
{
    srand(time(0));
    vector<shared_ptr<Curve>> curves;
    for (int i = 0; i < 25; i++)
    {
        int curveType = rand() % 3;
        if (curveType == 0)
        {
            curves.push_back(make_shared<Circle>(rand() % 10 + 1));
        }
        else if (curveType == 1)
        {
            int radiusX = rand() % 10 + 1;
            int radiusY = rand() % 10 + 1;
            if (radiusY == radiusX)
            {
                radiusX += 1;
            }
            curves.push_back(make_shared<Ellipse>(radiusX, radiusY));
        }
        else
        {
            curves.push_back(make_shared<Helix>(rand() % 10 + 1, rand() % 10 + 1));
        }
    }

    double t = M_PI / 4;
    string tab = "\t";
    for (const auto &curve : curves) 
    {
        auto point = curve->getPoint(t);
        auto derivative = curve->getDerivative(t);
        cout << "Point: " + tab + tab +"X = " << point[0] << tab + "Y = " << point[1] << tab + "Z = " << point[2] << "\n";
        cout << "Derivative: " + tab +"X = " << derivative[0] << tab + "Y = " << derivative[1] << tab + "Z = " << derivative[2] << "\n";
    }

    vector<shared_ptr<Circle>> circles;
    for (const auto &curve : curves)
    {
        if (auto circle = dynamic_pointer_cast<Circle>(curve))
        {
            circles.push_back(circle);
        }
    }
    
    sort(circles.begin(), circles.end(),
        [](const shared_ptr<Circle> &a, const shared_ptr<Circle>b)
        {
            return a->getRadius() < b->getRadius();
        });

    double radiusSum = 0;
    #pragma omp parallel for reduction(+:radiusSum)
    for (int i = 0; i < circles.size(); i++)
    {
        radiusSum += circles[i]->getRadius();
    }
    cout << "Radius sum: " << radiusSum << endl;

    return 0;
}