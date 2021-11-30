#include <iostream.h>
#include <conio.h>

const int STACK_LIMIT = 100;

class Stack{
	private:
		int arr[STACK_LIMIT];
		int TOP;
		int MAX;
	public:
		Stack(int);
		void push(int);
		int pop();
		void display();
}

Stack::Stack(int n){
	TOP = -1;
	MAX = n - 1;
	for(int i = 0; i<n; i++){
		arr[i] = 0;		
	}
}

void Stack::push(int item){
	if(TOP < MAX){
		arr[++TOP] = item;
	} else {
		cout << "Stack Overflow <- Unable to PUSH" << endl;
	}
}

int Stack::pop(){
	if(TOP >=0){
		return arr[TOP--];
	} else {
		cout << "Stack Underflow <- Unable to POP" << endl;
		return -1;
	}
}

void Stack::display(){
	for(int i = 0; i<=TOP; i++){
		cout << i << ": " << arr[i];
	}
}