/*
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

class prime
{
private:
    int flag = 0, num;

public:
    prime()
    {
        cout << "\n Please enter a number to check it is prime or not:\n";
        cin >> num;
    }

    void primex()
    {
        if (num <= 1)
        {
            cout << "\n The given number is not prime.\n";
        }
        else if (num > 1)
        {
            for (int i = 2; i < num - 1; i++)
            {
                if (num % i == 0)
                {
                    flag++;
                }
            }
            if (flag == 0)
                cout << "\n The given number is prime.\n";
            else
                cout << "\nThe given number is not prime.\n";
        }
    }
};

int main()
{
a:
    int check;
    prime x;
    x.primex();
    cout << "\nDo you want to check  another number?\n";
    cout << "\nIf yes then pless 1 otherwise press 0\n";
    cin >> check;
    if (check == 1)
        goto a;
    return 0;
}