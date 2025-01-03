/*
Date: 23/12/2024
 MD MAHAFUZUR RAHMAN
 Roll:2110428176
 Department of Applied Mathematics
 University Of Rajshahi.
LinkedIn : https://www.linkedin.com/in/md-mahafuzur-rahman-07b80b1b7
GitHub : https://github.com/itsmahafuz
*/

/*
Program to solve suppressed cubic equations or transcendental functions 
by using bisection method and Newton Raphson method.
*/

#include<iostream>
#include<iomanip>
#include<cmath>
#define  t 0.000001  // Tolerance level for stopping criterion
using namespace std;

// Function definition for f(x) = x^3 - 2x - 5
// This is the function whose root is to be found
double f(double x)
{
	return pow(x,3) - 2*x - 5;
}

// Derivative of the function f(x), f'(x) = 3x^2 - 2x
// Used in the Newton-Raphson method
double ff(double x)
{
	return 3*pow(x,2) - 2;
}

// Implementation of the Bisection Method to find a root within a given interval [a, b]
void BisectionMethod(double a, double b)
{
	cout<<"\nAccroding to Bisection Method...\n";
	// Check if the function changes sign over the interval [a, b]
	if (f(a) * f(b) >= 0)
	{
		cout << "\nThere is no root between this given interval..\n";
		return;
	}
	else
	{
		double c;
		c = (a + b) / 2;  // Initial midpoint calculation
		if (f(c) == 0)  // Check if midpoint itself is the root
		{
			cout << "\nThe root of the equation is : " << c << endl;
		}
		else
		{
			// Iterate until the interval width is less than the tolerance
			while (fabs(a - b) >= t)
			{
				if (f(a) * f(c) < 0)  // Root lies in [a, c]
					b = c;
				else if (f(b) * f(c))  // Root lies in [c, b]
					a = c;
				c = (a + b) / 2.0;  // Update midpoint
			}
			cout << "\nThe root of the equation is : " << c << endl;
		}
	}
}

// Implementation of the Newton-Raphson Method to find a root starting from an initial guess x1
void NewtonRaphson(double x1)
{
	double x0 = 0;  // Initial value for the previous approximation
	int i = 1;  // Step counter
	cout << "\nAccording to Newton Raphson method...\n";

	// Iterate until the difference between successive approximations is less than the tolerance
	do
	{
		x0 = x1;  // Update previous approximation
		if (ff(x0) == 0)  // Check for division by zero
		{
			cout << "\nMathematical Error...\n";
			return;
		}
		x1 = x0 - f(x0) / ff(x0);  // Newton-Raphson formula
		cout << "\nAt step- " << i << " x" << i << " = " << x1 << endl;
		i++;
	}while (abs(x1 - x0) >= t);
	cout << "\nThe root of the function in the given interval is : " << x1 << endl;
}

int main()
{
	cout.precision(8);  // Set precision for floating-point output
	cout.setf(ios::fixed);  // Use fixed-point notation for output
	char choice;  // Variable to store user's choice for repetition
	double a, b, c;  // Variables to store input intervals and initial guess
	
	do
	{
		cout << "\nEnter the initial interval for Bisection method : ";
		cin >> a >> b;  // Input interval [a, b]
		cout << "\nEnter the initial guess for Newton Raphson method: ";
		cin >> c;  // Input initial guess for Newton-Raphson
		
		BisectionMethod(a, b);  // Call Bisection Method
		cout << "\n";
		NewtonRaphson(c);  // Call Newton-Raphson Method
		cout << endl;
		
		cout << "\nIf you want to run the code again then press Y/y, otherwise press any other character: ";
		cin >> choice;  // Input user's choice
	} while (tolower(choice) == 'y');  // Repeat if user chooses 'y' or 'Y'
}
