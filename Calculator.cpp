#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

double GetInput(char InputName)
{
    double UserInput = 0.0;
    cout << "Enter the value for " << InputName << ": ";
    while (!(cin >> UserInput))
    {
        cout << "Invalid Input. Please try again." << "\n";
        cout << "Enter the value for " << InputName << ": ";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return UserInput;
}

int main()
{
  cout << "Quadratic Formula Calculator"  << "\n";
  double A, B, C;
  A = GetInput('A');
  B = GetInput('B');
  C = GetInput('C');

  if (A == 0)
  {
    if (B == 0)
    {
        if (C == 0)
        {
            cout << "Infinite solutions.\n";
        }
        else
        {
            cout << "No solution.\n";
        }
    }
    else
    {
        double x = (-C) / B;
        cout << "Linear Equation Detected.\n";
        cout << "Solution: " << x;
    }
  }
  else
  {
    double discriminant = (B * B) - (4 * A * C);

    if (discriminant > 0)
    {
        double answer1 = ( -B + sqrt(discriminant) ) / (2 * A);
        double answer2 = ( -B - sqrt(discriminant) ) / (2 * A);
        cout << "Two solutions found." << "\n";
        cout << "Solution 1: " << answer1 << "\n";
        cout << "Solution 2: " << answer2;
    }
    else if (discriminant == 0)
    {
        double answer = (-B) / (2 * A);
        cout << "One solution found." << "\n";
        cout << "Answer: " << answer;
    }
    else
    {
        cout << "No real solutions.";
    }
  }
  
  return 0;
}