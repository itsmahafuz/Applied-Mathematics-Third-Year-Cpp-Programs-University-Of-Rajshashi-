/* DATE : June 26th,2024
 MD MAHAFUZUR RAHMAN
 Roll:2110428176
 DEPARTMENT OF APPLIED MATHEMATICS
LinkedIn : https://www.linkedin.com/in/md-mahafuzur-rahman-07b80b1b7
GitHub : https://github.com/itsmahafuz
*/

// Largest and smallest number that can be formed using digit of a given number.

#include <iostream>
#include <cstring>
using namespace std;

int numDigits(int num)
{
    int digits = 0;
    if (num < 0)
        digits = 1; // Remove this line if '-' doesn't count as a digit
    while (num > 0)
    {
        num /= 10;
        digits++;
    }
    return digits;
}

int main()
{
New:
    int num;
    int temp, i, j, x;

    cout << "\nPlease Enter a positive integer number:\n";
    cin >> num;

    
    int n = numDigits(num);
    
    string a = to_string(num);

    /*For largest number we need to find out the descending order of 
     the digits.*/
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] < a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    // Hence the descending order for the given entries will be...
    cout << "\n The largest number that can be formed using the digits of the given number is : ";
    for (i = 0; i < n; i++)
        cout << a[i];
    cout << endl;

    // For smallest number we need to find out ascending order of the digit
    // For ascending order
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    // Hence the smallest number that can be formed ...
    cout << "\n The smallest number that can be formed using the digits of the given number is : ";
    for (i = 0; i < n; i++)
        cout << a[i];
    cout << endl;

    cout << "\nDo you want to check with a new number?\n";
    cout << "\nIf yes then press 1 otherwise press 0\n";
    cin >> x;
    if (x == 1)
        goto New;
    return 0;
}
