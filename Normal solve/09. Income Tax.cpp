/* 
 DATE : June 26th,2024
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

// Function to calculate the tax based on income
double gettax(double inc)
{
    if(inc<=250000)
    {
        return 0;  // No tax for income up to 250000
    }
    else if(inc>250000 && inc<=500000)
    {
        return (inc-250000)*.05;  // 5% tax for income above 250000 up to 500000
    }
    else if(inc>500000 && inc<=1000000)
    {
        return 250000*.05 + (inc-500000)*.1;  // Additional 10% tax for income above 500000 up to 1000000
    }
    else if(inc>1000000 && inc<=5000000)
    {
        return 250000*.05 + 500000*.1 +(inc -1000000)*.2;  // Additional 20% tax for income above 1000000 up to 5000000
    }
    else if(inc>5000000 && inc*10000000)
    {
        return 250000*.05 + 500000*.1 +4000000*.2+(inc-5000000)*.4;  // Additional 40% tax for income above 5000000
    }
    
}

int main()
{
    cout.precision(2);  // Set precision for floating-point output
    cout.setf(ios::fixed);  // Set the output format to fixed-point notation
    char choice;
    do
    {
        string name;
        cout<<"\nEnter your name (Start with a space) :\n";
        cin.ignore();  // Ignore the newline character left in the input buffer
        getline(cin,name);  // Get the user's name
        
        double inc;
        cout<<"\nEnter your yearly income : \n";
        cin>>inc;  // Get the user's yearly income
        
        cout<<"\nHello, \n\t Mr./Ms. "<<name<<endl;
        cout<<"\nYour income tax is : "<<gettax(inc)<<" tk.\n";  // Display the calculated tax
        
        cout<<"\n\nIf you want to run the code again then press Y/y otherwise press any other character : \n";
        cin>>choice;  // Get the user's choice to run the code again
    }while(tolower(choice)=='y');  // Repeat the process if the user wants to
    
    return 0;
}

