/* DATE : June 2nd,2024
 MD MAHAFUZUR RAHMAN
 Roll:2110428176
 Department of Applied Mathematics
 University Of Rajshahi.
LinkedIn : https://www.linkedin.com/in/md-mahafuzur-rahman-07b80b1b7
GitHub : https://github.com/itsmahafuz
*/

/*
Write a program to find the roots of a general quadratic equation.
*/

#include <iostream>
#include <cmath>
using namespace std;

void Quadratic(double a, double b, double c)
{
    double root, disc, r1, r2, rep, imp;
    if (a == 0)
    {
        cout << "\nThis is not a quadratic equation.\n";
        root = (-c) / b;
        cout << "\nThe root of this equation is : " << root << endl;
    }
    else
    {
        disc = b * b - 4 * a * c;
        if (disc == 0)
        {
            cout << "\nThe equation has two equal roots.\n";
            root = -b / (2 * a);
            cout << "Root-1 :" << root << endl;
            cout << "Root-2:" << root << endl;
        }
        else if (disc > 0)
        {
            cout << "\nThe equation has two real roots.\n";
            r1 = (-b + sqrt(disc)) / (2 * a);
            r2 = (-b - sqrt(disc)) / (2 * a);
            cout << "Root-1 :" << r1 << endl;
            cout << "Root-2:" << r2 << endl;
        }
        else
        {
            cout << "\nThe equation has two imaginary roots.\n";
            disc = -disc;
            rep = -b / (2 * a);
            imp = sqrt(disc) / (2 * a);
            cout << "Root-1 :" << rep << " +" << imp << "i" << endl;
            cout << "Root-2:" << rep << " -" << imp << "i" << endl;
        }
    }
}

int main()
{
    cout.precision(3);
    cout.setf(ios::fixed);
    double a, b, c;
    cout << "\nEnter the value of a,b & c for a quadratic equation(a*x^2+b*x+c=0):\n";
    cin >> a >> b >> c;
    Quadratic(a, b, c);
    return 0;
}