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
using namespace std;

int main()
{
NewStart:

	cout.precision(3);
	cout.setf(ios::fixed);

	int n;
	// Get the order of the square matrix
	cout << "\nEnter the order of the matrix:\n";
	cin >> n;

	// Declare arrays and other variables
	double a[n][n], b[n], c[n], eps, y;
	cout << "\nEnter the elements of the matrix row-wise:\n";
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];

	// Get the initial guess for	the eigen vector
	cout << "\nEnter the initial guess for thr eigen-vector:\n";
	for (int i = 0; i < n; i++)
		cin >> b[i];

	cout << "\nEnter the desired accuracy:\n";
	cin >> eps;

	double k = b[0]; // Assign some intitial value to the eigen value
	do
	{
		y = k;
		// Calculate axb where a is the matrix and b its intitial eigen vector

		for (int i = 0; i < n; i++)
		{
			c[i] = 0;
			for (int j = 0; j < n; j++)
			{
				c[i] = c[i] + a[i][j] * b[j]; // Afterall the iteration a*b=c
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

	cout << "\n\nThe largest Eigenvalue is : " << k << endl;
	cout << "\nAnd the corresponding Eigenvector is: \n";
	for (int i = 0; i < n; i++)
		cout << b[i] << endl;
	cout << "\n";


	int si;
	cout << "\nDo you want to calculate the determinant for another matrix?\n";
	cout << "If yes, please press 1, otherwise press 0:\n";
	cin >> si; // Read user choice
	if (si == 1)
	{
		goto NewStart; // Repeat the process if user wants to calculate another determinant
	}
	return 0;
}
