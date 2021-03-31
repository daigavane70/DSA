#ifndef STACKASS2_H_
#define STACKASS2_H_

	template <typename T> // use  of template
	//structure defined
	struct Node
	{
	    T data;        // data in the linked list of T type
	    Node<T> *next; // next in the linked list to store address of the next node
	};
	template <class T>
	class Stack_ass2
	{
	    Node<T> *top; // top pointer to keep track of the top element in the stack
	public:
	    // declaration of functions
	    Node<T>* getTop();
	    Stack_ass2(); // default constructor
	    bool isFull();
	    void push(T x);
	    T pop();
	    void display();
	    bool isEmpty();
	    T peep();
	};
#endif /* STACKASS2_H_ */
