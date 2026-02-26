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

bool GetAnswer()
{
    char answer;
    cout << "\n\n" << "Solve another equation? (y = yes): ";
    while (!(cin >> answer))
    {
        cout << "Invalid Input. Please try again." << "\n";
        cout << "Solve another equation? (y = yes): ";
        
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    if (answer == 'y')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Two_Real_Solutions(double a, double b, double c, double d)
{
    double answer1 = ( -b + sqrt(d) ) / (2 * a);
    double answer2 = ( -b - sqrt(d) ) / (2 * a);
    cout << "\nTwo solutions found." << "\n";
    cout << "x = " << answer1 << "\n";
    cout << "x = " << answer2;
}

void One_Real_Solution(double a, double b)
{
    double answer = (-b) / (2 * a);
    cout << "\nOne solution found." << "\n";
    cout << "x = " << answer;
}

void Linear_Solution(double b, double c)
{
    double x = (-c) / b;
    cout << "\nLinear Equation Detected.\n";
    cout << "x = " << x;
}

void Complex_Solutions(double a, double b, double c, double d)
{
    double real = (-b) / (2 * a);
    double imaginary = sqrt(-d) / (2 * a);
    cout << "\nTwo complex solutions found." << "\n";
    cout << "x = " << real << " + " << imaginary << "i" << "\n";
    cout << "x = " << real << " - " << imaginary << "i";
}

int main()
{
    cout << "Quadratic Formula Calculator"  << "\n\n";
    double A, B, C;
    
    bool repeat = false;
    
    do
    {
        A = GetInput('A');
        B = GetInput('B');
        C = GetInput('C');
        
        if (A == 0)
        {
            if (B == 0)
            {
                if (C == 0)
                {
                    cout << "\nInfinite solutions.\n";
                }
                else
                {
                    cout << "\nNo solution.\n";
                }
            }
            else
            {
                /*
                double x = (-C) / B;
                cout << "Linear Equation Detected.\n";
                cout << "x = " << x;
                */
                
                Linear_Solution(B, C);
            }
        }
        else
        {
            double discriminant = (B * B) - (4 * A * C);
            
            if (discriminant > 0)
            {
                /*
                double answer1 = ( -B + sqrt(discriminant) ) / (2 * A);
                double answer2 = ( -B - sqrt(discriminant) ) / (2 * A);
                cout << "Two solutions found." << "\n";
                cout << "x = " << answer1 << "\n";
                cout << "x = " << answer2;
                */
                
                Two_Real_Solutions(A, B, C, discriminant);
            }
            else if (discriminant == 0)
            {
                /*
                double answer = (-B) / (2 * A);
                cout << "One solution found." << "\n";
                cout << "x = " << answer;
                */
                
                One_Real_Solution(A, B);
            }
            else
            {
                /* cout << "No real solutions."; */
                
                /*
                double real = (-B) / (2 * A);
                double imaginary = sqrt(-discriminant) / (2 * A);
                cout << "Two complex solutions found." << "\n";
                cout << "x = " << real << " + " << imaginary << "i" << "\n";
                cout << "x = " << real << " - " << imaginary << "i";
                */
                
                Complex_Solutions(A, B, C, discriminant);
            }
        }
        repeat = GetAnswer();
    }
    while (repeat);
    
    return 0;
}
