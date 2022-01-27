#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    string day;
    bool schoolNight = 0;
    int time = 0;

    cout << "Enter day, whether it is a school night, and time: ";
    cin >> day >> schoolNight >> time;
    cout << endl;

    if (day == "Friday" || day == "Saturday")
    {
        cout << "Play Tickey to Ride!";
    }

    else
    {
        if (time == 6 && day == "Weekday")
        {
            cout << "Play Spirit Island!";
        }
        else if (time == 6 && day == "Sunday")
        {
            cout << "Play Flash Point";
        }
        else if (schoolNight)
        {
            cout << "Play Code Games!";
        }
        else
        {
            cout << "Play Settlers of Catan!";
        }
    }

    return EXIT_SUCCESS;
}