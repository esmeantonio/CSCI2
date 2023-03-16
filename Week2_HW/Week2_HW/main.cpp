/*
 Program name: .cpp
 Programmer: Esmeralda Antonio
 Date: 02/22/2023
 Version: 1.4
 Description: I created an abstract class Student that takes in the name, student id #, and expected graduation
 date from a user. It also has 2 pure virtual functions called greetings and info. I created the class Undergraduate
 which is derived from the class Student and it takes in the major, school, and degree type from the user. The
 Undergraduate class also implements the virtual functions greetings and info. The first is used to print out a
 greeting which presents the user as an undergrad while the latter indicates that what is printed below is the
 undergrad's information.
 */

#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string studentName;
    int studentID;
    string gradDate; //expected graduation date
public:
    //Pure virtual functions
    virtual void greetings() = 0;
    virtual void info() = 0;
    //Default constructor
    Student()
    {
        studentName = "BLANK";
        studentID = 0000;
        gradDate = "0/00/00";
    }
    //Constructor with 3 arguments
    Student(string name, int iD, string date)
    {
        studentName = name;
        studentID = iD;
        gradDate = date;
    }
    //Getter(accessor) functions
    string getName()
    {
        return studentName;
    }
    int getID()
    {
        return studentID;
    }
    string getDate()
    {
        return gradDate;
    }
    //Setter(mutator) functions
    void setName(string n)
    {
        studentName = n;
    }
    void setID(int i)
    {
        studentID = i;
    }
    void setDate(string d)
    {
        gradDate = d;
    }
};

class Undergraduate: public Student
{
private:
    string major;
    string school; //college/university name
    string degreeType; //Bachelor's, Master's, Doctorate's
public:
    void greetings() { cout << "Hello, I am an undergraduate student." << endl;}
    void info() { cout << "Displayed below is my information." << endl;}
    //Default constructor
    Undergraduate()
    {
        major = "BLANK";
        school = "BLANK";
        degreeType = "BLANK";
    }
    //Constructor with 6 arguments
    //We invoke parent constructor as well
    Undergraduate(string n, int i, string d, string m, string s, string t): Student(n, i, d)
    {
        major = m;
        school = s;
        degreeType = t;
    }
    //Getter(accessor) functions
    string getMajor()
    {
        return major;
    }
    string getSchool()
    {
        return school;
    }
    string getDegree()
    {
        return degreeType;
    }
    //Setter(mutator) functions
    void setMajor(string studentMajor)
    {
        major = studentMajor;
    }
    void setSchool(string schoolName)
    {
        school = schoolName;
    }
    void setDegree(string degree)
    {
        degreeType = degree;
    }
};

int main() {
    Undergraduate me;
    me.greetings();
    me.info();
    cout << me.getName() << endl;
    cout << endl;
    Undergraduate me2("Esmeralda A.", 12345, "06/2024",
                      "EECS", "El Camino College", "Bachelor's");
    me2.greetings();
    cout << "My name is " << me2.getName() << " and my expected graduation date is " << me2.getDate() << "."  << endl;
    me2.info();
    cout << "I currently attend " << me2.getSchool() << " and my ID # is " << me2.getID() << "." << endl;
    cout << "I will be graduating with a " << me2.getDegree() << " in the major of " << me2.getMajor() << "." << endl;
    return 0;
}
