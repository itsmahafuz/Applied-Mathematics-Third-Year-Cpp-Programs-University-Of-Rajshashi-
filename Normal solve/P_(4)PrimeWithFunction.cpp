/*
 DATE : June 26th,2024
 MD MAHAFUZUR RAHMAN
 Roll:2110428176
 Department of Applied Mathematics
 University Of Rajshahi.
 LinkedIn : https://www.linkedin.com/in/md-mahafuzur-rahman-07b80b1b7
 GitHub : https://github.com/itsmahafuz
*/

/*
 Program to check whether any given number is prime or not. Write codes
 for both with and without user defined function.
*/

#include <iostream>
using namespace std;

void prime(int n)
{
    int flag = 0;
    if (n <= 1)
        cout << "\nThe given number is not prime.\n";
    else if (n > 1)
    {
        for (int i = 2; i < n - 1; i++)
        {

            if (n % i == 0)
                flag++;
        }
        if (flag == 0)
            cout << "\n The given number is prime.\n";
        else
            cout << "\nThe given number is not prime.\n";
    }
}

int main()
{
  a:
    int n;
    cout << "\nPlease enter a number to check it is prime or not:\n";
    cin >> n;
    prime(n);
  
   int x;
    cout << "\nDo you want to check  another number?\n";
    cout << "\nIf yes then pless 1 otherwise press 0\n";
    cin >> x;
    if (x == 1)
        goto a;

    return 0;
}
