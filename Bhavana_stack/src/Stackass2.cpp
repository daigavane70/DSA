#include "Stackass2.h"

#include <iostream>
using namespace std;
template <class T>
Stack_ass2<T>::Stack_ass2()
{ // default constructor of Stack

    top = NULL; //top initialized to null
}
// Method to check whether stack is empty
template <class T>
Node<T>* Stack_ass2<T>::getTop(){
	return this->top;
}

template <class T>
bool Stack_ass2<T>::isEmpty()
{
    if (top == NULL) // if top pointing to null which means no element is in the stack
    {
        return true;
    }
    else
    { // if top not pointing to null
        return false;
    }
}
// Method to push the element in the stack
template <class T>
void Stack_ass2<T>::push(T x)
{ // data of the linked list of type T

    // creation of a new node in the stack
    Node<T> *newnode = new Node<T>(); // memory allocated to newnode pointer in the heap
    newnode->data = x;
    newnode->next = top;
    top = newnode; //top pointing to new node
}
// Method to pop element in stack
template <class T>
T Stack_ass2<T>::pop()
{

    T p = top->data; // p storing the data of the node at the top
    top = top->next; // top now pointing to the next node
    return p;        // return the p- data value at the earlier top
}
// Display method
template <class T>
void Stack_ass2<T>::display()
{
    Node<T> *ptr;                           // ptr pointer declared
    ptr = top;                              // top stored in ptr
    cout << "Stack elements are: " << endl; // To display all the elements in the stack
    while (ptr != NULL)
    { // run the loop until the ptr points to null
        cout << "|  " << ptr->data << "  |" << endl;
        ptr = ptr->next;
    }
}
// Method to peep the data value in the Stack
template <class T>
T Stack_ass2<T>::peep()
{
    if (!isEmpty())
    { // if not empty

        return top->data; // top returned
    }
    else
    {
        cout << "Stack is EMPTY!" << endl;
        return '\0';
    }
}
