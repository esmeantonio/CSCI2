/*
 Programmer: Esmeralda Antonio
 Program Name: Week3Lab.cpp
 Date: 02/25/2023
 Version: 1.8
 Description: The program below overloads the arithmetic operators for
 division and multiplication as well as the insertion, extraction, and
 comparison operators and they were creates as friends of the class
 Fraction. The purpose is to be able to ask the user for two fractions
 and then multiply, divide, and/or compare them.
 */

#include <iostream>
using namespace std;

class Fraction
{
private:
    double num;
    double denom;
public:
    //default constructor
    Fraction()
    {
        num = 0.0;
        denom = 1.0;
    }
    Fraction(double n, double d)
    {
        num = n;
        denom = d;
    }
    //Getter(accessor) functions
    double getNum()
    {return num;}
    double getDenom()
    {return denom;}
    //Setter(mutator) functions
    void setNum(double numerator)
    {num = numerator;}
    void setDenom(double denominator)
    {denom = denominator;}
    
    //function prototypes for operator overloading
    friend Fraction operator * (Fraction f1, Fraction f2);
    friend Fraction operator / (Fraction f1, Fraction f2);
    friend ostream & operator << (ostream &o, Fraction &f);
    friend istream & operator >> (istream &i, Fraction &f);
    friend bool operator < (Fraction &f1, Fraction &f2);
    friend bool operator > (Fraction &f1, Fraction &f2);
    friend bool operator == (Fraction &f1, Fraction &f2);
};

// * function overloading
Fraction operator *(Fraction f1, Fraction f2)
{
    Fraction temp;
    temp.num = f1.num * f2.num;
    temp.denom = f1.denom * f2.denom;
    return temp;
}
// / function overloading
Fraction operator /(Fraction f1, Fraction f2)
{
    Fraction temp;
    temp.num = f1.num * f2.denom;
    temp.denom = f1.denom * f2.num;
    return temp;
}
// insertion function overloading
ostream & operator << (ostream &o, Fraction &f)
{
    o << f.getNum() << "/" << f.getDenom();
    return o;
}
// extraction function overloading
istream & operator >> (istream &i, Fraction &f)
{
    char slash = '/';
    i >> f.num >> slash >> f.denom;
    return i;
}
// < function overloading
bool operator < (Fraction &f1, Fraction &f2)
{
    double temp1;
    double temp2;
    temp1 = f1.num / f1.denom;
    temp2 = f2.num / f2.denom;
    if (temp1 < temp2)
    {
        return true;
        
    } else {
        return false;
    }
}
// > function overloading
bool operator > (Fraction &f1, Fraction &f2)
{
    double temp1;
    double temp2;
    temp1 = f1.num / f1.denom;
    temp2 = f2.num / f2.denom;
    if (temp1 > temp2)
    {
        return true;
        
    } else {
        return false;
    }
}
// == function overloading
bool operator == (Fraction &f1, Fraction &f2)
{
    double temp1;
    double temp2;
    temp1 = f1.num / f1.denom;
    temp2 = f2.num / f2.denom;
    if (temp1 == temp2)
    {
        return true;
    } else {
        return false;
    }
}

int main() {
    Fraction fr1(3.0, 5.0);
    Fraction fr2(2.0, 7.0);
    Fraction product;
    product = fr1 * fr2;
    cout << "The product is: ";
    cout << product;
    cout << endl;
    
    Fraction fr3;
    cout <<"Enter the first fraction: ";
    cin >>fr3;
    Fraction fr4;
    cout << "Enter the second fraction: ";
    cin >>fr4;
    Fraction answer;
    answer = fr3 / fr4;
    cout << "The answer to " << fr3 << " divided by " << fr4 << " is " << answer << endl;
    
    if (fr3<fr4)
    {
        cout << fr3 << " is less than " << fr4 << endl;
    } else if (fr3>fr4) {
        cout << fr3 << " is greater than " << fr4 << endl;
    } else {
        cout << fr3 << " is equal to " << fr4 << endl;
    }
    return 0;
}
