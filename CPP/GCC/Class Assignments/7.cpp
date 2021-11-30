#include <iostream>
using namespace std;

class Fibonacci{
    private:
        int n;
    public:
        Fibonacci(int max): n(max)
        {
        }

        int get_nth_term(int an){
            if(an == 1 or an == 2){
                return 1;
            } else {
                return get_nth_term(an-1) + get_nth_term(an-2);
            }
        }

        void print_sequence_upto_n(){
            for(int i = 1; i <= n; i++){
                cout << get_nth_term(i) << " ";
            }
        }
};


int main(){
    Fibonacci A(10);
    A.print_sequence_upto_n();
    return 0;
}