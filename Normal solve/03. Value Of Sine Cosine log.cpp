/*
Date: 23/12/2024
MD MAHAFUZUR RAHMAN
Roll: 2110428176
Department of Applied Mathematics
University Of Rajshahi.
LinkedIn : https://www.linkedin.com/in/md-mahafuzur-rahman-07b80b1b7
GitHub : https://github.com/itsmahafuz
*/

/* Program to find the value of sin(x), cos(x), and log(1 + x) using its
   series for some given x using WHILE or DO WHILE condition. */

#include <iostream>
#include <cmath>
#define pi 3.14159  // Define the value of pi

using namespace std;

// Function to calculate sin(x) using its series expansion
void SineFun(double x, int n)
{
    double xr = x * (pi / 180);  // Convert x from degrees to radians
    double sum = xr, fact = 1;  // Initialize sum and factorial
    int i = 1;
    n = n - 1;  // Adjust number of terms

    if (n == 0)
    {
        sum = xr;  // If n is 0, sum is just xr
    }
    else
    {
        while (i <= n)
        {
            fact = fact * (2 * i + 1) * (2 * i);  // Calculate factorial for the denominator
            sum = sum + (pow(-1, i) * pow(xr, 2 * i + 1)) / fact;  // Update sum
            i++;
        }
    }
    // Output the calculated value of sin(x)
    cout << "\nThe value of sin(" << x << ") is : " << sum << endl;
}

// Function to calculate cos(x) using its series expansion
void CosineFun(double x, int n)
{
    double xr = x * (pi / 180);  // Convert x from degrees to radians
    double sum = 1, fact = 1;  // Initialize sum and factorial
    int i = 1;
    n = n - 1;  // Adjust number of terms

    if (n == 0)
    {
        sum = 1;  // If n is 0, sum is 1
    }
    else
    {
        while (i <= n)
        {
            fact = fact * (2 * i - 1) * (2 * i);  // Calculate factorial for the denominator
            sum = sum + (pow(-1, i) * pow(xr, 2 * i)) / fact;  // Update sum
            i++;
        }
    }
    // Output the calculated value of cos(x)
    cout << "\nThe value of cos(" << x << ") is : " << sum << endl;
}

// Function to calculate log(1 + x) using its series expansion
void LogFun(double x, int n)
{
    // The natural logarithm ln(1+x) can be approximated by the series
    // ln(1+u/1-u)=2(u+u^3/3+u^5/5+........)
    // Where u=(x-1)/(x+1)
    double y = 1 + x;
    double u = (y - 1) / (1 + y);  // Calculate u = (x-1)/(x+1)

    double sum = 0;
    // Iterate to sum the series terms
    int i = 1;
    while ( i < 2 * n - 1)
    {
        sum = sum + pow(u, 2 * i - 1) / (2 * i - 1);
        i++;
    }
    // Output the calculated value of log(1 + x)
    cout << "\nThe value of log(1 + " << x << ") is : " << 2 * sum << endl;
}

int main()
{
    cout.precision(6);  // Set precision for floating-point output
    cout.setf(ios::fixed);
    char choice;  // Variable to store user's choice to run the program again

    do
    {
        int n;  // Variable to store the number of terms
        double x, y;  // Variables to store input values for series calculation
        
        cout << "\nEnter the number of terms you want to calculate for sin(x), cos(x) and log(1 + x) series (n > 0) : ";
        cin >> n;

        cout << "\nEnter the value of x for sin(x) and cos(x) series (in degree) : ";
        cin >> x;

        cout << "\nEnter the value of x for log(1 + x) series : ";
        cin >> y;

        SineFun(x, n);  // Call function to calculate sin(x)
        CosineFun(x, n);  // Call function to calculate cos(x)
        LogFun(y, n);  // Call function to calculate log(1 + x)
        
        // Prompt the user to decide if they want to run the program again
        cout << "\nIf you want to run the code again then press Y/y otherwise press any other character: ";
        cin >> choice;

    } while (tolower(choice) == 'y');  // Continue if the user enters 'y' or 'Y'

    return 0;
}
