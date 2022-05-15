#include <iostream.h>
#include <conio.h>

const int QUEUE_LIMIT = 100;

class Queue{
	private:
		int arr[QUEUE_LIMIT];
		int FRONT;
		int BACK;
		int MAX;
	public:
		Queue(int);
		void insert(int);
		int get_front();
		void display();
		int is_empty();
}

Queue::Queue(int n){
	FRONT = -1;
	BACK = -1;
	MAX = n - 1;
	for(int i = 0; i<n; i++){
		arr[i] = 0;		
	}
}

void Queue::insert(int item){
	if((FRONT == 0 && BACK == MAX) || (FRONT == BACK + 1)){
		cout << "Queue Overflow <- Unable to insert" << endl;
	} else {
		if(FRONT == -1){
			FRONT = 0;
			BACK = 0;
		}
		else if(BACK == MAX){
			BACK = 1;
		} else {
			BACK += 1;
		}
		arr[BACK] = item;
	}
}

int Queue::get_front(){
	if(FRONT == -1){
		cout << "Queue Underflow <- Unable to get front" << endl;
		return -1;	
	}
	
	int item = arr[FRONT];
	if(FRONT == BACK){
		FRONT = -1;
		BACK = -1;
	} 
	else if(FRONT == MAX){
		FRONT = 1;
	}
	else {
		FRONT += 1;
	}
	return item;
}

int Queue::is_empty(){
	if(FRONT == -1){
		return 1;	
	} else {
		return 0;
	}
}

void Queue::display(){
	for(int i = 0; i<=MAX; i++){
		cout << i << ": " << arr[i] << endl;
	}
}