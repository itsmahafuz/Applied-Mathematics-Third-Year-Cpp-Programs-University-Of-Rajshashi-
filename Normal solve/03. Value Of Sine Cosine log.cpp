/*
Date: 05/01/2025
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

// Function to calculate the value of sin(x) using its series expansion
void sinfun(double x, int n)
{
    double xr = x * (M_PI / 180); // Convert x from degrees to radians
    double sum = xr, fact = 1.0;  // Initialize sum with the first term of the series
    n = n - 1; // Adjust the number of terms
    int i = 1;
    
    if (n == 0)
    {
        cout << "\nThe value of sin(" << x << ") is : " << sum << endl;
    }
    else
    {
        while (i <= n)
        {
            fact = fact * (2 * i + 1) * (2 * i); // Calculate factorial
            sum = sum + (pow(-1, i) * pow(xr, 2 * i + 1)) / fact; // Add the next term in the series
            i++;
        }
        cout << "\nThe value of sin(" << x << ") is : " << sum << endl;
    }
}

// Function to calculate the value of cos(x) using its series expansion
void cosfun(double x, int n)
{
    double xr = x * (M_PI / 180); // Convert x from degrees to radians
    double sum = 1, fact = 1.0;  // Initialize sum with the first term of the series
    n = n - 1; // Adjust the number of terms
    int i = 1;
    
    if (n == 0)
    {
        cout << "\nThe value of cos(" << x << ") is : " << sum << endl;
    }
    else
    {
        while (i <= n)
        {
            fact = fact * (2 * i - 1) * (2 * i); // Calculate factorial
            sum = sum + (pow(-1, i) * pow(xr, 2 * i)) / fact; // Add the next term in the series
            i++;
        }
        cout << "\nThe value of cos(" << x << ") is : " << sum << endl;
    }
}

// Function to calculate the value of log(1+x) using its series expansion
void logfun(double x, int n)
{
    /* The natural logarithm ln(1+x) can be approximated by the series
       ln(1+u/1-u) = 2(u + u^3/3 + u^5/5 + ........)
       Where u = (y - 1) / (y + 1) and y = 1 + x */
       
    double y = 1 + x;
    double u = (y - 1) / (y + 1);
    double sum = 0;
    int i = 0;
    while (i < n)
    {
        sum = sum + (pow(u, 2 * i + 1) / (2 * i + 1)); // Add the next term in the series
        i++;
    }
    cout << "\nThe value of log(1+" << x << ") is : " << 2 * sum << endl;
}

int main()
{
    cout.precision(4); // Set the precision for floating-point output
    cout.setf(ios::fixed); // Use fixed-point notation for floating-point output
    char choice;
    do
    {
        int n, m, p;
        double x, y, z;
        
        cout << "\nEnter the value of x (in degrees) for sin(x):\n";
        cin >> x;
        cout << "\nEnter the number of terms that you want to calculate for sin(x) series:\n ";
        cin >> n;
        
        cout << "\nEnter the value of x (in degrees) for cos(x):\n";
        cin >> y;
        cout << "\nEnter the number of terms that you want to calculate for cos(x) series:\n ";
        cin >> m;
        
        cout << "\nEnter the value of x for log(1+x):\n";
        cin >> z;
        cout << "\nEnter the number of terms that you want to calculate for log(1+x) series:\n ";
        cin >> p;
        
        // Calculate and display the values using the series expansions
        sinfun(x, n);
        cosfun(y, m);
        logfun(z, p);
        
        cout << "\nIf you want to run the code again then press Y/y otherwise press any other character:\n";
        cin >> choice;
    } while (tolower(choice) == 'y');
    
    return 0;
}
