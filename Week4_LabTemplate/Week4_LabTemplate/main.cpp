/*
 Programmer: Esmeralda Antonio
 Program Name: Week4Lab.cpp
 Date: March 04, 2023
 Version: 1.2
 Description: The LinkedList class holds a series of integers and has the member functions AddNode
 which takes in an integer and adds it as a node at the beginning of the list, AddAppend which
 takes in an integer and adds it as a node at the end of the list, DeleteNode which takes in an
 integer and removes that value (if found) from the list, and finally the display function
 which displays all integers in the list and displays the number of nodes in that list.
 */

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node (int value)
    {
        data = value;
        next = NULL;
    }
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
    
    //AddNode (at beginning of list)
    void AddNode(int num)
    {
        Node *n = new Node;
        n->data = num;
        if (head != NULL)
        {
            n->next = head;
            head = n;
        } else {
            head = n;
            n->next = NULL;
        }
    }
    //AddAppendNode (at end of list)
    void AddAppend(int m)
    {
        Node *n = new Node;
        Node *curr;
        n->data = m;
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
    //DeleteNode function
    void DeleteNode(int m)
    {
        Node *dptr = nullptr;
        Node *temp = head;
        Node *curr;
        curr = head;
        while (curr != NULL && curr->data != m)
        {
            temp = curr;
            curr = curr->next;
        }
        if (curr == NULL)
        {
            cout << m << " is not in the list" << endl;
            delete  dptr;
        } else {
            dptr = curr;
            curr = curr->next;
            temp->next = curr;
            if (dptr == head)
            {
                head = head->next;
                temp = NULL;
            }
            delete dptr;
            cout << "The value " << m << " was deleted." << endl;
        }
    }
    //Display func --> also count # of nodes
    void display()
    {
        Node *curr;
        curr = head;
        int counter = 0;
        while (curr != NULL)
        {
            counter++;
            cout << curr->data << endl;
            curr = curr->next;
        }
        cout << "Total # of nodes: " << counter << endl;
    }
};


//Driver for LinkedList class
int main() {
    LinkedList list1;
    cout << "Default list: " << endl;
    list1.display();
    list1.AddNode(7);
    list1.AddNode(9);
    list1.AddNode(5);
    list1.AddNode(3);
    list1.AddNode(1);
    cout << "Updated list: " << endl;
    list1.display();
    list1.AddAppend(12);
    list1.DeleteNode(1);
    cout << "Final list: " << endl;
    list1.display();
    return 0;
}
