#include <cstdlib>
#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    ifstream fileIn("quizGrades.txt");

    if(!fileIn)
    {
        cout << "File not found!";
        return EXIT_FAILURE;
    }

    const int NUM_GRADES = 150;
    double mean = 0.0, deviation = 0.0;
    int numStudents = 0;

    double grades [NUM_GRADES];

    while (fileIn >> grades[numStudents])
    {
        mean += grades[numStudents];
        numStudents++;
    }

    mean /= numStudents;

    for (int i = 0; i < numStudents; i++)
    {
        deviation += pow((grades[i] - mean), 2);
    }

    deviation = sqrt((deviation/(numStudents)));

    cout << "Mean = " << mean << endl << "Standard deviation = " << deviation << endl;

    fileIn.close();
    return EXIT_SUCCESS;

}