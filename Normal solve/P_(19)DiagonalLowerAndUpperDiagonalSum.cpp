/* DATE : June 2nd,2024
 MD MAHAFUZUR RAHMAN
 Roll:2110428176
 Department of Applied Mathematics
 University Of Rajshahi.
LinkedIn : https://www.linkedin.com/in/md-mahafuzur-rahman-07b80b1b7
GitHub : https://github.com/itsmahafuz
*/

/*
Write an OOP to read a matrix ,display the sum of its diagonal
elements,lower-diagonal elements and upper-diagonal elements.
*/

#include <iostream>
using namespace std;

const int Max = 100;

class matrix
{
private:
    int mat[Max][Max];
    int n;

public:
    matrix()
    {
        cout << "\nEnter the order of the square matrix : ";
        cin >> n;
    }

    void getMatrix()
    {
        // Input matrix elements
        cout << "\nEnter matrix elements:\n";
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                cin >> mat[i][j];
            }
    }

    void printDiagonalSum()
    {
        int ds = 0;
        // For Diagonal elements i=j
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i == j)
                    ds = ds + mat[i][j];

        cout << "\nThe Sum of the diagonal elements of the matrix is : " << ds << endl;
    }
    void lowerdiagonalSum()
    {
        int ldiagsum = 0;
        // For lower diagonal elements i>j
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (i > j)
                {
                    ldiagsum = ldiagsum + mat[i][j];
                }
            }
        cout << "\nThe Sum of the lower diagonal elements of the matrix is : " << ldiagsum << endl;
    }

    void upperdiagonalSum()
    {
        int udiagsum = 0;
        // For upper diagonal elements i<j
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (i < j)
                {
                    udiagsum = udiagsum + mat[i][j];
                }
            }
        cout << "\nThe Sum of the upper diagonal elements of the matrix is : " << udiagsum << endl;
    }
};

int main()
{
    cout.precision(3);
    cout.setf(ios::fixed);

    char choice;
    do
    {

        matrix mat;
        mat.getMatrix();
        mat.printDiagonalSum();
        mat.lowerdiagonalSum();
        mat.upperdiagonalSum();

        cout << "\nDo you want to calculate for another matrix? (y/n) : ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    return 0;
}