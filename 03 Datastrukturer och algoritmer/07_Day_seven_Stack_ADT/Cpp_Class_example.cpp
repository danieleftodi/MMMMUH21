#include <iostream>
using namespace std;

class Stack {
private:
	int size;
	int top;
	int* S;
public:
	Stack(int size);
	~Stack();
	void push(int x);
	int pop();
	int peek(int index);
	int isFull();
	int isEmpty();
	void display();
	int stackTop();
};
