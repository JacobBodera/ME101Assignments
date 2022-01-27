#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
    double a = 0, angleA = 0, b = 0, angleB = 0, c = 0, angleC = 0;
    double area = 0, perimeter = 0, semiPer = 0;
    double DEG_TO_RAD = M_PI/180.0;

    cout << "Enter length of side a:";
    cin >> a;
    cout << "Enter length of side b:";
    cin >> b;
    cout << "Enter angle of C:";
    cin >> angleC;
	
	cout << "-----" << c << "-----";
	
    c = sqrt((a*a + b*b) - (2*a*b*(cos(angleC*DEG_TO_RAD))));
    
    cout << "-----" << c << "-----";
    angleA = acos((((b*b) + (c*c) - (a*a))) / (2*b*c))/DEG_TO_RAD;
    angleB = acos((((a*a) + (c*c) - (b*b))) / (2*a*c))/DEG_TO_RAD;

    perimeter = a + b + c;

    semiPer = perimeter/2;

    area = sqrt(semiPer*(semiPer - a)*(semiPer - b)*(semiPer - c));

    cout << endl << "Side c = " << c << endl;
    cout << "Angle a = " << angleA << " degrees or " << angleA * DEG_TO_RAD << " radians." << endl;
    cout << "Angle b = " <<angleB << " degrees or " << angleB * DEG_TO_RAD << " radians." << endl;
    cout << "Perimeter = " << perimeter << endl;
    cout << "Area = " << area << endl;

}
