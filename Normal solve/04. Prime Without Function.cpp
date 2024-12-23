/*
 DATE : December 23rd,2024
 MD MAHAFUZUR RAHMAN
 Roll: 2110428176
 Department of Applied Mathematics
 University Of Rajshahi.
 LinkedIn : https://www.linkedin.com/in/md-mahafuzur-rahman-07b80b1b7
 GitHub : https://github.com/itsmahafuz
*/

/*
 Program to check whether any given number is prime or not. Write codes
 for both with and without user defined function.
*/

#include<iostream>
using namespace std;

int main()
{
    int num;  // Variable to store the number to be checked
    char choice;  // Variable to store user's choice to run the program again
    
    do
    {
        int flag = 0;  // Initialize flag to 0 for each iteration
        cout << "\nEnter a number to check: ";
        cin >> num;
        
        if (num <= 1)
        {
            cout << "\nThe number is not prime..\n";
        }
        else
        {
            for (int i = 2; i < num; i++)  // Loop from 2 to num-1
            {
                if (num % i == 0)  // Check if the number is divisible by i
                {
                    flag++;
                    break;  // Exit the loop if a divisor is found
                }
            }
            
            if (flag == 0)
            {
                cout << "\nThe number is a prime number..\n";
            }
            else
            {
                cout << "\nThe number is not a prime number..\n";
            }
        }
        
        cout << "\nDo you want to run the code again?\n";
        cout << "Press Y/y for yes and press N/n for no..\n";
        cin >> choice;
        
    } while (tolower(choice) == 'y');  // Continue if the user enters 'y' or 'Y'
    
    return 0;
}
