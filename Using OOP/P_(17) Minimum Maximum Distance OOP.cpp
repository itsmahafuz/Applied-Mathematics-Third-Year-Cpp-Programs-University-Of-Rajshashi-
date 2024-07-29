/* DATE : July 28, 2024
   MD MAHAFUZUR RAHMAN
   Roll: 2110428176
   Department of Applied Mathematics
   University Of Rajshahi.
   LinkedIn : https://www.linkedin.com/in/md-mahafuzur-rahman-07b80b1b7
   GitHub : https://github.com/itsmahafuz
*/

/*
Write an OOP program to find the smallest and largest distance
between any two points taken from a randomly given set of n points.
*/

#include <iostream>
#include <cmath>
using namespace std;

class MinMaxDistance
{
private:
    int n;               // Number of points
    double pnts[100][2]; // Array to store the coordinates of points
    double disNO[100];   // Array to store distances between pairs of points
    int m = 0;           // Counter for the distances array

public:
    // Constructor to input the number of points
    MinMaxDistance()
    {
        cout << "\nPlease make sure that all the points are distinct.\n";
        while (true)
        {
            cout << "\nEnter the number of points: ";
            cin >> n;

            if (n >= 2)
            {
                break;
            }

            cout << "\nThere should be at least two points\n";
        }
    }

    // Function to input the points
    void getPoints()
    {
        cout << "\nEnter the points row-wise (x y):\n";
        for (int i = 0; i < n; i++)
        {
            cin >> pnts[i][0] >> pnts[i][1];
        }
    }

    // Function to calculate the distance between any two points
    double distance(double x1, double y1, double x2, double y2)
    {
        double dx = x1 - x2;
        double dy = y1 - y2;
        return sqrt(dx * dx + dy * dy); // Return the Euclidean distance
    }

    // Function to calculate and print all pairwise distances
    void calculatePairs()
    {
        // Calculate all pairwise distances
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                disNO[m] = distance(pnts[i][0], pnts[i][1], pnts[j][0], pnts[j][1]);

                // Print the distance between the current pair of points
                cout << "Distance between (" << pnts[i][0] << ", " << pnts[i][1] << ") and ("
                     << pnts[j][0] << ", " << pnts[j][1] << ") is: " << disNO[m] << endl;

                m++;
            }
        }
    }

    // Function to sort distances and find the smallest and largest distances
    void finalAnswer()
    {
        // Sort the distances array in ascending order using bubble sort
        for (int i = 0; i < m - 1; i++)
        {
            for (int j = i + 1; j < m; j++)
            {
                if (disNO[i] > disNO[j])
                {
                    double temp = disNO[i];
                    disNO[i] = disNO[j];
                    disNO[j] = temp;
                }
            }
        }

        // Output the smallest and largest distances
        cout << "\nThe smallest distance is: " << disNO[0] << endl;
        cout << "\nThe largest distance is: " << disNO[m - 1] << endl;
    }
};

int main()
{
    cout.precision(2);
    cout.setf(ios::fixed);

    char choice;

    do
    {
        MinMaxDistance dd;
        dd.getPoints();
        cout<<endl;
        dd.calculatePairs();
        dd.finalAnswer();

        cout << "\nDo you want to run the program again? (y/n): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    return 0;
}
