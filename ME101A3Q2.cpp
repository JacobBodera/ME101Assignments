#include <cstdlib>
#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// assume that integers are less than abs(1 000 000)

int main()
{
    ifstream fileIn("intNumber.txt");

    if (!fileIn)
    {
        cout << "FILE NOT FOUND!";
        return EXIT_FAILURE;
    }   

    int num = 0, preComma = 0, postComma = 0;

    for (int i = 0; i < 10; i++)
    {
        fileIn >> num;
        
        if (abs(num) >= 1000)
        {
            preComma = abs(num/1000);
            postComma = abs(num%1000);

            if (num < 0)
                preComma *= -1;
            
            cout << preComma << "," << setfill('0') << setw(3) << postComma << endl;
        }
        else
        {
            cout << num << endl;
        }
        
    }

    fileIn.close();
    return EXIT_SUCCESS;
}