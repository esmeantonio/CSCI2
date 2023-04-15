/*
 Programmer: Esmeralda Antonio
 Program Name: Week6Lab.cpp
 Date: March 18, 2023
 Version: 1.5
 Description: Created a class StrStack which is a static stack that stores
 machine names of car parts for a manufacturing company and allows the user
 to add machine names, remove a machine, display the top machine (machine
 last added), display all machines, and exit(or quit) the tracking system.
 */

#include <iostream>
using namespace std;

class StrStack
{
private:
    string *stackArray;
    int size;   //size of stack
    int top;    //array index/top of stack
public:
    //prototypes
    StrStack(int );
    void push(string);
    string pop(string &);
    string peek() const;
    void display();
    bool isEmpty() const;
    bool isFull() const;
};
//Constructor
StrStack::StrStack(int s)
{
    stackArray = new string[s];
    size = s;
    top = -1;   //signifies stack is empty
}
//Push Func
void StrStack::push(string m)
{
    if (isFull())
    {
        cout << "The stack is full." << endl;
    } else {
        stackArray[++top] = m;
    }
}
//Pop Func
string StrStack::pop(string &m)
{
    if(isEmpty())
    {
        cout << "The stack is empty. Nothing to be removed" << endl;
        return " ";
    } else {
        m = stackArray[top--];
        return m;
    }
}
//Peek Func
string StrStack::peek() const
{
    if (isEmpty())
    {
        cout << "Stack is empty." << endl;
        return " ";
    } else {return stackArray[top];}
}
//Display Func
void StrStack::display()
{
    int t = top;
    while (t >= 0)
    {
        cout << stackArray[t] << " " << endl;
        t--;
    }
}
//isEmpty Func
bool StrStack::isEmpty() const
{
    if (top == -1)
    {return true;}
    else {return false;}
}
//isFull Func
bool StrStack::isFull() const
{
    if (top == size-1)
    {return true;}
    else {return false;}
}



int main() {
    // insert code here...
    StrStack machineStack(10);
    do {
        int userChoice;
        cout << endl;
        cout << "Welcome to the machine tracking system!" << endl;
        cout << "Please select an option:" << endl;
        cout << "1. Add a machine" << endl;
        cout << "2. Remove a machine" << endl;
        cout << "3. Display the top machine" << endl;
        cout << "4. Display all machines" << endl;
        cout << "5. Quit" << endl;
        cin >> userChoice;
        if (userChoice == 1) {
            if (machineStack.isFull()) {
                cout << "The stack is full." << endl;
            } else {
                string machine;
                cout << "Enter the machine's name: " << endl;
                cin >> machine;
                machineStack.push(machine);
            }
        } else if (userChoice == 2) {
            string x;
            if (machineStack.isEmpty()) {
                cout << "The stack is empty. Nothing to be removed. " << endl;
            } else {
                cout << machineStack.pop(x) << " popped from stack." << endl;
            }
        } else if (userChoice == 3) {
            cout << "The top machine is " << machineStack.peek() << endl;
        } else if (userChoice == 4) {
            machineStack.display();
        } else if (userChoice == 5) {
            cout << "Thank you for using the system. Goodbye!" << endl;
            exit(1);
        } else {
            cout << "Invalid choice." << endl;
        }
    } while (true);
    return 0;
}
