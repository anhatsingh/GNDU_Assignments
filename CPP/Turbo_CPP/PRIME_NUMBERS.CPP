#include  <iostream.h>
#include  <conio.h>

class Prime{
 private:
	int  num;
 public:
	Prime():  num(0){}
	Prime(int  n):  num(n){}
	int check_if_prime(int);
	int  sum_of_primes();
};

int  Prime::check_if_prime(int  c){
		for(int  i  =  2;  i<c;  ++i){
			if(c%i  ==  0){
				return  0;
			}
		}
		return  1;
}

int Prime::sum_of_primes(){
	int  sum  =  0,  count =  1;
		for(int i  =  2;  count  <=  num;  i++)
		{
			if(check_if_prime(i)){
				sum  +=  i;
				count++;
			}

		}
		return  sum;
}

int  main(){
clrscr();
Prime  n(4);

cout  << n.sum_of_primes();

getch();
return  0;
}