#include <iostream.h>
#include <conio.h>

#include <C:\\TURBOC3\Projects\STACK.CPP>
#include <C:\\TURBOC3\Projects\QUEUE.CPP>

int  main(){
clrscr();

Stack  my_stck(3);
my_stck.push(10);
my_stck.push(20);
my_stck.push(30);
my_stck.push(40);

cout << my_stck.pop() << endl;
cout << my_stck.pop() << endl;
cout << my_stck.pop() << endl;
cout << my_stck.pop() << endl;

cout<< endl;

Queue my_q(3);
my_q.insert(10);
my_q.insert(20);
my_q.insert(30);
my_q.insert(40);

cout << my_q.get_front() << endl;
cout << my_q.get_front() << endl;
cout << my_q.get_front() << endl;
cout << my_q.get_front() << endl;

getch();
return  0;
}