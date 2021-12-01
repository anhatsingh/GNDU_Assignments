#include <iostream.h>
#include <conio.h>

class A{
	public:
	A(){
		cout << "This is class A"  <<  endl;
	}

	virtual  void  ab(){
		cout  <<  "This  is  A  virt"  <<  endl;
	};
};

class B : public A{
	public:
	B(){
		cout << "This is class B"  <<  endl;
	}

	void  ab(){
		cout  <<  "This  is  virt"  <<  endl;
	}
};


int main(){
clrscr();

B abcd;
abcd.ab();

A  efgh;
efgh.ab();

getch();
return 0;
}