/*
 Program name: rectangle.cpp
 Programmer: Esmeralda Antonio
 Date: 02/11/2023
 Version: 1.0
 Description: We get width and length from user.
 Then we calculate the area of the rectangle.
 Lastly we display.
 */

#include <iostream>
using namespace std;

class Rectangle
{
private:
    double width;
    double length;
public:
    //Default Constructor
    Rectangle()
    {
        width = 0.0;
        length = 0.0;
    }
    //Constructor with two arguments
    Rectangle(double w, double len)
    {
        width = w;
        length = len;
    }
    //Accessor
    double getWidth()
    {
        return width;
    }
    //Mutator
    void setWidth(double w)
    {
        width = w;
    }
    //Accessor
    double getLength()
    {
        return length;
    }
    //Mutator
    void setLength(double l)
    {
        length = l;
    }
    //Calculate area of rectangle
    double getArea() const
    {
        return width*length;
    }
    //Output
    void display()
    {
        cout << "the area is " << getArea() << endl;
    }
}; //end class


int main()
{
    
    Rectangle rect1;  //using default constructor
    rect1.display();
    
    Rectangle rect2(2.7, 7.8);
    rect2.display();
    
    cout << "The width of rect2 is: " << rect2.getWidth() << endl;
    
    rect2.setLength(12.9);
    rect2.display();
    
    return 0;
}
