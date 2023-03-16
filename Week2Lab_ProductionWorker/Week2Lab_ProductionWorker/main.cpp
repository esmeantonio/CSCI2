/*
 Program name: Week2Lab_ProductionWorker.cpp
 Programmer: Esmeralda Antonio
 Date: 02/18/2023
 Version: 1.0
 Description:The ProductionWorker class inherits from
 the Employee class. The Employee class obtains the employee's
 name, number, and hire date from the user and the ProductionWorker
 class obtains the shift and hourly pay rate from the user.
 */

#include <iostream>
using namespace std;

class Employee
{
private:
    string employName;
    int employNum;
    string hireDate;
public:
    //Default constructor
    Employee()
    {
        employName = " ";
        employNum = 0;
        hireDate = "00/00/00";
    }
    
    //Constructor with 3 arguments
    Employee(string n, int nuM, string d)
    {
        employName = n;
        employNum = nuM;
        hireDate = d;
    }
    
    //Getter/accessor funcs.
    string getName()
    {
        return employName;
    }
    int getNum()
    {
        return employNum;
    }
    string getDate()
    {
        return hireDate;
    }
    
    //Setter/mutator funcs.
    void setName(string name)
    {
        employName = name;
    }
    void setNum(int num)
    {
        employNum = num;
    }
    void setDate(string d)
    {
        hireDate = d;
    }
};

//ProductionWorker inherits from Employee class
class ProductionWorker : public Employee
{
private:
    int shift;
    double payRate;
public:
    //Default constructor
    ProductionWorker()
    {
        shift = 0;
        payRate = 0.0;
        Employee();
    }
    
    //Constructor with 5 arguments, we will invoke parent constructor
    ProductionWorker(string e, int n, string h, int s, double p) : Employee(e, n, h)
    {
        shift = s;
        payRate = p;
    }
    
    //Getter/accessor funcs.
    double getShift()
    {
        return shift;
    }
    double getRate()
    {
        return payRate;
    }
    
    //Setter/accessor funcs.
    void setShift(int s)
    {
        shift = s;
        while (shift != 0 || shift != 1) {
            cout << "Invalid. Shift must be either 1 (day) or 0 (night). Try again." << endl;
            cin >> shift;
        }
    }
    void setRate(double p)
    {
        payRate = p;
        while (p < 0.0) {
            cout << "Invalid. Pay rate must be a positive value. Try again." << endl;
            cin >> payRate;
        }
    }
};

int main() {
    ProductionWorker worker1;
    ProductionWorker worker2("Esme", 5, "02/18/23", 1, 15.50);
    cout << "Worker 1 is named " << worker1.getName() << endl;
    cout << "The hire date is " << worker1.getDate() << " and the employee number is " << worker1.getNum() << endl;
    cout << "Worker 2 is named " << worker2.getName() << endl;
    cout << "Your shift is " << worker2.getShift() << endl;
    cout << "Your hourly pay rate is $" << worker2.getRate() << endl;
    cout << "Your hire date is " << worker2.getDate() << endl;
    return 0;
}
