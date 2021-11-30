#include <iostream>

using namespace std;

class Swap{
    private:
        int var1, var2;
    public:
        Swap(int a, int b): var1(a), var2(b){

        }

        void print(){
            cout << "Var1 is: " << var1 << endl;
            cout << "Var2 is: " << var2 << endl;
        }

        void swap_with_3rd_variable(){
            int temp = var1;
            var1 = var2;
            var2 = temp;
        }

        void swap_without_3rd_variable(){
            var1 = var1*var2;
            var2 = var1/var2;
            var1 = var1/var2;
        }
};

int main(){
    int num1, num2;
    cin >> num1 >> num2;

    Swap my_nums(num1, num2);
    my_nums.print();
    my_nums.swap_with_3rd_variable();
    my_nums.print();
    my_nums.swap_without_3rd_variable();
    my_nums.print();
}