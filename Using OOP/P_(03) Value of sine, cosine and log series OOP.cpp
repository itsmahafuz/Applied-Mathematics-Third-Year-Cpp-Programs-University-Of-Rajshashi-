/*
 MD MAHAFUZUR RAHMAN
 Roll:2110428176
 Department of Applied Mathematics
 University Of Rajshahi.
LinkedIn : https://www.linkedin.com/in/md-mahafuzur-rahman-07b80b1b7
GitHub : https://github.com/itsmahafuz
*/

/*Program to find the value of sin 𝑥 ,cos x and log(1 + x) using its
 series for some given 𝑥
using WHILE or DO WHILE condition.
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
#define pi 3.14159
#define epsilon 0.00001 // Tolerance for convergence

class Value
{
private:
    int n;
    double x, y;

public:
    // Function for sin x series..
   double sinefun(double xim, int num)
{
    x=xim;
    n=num;
    n = n - 1;
    x = x * (pi / 180.0);
    double fact = 1, sum = x;
    int i = 1;

    if (n == 0)
        sum = x;
    else
    {
        do
        {
            fact = fact * (2 * i + 1) * (2 * i);
            sum = sum + (pow(-1, i) * pow(x, 2 * i + 1)) / fact;
            i++;
        } while (i <= n);
    }
    return sum;
}

// Function for cos x series..

double cosinefun(double xem, int nem)
{
    n=nem;
    x=xem;
    x = x * (pi / 180.0);
    n = n - 1;
    double fact = 1, sum = 1;
    int i = 1;
    if (n == 0)
        sum = 1;
    else
    {
        do
        {
            fact = fact * (2 * i) * (2 * i - 1);
            sum = sum + (pow(-1, i) * pow(x, 2 * i)) / fact;
            i++;
        } while (i <= n);
    }
    return sum;
}

//Function for log(1+x) series...
//log10(1+x) = ln(1+x)/ln(10)

void logfun(double yim,int nim)
{
    y=yim;
    n=nim;
    x=1+y;
  
 
    
    //The natural logarithm ln(x) can be approximated by the series
    // ln(1+v/1-v)=2(v+v^3/3+v^5/5+........)
    //Where v=(x-1)/(x+1)

    // Calculate v used in the series approximation
    double v=(x-1)/(x+1);
    double sum=0.0,p;
    int i=1;
   while (i <= (2 * n - 1)) {
        p = 1;
        int j = 1;
        
        // Compute v^i
        while (j <= i) {
            p = p * v;
            j++;
        }
        
        // Add the term to the sum
        sum += p / i;
        i += 2;
    }

// Calculate the error between the standard log and the approximation
    double error = abs(log10(x) - 2 * sum / log(10));

    // Print the actual logarithm using the standard library
    cout << "\nThe actual vaule of log(1+y) using the standard library : " << log10(x) << endl;
    cout << "\nError : " << error<< endl;
    cout << "\nThe value of log (1 + " << y << ") = " << 2 * sum / log(10)<<endl;
  
}

};

int main()
{
    // Setting precision for floating-point output
    cout.precision(6);
    cout.setf(ios::fixed);
   NewStart:
    int n;
    double x,y;

    cout << "Please enter the value of y (y>=0 for log (1+y) series):\n";
    cin >> y;
    cout << "Please enter the value of x in degree(for sine and cosine series):\n";
    cin >> x;

    // Input the number of terms for series approximation
    cout << "Please enter the number of term(n>=1) that you want to calculate:\n";
    cin >> n;

    // Creating an object p of the class Value
    Value p;
    cout << "\nThe value of sin(" << x << ") is: "<<p.sinefun(x,n)<<endl;

    cout << "\nThe value of cos(" << x << ") is: "<<p.cosinefun(x,n)<<endl;

    cout<<"\nFOR log(1+x) series:\n";
    p.logfun(y,n);
    cout<<endl;

    double in;
    cout << "\n Do you want to check with new inputs?\n";
    cout << "\n If yes then please press 1 otherwise press 0:\n";
    cin >> in;
    if (in == 1)
   {
    goto NewStart;
   }
    return 0;
}