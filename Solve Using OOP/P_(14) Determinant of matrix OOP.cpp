/*
Date: July 27th,2024
 MD MAHAFUZUR RAHMAN
 Roll:2110428176
 Department of Applied Mathematics
 University Of Rajshahi.
LinkedIn : https://www.linkedin.com/in/md-mahafuzur-rahman-07b80b1b7
GitHub : https://github.com/itsmahafuz
*/

/*
Program to find the determinant of square matrix using row-elementary
operations.
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class DeterminantOfMatrix
{
private:
    int n;
    double a[100][100];
    double det = 1;

public:
    DeterminantOfMatrix()
    {
        // First we need to take the input of the matrix
        cout << "\nEnter the order of the square matrix: ";
        cin >> n;
    }

    void getMatrix()
    {
        cout << "\nEnter the elements of the matrix:\n";
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        /* Let
        matr=[1 2 3]
             [4 5 6]
             [7 8 9]
        */
    }

    void printMatrix()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << setw(8) << a[i][j] << " ";
            }
            cout << endl;
        }
    }

    void MatrixPivotisation()
    {
        // Pivotisation  to make the matrix diagonally dominant
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
                    det = det * (-1);
                }
            }
        }
        cout << "\nThe matrix after pivotisation is: \n";
        printMatrix();
        /*  The matrix after pivotisation is
        matr=[7 8 9]
             [4 5 6]
             [1 2 3]

        */
    }

    void GuessElimination()
    {
        for (int i = 0; i < n; i++)
        {
            for (int k = i + 1; k < n; k++)
            {
                double temp = a[k][i] / a[i][i]; // for i=0, t=4/7
                for (int j = 0; j < n; j++)
                {
                    a[k][j] = a[k][j] - temp * a[i][j]; // for i=0, a[1][0]=4-(7*(4/7))=0
                }
            }
        }
        cout << "\nThe matrix after Gausssian elimination is:\n";
        printMatrix();
        /* The matrix after Gauss elimination is:
      matr= [7.00 8.00 9.00]
             [0.00 0.43 0.86]
             [0.00 0.00 0.00]
        */
    }

    void Determinat()
    {
        // Calculate the determinant using the diagonal elements now
        for (int i = 0; i < n; i++)
            det = det * a[i][i];
        cout << "\nThe determinant of the given matrix is: " << det;
        cout << endl;
        cout << endl;
    }
};

int main()
{
    cout.precision(2);
    cout.setf(ios::fixed);

    char choice;

    do
    {
        DeterminantOfMatrix mat;
        mat.getMatrix();
        mat.MatrixPivotisation();
        mat.GuessElimination();
        mat.Determinat();

        cout << "\nDo you want to find the determinant for another matrix? (y/n): ";
        cin >> choice;
        
    } while (choice == 'Y' || choice == 'y');

    return 0;
}