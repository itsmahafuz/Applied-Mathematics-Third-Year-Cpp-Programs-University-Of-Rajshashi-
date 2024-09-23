/*
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

int main()
{
    int i, j, k, n, y;
    cout.precision(2);
    cout.setf(ios::fixed);

    // First we need to take the input of the matrix

NewStart:
    cout << "\nPlease enter the dimension of the square matrix:\n";
    cin >> n;
    double a[n][n], det = 1.0;
    cout << "\n Please enter the elements of the matrix:\n";
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    /* Let
    matr=[1 2 3]
         [4 5 6]
         [7 8 9]
    */
    // Pivotisation  to make the matrix diagonally dominant

    for (i = 0; i < n; i++)
        for (k = i + 1; k < n; k++)
        {
            if (abs(a[i][i]) < abs(a[k][i]))
            {
                for (j = 0; j < n; j++)
                {
                    double temp = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = temp;
                }
                det = det * -1;
            }
        }
    cout << "\nThe matrix after pivotisation is:\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    /*  The matrix after pivotisation is
        matr=[7 8 9]
             [4 5 6]
             [1 2 3]

        */

    // Loop to perform the Gauss elimination
    for (int i = 0; i < n; i++)
        for (int k = i + 1; k < n; k++)
        {
            double t = a[k][i] / a[i][i]; // for i=0, t=4/7
            for (int j = 0; j < n; j++)
            {
                a[k][j] = a[k][j] - t * a[i][j]; // for i=0, a[1][0]=4-(7*(4/7))=0
            }
        }

    cout << "\nThe matrix after Gauss elimination is:\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    /* The matrix after Gauss elimination is:
      matr= [7.00 8.00 9.00]
             [0.00 0.43 0.86]
             [0.00 0.00 0.00]
        */

    // Calculate the determinant using the diagonal elements now

    for (int i = 0; i < n; i++)
        det = det * a[i][i];
    cout << "\nThe determinant of square matrix is:  ";
    cout << det;

    cout << "\n Do you want to calculate determinant for another matrix?\n";
    cout << "\n If yes then please press 1 otherwise press 0:\n";
    cin >> y;
    if (y == 1)
        goto NewStart;
    return 0;
}
