#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;


int main() {
    int amount = 0;

    cout << "Enter an amount in centre (round to nearest 5 cents):" << endl;
    cin >> amount;

    int toonies = 0, loonies = 0, quarters = 0, dimes = 0, nickels = 0;

    toonies = amount/200;
    amount %= 200;

    loonies = amount/100;
    amount %= 100;

    quarters = amount/25;
    amount %= 25;

    dimes = amount/10;
    amount %= 10;

    nickels = amount/5;

    cout << "Toonies = " << toonies << "\nLoonies = " << loonies << "\nQuarters = " << quarters << "\nDimes = " <<
         dimes << "\nNickels = " << nickels;
}
