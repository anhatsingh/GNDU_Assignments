#include <iostream>

using namespace std;

class matrix{
    private:
        int m,n;
    public:
        int arr[10][10];
        
        matrix(){
            for(int i = 0; i < 10; i++){
                for(int j = 0; j < 10; j++){
                    arr[i][j] = 0;
                }
            }
            cout << "Enter number of rows of matrix: ";
            cin >> m;
            cout << "Enter number of columns of matrix: ";
            cin >> n;
        }

        void read(){
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    cin >> arr[i][j];
                }
            }
        }

        void add(matrix B){
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    arr[i][j] += B.arr[i][j];
                }
            }
        }

        void multiply(matrix B){
            int temp[m][n];
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    temp[i][j] = 0;
                    for(int k = 0; k < m; k++){
                        temp[i][j] += arr[i][k] * B.arr[k][j];
                    }
                }
            }

            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    arr[i][j] = temp[i][j];
                }
            }
        }

        void print(){
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    cout << arr[i][j] << ",";
                }
                cout << endl;
            }
        }

        int diagonal_sum(){
            int sum = 0;
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(i == j){
                        sum += arr[i][j];
                    }
                }
            }
            return sum;
        }
};


int main(){
    matrix A,B;

    A.read();
    B.read();
    
    A.add(B);
    A.print();

    A.multiply(B);
    A.print();

    cout << A.diagonal_sum() << endl;

    return 0;

}