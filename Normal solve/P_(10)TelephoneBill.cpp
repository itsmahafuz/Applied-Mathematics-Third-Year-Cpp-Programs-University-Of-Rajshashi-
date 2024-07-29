/* DATE : June 26th,2024
 MD MAHAFUZUR RAHMAN
 Roll:2110428176
 Department of Applied Mathematics,
 University Of Rajshahi.
LinkedIn : https://www.linkedin.com/in/md-mahafuzur-rahman-07b80b1b7
GitHub : https://github.com/itsmahafuz
*/

/*
Program to take input of a user name and minutes spent talking on the
telephone and print a telephone bill which billing criteria is as follows
i) First 150 minutes is free of cost
ii) Next 250 calls (151-400 minute) are charged at the rate of 1
   TK/minute
iii) And all calls after 400 minutes, are charged at the rate of
    2/minute
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double telephoneBill(double minutes)
{
    double bill = 0.0;
    if (minutes <= 150)
    {
        bill = 0.0;
    }
    else if (minutes > 150 && minutes <= 400)
    {
        bill = (minutes - 150) * 1;
    }
    else
    {
        bill = 250 * 1 + (minutes - 400) * 2;
    }
    return bill;
}
int main()
{
    cout.precision(2);
    cout.setf(ios::fixed);
    string firstname, lastname;
    int x;
New:
    cout << "\nPlease enter your first name and last name:\n";
    cin >> firstname >> lastname;
    double minutes;
    cout << "\nEnter the minutes spent talking on the telephone: ";
    cin >> minutes;
    cout << "\nMr./Ms. " << firstname << " " << lastname << ",\n";
    cout << "\nYour telephone bill is : " << telephoneBill(minutes) << " Tk." << endl;

    cout << "\nDo you want to calculate the bill for another person?\n";
    cout << "\nIf yes then pless 1 otherwise press 0\n";
    cin >> x;
    if (x == 1)
        goto New;
}
