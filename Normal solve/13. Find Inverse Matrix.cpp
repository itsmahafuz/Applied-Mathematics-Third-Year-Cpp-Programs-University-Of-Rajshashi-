/*
 DATE : 05/01/2024
 MD MAHAFUZUR RAHMAN
 Roll: 2110428176
 Department of Applied Mathematics,
 University Of Rajshahi.
LinkedIn : https://www.linkedin.com/in/md-mahafuzur-rahman-07b80b1b7
GitHub : https://github.com/itsmahafuz
*/

/* Program to find the inverse of a given square matrix using row
elementary operations. */

#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
    cout.precision(3); // Set the precision for floating-point output
    cout.setf(ios::fixed); // Use fixed-point notation for floating-point output
    
    char choice;
    do
    {
        int n;
        cout << "\nEnter the order of the square matrix: \n";
        cin >> n;
        
        double a[n][2*n], real[n][n], inv[n][n], c[n][n];
        
        // Initializing zero matrix
        for(int i=0; i<n; i++)
            for(int j=0; j<2*n; j++)
                a[i][j] = 0;
        
        cout << "\nEnter the elements:\n";
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin >> a[i][j];
        
        // Store the original matrix
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                real[i][j] = a[i][j];
        
        // Augment the identity matrix to the original matrix
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<2*n; j++)
            {
                if(j == (i + n))
                {
                    a[i][j] = 1;
                }
            }
        }
        
        cout << "\nThe augmented matrix is: \n";
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<2*n; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
        
        // Pivotisation to ensure numerical stability
        for(int i=0; i<n; i++)
        {
            for(int k=i+1; k<n; k++)
            {
                if(abs(a[i][i]) < abs(a[k][i]))
                {
                    for(int j=0; j<2*n; j++)
                    {
                        double temp = a[i][j];
                        a[i][j] = a[k][j];
                        a[k][j] = temp;
                    }
                }
            }
        }
        
        cout << "\nThe pivotised matrix is: \n";
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<2*n; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
        
        // Gaussian elimination to form the identity matrix
        for(int i=0; i<n; i++)
        {
            if(abs(a[i][i]) == 0)
            {
                cout << "\nThe system is inconsistent.\n";
                goto aa;
            }
            for(int k=0; k<n; k++)
            {
                if(k != i)
                {
                    double t = a[k][i] / a[i][i];
                    for(int j=0; j<2*n; j++)
                    {
                        a[k][j] = a[k][j] - t * a[i][j];
                    }
                }
            }
        }
        
        cout << "\nThe matrix after Gaussian elimination is: \n";
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<2*n; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
        
        // Normalize the rows to form the identity matrix on the left side
        for(int i=0; i<n; i++)
        {
            double k = a[i][i];
            for(int j=0; j<2*n; j++)
            {
                a[i][j] = a[i][j] / k;
            }
        }
        
        cout << "\nThe matrix after normalization is: \n";
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<2*n; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
        
        cout << "\nThe inverse matrix is: \n";
        for(int i=0; i<n; i++)
        {
            for(int j=n; j<2*n; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        
        // Store the inverse matrix
        for(int i=0; i<n; i++)
            for(int j=n; j<2*n; j++)
                inv[i][j-n] = a[i][j];
        
        // Verify the result by multiplying the original matrix by its inverse
        cout << "\nVerify: A * A^-1: \n";
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                c[i][j] = 0;
                for(int k=0; k<n; k++)
                {
                    c[i][j] += real[i][k] * inv[k][j];
                }
            }
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout << c[i][j] << " ";
            }
            cout << "\n";
        }
        
        aa:
        cout << "\n\nIf you want to run the code again then press Y/y otherwise press any other character: \n";
        cin >> choice;
    } while(tolower(choice) == 'y');
    
    return 0;
}

