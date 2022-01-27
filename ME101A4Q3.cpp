#include <cstdlib>
#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream fileIn("boat_regatta.txt");

    if(!fileIn)
    {
        cout << "FILE NOT FOUND!";
        return EXIT_FAILURE;
    }

    ofstream fileOut("boat_time_report.txt");

    int minTime = 100000, maxTime = -100000, startTime = 0, endTime = 0, deltaTime;
    const int DAY_MINUTES = 1440;

    while(fileIn >> startTime >> endTime)
    {
        startTime = (startTime/100)*60 + (startTime%100);
        endTime = (endTime/100)*60 + (endTime%100);

        if (startTime <= endTime)
        {
            deltaTime = endTime - startTime;
        }
        else
        {
            deltaTime = DAY_MINUTES - (startTime - endTime);
        }

        if (deltaTime < minTime)
        {
            minTime = deltaTime;
        }
        if (deltaTime > maxTime)
        {
            maxTime = deltaTime;
        }
    }

    fileOut << "The shortest time it took to complete the race was " << minTime << " minutes." << endl;
    fileOut << "The longest time it took to complete the race was " << maxTime << " minutes." << endl;

    fileIn.close();
    fileOut.close();

    return EXIT_SUCCESS;
}