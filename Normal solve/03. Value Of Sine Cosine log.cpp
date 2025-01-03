/*
Date: 03/01/2025
MD MAHAFUZUR RAHMAN
Roll: 2110428176
Department of Applied Mathematics
University Of Rajshahi.
LinkedIn : https://www.linkedin.com/in/md-mahafuzur-rahman-07b80b1b7
GitHub : https://github.com/itsmahafuz
*/

/* Calculate the value of sin(x), cos(x), and log(1+x) using its series for some
   given x using WHILE or DO WHILE condition. */

#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

#define pi 3.141592654  // Define the value of pi

// Function to calculate the approximate value of sin(x)
void sinfun(double x, int n)
{
    double xr = x * (pi / 180);  // Convert x from degrees to radians
    double sum = xr, fact = 1.0;  // Initialize sum with the first term of the series
    int i = 1;
    
    n = n - 1;  // Adjust the number of terms
    if (n == 0)  // If only the first term is required
    {
        cout << "\nThe approximate value of sin(" << x << ") is : " << sum << endl;
    }
    else
    {
        while (i <= n)  // Loop to calculate the series
        {
            fact = fact * (2 * i + 1) * (2 * i);  // Calculate factorial
            sum = sum + (pow(-1, i) * pow(xr, 2 * i + 1)) / fact;  // Add the next term in the series
            i++;
        }
        cout << "\nThe approximate value of sin(" << x << ") is : " << sum << endl;
    }
}

// Function to calculate the approximate value of cos(x)
void cosfun(double x, int n)
{
    double xr = x * (pi / 180);  // Convert x from degrees to radians
    double sum = 1, fact = 1.0;  // Initialize sum with the first term of the series
    int i = 1;
    
    n = n - 1;  // Adjust the number of terms
    if (n == 0)  // If only the first term is required
    {
        cout << "\nThe approximate value of cos(" << x << ") is : " << sum << endl;
    }
    else
    {
        while (i <= n)  // Loop to calculate the series
        {
            fact = fact * (2 * i - 1) * (2 * i);  // Calculate factorial
            sum = sum + (pow(-1, i) * pow(xr, 2 * i)) / fact;  // Add the next term in the series
            i++;
        }
        cout << "\nThe approximate value of cos(" << x << ") is : " << sum << endl;
    }
}

// Function to calculate the approximate value of log(1+x)
void logfun(double x, int n)
{
    /* The natural logarithm ln(1+x) can be approximated by the series
       ln(1+u/1-u) = 2(u + u^3/3 + u^5/5 + ........)
       Where u = (y - 1) / (y + 1) and y = 1 + x */
    double y = 1 + x;
    double u = (y - 1) / (y + 1);
    int i = 1;
    double sum = 0;
    
    while (i <= 2 * n - 1)  // Loop to calculate the series
    {
        sum = sum + pow(u, 2 * i - 1) / (2 * i - 1);  // Add the next term in the series
        i++;
    }
    cout << "\nThe approximated value of log(1+" << x << ") is : " << 2 * sum << endl;
}

int main()
{
    cout.precision(3);
    cout.setf(ios::fixed);
    char choice;
    do
    {
        double x, y, z, n;
        cout << "\nEnter the value of x (in degrees) for sin(x) series :\n";
        cin >> x;
        
        cout << "\nEnter the value of x (in degrees) for cos(x) series :\n";
        cin >> y;
        
        cout << "\nEnter the value of x >= 0 for log(1+x) series :\n";
        cin >> z;
        
        cout << "\nEnter the number of terms that you want to calculate for sin(x), cos(x), and log(1+x) series : \n";
        cin >> n;
        
        sinfun(x, n);  // Calculate sin(x)
        cosfun(y, n);  // Calculate cos(x)
        logfun(z, n);  // Calculate log(1+x)
        
        cout << "\nIf you want to run the code again then press Y/y otherwise press any other character:\n";
        cin >> choice;
        
    } while (tolower(choice) == 'y');  // Repeat the process if the user wants to
    return 0;
}
