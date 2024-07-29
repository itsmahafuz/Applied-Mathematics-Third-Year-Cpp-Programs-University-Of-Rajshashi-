/* DATE : July 28,2024
 MD MAHAFUZUR RAHMAN
 Roll:2110428176
 Department of Applied Mathematics
 University Of Rajshahi.
LinkedIn : https://www.linkedin.com/in/md-mahafuzur-rahman-07b80b1b7
GitHub : https://github.com/itsmahafuz
*/

/*
Write an OOP  find the smallest and largest distance
between any two points taken from a randomly given set of n points.
*/

#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate the distance between any two points
double distance(double x1, double y1, double x2, double y2) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(dx * dx + dy * dy); // Return the Euclidean distance
}

int main() {
    cout << "\nPlease make sure that all the points you enter are distinct\n";
    int n;

    // Prompt user to enter the number of points
    while (true) {
        cout << "\nEnter the number of points: ";
        cin >> n;
        
        if (n >= 2) {
            break; // Ensure there are at least two points
        }

        cout << "\nThere should be at least two points\n";
    }

    double points[n][2]; // Array to store the coordinates of points

    // Prompt user to enter the coordinates of the points
    cout << "\nEnter the points row-wise (x y):\n";
    for (int i = 0; i < n; ++i) {
        cin >> points[i][0] >> points[i][1];
    }

    // Calculate the number of unique pairs of points
    int numDistances = n * (n - 1) / 2;
    double distances[numDistances]; // Array to store distances between pairs of points
    int m = 0; // Counter for the distances array

    // Calculate all pairwise distances
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            distances[m] = distance(points[i][0], points[i][1], points[j][0], points[j][1]);
            // Print the distance between the current pair of points
            cout << "Distance between (" << points[i][0] << ", " << points[i][1] << ") and (" 
                 << points[j][0] << ", " << points[j][1] << ") is " << distances[m] << endl;
            m++;
        }
    }

    // Sort the distances array in ascending order using bubble sort
    for (int i = 0; i < numDistances - 1; ++i) {
        for (int j = i + 1; j < numDistances; ++j) {
            if (distances[i] > distances[j]) {
                // Swap distances[i] and distances[j]
                double temp = distances[i];
                distances[i] = distances[j];
                distances[j] = temp;
            }
        }
    }

    // Output the smallest and largest distances
    cout << "\nThe smallest distance is: " << distances[0] << endl;
    cout << "\nThe largest distance is: " << distances[numDistances - 1] << endl;

    return 0;
}

