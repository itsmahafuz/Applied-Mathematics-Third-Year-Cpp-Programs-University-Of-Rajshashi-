/* DATE : July 23rd,2024
 MD MAHAFUZUR RAHMAN
 Roll:2110428176
 Department of Applied Mathematics,
 University Of Rajshahi.
LinkedIn : https://www.linkedin.com/in/md-mahafuzur-rahman-07b80b1b7
GitHub : https://github.com/itsmahafuz
*/

/*
Program to take input of the name  of a third year student of Applied
Mathematics, RU and marks obtained in all courses including LAB and
viva, and print the overall GPA in year three following the standard grading
criteria of Applied Mathematics.
*/

/*
In the third year, there are 11 courses including LAB and Viva.
Where full mark of Viva course is 50 and full mark of the others are 100.*/

#include <iostream>
#include <cmath>
using namespace std;

class GetYourCGPA
{
private:
    string firstname, lastname;
    int r;
    double marks, sum = 0, m320, m321;
    double a[11];

public:
    GetYourCGPA()
    {
        cout << "\nEnter your first name and last name:\n";
        cin >> firstname >> lastname;
        cout << "\nEnter Roll number:\n";
        cin >> r;
    }
    double grade(double m)
    {
        marks = m;
        if (marks >= 80)
            return 4.00; // A+
        else if (marks >= 75)
            return 3.75; // A
        else if (marks >= 70)
            return 3.50; // A-
        else if (marks >= 65)
            return 3.25; // B+
        else if (marks >= 60)
            return 3.00; // B
        else if (marks >= 55)
            return 2.75; // B-
        else if (marks >= 50)
            return 2.50; // C+
        else if (marks >= 45)
            return 2.25; // C
        else if (marks >= 40)
            return 2.00; // D
        else
            return 0.00; // F
    }

    void CGPA()
    {
        // We will get the marks of 9 main course (i.e. Without Lab and Viva)
        for (int i = 1; i < 10; i++)
        {
        a:
            cout << "\nEnter marks obtained in the course A.Math-30" << i << " : ";
            cin >> marks;
            if (marks < 0 || marks > 100)
                goto a;
            a[i] = grade(marks) * 4.0;
            sum = sum + a[i]; // Here we multiplied grade with 4.0 because this course has 4 credits
        }

    // Now we will take input of Lab coure 320
    b:
        cout << "\nEnter marks obtained in the course A.Math-320 : ";
        cin >> m320;
        if (m320 < 0 || m320 > 100)
            goto b;
        a[10] = grade(m320) * 4.0;
        sum = sum + a[10];

        // Now we will take input of Viva coure 321
        // The full mark for this course is 50.
    c:
        cout << "\nEnter marks obtained in the course A.Math-321 : ";
        cin >> m321;
        m321 = m321 * 2;
        if (m321 < 0 || m321 > 100)
            goto c;
        a[11] = grade(m321) * 4.0;
        sum = sum + a[11];

        /*Accroding To Applied Mathematics If you fail in A.Math-320
        then you are fail..
        */
        if (m320 < 40)
        {
            cout << "\nYour CGPA is : 0.00\n"
                 << endl;
            cout << "Sorry! You fail.\n";
        }
        else
        {
            // Another rule is if you fail more than 2 courses then you fail
            int count = 0;
            for (int i = 1; i < 12; i++)
            {
                if (a[i] == 0)
                    count++;
            }
            if (count > 2)
            {
                cout << "\nYour CGPA is : 0.00\n"
                     << endl;
                cout << "Sorry! You fail.\n";
            }
            else
            {
                // CGPA=summation(credit*grade)/summation(credit)
                cout << "\nYour CGPA is : " << sum / 44; // Total credit=10*4+2=40+2=42
                cout << "\nCongratulation ! You pass..\n";
            }
        }
    }
};

int main()
{
New:
    GetYourCGPA result;
    result.CGPA();

    int x;
    cout << "\nDo you want to calculate the CGPA for another person?\n";
    cout << "\nIf yes then pless 1 otherwise press 0\n";
    cin >> x;
    if (x == 1)
        goto New;
}