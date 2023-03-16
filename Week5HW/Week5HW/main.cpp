/*
 Programmer: Esmeralda Antonio
 Program Name: Week5HW.cpp
 Date: March 11, 2023
 Version: 1.0
 Description: Created a class Node with two instance variables: data and next.
 Created a class LinkedList with an instance variable head of type Node and with
 3 methods: add which takes in a value and adds it to a linked list as a node at
 the end, getSize which returns the size of the list, and search which takes in a
 value and looks for that value in the list and returns true if it is found and
 false otherwise.
 */

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    //Constructor with 1 argument
    Node(int value)
    {
        data = value;
        next = NULL;
    }
    //Default Constructor
    Node()
    {
        data = NULL;
        next = NULL;
    }
};

class LinkedList
{
private:
    Node *head;
public:
    //Default Constructor
    LinkedList()
    {
        head = NULL;
    }
    //adds a new node with given data at end of linked list
    void add(int data)
    {
        Node *n = new Node;
        n->data = data;
        Node *curr;
        if (head != NULL)
        {
            curr = head;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = n;
        } else {
            head = n;
        }
    }
    //returns the size of the linked list (# of nodes)
    int getSize()
    {
        int counter = 0;
        Node *curr;
        curr = head;
        while (curr != NULL)
        {
            counter++;
            curr = curr->next;
        }
        return counter;
    }
    //returns true if list contains a node with given data else returns false
    bool search(int d)
    {
        int dCount = 0; //keeps track of amount of times d is found in list
        Node *curr;
        curr = head;
        while (curr != NULL)
        {
            if (curr->data == d) {
                dCount++;
                curr = curr->next;
            }
            curr = curr->next;
        }
        if (dCount > 0)
        {
            return true;
        } else {
            return false;
        }
    }
    
};
int main() {
    LinkedList list1;
    list1.add(5);
    list1.add(7);
    list1.add(3);
    list1.add(15);
    list1.add(18);
    list1.add(17);
    cout << "LinkedList size: " << list1.getSize() << endl;
    cout << "Is x found in list: (1=true, 0=false) " << endl;
    cout << "x = 3? :  " << list1.search(3) << endl;
    cout << "x = 21? : " << list1.search(21) << endl;

    return 0;
}
