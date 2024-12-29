/*
 DATE : December 28th, 2024
 MD MAHAFUZUR RAHMAN
 Roll: 2110428176
 Department of Applied Mathematics,
 University Of Rajshahi.
LinkedIn : https://www.linkedin.com/in/md-mahafuzur-rahman-07b80b1b7
GitHub : https://github.com/itsmahafuz
*/

/*
Program to find the inverse of a given square matrix using row
elementary operations.
*/

#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
    // Set the precision for displaying floating-point numbers
    cout.precision(3);
    cout.setf(ios::fixed);
    
    char choice; // Variable to check if the user wants to repeat the program
    do
    {
        int n; // Variable to store the order of the matrix
        cout << "\nEnter the order of the square matrix: \n";
        cin >> n;
        
        double a[n][2 * n]; // Declare an augmented matrix of size n x 2n
        
        // Initialize the matrix with zeros
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 2 * n; j++)
                a[i][j] = 0;
        
        // Input the elements of the square matrix
        cout << "\nEnter the elements of the square matrix:\n";
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        
        // Form the augmented matrix by appending an identity matrix to the square matrix
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 2 * n; j++)
            {
                if (j == i + n) // Add 1 to form the identity matrix
                    a[i][j] = 1;
            }
        
        // Display the augmented matrix
        cout << "\nThe augmented matrix is: \n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 2 * n; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
        
        // Pivotisation to make the diagonal elements dominant
        for (int i = 0; i < n; i++)
        {
            for (int k = i + 1; k < n; k++)
            {
                // Swap rows if the diagonal element is smaller than the current element
                if (abs(a[i][i]) < abs(a[k][i]))
                    for (int j = 0; j < 2 * n; j++)
                    {
                        double temp = a[i][j];
                        a[i][j] = a[k][j];
                        a[k][j] = temp;
                    }
            }
        }
        // Display the matrix after pivotisation
        cout << "\nThe matrix after pivotisation is: \n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 2 * n; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
        
        // Convert the left part of the matrix to an identity matrix
        for (int i = 0; i < n; i++)
        {
            if (a[i][i] == 0)
            {
                // If a diagonal element is zero, the matrix is not invertible
                cout << "\nThe given matrix doesn't have an inverse matrix..\n";
                goto S; // Exit the current operation
            }
            for (int k = 0; k < n; k++)
            {
                if (k != i) // Eliminate non-diagonal elements in the current column
                {
                    double temp = a[k][i] / a[i][i];
                    for (int j = 0; j < 2 * n; j++)
                    {
                        a[k][j] = a[k][j] - temp * a[i][j];
                    }
                }
            }
        }
        // Normalize each row to make the leading diagonal element 1
        for (int i = 0; i < n; i++)
        {
            double temp = a[i][i];
            for (int j = 0; j < 2 * n; j++)
            {
                a[i][j] = a[i][j] / temp;
            }    
        }
        
        // Display the augmented matrix after transformation
        cout << "\nAfter converting the left matrix to an identity matrix:\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 2 * n; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
        
        // Extract and display the inverse matrix (the right part of the augmented matrix)
        cout << "\nThe inverse matrix is : \n";
        for (int i = 0; i < n; i++)
        {
            for (int j = n; j < 2 * n; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
        
        S: // Label for handling non-invertible matrices
        // Ask the user if they want to run the program again
        cout << "\nIf you want to run the code again then press Y/y otherwise press any other character..: \n";
        cin >> choice;
    } while (tolower(choice) == 'y'); // Repeat if the user enters 'Y' or 'y'
}

