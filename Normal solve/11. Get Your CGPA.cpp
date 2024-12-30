/* DATE : December 23rd,2024
 MD MAHAFUZUR RAHMAN
 Roll: 2110428176
 Department of Applied Mathematics,
 University Of Rajshahi.
LinkedIn : https://www.linkedin.com/in/md-mahafuzur-rahman-07b80b1b7
GitHub : https://github.com/itsmahafuz
*/

/*
Program to take input of the name of a third year student of Applied
Mathematics, RU and marks obtained in all courses including LAB and
viva, and print the overall GPA in year three following the standard grading
criteria of Applied Mathematics.
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Function to get the grade point based on the marks
double GetGrade(double n)
{
    if(n >= 80)
        return 4.00; // A+
    else if(n >= 75)
        return 3.75; // A
    else if(n >= 70)
        return 3.50; // A-
    else if(n >= 65)
        return 3.25; // B+
    else if(n >= 60)
        return 3.00; // B
    else if(n >= 55)
        return 2.75; // B-
    else if(n >= 50)
        return 2.50; // C+
    else if(n >= 45)
        return 2.25; // C
    else if(n >= 40)
        return 2.00; // D
    else
        return 0.00;  // F (Fail)
}

int main()
{
    cout.precision(3);
    cout.setf(ios::fixed);
    char choice;

    do
    {
        // There are nine main courses of 100 marks
        // One lab of 100 marks
        // One viva of 50 marks

        double a[11];  // Array to store marks of courses
        string name;  // Variable to store student's name
        int roll;  // Variable to store student's roll number
        cout << "\nEnter your name: \n";
        cin.ignore();  // To ignore the newline character left by previous input
        getline(cin, name);  // To read the full name including spaces

        cout << "\nEnter your roll number:\n";
        cin >> roll;

        double CGrade = 0;  // Variable to store cumulative grade points
        for(int i = 0; i < 9; i++)
        {
        aga:
            // Prompt user to enter marks for each course
            cout << "\nEnter the marks obtained in the course A.Math-30" << i + 1 << ": ";
            cin >> a[i];
            if(a[i] > 100 || a[i] < 0)
            {
                cout << "\nInvalid marks, please enter again.";
                goto aga;
            }
            CGrade = CGrade + 4 * GetGrade(a[i]);  // Calculate grade points for each course
        }

        // For Lab course
        aa: 
        cout << "\nEnter the marks obtained in the course A.Math-320: ";
        cin >> a[9];
        if(a[9] > 100 || a[9] < 0)
        {
            cout << "\nInvalid marks, please enter again.";
            goto aa;
        }
        CGrade = CGrade + 4 * GetGrade(a[9]);  // Calculate grade points for lab course

        // For viva course
        ab: 
        cout << "\nEnter the marks obtained in the course A.Math-321: ";
        cin >> a[10];
        if(a[10] > 50 || a[10] < 0)
        {
            cout << "\nInvalid marks, please enter again.";
            goto ab;
        }
        a[10]=2.0*a[10];
        CGrade = CGrade + 4 * GetGrade( a[10]);  // Calculate grade points for viva course

        double result = CGrade / 44.00;  // Calculate overall GPA
        
        int count=0;
        //Check if the student has failed in more than two subjects
        for(int i=0;i<11;i++)
        {
        	if(GetGrade(a[i])==0)
        	count++;
	   }

        // Check if the student has failed
        if(GetGrade(a[9]) < 2.00 || GetGrade(a[10]) < 2.00 || result < 2.00 || count>2)
        {
            cout << "\nSorry ..You failed...!\n";
            cout<<"\nYour CGPA is : 0.00";
            cout << "\nBest of luck for the next time..\n";
        }
        else
        {
            cout << "\nCongratulations ..You passed...!\n";
            cout << "\nYour CGPA is: " << result << endl;
        }

        // Prompt the user to decide if they want to run the program again
        cout << "\nDo you want to calculate again? (Y/y for yes, any other key for no): ";
        cin >> choice;

    } while(tolower(choice) == 'y');  // Continue if the user enters 'y' or 'Y'

    return 0;
}
