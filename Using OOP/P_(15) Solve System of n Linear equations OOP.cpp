/*
Date : July 27,2024
 MD MAHAFUZUR RAHMAN
 Roll:2110428176
 Department of Applied Mathematics
 University Of Rajshahi.
LinkedIn : https://www.linkedin.com/in/md-mahafuzur-rahman-07b80b1b7
GitHub : https://github.com/itsmahafuz
*/

/* Program to solve a system of n linear equations by
using Gauss's Elimination method. */

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class SolveSystemOfLinearEQN
{
private:
    int n;
    double a[100][100], x[100]; // Declare an array to store the elements of augmented-matrix

public:
    SolveSystemOfLinearEQN()
    {
        cout << "\nEnter the number of equations: ";
        cin >> n;
    }

    void getAugmentedMatrix()
    {
        cout << "\nEnter the elements of the augmented-matrix row-wise:\n";
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n + 1; j++)
                cin >> a[i][j];
    }

    void printMatrix()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                cout << setw(10) << a[i][j] << " ";
            }
            cout << endl;
        }
    }

    void MatrixPivotisation()
    {
        // Pivotisation to make the equations diagonally dominant
        for (int i = 0; i < n; i++)
        {
            for (int k = i + 1; k < n; k++)
            {
                if (abs(a[i][i]) < abs(a[k][i]))
                {
                    for (int j = 0; j < n + 1; j++)
                    {
                        double temp = a[i][j];
                        a[i][j] = a[k][j];
                        a[k][j] = temp;
                    }
                }
            }
        }
        cout << "\nThe matrix after pivotisation is:\n";
        printMatrix();
    }

    void gaussianElimination()
    {
        // Loop to perform the Gauss elimination
        for (int i = 0; i < n; i++)
        {
            for (int k = i + 1; k < n; k++)
            {
                double t = a[k][i] / a[i][i];
                for (int j = 0; j < n + 1; j++)
                {
                    a[k][j] = a[k][j] - t * a[i][j];
                }
            }
        }
        cout << "\n\nThe matrix after Gauss-elimination is as follows:\n";
        printMatrix();
    }

    void BackSubstitution()
    {
        // Back-substitution
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i][i] == 0)
            {
                cout << "\nThe system is inconsistent.\n";
                return;
            }
            else
            {

                x[i] = a[i][n];
                for (int j = i + 1; j < n; j++)
                {
                    x[i] = x[i] - a[i][j] * x[j];
                }
                x[i] = x[i] / a[i][i];
            }
        }
    }

    void ValuesOfVariables()
    {
        cout << "\nThe values of the variables are as follows:\n";
        for (int i = 0; i < n; i++)
        {
            cout << "x" << i + 1 << "= " << x[i] << endl;
        }
    }
};

int main()
{
    cout.precision(3);
    cout.setf(ios::fixed);

    char choice;

    do
    {
        SolveSystemOfLinearEQN mat;
        mat.getAugmentedMatrix();
        mat.MatrixPivotisation();
        mat.gaussianElimination();
        mat.BackSubstitution();
        mat.ValuesOfVariables();

        cout << "\nDo you want to solve another system of equations? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    return 0;
}