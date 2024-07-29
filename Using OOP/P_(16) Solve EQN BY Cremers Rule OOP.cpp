/*
Date : July 28,2024
 MD MAHAFUZUR RAHMAN
 Roll:2110428176
 Department of Applied Mathematics
 University Of Rajshahi.
LinkedIn : https://www.linkedin.com/in/md-mahafuzur-rahman-07b80b1b7
GitHub : https://github.com/itsmahafuz
*/

/* Program to solve a system of n linear equations by
using Cremer's rule. */

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class SolveSystemOfEQN
{
private:
    int n;
    double CF[100][100], b[100], T[100][100], CM[100][100], x[100];

public:
    SolveSystemOfEQN()
    {
        cout << "\nEnter the number of equations:\n";
        cin >> n;
    }

    void getMainMatrix()
    {
        cout << "\nEnter the elements of the matrix row-wise:\n";
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> CF[i][j];
    }

    void getConstantMatrix()
    {
        cout << "\nEnter the elements of the RHM :\n";
        for (int i = 0; i < n; i++)
            cin >> b[i];
    }

    double det(int n, double a[100][100])
    {
        double determinant = 1.0;

        // Pivotisation code
        for (int i = 0; i < n; i++)
        {
            for (int k = i + 1; k < n; k++)
            {
                if (abs(a[i][i]) < abs(a[k][i]))
                {
                    for (int j = 0; j < n; j++)
                    {
                        double temp = a[i][j];
                        a[i][j] = a[k][j];
                        a[k][j] = temp;
                    }
                    determinant = determinant * (-1);
                }
            }
        }

        // Diagonalization code
        for (int i = 0; i < n; i++)
        {
            for (int k = i + 1; k < n; k++)
            {
                double t = a[k][i] / a[i][i];
                for (int j = 0; j < n; j++)
                {
                    a[k][j] = a[k][j] - t * a[i][j];
                }
            }
        }

        // Finally Calculate the determinant;
        for (int i = 0; i < n; i++)
            determinant = determinant * a[i][i];
        return determinant;
    }

    void CremersRule()
    {
        // Store the co-efficient matrix in a different matrix
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                T[i][j] = CF[i][j];

        double DetCF = det(n, CF);
        if (DetCF == 0)
        {
            cout << "\nThe system doesn't have a  unique solution.\n";
            return;
        }
        else
        {
            // Now apply Cremer's Rule
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    for (int k = 0; k < n; k++)
                    {
                        if (k != i)
                            CM[j][k] = T[j][k];
                        else
                            CM[j][k] = b[j];
                    }
                }
                x[i] = det(n, CM) / DetCF;
            }
        }

        cout << "\nThe required solution is :\n";
        for (int i = 0; i < n; i++)
            cout << "x" << i + 1 << "= " << x[i] << endl;
    }
};

int main()
{
    cout.precision(2);
    cout.setf(ios::fixed);

    char choice;

    do
    {
        SolveSystemOfEQN crem;
        crem.getMainMatrix();
        crem.getConstantMatrix();
        crem.CremersRule();

        cout << "\nDo you want to solve another system of equations? (y/n): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
    return 0;
}