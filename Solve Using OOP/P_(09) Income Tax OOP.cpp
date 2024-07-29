/*
 DATE : July 22,2024
 MD MAHAFUZUR RAHMAN
 Roll:2110428176
 DEPARTMENT OF APPLIED MATHEMATICS
 LinkedIn : https://www.linkedin.com/in/md-mahafuzur-rahman-07b80b1b7
 GitHub : https://github.com/itsmahafuz
*/

/*
Program to take input of a user name and yearly income and print income
tax where the taxation criteria is as follows
i) First 250000 is tax free
ii) 5% tax for next 250000
iii) 10% tax for next 500000
iv) 20% tax for next 4000000
v) 40% tax for income above 5000000
*/

#include <iostream>
#include <iomanip>
using namespace std;

class IncomeTax
{
private:
    string fname, lname;
    double inc;

public:
    IncomeTax()
    {
        cout << "\nEnter your First & last name:\n";
        // getline(cin, name); // Use getline to read the full name, including spaces
        cin >> fname >> lname;

        cout << "\nEnter your yearly total income: ";
        cin >> inc;
    }
    void Tax()
    {
        double tax = 0.0;
        if (inc <= 250000)
        {
            tax = 0.0;
        }
        else if (inc > 250000 && inc <= 500000)
        {
            tax = (inc - 250000) * .05;
        }
        else if (inc > 500000 && inc <= 1000000)
        {
            tax = 250000 * 0.05 + (inc - 500000) * 0.1;
        }
        else if (inc > 1000000 && inc <= 5000000)
        {
            tax = 250000 * 0.05 + 500000 * 0.1 + (inc - 1000000) * .2;
        }
        else
        {
            tax = 250000 * 0.05 + 500000 * 0.1 + 1000000 * .2 + (inc - 5000000) * .4;
        }
        cout << "\nMr./Ms." << fname << endl;
        cout << "Your Income Tax is : " << tax << " Tk." << endl;
    }
};

int main()
{
a:
    cout.precision(2);
    cout.setf(ios::fixed);
    int si;
    IncomeTax Yearly;
    Yearly.Tax();
    cout << "\nDO you want to calculate income tax for a different person?\n";
    cout << "\nIf yes press 1 or 0\n";
    cin >> si;
    if (si == 1)
        goto a;
    return 0;
}