/*
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

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Here t is the tolerence.If you want you can change this.
#define t 0.0000001

double f(double x)
{
    return pow(x,3)-2*x-5;
}
double ff(double x)
{
    return 3*pow(x,2)-2;
}
void NewtonRaphson(double x1)
{
    double x0 = 0;
    int i = 1;
    cout << "\n Accroding to Newton Raphson Method:\n";
    while (abs(x1 - x0) >= t)
    {
        x0 = x1;
        if (ff(x0) == 0)
        {
            cout << "\n Mathematical Error.\n";
            exit(0);
        }
        x1 = x0 - f(x0) / ff(x0);
        cout << "\n At step-" << i << " x" << i << " = " << x1 << endl;
        i++;
    }
    
    cout << "\nThe required root of the function is:" << x1 << endl;
    cout << "The number of times the iteration was continued is:" << i-1 << endl;
}

void Bisection(double a, double b)
{
    if (f(a) * f(b) >= 0)
    {
        cout << "\n Accroding to the Bisection method:\n";
        cout << " There is no root between  the given interval:\n";
    }
    else if (f(a) * f(b) < 0)
    {
        double c = (a + b) / 2;
        if (f(c) == 0)
        {
            cout << "\n Accroding to the Bisection method:\n";

            cout << " The root of the equation between the given interval is: " << c << endl;
        }
        else
        {
            while (fabs(a - b) >= t)
            {
                if (f(a) * f(c) < 0)
                    b = c;
                else if (f(b) * f(c) < 0)
                    a = c;
                c = (a + b) / 2.0;
            }
            cout << "\n Accroding to the Bisection method:\n";

            cout << " The root of the equation between the given interval is: " << c << endl;
        }
    }
}

int main()
{
    cout.precision(9);
    cout.setf(ios::fixed);
    double a, b, d, y;

NewStart:
    cout << "\n Please enter the initial interval [a,b] for Bisection Method:\n";
    cin >> a >> b;
    cout << "\n Please enter the initial guess for Newton Raphson Method:\n";
    cin >> d;
    NewtonRaphson(d);
    Bisection(a, b);
    cout << "\n Do you want to put a new interval?\n";
    cout << "\n If yes then please press 1 otherwise press 0:\n";
    cin >> y;
    if (y == 1)
        goto NewStart;
}