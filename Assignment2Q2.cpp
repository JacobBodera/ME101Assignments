#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;


int main ()
{
    double initValue = 0, interestRate = 0;
    int numYears = 0;

    cout << "Enter the initial value of your investment: ";
    cin >> initValue;
    cout << endl << "Enter the interest rate as a decimal value: ";
    cin >> interestRate;
    cout << endl << "Enter the number of years your investment will be held: ";
    cin >> numYears;

    double finalValue = initValue * pow((1 + interestRate/12), 12 * numYears);

    cout << endl << "Your final investment is $" << fixed << setprecision(2) << finalValue;
}
