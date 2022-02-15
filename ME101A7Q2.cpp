#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <iostream>

using namespace std;

const double PAVE_COST = 19.5, FENCE_COST = 27.0, GATE_COST = 150.0, ADMIN_FEE = 45.0, HST = 1.13;

double tri_perim (double s1, double s2, double s3)
{
    return s1 + s2 + s3;
}

double tri_area (double s1, double s2, double s3)
{
    double semiPer = tri_perim(s1,s2,s3)/2;
    return sqrt(semiPer*(semiPer - s1)*(semiPer - s2)*(semiPer - s3));
}

double quad_perim (double s1, double s2, double s3, double s4)
{
    return s1 + s2 + s3 + s4;
}

double quad_area (double s1, double s2, double diag, double s3, double s4)
{
    return tri_area(s1,s2,diag) + tri_area(s3,s4,diag);
}

double total_cost (bool isFenced, double area, double perim)
{
    if (isFenced)
        return ((ceil(area)*PAVE_COST) + (ceil(perim)*FENCE_COST) + GATE_COST + ADMIN_FEE) * HST;
    return ((area*PAVE_COST) + ADMIN_FEE) * HST;
}

int main()
{
    ifstream fin("Sep_jobs.txt");
    ofstream fout("Sep_job_data.txt");

    if (!fin)
    {
        cout << "File not found!";
        return EXIT_FAILURE;
    }

    int jobNum = 0;
    bool isFenced = false;
    string shape;

    fout << "Job #" << setw(8) << "Fence" << setw(13) << "Paved Area" << setw(12) << "PaveCost" << setw(15) << "Fence Length"
         << setw(13) << "Fence Cost" << setw(8) << "Taxes" << setw(13) << "Total Cost" << endl;

    while (fin >> jobNum >> isFenced >> shape)
    {
        double s1 = 0, s2 = 0, s3 = 0, s4 = 0, diag = 0;
        double area = 0, paveCost = 0, perimeter = 0, fenceCost = 0, taxes = 0, totalCost = 0;

        if (shape == "tri")
        {
            fin >> s1 >> s2 >> s3;
            area = tri_area(s1, s2, s3);
            if (isFenced)    
                perimeter = tri_perim(s1, s2, s3);
        }
        else
        {
            fin >> s1 >> s2 >> diag >> s3 >> s4;
            area = quad_area(s1, s2, diag, s3, s4);
            if (isFenced)
                perimeter = quad_perim(s1, s2, s3, s4);
        }

        paveCost = ceil(area) * PAVE_COST;
        fenceCost = ceil(perimeter) * FENCE_COST + GATE_COST;
        totalCost = total_cost(isFenced, area, perimeter);
        taxes = (totalCost/HST) * (HST - 1);

        fout << fixed << setprecision(0) << jobNum << setw(7) << isFenced << setw(13) << setprecision(2) <<  area << setw(14) << paveCost 
             << setw(12) << perimeter << setw(14) << fenceCost << setw(11) << taxes << setw(11) << totalCost << endl;
    }

    fin.close();
    fout.close();

    return EXIT_SUCCESS;
}