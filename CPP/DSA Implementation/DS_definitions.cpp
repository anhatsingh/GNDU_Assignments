#include <iostream>
using namespace std;

class Stack{
    private:
        int max, top;
        int stck[1000];
    public:
        Stack(int n): max(n-1), top(0){
            for(int i = 0; i<n; i++){
                stck[i] = 0;
            }
        }

        void push(int element){
            if(top <= max){
                stck[top] = element;
                top +=  1;
            } else {
                cout << "Overflow";
            }
        }

        void pop(){
            if(top > 0){                
                top -=  1;
            } else {
                cout << "Underflow";
            }
        }

        int display(){
            if (top > 0){                
                cout << stck[top - 1] << endl;
            } else {
                cout << "Stack Empty" << endl;
            }
            
        }
};


class Queue{
    private:        
        int que[1000];
    public:
        int front, rear, max;
        Queue(int n): max(n-1), front(-1), rear(-1){
            for(int i = 0; i < n; i++){
                que[i] = 0;
            }
        }

        void insert(int element){
            if (rear == -1) {                
                rear = 0;
                front = 0;
                que[rear] = element;                
            }
            else if (rear == max && front != 0) {                
                rear = 0;
                que[rear] = element;                
            }
            else if (rear + 1 != front && rear < max){                
                rear += 1;
                que[rear] = element;                
            }
            else {                
                cout << "Overflow";
            }
        }

        void del(){            
            if (front == -1){
                front = -1;
                rear = -1;
                cout << "Underflow" << endl;
            }
            else if (front == max) {
                front = 0;
            }
            else if (front == rear) {
                front = -1;
                rear = -1;
            }
            else {
                front += 1;
            }
            
        }

        void display(){
            if (front != -1){
                cout << que[front] << endl;
            } else {
                cout << "Underflow" << endl;
            }
        }
};