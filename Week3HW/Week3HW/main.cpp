/*
 Programmer: Esmeralda Antonio
 Program Name: Week3HW_NumDays.cpp
 Date: 02/27/2023 (Last Worked on: 03/03/23)
 Version: 1.9
 Description: The program below overloads the addition, subtraction,
 prefix and postfix increment operators, prefix and postfix decrement
 operators, and they were created as friends of the class NumDays.
 The class NumDays takes in a number of work hours and converts it
 to a number of days where 8 hours is equivalent to one day. The
 class is able to store and retrieve the hours and days as well.
 */

#include <iostream>
using namespace std;

class NumDays
{
private:
    double hours;
    double days;
public:
    //default constructor
    NumDays()
    {
        hours = 0.0;
        days = 0.0;
    }
    NumDays(double h)
    {
        hours = h;
        days = h/8.0;
    }
    //Getter(accessor) functions
    double getHours()
    {return hours;}
    double getDays()
    {return days;}
    //Setter(mutator) function
    void setHours(double hrs)
    {
        hours = hrs;
        days = hrs/8.0;
    }
    //Operator overloading function prototypes
    friend double operator + (NumDays d1, NumDays d2);
    friend double operator - (NumDays d1, NumDays d2);
    //++ (prefix and postfix)
    friend NumDays operator ++(NumDays &d1);
    friend NumDays operator ++(NumDays &d1, int d);
    //-- (prefix and postfix)
    friend NumDays operator --(NumDays &d1);
    friend NumDays operator --(NumDays &d1, int d);
};

//Addition Operator
double operator +(NumDays d1, NumDays d2)
{
    return d1.hours + d2.hours;
}
//Subtraction Operator
double operator -(NumDays d1, NumDays d2)
{
    return d1.hours - d2.hours;
}
//Prefix Increment
NumDays operator ++(NumDays &d1)
{
    ++d1.hours;
    d1.setHours(d1.getHours());
    return d1.getHours();
}
//Postfix Increment
NumDays operator ++(NumDays &d1, int d)
{
    d = d1.hours;
    d1.setHours(++d);
    return d;
}
//Prefix Decrement
NumDays operator --(NumDays &d1)
{
    d1.setHours(--d1.hours);
    return d1.getHours();
    
}
//Postfix Decrement
NumDays operator --(NumDays &d1, int d)
{
    d = d1.hours;
    d1.setHours(--d);
    return d;
}
int main() {
    NumDays n1(12);
    cout << n1.getDays() << endl;
    NumDays n2(18);
    cout << "Before prefix increment: " << endl;
    cout << "Hours: " << n2.getHours() << endl;
    cout << "Days: " << n2.getDays() << endl;
    ++n2;
    cout << "After prefix increment: " << endl;
    cout << "Hours: " << n2.getHours() << endl;
    cout << "Days: " << n2.getDays() << endl;
    
    cout << "Before prefix decrement: " << endl;
    cout << "Hours: " << n2.getHours() << endl;
    cout << "Days: " << n2.getDays() << endl;
    --n2;
    cout << "After prefix decrement: " << endl;
    cout << "Hours: " << n2.getHours() << endl;
    cout << "Days: " << n2.getDays() << endl;
    
    cout << "Before postfix increment: " << endl;
    cout << "Hours: " << n2.getHours() << endl;
    cout << "Days: " << n2.getDays() << endl;
    n2++;
    cout << "After postfix increment: " << endl;
    cout << "Hours: " << n2.getHours() << endl;
    cout << "Days: " << n2.getDays() << endl;
    
    cout << "Before postfix decrement: " << endl;
    cout << "Hours: " << n2.getHours() << endl;
    cout << "Days: " << n2.getDays() << endl;
    n2--;
    cout << "After postfix decrement: " << endl;
    cout << "Hours: " << n2.getHours() << endl;
    cout << "Days: " << n2.getDays() << endl;
    return 0;
}
