#include <iostream>
using namespace std;

class Number{
    private:
        int num;        
    public:
        Number(int n = 0): num(n) {
        }

        void check_if_prime(){
            bool is_prime = true;
            for(int i = 2; i < num; i++){
                if(num % i == 0){
                    is_prime = false;
                    break;
                }
            }
            if(is_prime){
                cout << num << " is prime" << endl;                
            } else {
                cout << num << " is NOT prime" << endl;
            }
        }

        void print_primes_upto_n(){
            for(int i = 2; i <= num; i++){
                bool is_prime = true;
                for(int j = 2; j < i; j++){
                    if(i%j == 0){
                        is_prime = false;
                        break;
                    }
                }

                if(is_prime) cout << i << " ";
            }
            cout << endl;
        }

        void is_number_even(){
            if(num % 2 == 0) {
                cout << "Number is Even" << endl;
            } else {
                cout << "Number is Odd" << endl;
            }
        }

        int factorial(){
            int fact = 1;
            for(int i = 1; i <= num; i++){
                fact *= i;
            }
            return fact;
        }

        void sum_of_digits(){
            int n = num;
            int sum = 0;
            
            while(n>0){
                sum = sum + n % 10;
                n = n / 10;
            }

            cout << "The sum is " << sum << endl;
        }
};

int main(){
    int n;
    cin >> n;
    
    Number my_num(n);
    
    my_num.check_if_prime();
    my_num.print_primes_upto_n();
    my_num.is_number_even();
    cout << my_num.factorial() << endl;
    my_num.sum_of_digits();
}