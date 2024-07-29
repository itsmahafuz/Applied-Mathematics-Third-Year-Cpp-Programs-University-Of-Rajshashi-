/* DATE : July 23rd,2024
 MD MAHAFUZUR RAHMAN
 Roll:2110428176
 Department of Applied Mathematics,
 University Of Rajshahi.
LinkedIn : https://www.linkedin.com/in/md-mahafuzur-rahman-07b80b1b7
GitHub : https://github.com/itsmahafuz
*/

/*
Program to find the inverse of a given square matrix using
row-elementary operations.
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class InverseMatrix
{
private:
    int n;
    double a[100][100];

public:
    InverseMatrix()
    {
        cout << "\nEnter the order of the square matrix: ";
        cin >> n;

        // Initialize the matrix elements to zero
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 2 * n; j++)
            {
                a[i][j] = 0;
            }
        }
    }

    void getMatrix()
    {
        cout << "\nEnter the elements:\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
    }

    void formAugmentedMatrix()
    {
        // Form an augmented matrix by adding an identity matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 2 * n; j++)
            {
                if (j == (i + n))
                {
                    a[i][j] = 1;
                }
            }
        }

        cout << "\nAfter augment:\n";
        printMatrix();
    }

    void MatrixPivotisation()
    {
        // Pivotisation to make the matrix diagonally dominant
        for (int i = 0; i < n; i++)
        {
            for (int k = i + 1; k < n; k++)
            {
                if (abs(a[i][i]) < abs(a[k][i]))
                {
                    for (int j = 0; j < 2 * n; j++)
                    {
                        double temp = a[i][j];
                        a[i][j] = a[k][j];
                        a[k][j] = temp;
                    }
                }
            }
        }

        cout << "\nAugmented matrix after pivotization:\n";
        printMatrix();
    }

    void inverse()
    {

        // Convert the left matrix to an identity matrix
        for (int i = 0; i < n; i++)
        {
            if (a[i][i] == 0)
            {
                cout << "\nThe given matrix doesn't have an inverse matrix." << endl;
                return;
            }

            for (int k = 0; k < n; k++)
            {
                if (k != i)
                {
                    double temp = a[k][i] / a[i][i];
                    for (int j = 0; j < 2 * n; j++)
                    {
                        a[k][j] -= temp * a[i][j];
                    }
                }
            }
        }

        // Divide every row by its leading entry
        for (int i = 0; i < n; i++)
        {
            double temp = a[i][i];
           
        
                for (int j = 0; j < 2 * n; j++)
                {
                    a[i][j] /= temp;
                }
            
        }
        cout << "\nConverting the left matrix to an identity matrix:\n";
        printMatrix();

        cout << "\nThe required inverse matrix is:\n";
        printInverseMatrix();
    }

    void printMatrix()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 2 * n; j++)
            {
                cout << setw(8) << a[i][j] << " ";
            }
            cout << endl;
        }
    }

    void printInverseMatrix()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = n; j < 2 * n; j++)
            {
                cout << setw(8) << a[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    cout.precision(2);
    cout.setf(ios::fixed);

    char choice;

    do
    {
        InverseMatrix mat;
        mat.getMatrix();
        mat.formAugmentedMatrix();
        mat.MatrixPivotisation();
        mat.inverse();

        cout << "\nDo you want to find inverse of another matrix? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}