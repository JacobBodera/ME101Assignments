#include <cstdlib>
#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

int main ()
{
    int minHighTemp = 100000, maxLowTemp = -100000, highTemp = 0, lowTemp = 0;

    ifstream fileIn("Dec_temp_2021.txt");

    if(!fileIn)
    {
        cout << "FILE NOT FOUND!";
        return EXIT_FAILURE;
    }

    while (fileIn >> highTemp >> lowTemp)
    {
        if (highTemp < minHighTemp)
        {
            minHighTemp = highTemp;
        }
        if(lowTemp > maxLowTemp)
        {
            maxLowTemp = lowTemp;
        }
    }

    cout << "The lowest daily high temperature in December was " << minHighTemp << endl;
    cout << "The highest daily low temperature in December was " << maxLowTemp << endl;

    fileIn.close();
    return EXIT_SUCCESS;
}

