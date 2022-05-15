//  This  contains  reversing  a  number,  finding  sum  of  digits  of  a  number,  if number  is  palindrome.

//  instead  of  storing  number  as  a  int,  i  will  be  storing  it  as  character  array.

#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <string.h>

class Number {
	private:
		char num[50];
	public:
		Number();
		char* reverse();
		int palindrome();
		int sum_of_digits();
};

Number::Number(){
//Storing  the  number  as  character  array.
	cout << "Enter the number: ";
	char ch = getche();
	int i = 0;
	while(ch != '\r'){
		num[i] = ch;
		ch = getche();
		i++;
	}
	num[i] = '\0';
}

char* Number::reverse(){
	return strrev(num);

}

int  Number::palindrome(){
	char temp[50];
	this->reverse();

	int i = 0;
	while(num[i]){
		temp[i] = num[i];
		i++;
	}
	temp[i] = '\0';
	this->reverse();

	if(strcmp(temp,  num)  ==  0){
		return  1;
	}  else  {
		return  0;
	}
}

int  Number::sum_of_digits(){
     int i  =  0;
     int sum  =  0;
     while(num[i]){
	     sum  +=  num[i]  -  '0';
	     i++;
     }
     return  sum;
}

int main(){
clrscr();

Number n;
cout  <<  endl;
cout  <<  n.reverse()  <<  endl;
cout  <<  n.palindrome()  <<  endl;
cout  <<  n.sum_of_digits()  <<  endl;

getch();
return 0;
}