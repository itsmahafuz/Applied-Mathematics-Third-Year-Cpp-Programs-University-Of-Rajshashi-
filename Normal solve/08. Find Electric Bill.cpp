/* DATE : December 23rd,2024
 MD MAHAFUZUR RAHMAN
 Roll: 2110428176
 DEPARTMENT OF APPLIED MATHEMATICS,
 University Of Rajshahi.
LinkedIn : https://www.linkedin.com/in/md-mahafuzur-rahman-07b80b1b7
GitHub : https://github.com/itsmahafuz
*/

/* Program to take input of a user name and consumed current units and print
   an electric bill which billing criteria is as follows:
   i) First 50 units has minimum charge 100tk
   ii) Next 200 units cost 2.50 TK/unit
   iii) Next 250 units cost 3.50 TK/unit
   iv) Units above 500 are charged at a rate 5.00TK/unit
   Make sure you implement the idea using user-defined function. */

#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate the electric bill based on consumed units
void GetBill(double unit)
{
    double bill;
    if(unit <= 50)
        bill = 100;  // Minimum charge for first 50 units
    else if(unit > 50 && unit <= 250)
        bill = 100 + (unit - 50) * 2.50;  // Charge for next 200 units
    else if(unit > 250 && unit <= 500)
        bill = 100 + 200 * 2.50 + (unit - 250) * 3.50;  // Charge for next 250 units
    else if(unit > 500)
        bill = 100 + 200 * 2.50 + 250 * 3.50 + (unit - 500) * 5.00;  // Charge for units above 500
    
    // Print the calculated bill
    cout << "\nYour electric bill is: " << bill << "tk." << endl;
}

int main()
{
    cout.precision(2);  // Set precision for floating-point output
    cout.setf(ios::fixed);
    char choice;  // Character to store user's choice to run the program again

    do
    {
        string name;  // Variable to store username
        double unit;  // Variable to store consumed units
        
        cout << "\nEnter the username (kindly put a space before the username):";
	       cin.ignore();  // Ignore the newline character left by previous input
        getline(cin, name);  // Read the full name including spaces
        
        cout << "\nEnter consumed current units: ";
        cin >> unit;

        // Greet the user
        cout << "\nHello, Mr./Ms. " << name;

        GetBill(unit);  // Call the function to calculate and print the bill
        cout << endl;

        // Prompt the user to decide if they want to run the program again
        cout << "\nDo you want to run the code again?\n";
        cout << "Press Y/y for yes and press N/n for no..\n";
        cin >> choice;
        
    } while(tolower(choice) == 'y');  // Continue if the user enters 'y' or 'Y'
    
    return 0;
}
