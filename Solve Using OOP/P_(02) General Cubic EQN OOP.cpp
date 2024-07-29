/*
 Date: July 29,2024
 MD MAHAFUZUR RAHMAN
 Roll:2110428176
 Department of Applied Mathematics
 University Of Rajshahi.
LinkedIn : https://www.linkedin.com/in/md-mahafuzur-rahman-07b80b1b7
GitHub : https://github.com/itsmahafuz
*/

/*
Program to solve general cubic equation by using
determinant approach.
*/

#include <iostream>
#include <cmath>
#include <complex>

using namespace std;

class CubicEQN
{
private:
    double a, b, c, d;

public:
    CubicEQN()
    {
        // Input coefficients of the cubic equation
        cout << "Enter coefficients of cubic equation (ax^3 + bx^2 + cx + d): ";
        cin >> a >> b >> c >> d;
    }

    // Function to solve a cubic equation using the determinant approach
    void solveCubic()
    {
        // Handle the case where the equation is not cubic
        if (a == 0)
        {
            cout << "The coefficient 'a' cannot be zero. This is not a cubic equation." << endl;
            return;
        }

        // Calculate coefficients for the depressed cubic equation
        double p = (3 * a * c - b * b) / (3 * a * a);
        double q = (2 * b * b * b - 9 * a * b * c + 27 * a * a * d) / (27 * a * a * a);

        // Calculate the discriminant
        double delta = q * q / 4 + p * p * p / 27;

        // Calculate the constant term 'r'
        double r = -b / (3 * a);

        // Case 1: Delta > 0 (One real root, two complex conjugate roots)
        if (delta > 0)
        {
            double alpha = -q / 2 + sqrt(delta);
            double beta = -q / 2 - sqrt(delta);
            double u = cbrt(alpha);
            double v = cbrt(beta);
            double root1 = u + v + r;

            // Output real root and complex conjugate roots
            cout << "Root 1: " << root1 << endl;
            cout << "Root 2: " << -0.5 * (u + v) + r << " + " << sqrt(3.0) * (u - v) / 2 << "i" << endl;
            cout << "Root 3: " << -0.5 * (u + v) + r << " - " << sqrt(3.0) * (u - v) / 2 << "i" << endl;
        }
        // Case 2: Delta = 0 (One real root, two repeated real roots)
        else if (delta == 0)
        {
            double u = cbrt(-q / 2);
            double root1 = 2 * u + r;
            double root2 = -u + r;

            // Output roots
            cout << "Root 1: " << root1 << endl;
            cout << "Root 2: " << root2 << endl;
            cout << "Root 3: " << root2 << endl;
        }
        // Case 3: Delta < 0 (Three real roots)
        else
        {
            double rho = sqrt(-p * p * p / 27);
            double theta = acos(-q / (2 * rho));
            double factor = 2 * cbrt(rho);

            // Calculate the three real roots
            double root1 = factor * cos(theta / 3) + r;
            double root2 = factor * cos((theta + 2 * M_PI) / 3) + r;
            double root3 = factor * cos((theta + 4 * M_PI) / 3) + r;

            // Output the three real roots
            cout << "Root 1: " << root1 << endl;
            cout << "Root 2: " << root2 << endl;
            cout << "Root 3: " << root3 << endl;
        }
    }
};

int main()
{
    cout.precision(2);
    cout.setf(ios::fixed);

    char choice;

    do
    {
        cout<<endl;
        CubicEQN CU;
        CU.solveCubic();

        cout << "\nDo you want to put new values? (y/n) : ";
        cin >> choice;
        

    } while (choice == 'Y' || choice == 'y');

    return 0;
}