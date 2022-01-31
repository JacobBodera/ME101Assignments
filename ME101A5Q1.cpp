#include <cstdlib>
#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    ifstream fin("taxi.txt");
    ofstream fout("taxi_report.txt");

    if(!fin)
    {
        cout << "File not found!";
        return EXIT_FAILURE;
    } 

    bool isVIP = false;
    int numStops = 0;
    double totalCost = 0, totalDistance = 0;

    const double VIP_DISCOUNT = 0.75, FLAT_COST = 15.0, KILOMETER_COST = 2.6;

    while (fin >> isVIP >> numStops)
    {
        double tripCost = 0, tripDistance = 0;
        double curX = 0, curY = 0, preX = 0, preY = 0;

        for (int i = 0; i < numStops; i++)
        {
            fin >> curX >> curY;
            tripDistance += sqrt(pow(curX - preX, 2) + pow(curY - preY, 2));
            preX = curX;
            preY = curY;
        }
        tripDistance += sqrt(pow(preX, 2) + pow(preY, 2));
    }
}