/* DATE :06/01/2024
 MD MAHAFUZUR RAHMAN
 Roll:2110428176
 Department of Applied Mathematics,
 University Of Rajshahi.
LinkedIn : https://www.linkedin.com/in/md-mahafuzur-rahman-07b80b1b7
GitHub : https://github.com/itsmahafuz
*/

/* Write an OOP to find the inverse of an n × n square matrix. */

#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

class InverseMatrix
{
    private:    
        int n; // Order of the matrix
        double a[100][100], real[100][100], inv[100][100], c[100][100]; // Matrices for calculations

    public:
        // Constructor to initialize the matrix order and elements to zero
        InverseMatrix()
        {
            cout << "\nEnter the order of the matrix : \n";
            cin >> n;
            
            // Initialize augmented matrix elements to zero
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < 2 * n; j++)
                {
                    a[i][j] = 0;
                }
            }    
        }
        
        // Function to input the matrix elements
        void getmatrix()
        {
            cout << "\nEnter the elements of the matrix :\n";
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    cin >> a[i][j];
                }
            }
            // Store the original matrix to another matrix
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    real[i][j] = a[i][j];
                }
            }
        }

        // Function to print the augmented matrix
        void printmatrix()
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < 2 * n; j++)
                {
                    cout << a[i][j] << " ";
                }
                cout << "\n";
            }
        }

        // Function to augment the identity matrix and perform pivotisation
        void AugPiv()
        {
            // Augment the identity matrix
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < 2 * n; j++)
                {
                    if(j == (i + n))
                        a[i][j] = 1;        
                }
            }
            cout << "\nThe augmented matrix is : \n";
            printmatrix();
            
            // Pivotisation to ensure numerical stability
            for(int i = 0; i < n; i++)
            {
                for(int k = i + 1; k < n; k++)
                {
                    if(abs(a[i][i]) < abs(a[k][i]))
                    {
                        for(int j = 0; j < 2 * n; j++)
                        {
                            double temp = a[i][j];
                            a[i][j] = a[k][j];
                            a[k][j] = temp;
                        }
                    }
                }
            }
            cout << "\nThe matrix after pivotisation is : \n";
            printmatrix();
        }
        
        // Function to perform Gaussian elimination and find the inverse
        void Gaussian()
        {
            for(int i = 0; i < n; i++)
            {
                if(a[i][i] == 0)
                {
                    cout << "\nThe system is inconsistent..\n";
                    return;
                }
                for(int k = 0; k < n; k++)
                {
                    if(k != i)
                    {
                        double t = a[k][i] / a[i][i];
                        
                        for(int j = 0; j < 2 * n; j++)
                        {
                            a[k][j] = a[k][j] - t * a[i][j];
                        }
                    }
                }
            }
            cout << "\nThe matrix  after Gaussian Elimination is : \n";
            printmatrix();
            
            // Normalize the rows to form the identity matrix
            for(int i = 0; i < n; i++)
            {
                double k = a[i][i];
                for(int j = 0; j < 2 * n; j++)
                {
                    a[i][j] = a[i][j] / k;
                }
            }
            cout << "\nThe  matrix after dividing by leading entries is : \n";
            printmatrix();
            
            cout << "\nThe inverse matrix is :\n";
            for(int i = 0; i < n; i++)
            {
                for(int j = n; j < 2 * n; j++)
                {
                    cout << a[i][j] << " ";
                }
                cout << "\n";
            }
            // Store the inverse matrix
            for(int i = 0; i < n; i++)
            {
                for(int j = n; j < 2 * n; j++)
                {
                    inv[i][j - n] = a[i][j];
                }
            }
        }
        
        // Function to verify the inverse by multiplying the original matrix with its inverse
        void verifyInverse()
        {
            cout << "\nVerification : A*A^-1 is :\n";
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    c[i][j] = 0;
                    for(int k = 0; k < n; k++)
                    {
                        c[i][j] = c[i][j] + real[i][k] * inv[k][j];
                    }
                }
            }
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    cout << c[i][j] << " ";
                }
                cout << "\n";
            }
        }
};

int main()
{
    cout.precision(3); // Set the precision for floating-point output
    cout.setf(ios::fixed); // Use fixed-point notation for floating-point output
    char choice;
    do
    {
        InverseMatrix m1; // Create an instance of InverseMatrix
        m1.getmatrix(); // Input the matrix elements
        m1.AugPiv(); // Augment and pivot the matrix
        m1.Gaussian(); // Perform Gaussian elimination and find the inverse
        m1.verifyInverse(); // Verify the inverse by multiplying the original matrix with its inverse
        
        cout << "\n\nIf you want to run the code again then press Y/y otherwise press any other character : \n";
        cin >> choice;
    } while(tolower(choice) == 'y');
}
