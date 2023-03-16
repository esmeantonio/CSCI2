/*
 Program name: rectangle.cpp
 Programmer: Esmeralda Antonio
 Date: 02/11/2023
 Version: 1.0
 Description: We get radius of a circle from user.
 Then we calculate the area of the circle.
 Lastly we display.
 */

#include <iostream>
#include <math.h>
using namespace std;
const double pi = 3.14159265358979323846;

class Circle
{
private:
    double radius;
public:
    //Default Constructor
    Circle()
    {
        radius = 0.0;
    }
    //Constructor with one arguments
    Circle(double r)
    {
        radius = r;
    }
    //Accessor
    double getRadius()
    {
        return radius;
    }
    //Mutator
    void setRadius(double r)
    {
        radius = r;
        while (radius < 0.0) {
            cout << "Invalid input. No negative values." << endl;
            cin >> radius;
        }
    }
    //Calculate area of circle
    double getArea() const
    {
        return pi*pow(radius, 2);
    }
    //Output
    void display()
    {
        cout << "the area of the circle is " << getArea() << endl;
    }
}; //end class


int main()
{
    
    Circle circ1;  //using default constructor
    circ1.display();
    
    Circle circ2(3.5);
    circ2.display();
    
    cout << "The radius of circ2 is: " << circ2.getRadius() << endl;
    
    circ2.setRadius(-4.5);
    circ2.display();
    
    return 0;
}
