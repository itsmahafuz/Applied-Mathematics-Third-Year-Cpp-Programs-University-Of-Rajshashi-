/* DATE : July 23rd,2024
 MD MAHAFUZUR RAHMAN
 Roll:2110428176
 Department of Applied Mathematics,
 University Of Rajshahi.
LinkedIn : https://www.linkedin.com/in/md-mahafuzur-rahman-07b80b1b7
GitHub : https://github.com/itsmahafuz
*/

/*
Program to find the dominant eigenvalue and corresponding eigenvector of
a given non-diagonal square matrix.
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

class EigenValueVector
{
private:
    int n;
    double a[100][100];
    double b[100];
    double c[100];
    double eps;

public:
    EigenValueVector(int size)
    {
        n = size;
    }

    void getMatrix()
    {
        cout << "\nEnter the elements of the matrix row-wise:\n";
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
    }

    void getInitialGuess()
    {
        cout << "\nEnter the initial guess for the eigen-vector:\n";
        for (int i = 0; i < n; i++)
            cin >> b[i];
    }

    void getAccuracy()
    {
        cout << "\nEnter the desired accuracy:\n";
        cin >> eps;
    }

    void calculateEigen()
    {
        double k = b[0]; // Assign some initial value to the eigenvalue
        double y;
        do
        {
            y = k;
            // Calculate axb where a is the matrix and b is its initial eigen vector
            for (int i = 0; i < n; i++)
            {
                c[i] = 0;
                for (int j = 0; j < n; j++)
                {
                    c[i] += a[i][j] * b[j]; // After all the iterations a*b=c
                }
            }

            k = abs(c[0]);
            for (int i = 1; i < n; i++)
            {
                if (k < abs(c[i]))
                    k = abs(c[i]); // Find the largest element of c and assign it to k
            }

            for (int i = 0; i < n; i++)
                b[i] = c[i] / k; // Calculate the new Eigen vector

        } while (abs(k - y) >= eps);

        cout << "\n\nThe largest Eigenvalue is: " << k << endl;
        cout << "\nAnd the corresponding Eigenvector is:\n";
        for (int i = 0; i < n; i++)
            cout << b[i] << endl;
        cout << "\n";
    }
};

int main()
{
    cout.precision(3);
    cout.setf(ios::fixed);

    int n;

    char choice;
    do
    {
        cout << "\nEnter the order of the matrix:\n";
        cin >> n;
        EigenValueVector mat(n);
        mat.getMatrix();
        mat.getInitialGuess();
        mat.getAccuracy();
        mat.calculateEigen();

        cout << "\nDo you want to calculate the eigenvalue and eigenvector for another matrix? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
