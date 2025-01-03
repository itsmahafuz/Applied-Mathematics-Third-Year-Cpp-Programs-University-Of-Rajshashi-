/* DATE : 03/01/2025
 MD MAHAFUZUR RAHMAN
 Roll: 2110428176
 DEPARTMENT OF APPLIED MATHEMATICS,
 University Of Rajshahi.
LinkedIn : https://www.linkedin.com/in/md-mahafuzur-rahman-07b80b1b7
GitHub : https://github.com/itsmahafuz
*/

/* Program to find the largest and smallest number that can be formed 
using digits of a given number. Write codes for both with and without 
user defined function.  */

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

void smallestNum(string num,int n)
{
    // At first we have to sort the digits in ascending order
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(num[i]>num[j])
            {
                // Swap the digits if they are in the wrong order
                char temp=num[i];
                num[i]=num[j];
                num[j]=temp;
            }
        }
    }

    // The smallest number is
    cout<<"\nThe smallest number is : ";
    if(num[0]=='0')
    {
        // If the first digit is zero, skip it and print the remaining digits
        for(int i=1;i<n;i++)
        {
            cout<<num[i];
        }
    }
    else
    {
        // Otherwise, print all the digits
        for(int  i=0;i<n;i++)
        {
            cout<<num[i];
        }
    }
}

void largestNum(string num,int n)
{
    // Sort the digits in descending order
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(num[i]<num[j])
            {
                // Swap the digits if they are in the wrong order
                char temp=num[i];
                num[i]=num[j];
                num[j]=temp;
            }
        }
    }
    
    // The largest number
    cout<<"\nThe largest number is : ";
    for(int i=0;i<n;i++)
    {
        cout<<num[i];
    }
}

int main()
{
    char choice;
    do
    {
        string num;
        cout<<"\nEnter a positive number : \n";
        cin>>num;
        
        int size=num.size();
        
        smallestNum(num,size); // Find the smallest number
        cout<<"\n";
        
        largestNum(num,size); // Find the largest number
        cout<<"\n";
        
        cout << "\nIf you want to run the code again then press Y/y otherwise press any other character:\n";
        cin >> choice;
    }while(tolower(choice)=='y'); // Repeat the process if the user wants to
    
    return 0;
}
