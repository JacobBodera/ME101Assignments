#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    string fileName;

    cout << "Please input the name of the file:  ";
    cin >> fileName;

    ifstream fin(fileName.c_str());

    if(!fin)
    {
        cout << "This file could not be found!";
        return EXIT_FAILURE;
    }
    const int ROWS = 200;
    const int COLS = 79;
    char image[ROWS][COLS];

    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
           image[r][c] = ' ';
        }
    }

    char character;
    int height = 0, row = 0, col = 0, minRow = ROWS + 1, maxRow = -1;
    fin >> height;
    while (fin >> row >> col >> character)
    {
         image[row][col] = character;

        if (row < minRow)
            minRow = row;
        if (row > maxRow)
            maxRow = row;
    }

    for (int r = minRow; r <= maxRow; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
           cout << image[r][c];
        }
        cout << endl;
    }
    fin.close();
    return EXIT_SUCCESS;
}