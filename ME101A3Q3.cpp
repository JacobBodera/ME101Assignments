#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    double sideA = 0.0, sideB = 0.0, angle = 0.0;
    const double SIDE_TOL = 0.1, ANGLE_TOL = 0.5;

    cout << "Please enter the length of the sides (cm) and the angle (degrees) contained within them:  ";
    cin >> sideA >> sideB >> angle;
    cout << endl;

    if (sideA <= 0 || sideB <= 0 || angle <= 0 || angle >= 180)
    {
        cout << "The value(s) entered are not within rangle!";
        return EXIT_FAILURE;
    }

    if (fabs(angle - 90) > ANGLE_TOL)
    {
        cout << "The paving stone is a parallelogram,";
    }
    else if (fabs(sideA - sideB) < SIDE_TOL)
    {
        cout << "The paving stone is a square.";
    }
    else
    {
        cout << "The paving stone is a rectangle.";
    }

    return EXIT_SUCCESS;
}