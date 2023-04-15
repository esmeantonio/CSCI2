/*
 Programmer: Esmeralda Antonio
 Program Name: Week7_BalancedParenthesis.cpp
 Date: 03/30/23
 Version: 1.7
 Description: Takes in a string of characters from user and stores each
 character into a stack. The program then loops through stack in the
 display method to determine if the string has balanced parenthesis or not.
 */

#include <iostream>
#include <string>
using namespace std;
class DynStack
{
private:
    struct Node
    {
        char value;
        Node *next;
    };
    Node *top;
public:
    DynStack()
    {
        top = NULL;
    }
    void push(char);
    bool isEmpty();
    void display();
    void clear(char &);
};
//Adds a character to stack
void DynStack::push(char c)
{
    Node *n;
    n = new Node;
    n->value = c;
    n->next = NULL;
    if (isEmpty()) {
        top = n;
    } else {
        n->next = top;
        top = n;
    }
}
//Checks if stack is empty
bool DynStack::isEmpty()
{
    if (top == NULL) {
        return true;
    } else {
        return false;
    }
}
//Displays whether a stack is balanced or not
void DynStack::display()
{
    Node *curr;
    curr = top;
    int leftCounter = 0;
    int rightCounter = 0;
    while (curr != NULL)
    {
        if (curr->value == '(') {
         leftCounter++;
         curr = curr->next;
         } else if (curr->value == ')') {
         rightCounter++;
         curr = curr->next;
         } else {
         curr = curr->next;
         }
         }
         if (rightCounter == leftCounter) {
         cout << " is balanced." << endl;
         } else {
         cout << "  is unbalanced." << endl;
    }
}
//Clears the stack for next user input using pop()
void DynStack::clear(char &x) {
    Node *temp;
    while(!isEmpty()) {
        x = top->value;
        temp = top->next;
        delete top;
        top = temp;
    }
}

int main() {
    DynStack st1;
    int userChoice;
    string phrase;
    char y;
    do {
        cout << "Menu: " << endl;
        cout << "1) Check if a string of characters is balanced \n2) Exit" << endl;
        cin >> userChoice;
        switch (userChoice)
        {
            case 1:
                cout << "Enter string: " << endl;
                cin >> phrase;
                //loops through string to add each character to stack
                for (int i = 0; i < phrase.length(); i++){
                    st1.push(phrase[i]);
                }
                cout << phrase;
                st1.display();
                st1.clear(y);
                break;
            case 2:
                exit(1);
                break;
            default: cout << "Invalid selection." << endl;
        }
    } while (true);
    return 0;
}
