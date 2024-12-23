/*
Date: 23/12/2024
MD MAHAFUZUR RAHMAN
Roll: 2110428176
Department of Applied Mathematics
University Of Rajshahi.
LinkedIn : https://www.linkedin.com/in/md-mahafuzur-rahman-07b80b1b7
GitHub : https://github.com/itsmahafuz
*/

/*
Program to solve a general cubic equation using
the determinant approach.
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Function to compute the solutions of the cubic equation
void getSolution(double a, double b, double c, double d)
{
    double p, q, r, del, u, v, rho, theta, factor;

    // Check if the equation is actually cubic
    if (a == 0)
    {
        cout << "\nThis is not a cubic equation... Try again...\n";
        return;
    }
    else
    {
        // Calculate reduced coefficients p and q for the cubic equation
        p = (3 * a * c - b * b) / (3 * a * a);
        q = (2 * b * b * b - 9 * a * b * c + 27 * a * a * d) / (27 * a * a * a);

        // Calculate the discriminant (del)
        del = pow((q / 2), 2) + pow((p / 3), 3);

        // Calculate the constant term for the real part of roots
        r = -b / (3 * a);

        // Case 1: One real root and two complex conjugate roots
        if (del > 0)
        {
            cout << "\nThe equation has one real root and two complex conjugate roots.\n";

            // Compute the real cube roots u and v
            u = cbrt(-(q / 2) + sqrt(del));
            v = cbrt(-(q / 2) - sqrt(del));

            // Real root
            cout << "\nThe real root is:\n" << u + v + r << endl;

            // Complex conjugate roots
            cout << "\nThe complex roots are:\n";
            cout << -((u + v) / 2) + r << " + " << (sqrt(3) / 2) * (u - v) << "i" << endl;
            cout << -((u + v) / 2) + r << " - " << (sqrt(3) / 2) * (u - v) << "i" << endl;
        }
        // Case 2: One single root and two repeated roots
        else if (del == 0)
        {
            cout << "\nThe equation has one single root and two repeated roots:\n";

            // Compute the repeated root
            u = cbrt(-(q / 2));

            // Single root
            cout << "\nThe single root is:\n" << 2 * u + r << endl;

            // Repeated root
            cout << "\nThe repeated root is:\n" << -u + r << endl;
        }
        // Case 3: Three distinct real roots
        else
        {
            cout << "\nThe equation has three distinct real roots.\n";

            // Compute rho and theta for trigonometric representation
            rho = sqrt(-(p * p * p) / 27);
            theta = acos(-q / (2 * rho));

            // Compute scaling factor
            factor = 2 * cbrt(rho);

            // Compute the three real roots
            // M_PI is used here to represent the value of p (pi), approximately 3.141592653589793.
            // It ensures calculations are accurate and done in radians, as trigonometric functions in C++ require angles in radians.
            cout << "\nThe first root is: " << factor * cos(theta / 3) + r << endl;
            cout << "\nThe second root is: " << factor * cos((theta + 2 * M_PI) / 3) + r << endl; // Add 2p/3 radians for the second root
            cout << "\nThe third root is: " << factor * cos((theta + 4 * M_PI) / 3) + r << endl; // Add 4p/3 radians for the third root
        }
    }
}

int main()
{
    // Set the precision for displaying floating-point numbers
    cout.precision(3);
    cout.setf(ios::fixed);

    char choice;  // Variable to store user's choice for rerunning the program
    double a, b, c, d;  // Coefficients of the cubic equation

    do
    {
        // Prompt the user to input coefficients for the cubic equation
        cout << "\nEnter the values of a, b, c, and d for the equation (a*x^3 + b*x^2 + c*x + d = 0): \n";
        cin >> a >> b >> c >> d;

        // Call the function to solve the cubic equation
        getSolution(a, b, c, d);

        // Ask the user if they want to run the code again
        cout << "\nIf you want to run the code again, press Y/y:\n";
        cin >> choice;
    } while (tolower(choice) == 'y');  // Continue if the user inputs 'Y' or 'y'

    return 0;
}
