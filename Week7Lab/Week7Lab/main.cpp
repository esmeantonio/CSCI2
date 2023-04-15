/*
 Programmer: Esmeralda Antonio
 Program Name: Week7Lab.cpp
 Date: 03/25/23
 Version: 1.5
 Description: The inventory class stores and retrieves the serial number, manufactured date,
 and lot number of a part. The DynStack class stores a stack of inventory objects. In the
 driver for DynStack, there is a program that gives the user the option to add or remove a
 part from the DynStack and takes in the information of the part. When the user has finished
 or would like to quit, the information for each part in the stack is printed out for
 the user.
 */

#include <iostream>
#include <string>
using namespace std;
class Inventory
{
private:
    int serialNumber;
    string manufactDate;
    int LotNum;
public:
    //default constructor
    Inventory() {
        serialNumber = 0;
        manufactDate = " ";
        LotNum = 0;
    }
    //constructor with 3 arguments
    Inventory(int s, string d, int l) {
        serialNumber = s;
        manufactDate = d;
        LotNum = l;
    }
    //Getter (accessor) funcs
    int getSerialNum() {
        return serialNumber;
    }
    string getDate() {
        return manufactDate;
    }
    int getLotNum() {
        return LotNum;
    }
    //Setter (mutator) funcs
    void setSerialNum(int sn) {
        serialNumber = sn;
    }
    void setDate(string md) {
        manufactDate = md;
    }
    void setLot(int ln) {
        LotNum = ln;
    }
};

class DynStack
{
private:
    struct Node
    {
        Inventory part;
        Node *next;
    };
    Node *top;
public:
    DynStack()
    {
        top = NULL;
    }
    void push(Inventory);
    void pop(Inventory &);
    bool isEmpty();
    void display();
};

void DynStack::pop(Inventory &i)
{
    Node *temp;
    if (isEmpty()) {
        cout << "The stack is empty." << endl;
    } else {
        i = top->part;
        temp = top->next;
        cout << "The part with serial number: " << i.getSerialNum() << ", manufactDate: " << i.getDate() << ", and LotNum: " << i.getLotNum() << " has been removed." <<endl;
        delete top;
        top = temp;
    }
}

void DynStack::push(Inventory i)
{
    Node *n;
    n = new Node;
    n->part = i;
    n->next = NULL;
    if (isEmpty()) {
        top = n;
    } else {
        n->next = top;
        top = n;
    }
}

bool DynStack::isEmpty()
{
    if (top == NULL) {
        return true;
    } else {
        return false;
    }
}

void DynStack::display()
{
    Node *curr;
    curr = top;
    Inventory i;
    int counter = 1;
    while (curr != NULL)
    {
        i = curr->part;
        cout << "Part " << counter << "'s information: " << endl;
        cout << "Serial #: " << i.getSerialNum() << endl;
        cout << "Manufactured Date: " << i.getDate() << endl;
        cout << "Lot #: " << i.getLotNum() << endl;
        cout << endl;
        curr = curr->next;
        counter++;
    }
}


int main() {
    // insert code here...
    Inventory *partA = new Inventory;
    DynStack st1;
    int userChoice;
    int sNum;
    string mDate;
    int lNum;
    Inventory x;
    do {
        cout << "Inventory Menu: " << endl;
        cout << "1) Add a part \n2) Take/Remove a part \n3) Quit" << endl;
        cin >> userChoice;
        switch (userChoice)
        {
            case 1:
                cout << "Enter part's serial #: " << endl;
                cin >> sNum;
                cin.ignore();
                cout << "Enter manufactured date: " << endl;
                cin >> mDate;
                cout << "Enter lot number: " << endl;
                cin >> lNum;
                partA->setSerialNum(sNum);
                partA->setDate(mDate);
                partA->setLot(lNum);
                st1.push(*partA);
                break;
            case 2:
                st1.pop(x);
                break;
            case 3:
                st1.display();
                exit(1);
                //break;
            default: cout << "Invalid selection.";
        }
    } while (true);
    
    return 0;
}
