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

// In this program, I am using a User defined function

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void determinant(double *a, int n)
{
    int i, j, k;
    double det = 1.0; // Initialize determinant to 1

    // Pivotisation to make the matrix diagonally dominant
    for (i = 0; i < n; i++)
    {
        for (k = i + 1; k < n; k++)
        {
            if (abs(a[i * n + i]) < abs(a[k * n + i]))
            {
                // Swap rows i and k
                for (j = 0; j < n; j++)
                {
                    double temp = a[i * n + j];
                    a[i * n + j] = a[k * n + j];
                    a[k * n + j] = temp;
                }
                det *= -1; // Change sign of determinant when rows are swapped
            }
        }
    }

    cout << "\nThe matrix after pivotisation is:\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << a[i * n + j] << " "; // Print matrix element
        }
        cout << endl;
    }

    // Loop to perform the Gauss elimination
    for (i = 0; i < n; i++)
    {
        for (k = i + 1; k < n; k++)
        {
            double t = a[k * n + i] / a[i * n + i]; // Compute factor to eliminate element
            for (j = 0; j < n; j++)
            {
                a[k * n + j] -= t * a[i * n + j]; // Subtract row i from row k
            }
        }
    }

    cout << "\nThe matrix after Gauss elimination is:\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << a[i * n + j] << " "; // Print matrix element
        }
        cout << endl;
    }

    // Calculate the determinant using the diagonal elements
    for (i = 0; i < n; i++)
    {
        det *= a[i * n + i]; // Multiply diagonal elements
    }

    cout << "\nThe determinant of the square matrix is: " << det << endl; // Print determinant
}

int main()
{
    int n, y;
    cout.precision(2);     // Set precision for floating-point output
    cout.setf(ios::fixed); // Use fixed-point notation for floating-point output

NewStart:
    cout << "\nPlease enter the dimension of the square matrix:\n";
    cin >> n; // Read matrix dimension

    // Allocate memory for the matrix as a single pointer
    double *a = new double[n * n]; // Allocate a 1D array to represent the 2D matrix

    cout << "\nPlease enter the elements of the matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i * n + j]; // Read matrix element
        }
    }

    determinant(a, n); // Call function to calculate determinant

    // Deallocate memory for the matrix
    delete[] a; // Free the allocated memory

    cout << "\nDo you want to calculate the determinant for another matrix?\n";
    cout << "If yes, please press 1, otherwise press 0:\n";
    cin >> y; // Read user choice
    if (y == 1)
    {
        goto NewStart; // Repeat the process if user wants to calculate another determinant
    }

    return 0;
}
