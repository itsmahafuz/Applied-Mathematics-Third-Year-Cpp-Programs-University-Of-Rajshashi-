/* DATE : December 23rd,2024
 MD MAHAFUZUR RAHMAN
 Roll: 2110428176
 DEPARTMENT OF APPLIED MATHEMATICS,
 University Of Rajshahi.
LinkedIn : https://www.linkedin.com/in/md-mahafuzur-rahman-07b80b1b7
GitHub : https://github.com/itsmahafuz
*/

// Largest and smallest number that can be formed using digits of a given number

#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main()
{
    char choice;  // Character to store user's choice for running the program again
    do
    {
        string number;  // Variable to store the input number as a string
        cout << "\nEnter a number:\n";
        cin >> number;
        int size = number.size();  // Get the size of the string using the inbuilt 'size()' function
        
        // Find the smallest number by sorting digits in ascending order
        for(int i = 0; i < size; i++)
        {
            for(int j = i + 1; j < size; j++)
            {
                if(number[i] > number[j])
                {
                    char temp = number[i];
                    number[i] = number[j];
                    number[j] = temp;
                }
            }
        }
        cout << "\nThe smallest number that can be formed using digits of the given number is: ";
        for(int i = 0; i < size; i++)
        {
            cout << number[i];
        }
        cout << endl;
        
        // Find the largest number by sorting digits in descending order
        for(int i = 0; i < size; i++)
        {
            for(int j = i + 1; j < size; j++)
            {
                if(number[i] < number[j])
                {
                    char temp = number[i];
                    number[i] = number[j];
                    number[j] = temp;
                }
            }
        }
        cout << "\nThe largest number that can be formed using digits of the given number is: ";
        for(int i = 0; i < size; i++)
        {
            cout << number[i];
        }
        cout << endl;
        
        // Prompt the user to decide if they want to run the program again
        cout << "\nIf you want to run the code again then press Y/y, otherwise press other characters: \n";
        cin >> choice;
    } while(tolower(choice) == 'y');  // Continue if the user enters 'y' or 'Y'
    
    return 0;
}

