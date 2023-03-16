/*
 Program name: Inheritance_RectangleAndBox_ClassExample.cpp
 Programmer: Esmeralda Antonio
 Date: 02/18/2023
 Version: 1.0
 Description: We created a class Rectangle and a class Box which inherits from
 the Rectangle class. The class Rectangle obtains the length and width from the
 user to calculate the area while the Box class obtains the height to calculate
 the volume.
 */

#include <iostream>
using namespace std;


class Rectangle
{
private:
    double length;
    double width;
    
public:
    //Default constructor
    Rectangle()
    {
        width = 0.0;
        length = 0.0;
    }
    
    //Constructor with two arguments
    Rectangle(double len, double wid)
    {
        length = len;
        width = wid;
    }
    
    //Getter or Accessor Funcs.
    double getWidth()
    {
        return width;
    }
    double getLength()
    {
        return length;
    }
    
    //Setter or Mutator Funcs.
    void setWidth(double w)
    {
        width = w;
    }
    void setLength(double l)
    {
        length = l;
    }
    
    //Calculates area
    double getArea() const
    {
        return width*length;
    }
    void display()
    {
        cout << "The area is " << getArea() << endl;
    }
};

//Inheritance class -> Box inherits from Rectangle class
class Box : public Rectangle
{
private:
    double height;
public:
    Box() //Default constructor
    {
        height = 0.0;
        Rectangle();
    }
    //Constructor with 3 arguments
    Box(double l, double w, double h) : Rectangle(l, w)  //We invoke the parent constructor here
    {
        height = h;
    }
    //Getter or Accessor Func.
    double getHeight() {
        return height;
    }
    double volume()
    {
        return getArea()*height;
    }
    void displayVolume()
    {
        cout << "The volume of Box is " << volume() << endl;
    }
};


int main() {
    
    Box b1;
    Box b2(8, 10, 3);
    b1.displayVolume();
    b2.displayVolume();
    cout << "The width value is " << b2.getWidth() << endl;
    cout << "The height value is " << b2.getHeight() << endl;
    Rectangle rect1;
    Rectangle rect2(2.4, 5.6);
    rect1.display();
    rect2.display();
    cout << "The width value is " << rect2.getWidth() << endl;
    
    return 0;
}
