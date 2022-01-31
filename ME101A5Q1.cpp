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
    int numStops = 0, tripNumber = 0;
    double totalCost = 0, totalDistance = 0, longestTrip = 0, lowestCost = 1E8;

    const double VIP_DISCOUNT = 0.75, FLAT_COST = 15.0, KILOMETER_COST = 2.6;

    fout << "Trip #" << setw(6) << "VIP" << setw(8) << "Stops" << setw(11) << "TripDist" << setw(11) << "TripCost" << setw(12) << 
            "TotalDist" << setw(12) << "TotalCost" << endl;

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
        tripCost = FLAT_COST + tripDistance*KILOMETER_COST;

        if (isVIP)
            tripCost *= VIP_DISCOUNT;

        totalDistance += tripDistance;
        totalCost += tripCost;
        tripNumber++;

        if (tripNumber < 5 || tripNumber % 10 == 4)
        {
        fout << fixed << setprecision(0) << setw(4) << tripNumber << setw(7) << isVIP << setw(7) << numStops << setw(12) << setprecision(2)
             << tripDistance << setw(11) << tripCost << setw(12) << totalDistance << setw(12) << totalCost << endl;
        }

        if (tripDistance > longestTrip)
            longestTrip = tripDistance;

        if (tripCost < lowestCost)
            lowestCost = tripCost;
    }
    fout << endl << "The cumulative distance travelled is " << totalDistance << "km" << endl << "The total amount collected was $" << totalCost
         << endl << "The longest trip was " << longestTrip << "km" << endl << "The least expensive trip was $" << lowestCost;
    
    fin.close();
    fout.close();

    return EXIT_SUCCESS;
}