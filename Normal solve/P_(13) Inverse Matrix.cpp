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

int main()
{

    cout.precision(2);
    cout.setf(ios::fixed);
    int n;
    double a[100][100];
New:

    //This will help us to make the matrix empty after iteration
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n; j++)
        {
            a[i][j] = 0;
        }
    }


    cout << "\nEnter the order of the matrix : ";
    cin >> n;
    cout << "\nEnter the elements :\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j]; // Let we take 2 5 1 3

    // Form an augmented matrix by adding an identity matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n; j++)
        {
            if (j == (i + n))
                a[i][j] = 1;
        }
    }

    cout << "After augment :" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n; j++)
            cout << a[i][j] << "  ";
        cout << endl;
    }
    /*The augmented matrix will be
    2.00 5.00 1.00 0.00
    1.00 3.00 0.00 1.00
    */

    // Pivotisation to make the matrix diagonally dominant
    for (int i = 0; i < n; i++)
        for (int k = i + 1; k < n; k++)
            if (abs(a[i][i]) < abs(a[k][i]))
            {
                for (int j = 0; j < 2 * n; j++)
                {
                    double temp = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = temp;
                }
            }

    cout << "\nAugmented matrix after pivotization is: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    /* Augmented matrix after pivotization is:
     2.00 5.00 1.00 0.00
     1.00 3.00 0.00 1.00 */

    // Now convert the left matrix to an identity matrix
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < 2 * n; k++)
        {
            if (k != i)
            {
                double temp = a[k][i] / a[i][i];
                for (int j = 0; j < 2 * n; j++)
                {
                    a[k][j] = a[k][j] - temp * a[i][j];
                }
            }
        }
    }

    cout << "\nConverting the left matrix to an identity matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    /* After converting
    2.00 0.00 6.00 -10.00
    0.00 0.50 -0.50 1.00 */

    // divide every row by its leading entry
    for (int i = 0; i < n; i++)
    {
        double temp = a[i][i];
        if (temp == 0)
        {
            cout << "\nThe given matrix doesn't have an inverse matrix." << endl;
            return 0;
        }
        else
        {
            for (int j = 0; j < 2 * n; j++)
            {
                a[i][j] = a[i][j] / temp;
            }
        }
    }

    cout << "\nThe required inverse matrix is: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j < 2 * n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    int si;
    cout << "\nDo you want to claculate again ?";
    cout << "\nIf yes,press 1 and no press 0\n";
    cin >> si;
    if (si == 1)
        goto New;

    return 0;
}
